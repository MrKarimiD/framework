/***************************************************************************
 *   Copyright 2015 Florian Bauer. Michael Eischer, Jan Kallwies,          *
 *       Philipp Nordhus                                                   *
 *   Robotics Erlangen e.V.                                                *
 *   http://www.robotics-erlangen.de/                                      *
 *   info@robotics-erlangen.de                                             *
 *                                                                         *
 *   This program is free software: you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation, either version 3 of the License, or     *
 *   any later version.                                                    *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 ***************************************************************************/

#include "lua_path.h"
#include "lua_protobuf.h"
#include "lua.h"
#include "path/path.h"
#include "protobuf/debug.pb.h"
#include "protobuf/robot.pb.h"
#include "core/timer.h"

// ensure that we got a valid number
static float verifyNumber(lua_State *L, int index)
{
    const float number = luaL_checknumber(L, index);
    if (std::isnan(number) || std::isinf(number)) {
        luaL_argerror(L, index, "invalid number");
    }
    return number;
}

static Path *checkPath(lua_State *L, int index)
{
    Path **p;
    p = (Path **) luaL_checkudata(L, index, "path");
    if (p == NULL) {
        luaL_typerror(L, index, "path");
    }
    return *p;
}

static void updateTiming(lua_State *L, lua_Number time)
{
    // update path planning time
    lua_getfield(L, LUA_REGISTRYINDEX, "PathPlanning");
    const lua_Number v = lua_tonumber(L, -1) + time;
    lua_pop(L, 1);

    lua_pushnumber(L, v);
    lua_setfield(L, LUA_REGISTRYINDEX, "PathPlanning");
}

// Path is a C++ class and thus can't be created with newuserdata
static int pathCreate(lua_State *L)
{
    Path **p = (Path **) lua_newuserdata(L, sizeof(Path*));
    *p = new Path;
    luaL_getmetatable(L, "path");
    lua_setmetatable(L, -2);
    return 1;
}

static int pathDestroy(lua_State *L)
{
    delete checkPath(L, 1);
    return 0;
}

static int pathReset(lua_State *L)
{
    Path *p = checkPath(L, 1);
    p->reset();
    return 0;
}

static int pathClearObstacles(lua_State *L)
{
    Path *p = checkPath(L, 1);
    p->clearObstacles();
    return 0;
}

static int pathSetBoundary(lua_State *L)
{
    Path *p = checkPath(L, 1);
    const float x1 = verifyNumber(L, 2);
    const float y1 = verifyNumber(L, 3);
    const float x2 = verifyNumber(L, 4);
    const float y2 = verifyNumber(L, 5);
    p->setBoundary(x1, y1, x2, y2);
    return 0;
}

static int pathSetRadius(lua_State *L)
{
    Path *p = checkPath(L, 1);
    const float r = verifyNumber(L, 2);
    p->setRadius(r);
    return 0;
}

static int pathAddCircle(lua_State *L)
{
    Path *p = checkPath(L, 1);
    const float x = verifyNumber(L, 2);
    const float y = verifyNumber(L, 3);
    const float r = verifyNumber(L, 4);
    const char* name = NULL;
    name = luaL_optlstring(L,5, "NoName", 0);
    p->addCircle(x, y, r, name);
    return 0;
}

static int pathAddLine(lua_State *L)
{
    Path *p = checkPath(L, 1);
    const float x1 = verifyNumber(L, 2);
    const float y1 = verifyNumber(L, 3);
    const float x2 = verifyNumber(L, 4);
    const float y2 = verifyNumber(L, 5);
    const float width = verifyNumber(L, 6);

    const char* name = NULL;
    name = luaL_optlstring(L,7, "NoName", 0);

    // a line musn't have length zero
    if (x1 == x2 && y1 == y2) {
        luaL_error(L, "Points are identical");
    }
    p->addLine(x1, y1, x2, y2, width, name);
    return 0;
}

static int pathSetProbabilities(lua_State *L)
{
    Path *p = checkPath(L, 1);
    const float p_dest = verifyNumber(L, 2);
    const float p_wp = verifyNumber(L, 3);
    p->setProbabilities(p_dest, p_wp);
    return 0;
}

static int pathAddRect(lua_State *L)
{
    Path *p = checkPath(L, 1);
    const float x1 = verifyNumber(L, 2);
    const float y1 = verifyNumber(L, 3);
    const float x2 = verifyNumber(L, 4);
    const float y2 = verifyNumber(L, 5);

    const char* name = NULL;
    name = luaL_optlstring(L,6, "NoName", 0);

    p->addRect(x1, y1, x2, y2, name);
    return 0;
}

