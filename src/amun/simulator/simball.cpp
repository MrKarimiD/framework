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

#include "simball.h"
#include "simulator.h"
#include "core/rng.h"
#include "protobuf/ssl_detection.pb.h"

SimBall::SimBall(RNG *rng, btDiscreteDynamicsWorld *world) :
    m_rng(rng),
    m_world(world)
{
    // see http://robocup.mi.fu-berlin.de/buch/rolling.pdf for correct modelling
    m_sphere = new btSphereShape(BALL_RADIUS * SIMULATOR_SCALE);

    btVector3 localInertia(0, 0, 0);
    // FIXME measure inertia coefficient
    m_sphere->calculateLocalInertia(BALL_MASS, localInertia);

    btTransform startWorldTransform;
    startWorldTransform.setIdentity();
    startWorldTransform.setOrigin(btVector3(0, 0, BALL_RADIUS) * SIMULATOR_SCALE);
    m_motionState = new btDefaultMotionState(startWorldTransform);

    btRigidBody::btRigidBodyConstructionInfo rbInfo(BALL_MASS, m_motionState, m_sphere, localInertia);

    // parameters seem to be ignored...
    m_body = new btRigidBody(rbInfo);
    m_body->setRestitution(0.78f);
    // \mu_k = -a / g (while slipping)
    m_body->setFriction(0.35f);
    // \mu_r = -a / g = 0.0357 (while rolling)
    // rollingFriction in bullet is too unstable to be useful
    // use custom implementation in begin()
    m_world->addRigidBody(m_body);
}

SimBall::~SimBall()
{
    m_world->removeRigidBody(m_body);
    delete m_body;
    delete m_sphere;
    delete m_motionState;
}

void SimBall::begin()
{
    // custom implementation of rolling friction
    const btVector3 p = m_body->getWorldTransform().getOrigin() / SIMULATOR_SCALE;
    if (p.z() < BALL_RADIUS * 1.1) { // ball is on the ground
        const btVector3 velocity = m_body->getLinearVelocity() / SIMULATOR_SCALE;
        if (velocity.length() < 0.01) {
            // stop the ball if it is really slow
            // -> the real ball snaps to a dimple
            m_body->setLinearVelocity(btVector3(0, 0, 0));
        } else {
            // just apply rolling friction, normal friction is somehow handled by bullet
            // this is quite a hack as it's always applied
            // but as the strong deceleration is more or less magic, some additional deceleration doesn't matter
            const btScalar hackFactor = 1.4;
            const btScalar rollingDeceleration = hackFactor * 0.35;
            btVector3 force(velocity.x(), velocity.y(), 0.0f);
            force.normalize();
            m_body->applyCentralImpulse(-force * rollingDeceleration * SIMULATOR_SCALE * BALL_MASS * SUB_TIMESTEP);
        }
    }

    if (m_move.has_p_x()) {
        if (m_move.position()) {
            // set ball to the given position and speed
            const btVector3 pos(m_move.p_x(), m_move.p_y(), BALL_RADIUS);
            btTransform transform = m_body->getWorldTransform();
            transform.setOrigin(pos * SIMULATOR_SCALE);
            m_body->setWorldTransform(transform);
            const btVector3 linVel(m_move.v_x(), m_move.v_y(), 0.0f);
            m_body->setLinearVelocity(linVel * SIMULATOR_SCALE);
            m_body->activate();
            m_body->setDamping(0.0, 0.0);
            m_move.Clear(); // clear move command
            // reset is neccessary, as the command is only sent once
            // without one canceling it
        } else {
            // move ball by hand
            btVector3 force(m_move.p_x(), m_move.p_y(), 0.0f);
            force = force - m_body->getWorldTransform().getOrigin() / SIMULATOR_SCALE;
            force.setZ(0.0f);
            m_body->activate();
            m_body->applyCentralImpulse(force * BALL_MASS * 0.1 * SIMULATOR_SCALE);
            m_body->setDamping(0.99, 0.99);
        }
    } else {
        // ball is slowed down by rolling friction, not damping!
        m_body->setDamping(0.0, 0.0);
    }
}

void SimBall::update(SSL_DetectionBall *ball, float stddev)
{
    // setup ssl-vision ball detection
    ball->set_confidence(1.0);
    ball->set_pixel_x(0);
    ball->set_pixel_y(0);

    btTransform transform;
    m_motionState->getWorldTransform(transform);
    const btVector3 p = transform.getOrigin() / SIMULATOR_SCALE;

    // add noise to coordinates
    // to convert from bullet coordinate system to ssl-vision rotate by 90 degree ccw
    const Vector2 noise = m_rng->normalVector(stddev);
    ball->set_x((p.y() + noise.x) * 1000.0f);
    ball->set_y(-(p.x() + noise.y) * 1000.0f);
    ball->set_z(p.z() * 1000.0f);
}

void SimBall::move(const amun::SimulatorMoveBall &ball)
{
    m_move = ball;
}

btVector3 SimBall::position() const
{
    const btTransform transform = m_body->getWorldTransform();
    return btVector3(transform.getOrigin().x(), transform.getOrigin().y(), 0);
}

void SimBall::kick(const btVector3 &power)
{
    m_body->activate();
    m_body->applyCentralForce(power);
}
