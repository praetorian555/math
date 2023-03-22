#pragma once

#include <iosfwd>

namespace math
{
std::ostream& operator<<(std::ostream& Out, const class Vector2& Vec);
std::ostream& operator<<(std::ostream& Out, const class Vector3& Vec);
std::ostream& operator<<(std::ostream& Out, const class Vector4& Vec);
std::ostream& operator<<(std::ostream& Out, const class Normal3& Vec);
std::ostream& operator<<(std::ostream& Out, const class Point2& Vec);
std::ostream& operator<<(std::ostream& Out, const class Point3& Vec);
std::ostream& operator<<(std::ostream& Out, const class Point4& Vec);
}
