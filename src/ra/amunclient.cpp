/***************************************************************************
 *   Copyright 2014 Michael Eischer, Philipp Nordhus                       *
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

#include "amunclient.h"
#include "amun/amun.h"

AmunClient::AmunClient(QObject *parent) :
    QObject(parent),
    m_amun(NULL)
{
}

AmunClient::~AmunClient()
{
    stop();
}

void AmunClient::start(quint16 visionPort)
{
    delete m_amun;
    m_amun = new Amun(this);
    if (visionPort > 0) {
        m_amun->setVisionPort(visionPort);
    }
    connect(m_amun, SIGNAL(sendStatus(Status)), SIGNAL(gotStatus(Status)));
    m_amun->start();
}

void AmunClient::stop()
{
    delete m_amun;
    m_amun = NULL;
}

void AmunClient::sendCommand(const Command &command)
{
    m_amun->handleCommand(command);
}
