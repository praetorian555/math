#pragma once

#include "math/impl/normal3.h"
#include "math/impl/point2.h"
#include "math/impl/point3.h"
#include "math/impl/point4.h"
#include "math/impl/vector2.h"
#include "math/impl/vector3.h"
#include "math/impl/vector4.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
// Implementations
///////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
math::Vector3<T>::Vector3(const Normal3<T>& n) : X(n.X), Y(n.Y), Z(n.Z)
{
}

template <typename T>
math::Vector3<T>::Vector3(const Point3<T>& p) : X(p.X), Y(p.Y), Z(p.Z)
{
}

template <typename T>
math::Vector4<T>::Vector4(const Point4<T>& p) : X(p.X), Y(p.Y), Z(p.Z), W(p.W)
{
}

template <typename T>
math::Vector3<T>::Vector3(const Vector2<T>& XY, T Z) : X(XY.X), Y(XY.Y), Z(Z)
{
}

template <typename T>
math::Vector2<T> math::Vector3<T>::XY() const
{
    return Vector2<T>(X, Y);
}

template <typename T>
math::Vector2<T> math::Vector3<T>::YZ() const
{
    return Vector2<T>(Y, Z);
}

template <typename T>
math::Vector2<T> math::Vector3<T>::XZ() const
{
    return Vector2<T>(X, Z);
}

template <typename T>
math::Vector4<T>::Vector4(const Vector2<T>& XY, T Z, T W) : X(XY.X), Y(XY.Y), Z(Z), W(W)
{
}

template <typename T>
math::Vector4<T>::Vector4(const Vector3<T>& XYZ, T W) : X(XYZ.X), Y(XYZ.Y), Z(XYZ.Z), W(W)
{
}

template <typename T>
math::Vector2<T> math::Vector4<T>::XY() const
{
    return Vector2<T>(X, Y);
}

template <typename T>
math::Vector2<T> math::Vector4<T>::XZ() const
{
    return Vector2<T>(X, Z);
}

template <typename T>
math::Vector2<T> math::Vector4<T>::XW() const
{
    return Vector2<T>(X, W);
}

template <typename T>
math::Vector2<T> math::Vector4<T>::YZ() const
{
    return Vector2<T>(Y, Z);
}

template <typename T>
math::Vector2<T> math::Vector4<T>::YW() const
{
    return Vector2<T>(Y, W);
}

template <typename T>
math::Vector2<T> math::Vector4<T>::ZW() const
{
    return Vector2<T>(Z, W);
}

template <typename T>
math::Vector3<T> math::Vector4<T>::XYZ() const
{
    return Vector3<T>(X, Y, Z);
}

template <typename T>
math::Vector3<T> math::Vector4<T>::XYW() const
{
    return Vector3<T>(X, Y, W);
}

template <typename T>
math::Vector3<T> math::Vector4<T>::XZW() const
{
    return Vector3<T>(X, Z, W);
}

template <typename T>
math::Vector3<T> math::Vector4<T>::YZW() const
{
    return Vector3<T>(Y, Z, W);
}

template <typename T>
template <typename U>
math::Point2<T>::Point2(const Point3<U>& p) : X(p.X), Y(p.Y)
{
}

template <typename T>
template <typename U>
math::Point3<T>::Point3(const Point2<U>& p) : X(p.X), Y(p.Y), Z(0)
{
}

template <typename T>
template <typename U>
math::Point4<T>::Point4(const Point3<U>& p) : X(p.X), Y(p.Y), Z(p.Z), W(1)
{
}

template <typename T>
template <typename U>
math::Point3<T>::Point3(const Point4<U>& p) : X(p.X), Y(p.Y), Z(p.Z)
{
}