static int pathTest(lua_State *L)
{
    const qint64 t = Timer::systemTime();

    Path *p = checkPath(L, 1);

    // get spline
    robot::Spline spline;
    protobufToMessage(L, 2, spline);

    if (spline.t_start() >= spline.t_end()) {
        luaL_error(L, "t_start (%f) has to be less than t_end (%f)", spline.t_start(), spline.t_end());
    }

    const float radius = verifyNumber(L, 3);
    const bool ret = p->testSpline(spline, radius);
    lua_pushboolean(L, ret);

    updateTiming(L, (Timer::systemTime() - t) / 1E9);

    return 1;
}

static int pathGet(lua_State *L)
{
    const qint64 t = Timer::systemTime();

    // robot radius must have been set before
    Path *p = checkPath(L, 1);
    if (!p->isRadiusValid()) {
        luaL_error(L, "No valid radius set for path object");
        return 0;
    }

    const float start_x = verifyNumber(L, 2);
    const float start_y = verifyNumber(L, 3);
    const float end_x = verifyNumber(L, 4);
    const float end_y = verifyNumber(L, 5);

    Path::List list = p->get(start_x, start_y, end_x, end_y);

    // convert path to lua table
    int i = 1;
    lua_createtable(L, list.size() + 1, 0);

    foreach (const Path::Waypoint &wp, list) {
        lua_pushinteger(L, i++);
        lua_createtable(L, 0, 4);

        lua_pushnumber(L, wp.x);
        lua_setfield(L, -2, "p_x");
        lua_pushnumber(L, wp.y);
        lua_setfield(L, -2, "p_y");
        lua_pushnumber(L, wp.l);
        lua_setfield(L, -2, "left");
        lua_pushnumber(L, wp.r);
        lua_setfield(L, -2, "right");

        lua_settable(L, -3);
    }

    updateTiming(L, (Timer::systemTime() - t) / 1E9);

    return 1;
}

static void drawTree(Lua *thread, const KdTree *tree) {
    if (tree == NULL) {
        return;
    }
    const QList<const KdTree::Node *> nodes = tree->getChildren();

    amun::Point *point;
    // draw tree by creating lines from every node to its predecessor
    foreach (const KdTree::Node *node, nodes) {
        amun::Visualization *vis = thread->addVisualization();
        vis->set_name("RRT");
        amun::Pen *pen = vis->mutable_pen();
        pen->mutable_color()->set_red(255);
        amun::Path *path = vis->mutable_path();

        const Vector &p1 = tree->position(node);
        point = path->add_point();
        point->set_x(p1.x);
        point->set_y(p1.y);

        const KdTree::Node *endNode = tree->previous(node);
        if (tree->inObstacle(endNode)) { // mark line segments starting in an obstacle node
            pen->mutable_color()->set_blue(255);
        }
        const Vector &p2 = tree->position(endNode);
        point = path->add_point();
        point->set_x(p2.x);
        point->set_y(p2.y);
    }
}

static int pathAddTreeVisualization(lua_State *L)
{
    const Path *p = checkPath(L, 1);
    Lua *thread = getStrategyThread(L);
    drawTree(thread, p->treeStart());
    drawTree(thread, p->treeEnd());
    return 0;
}

static const luaL_Reg pathMethods[] = {
    {"create",          pathCreate},
    {"reset",           pathReset},
    {"clearObstacles",  pathClearObstacles},
    {"setBoundary",     pathSetBoundary},
    {"setRadius",       pathSetRadius},
    {"addCircle",       pathAddCircle},
    {"addLine",         pathAddLine},
    {"addRect",         pathAddRect},
    {"setProbabilities",    pathSetProbabilities},
    {"test",            pathTest},
    {"get",             pathGet},
    {"addTreeVisualization", pathAddTreeVisualization},
    {0, 0}
};

static const luaL_Reg pathMeta[] = {
    // ensure the path object is deleted
    {"__gc", pathDestroy},
    {0, 0}
};

int pathRegister(lua_State *L)
{
    luaL_register(L, "path", pathMethods);
    luaL_newmetatable(L, "path");
    luaL_register(L, 0, pathMeta);
    lua_pushliteral(L, "__index");
    lua_pushvalue(L, -3);
    lua_rawset(L, -3);
    lua_pushliteral(L, "__metatable");
    lua_pushvalue(L, -3);
    lua_rawset(L, -3);
    lua_pop(L, 1);
    return 1;
}
