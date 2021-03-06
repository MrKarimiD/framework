/***************************************************************************
 *   Copyright 2015 Philipp Nordhus                                        *
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

#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>

/*!
 * \ingroup path
 * \brief 2-dimensional vector class
 */
class Vector
{
public:
    /*!
     * \brief Contructor
     *
     * This constructor does not initialize any members
     */
    Vector() {}

    /*!
     * \brief Initializing constructor
     * \param x x-coordinate of the vector
     * \param y y-coordinate of the vector
     */
    Vector(float x, float y) { d[0] = x; d[1] = y; }

public:
    float& operator [] (unsigned int index);
    float operator [] (unsigned int index) const;
    Vector operator + (const Vector &rho) const;
    Vector operator - (const Vector &rho) const;
    Vector operator * (float scalar) const;
    Vector operator / (float scalar) const;
    Vector& operator *= (float scalar);
    float operator * (const Vector &rho) const;
    bool operator == (const Vector &rho) const;
    bool operator != (const Vector &rho) const;

    Vector perpendicular() const;
    Vector normalized() const;
    float length() const;
    float lengthSquared() const;
    float distance(const Vector &rho) const;

public:
    union {
        struct {
            float x;
            float y;
        };
        float d[2];
    };
};

inline float& Vector::operator [] (unsigned int index)
{
    return d[index];
}

inline float Vector::operator [] (unsigned int index) const
{
    return d[index];
}

inline Vector Vector::operator + (const Vector &rho) const
{
    return Vector(x + rho.x, y + rho.y);
}

inline Vector Vector::operator - (const Vector &rho) const
{
    return Vector(x - rho.x, y - rho.y);
}

inline Vector Vector::operator * (float scalar) const
{
    return Vector(x * scalar, y * scalar);
}

inline Vector Vector::operator / (float scalar) const
{
    return Vector(x / scalar, y / scalar);
}

inline float Vector::operator * (const Vector &rho) const
{
    return x * rho.x + y * rho.y;
}

inline bool Vector::operator == (const Vector &rho) const
{
    return x == rho.x && y == rho.y;
}

inline bool Vector::operator != (const Vector &rho) const
{
    return x != rho.x || y != rho.y;
}

inline Vector& Vector::operator *= (float scalar)
{
    x *= scalar;
    y *= scalar;
    return *this;
}

/*!
 * \brief Calculate a perpendicular vector
 * \return A vector perpendicular to this one
 */
inline Vector Vector::perpendicular() const
{
    return Vector(-y, x);
}

/*!
 * \brief Normalize the vector
 * \return A normalized copy of the vector
 */
inline Vector Vector::normalized() const
{
    Vector v = *this;
    const float l = length();
    if (l > 0) {
        v.x /= l;
        v.y /= l;
    }
    return v;
}

/*!
 * \brief Calculate the length of the vector
 * \return The length of the vector
 */
inline float Vector::length() const
{
    return std::sqrt(lengthSquared());
}

/*!
 * \brief Calculate the squared length of the vector
 * \return The squared length of the vector
 */
inline float Vector::lengthSquared() const
{
    return d[0] * d[0] + d[1] * d[1];
}

/*!
 * \brief Calculate the distance to another vector
 * \param rho Another vector
 * \return The distance to the other vector
 */
inline float Vector::distance(const Vector &rho) const
{
    return (*this - rho).length();
}

#endif // VECTOR_H
