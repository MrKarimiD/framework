/***************************************************************************
 *   Copyright 2015 Michael Eischer, Philipp Nordhus                       *
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

#ifndef FIELDWIDGET_H
#define FIELDWIDGET_H

#include "protobuf/command.h"
#include "protobuf/status.h"
#include <QGraphicsView>
#include <QMap>
#include <QHash>

class QLabel;
class QMenu;
class QGestureEvent;

class FieldWidget : public QGraphicsView
{
    Q_OBJECT

private:
    struct Robot
    {
        Robot() : robot(NULL), id(NULL) {}
        QGraphicsPathItem *robot;
        QGraphicsSimpleTextItem *id;
        bool visible;
    };

    typedef QMap<uint, Robot> RobotMap;
    enum DragType {
        DragNone =          0x00,
        DragBall =          0x10,
        DragYellow =        0x20,
        DragBlue =          0x21,
        DragTopLeft =       0x40,
        DragTopRight =      0x41,
        DragBottomLeft =    0x42,
        DragBottomRight =   0x43,
        DragAOIMask =       0x40
    };

public:
    explicit FieldWidget(QWidget *parent = 0);
    ~FieldWidget();

signals:
    void sendCommand(const Command &command);

public slots:
    void handleStatus(const Status &status);
    void visualizationsChanged(const QStringList &items);
    void clearData();
    void hideVisualizationToggles();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *);
    void resizeEvent(QResizeEvent *event);
    bool gestureEvent(QGestureEvent *event);
    void drawBackground(QPainter *painter, const QRectF &rect);
    void leaveEvent(QEvent *event);
    bool event(QEvent *event);

private slots:
    void updateVisualizationVisibility();
    void setHorizontal();
    void setVertical();
    void flip();
    void setAntialiasing(bool enable);
    void setOpenGL(bool enable);
    void updateAll();
    void setAOIVisible(bool visible);
    void takeScreenshot();
    void saveSituation();

private:
    void resizeAOI(const QPointF &pos);
    void updateAOI();
    void updateDetection();
    void updateGeometry();
    void updateVisualizations();
    void updateVisualizations(const amun::DebugValues &v);
    void clearTeamData(RobotMap &team, QHash<uint, robot::Specs> &specsMap);
    void updateTeam(RobotMap &team, QHash<uint, robot::Specs> &specsMap, const robot::Team &specs);
    void setRobot(const world::Robot &robot, const robot::Specs &specs, RobotMap &robots, const QColor &color);
    void addBlob(float x, float y, const QBrush &brush, QGraphicsItem *parent);
    void setFieldOrientation(float rotation);
    void sendSimulatorMoveCommand(const QPointF &p);
    void drawLines(QPainter *painter, QRectF rect, bool cosmetic);
    void drawGoal(QPainter *painter, float side, bool cosmetic);
    QGraphicsItem* createCircle(const QPen &pen, const QBrush &brush, const amun::Visualization &vis);
    QGraphicsItem* createPolygon(const QPen &pen, const QBrush &brush, const amun::Visualization &vis);
    QGraphicsItem* createPath(const QPen &pen, const QBrush &brush, const amun::Visualization &vis);
    void layoutChildren();

private:
    QGraphicsScene *m_scene;

    QMenu *m_contextMenu;
    QAction *m_actionShowBlueVis;
    QAction *m_actionShowYellowVis;
    QAction *m_actionShowControllerVis;
    QAction *m_actionAntialiasing;
    QAction *m_actionGL;

    std::string m_geometryString;
    bool m_geometryUpdated;
    world::Geometry m_geometry;
    float m_rotation;
    QRectF m_fieldRect;
    QRectF m_aoi;
    QGraphicsPathItem *m_aoiItem;

    QHash<uint, robot::Specs> m_teamBlue;
    QHash<uint, robot::Specs> m_teamYellow;
    world::State m_worldState;
    bool m_worldStateUpdated;
    QMap<int, bool> m_visibleVisSources;
    // save status to avoid copying the debug values
    QMap<int, Status> m_visualizations;
    bool m_visualizationsUpdated;
    amun::GameState m_gameState;

    QGraphicsEllipseItem *m_ball;
    QStringList m_visibleVisualizations;
    typedef QList<QGraphicsItem*> Items;
    Items m_visualizationItems;
    RobotMap m_robotsBlue;
    RobotMap m_robotsYellow;

    Qt::GestureType m_touchStatusType;
    bool m_hasTouchInput;
    QLabel *m_lblMousePos;
    QPointF m_mouseBegin;
    QPoint m_dragStart;
    DragType m_dragType;
    QGraphicsItem *m_dragItem;
    int m_dragId;
};

#endif // FIELDWIDGET_H
