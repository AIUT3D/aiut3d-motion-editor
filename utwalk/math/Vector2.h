/**
 * @file Vector2.h
 * Contains template class Vector2 of type V
 *
 * @author <a href="mailto:martin.kallnik@gmx.de">Martin Kallnik</a>
 * @author Max Risler
 */

#ifndef __Vector2_h__
#define __Vector2_h__

#include <cmath>
#include <iostream>

/** This class represents a 2-vector */
template <class V> class Vector2
{
public:
    /** The vector values */
    V x,y;

    /** Default constructor. */
    Vector2<V>():x(0),y(0)
    {
    }
    /** Default constructor. */
    Vector2<V>(V x, V y):x(x),y(y)
    {
    }

    /** Assignment operator
    *\param other The other vector that is assigned to this one
    *\return A reference to this object after the assignment.
    */
    Vector2<V>& operator=(const Vector2<V>& other)
    {
        x=other.x;
        y=other.y;
        return *this;
    }

    /** Copy constructor
    *\param other The other vector that is copied to this one
    */
    Vector2<V>(const Vector2<V>& other) {
        *this = other;
    }

    /** Addition of another vector to this one.
    *\param other The other vector that will be added to this one
    *\return A reference to this object after the calculation.
    */
    Vector2<V>& operator+=(const Vector2<V>& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    /** Substraction of this vector from another one.
    *\param other The other vector this one will be substracted from
    *\return A reference to this object after the calculation.
    */
    Vector2<V>& operator-=(const Vector2<V>& other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    /** Multiplication of this vector by a factor.
    *\param factor The factor this vector is multiplied by
    *\return A reference to this object after the calculation.
    */
    Vector2<V>& operator*=(const V& factor)
    {
        x *= factor;
        y *= factor;
        return *this;
    }

    /** Division of this vector by a factor.
    *\param factor The factor this vector is divided by
    *\return A reference to this object after the calculation.
    */
    Vector2<V>& operator/=(const V& factor)
    {
        if (factor == 0) return *this;
        x /= factor;
        y /= factor;
        return *this;
    }

    /** Addition of another vector to this one.
    *\param other The other vector that will be added to this one
    *\return A new object that contains the result of the calculation.
    */
    Vector2<V> operator+(const Vector2<V>& other) const
    {
        return Vector2<V>(*this) += other;
    }

    /** Subtraction of another vector to this one.
    *\param other The other vector that will be added to this one
    *\return A new object that contains the result of the calculation.
    */
    Vector2<V> operator-(const Vector2<V>& other) const
    {
        return Vector2<V>(*this) -= other;
    }

    /** Negation of this vector.
    *\return A new object that contains the result of the calculation.
    */
    Vector2<V> operator-() const
    {
        return Vector2<V>() -= *this;
    }

    /** Inner product of this vector and another one.
    *\param other The other vector this one will be multiplied by
    *\return The inner product.
    */
    V operator*(const Vector2<V>& other) const
    {
        return x * other.x + y * other.y;
    }

    /** Multiplication of this vector by a factor.
    *\param factor The factor this vector is multiplied by
    *\return A new object that contains the result of the calculation.
    */
    Vector2<V> operator*(const V& factor) const
    {
        return Vector2<V>(*this) *= factor;
    }

    /** Division of this vector by a factor.
    *
    *\param factor The factor this vector is divided by
    *\return A new object that contains the result of the calculation.
    */
    Vector2<V> operator/(const V& factor) const
    {
        return Vector2<V>(*this) /= factor;
    }

    /** Comparison of another vector with this one.
    *\param other The other vector that will be compared to this one
    *\return Whether the two vectors are equal.
    */
    bool operator==(const Vector2<V>& other) const
    {
        return (x==other.x && y==other.y);
    }

    /** Comparison of another vector with this one.
    *\param other The other vector that will be compared to this one.
    *\return Whether the two vectors are unequal.
    */
    bool operator!=(const Vector2<V>& other) const
    {
        return !(*this == other);
    }

    /** Calculation of the length of this vector.
    *\return The length.
    */
    V abs() const
    {
        return (V) sqrtf(((float)x)*x+((float)y)*y);
    }

    /** Calculation of the square length of this vector.
    *\return length*length.
    */
    V squareAbs() const
    {
        return (x*x) + (y*y);
    }

    /** normalize this vector.
    *\param len The length, the vector should be normalized to, default=1.
    *\return the normalized vector.
    */
    Vector2<V> normalize(V len)
    {
        const V length = abs();
        if (length == 0) return *this;
        return *this = (*this * len) / length;
    }

    /** normalize this vector.
    *\return the normalized vector.
    */
    Vector2<V> normalize()
    {
        const V length = abs();
        if (length == 0) return *this;
        return *this /= length;
    }

    /** transpose this vector.
    *\return the transposed vector.
    */
    Vector2<V> transpose()
    {   V buffer = x;
        x = y;
        y = buffer;
        return *this;
    }

    /** the vector is rotated left by 90 degrees.
    *\return the rotated vector.
    */
    Vector2<V> rotateLeft()
    {   V buffer = -y;
        y = x;
        x = buffer;
        return *this;
    }

    /** the vector is rotated right by 90 degrees.
    *\return the rotated vector.
    */
    Vector2<V> rotateRight()
    {   V buffer = -x;
        x = y;
        y = buffer;
        return *this;
    }

    /** the vector is rotated by alpha degrees.
    *\return the rotated vector.
    */
    Vector2<V> rotate(float alpha)
    {   float buffer = (float) x;
        float a = cosf(alpha);
        float b = sinf(alpha);
        x = (V)(a*(float)x - b*(float)y);
        y = (V)(b*buffer + a*(float)y);
        return *this;
    }

    /**
    * array-like member access.
    * \param i index of coordinate
    * \return reference to x or y
    */
    V& operator[](int i)
    {
        return  (&x)[i];
    }

    /**
    * const array-like member access.
    * \param i index of coordinate
    * \return reference to x or y
    */
    const V& operator[](int i) const
    {
        return  (&x)[i];
    }

    /** Calculation of the angle of this vector */
    float angle() const
    {
        return atan2f((float)y,(float)x);
    }

    /**
    * Calculation of the square of the vector.
    * \return The square
    */
    V sqr() const {
        return x * x + y * y;
    }

    friend std::ostream& operator<<(std::ostream &out, const Vector2<V>& vec)
    {
        out << "(" << vec.x << "," << vec.y << ")";
        return out;
    }
};

#endif // __Vector2_h__
