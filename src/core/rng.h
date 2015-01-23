/***************************************************************************
 *   Copyright 2014 Philipp Nordhus                                        *
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

#ifndef RNG_H
#define RNG_H

#include "vector2.h"
#include <inttypes.h>

class RNG
{
public:
    RNG(uint32_t seed = 0);

public:
    uint32_t uniformInt();
    double uniform();
    double uniformPositive();
    Vector2 uniformVector();
    double normal(double sigma, double mean = 0.0);
    Vector2 normalVector(double sigma, double mean = 0.0);

private:
    uint32_t m_s1;
    uint32_t m_s2;
    uint32_t m_s3;
};

/*!
 * \brief Generate a random floating point number in the range [0, 1]
 * \return A random number drawn from a uniform distribution [0, 1]
 */
inline double RNG::uniform()
{
    return uniformInt() / 4294967296.0;
}

/*!
 * \brief Initialize a vector with two random values drawn from a uniform distribution
 *
 * \sa uniform
 * \return A random vector drawn from a uniform distribution
 */
inline Vector2 RNG::uniformVector()
{
    return Vector2(uniform(), uniform());
}

/*!
 * \brief Generate a random value drawn from a normal distribution
 * \param sigma Standard deviation
 * \param mean Expected value
 * \return A random value drawn from a normal distribution
 */
inline double RNG::normal(double sigma, double mean)
{
    return normalVector(sigma, mean).x;
}

#endif // RNG_H
