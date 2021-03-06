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

#ifndef BALLFILTER_H
#define BALLFILTER_H

#include "filter.h"
#include "kalmanfilter.h"
#include "protobuf/world.pb.h"
#include "protobuf/ssl_detection.pb.h"
#include <QList>
#include <QPair>

class BallFilter : public Filter
{
public:
    BallFilter(const SSL_DetectionBall &ball, qint64 last_time);
    ~BallFilter();

public:
    void update(qint64 time);
    void get(world::Ball *ball, bool flip);

    void addVisionFrame(qint32 cameraId, const SSL_DetectionBall &ball, qint64 time);

    float distanceTo(const SSL_DetectionBall &ball) const;
    static bool isInAOI(const SSL_DetectionBall &ball, bool flip, float x1, float y1, float x2, float y2);

private:
    struct VisionFrame
    {
        VisionFrame(qint32 cameraId, const SSL_DetectionBall &detection, qint64 time)
            : cameraId(cameraId), detection(detection), time(time) {}
        qint32 cameraId;
        SSL_DetectionBall detection;
        qint64 time;
    };
    typedef KalmanFilter<4, 2> Kalman;

    void predict(qint64 time, bool cameraSwitched);
    void applyVisionFrame(const VisionFrame &frame);

    float m_x;
    float m_y;
    qint64 m_time;
    QList<world::BallPosition> m_measurements;

    Kalman *m_kalman;
    QList<VisionFrame> m_visionFrames;
};

#endif // BALLFILTER_H
