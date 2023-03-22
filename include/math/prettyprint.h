#pragma once

#include <iosfwd>

#include "math/vector2.h"
#include "math/vector3.h"
#include "math/vector4.h"
#include "math/normal3.h"
#include "math/point2.h"
#include "math/point3.h"
#include "math/point4.h"

namespace math
{
std::ostream& operator<<(std::ostream& Out, const Vector2& Vec);
std::ostream& operator<<(std::ostream& Out, const Vector3& Vec);
std::ostream& operator<<(std::ostream& Out, const Vector4& Vec);
std::ostream& operator<<(std::ostream& Out, const Normal3& Vec);
std::ostream& operator<<(std::ostream& Out, const Point2& Vec);
std::ostream& operator<<(std::ostream& Out, const Point3& Vec);
std::ostream& operator<<(std::ostream& Out, const Point4& Vec);
}
