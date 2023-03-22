#include "math/prettyprint.h"

#include <iostream>

#include "math/normal3.h"
#include "math/point2.h"
#include "math/point3.h"
#include "math/point4.h"
#include "math/vector2.h"
#include "math/vector3.h"
#include "math/vector4.h"

std::ostream& math::operator<<(std::ostream& Out, const Vector2& Vec)
{
    Out << "Vector2(X=" << Vec.X << ", Y=" << Vec.Y << ")";
    return Out;
}

std::ostream& math::operator<<(std::ostream& Out, const math::Vector3& Vec)
{
    Out << "Vector3(X=" << Vec.X << ", Y=" << Vec.Y << ", Z=" << Vec.Z << ")";
    return Out;
}

std::ostream& math::operator<<(std::ostream& Out, const math::Vector4& Vec)
{
    Out << "Vector4(X=" << Vec.X << ", Y=" << Vec.Y << ", Z=" << Vec.Z << ", W=" << Vec.W << ")";
    return Out;
}

std::ostream& math::operator<<(std::ostream& Out, const math::Normal3& Vec)
{
    Out << "Normal3(X=" << Vec.X << ", Y=" << Vec.Y << ", Z=" << Vec.Z << ")";
    return Out;
}

std::ostream& math::operator<<(std::ostream& Out, const math::Point2& Vec)
{
    Out << "Point2(X=" << Vec.X << ", Y=" << Vec.Y << ")";
    return Out;
}

std::ostream& math::operator<<(std::ostream& Out, const math::Point3& Vec)
{
    Out << "Point3(X=" << Vec.X << ", Y=" << Vec.Y << ", Z=" << Vec.Z << ")";
    return Out;
}

std::ostream& math::operator<<(std::ostream& Out, const math::Point4& Vec)
{
    Out << "Point4(X=" << Vec.X << ", Y=" << Vec.Y << ", Z=" << Vec.Z << ", W=" << Vec.W << ")";
    return Out;
}
