#include "math/quaternion.h"

#include <cassert>
#include <cmath>

#include "math/transform.h"

math::Quaternion::Quaternion(const math::Transform& T)
{
    const real Trace = T.GetMatrix().Data[0][0] + T.GetMatrix().Data[1][1] +
                       T.GetMatrix().Data[2][2] + T.GetMatrix().Data[3][3];

    if (Trace > MATH_REALC(0.0))
    {
        W = math::Sqrt(Trace) / 2;
        const real Scalar = 1 / (4 * W);
        Vec.X = (T.GetMatrix().Data[2][1] - T.GetMatrix().Data[1][2]) * Scalar;
        Vec.Y = (T.GetMatrix().Data[0][2] - T.GetMatrix().Data[2][0]) * Scalar;
        Vec.Z = (T.GetMatrix().Data[1][0] - T.GetMatrix().Data[0][1]) * Scalar;
    }
    else
    {
        const int Next[3] = {1, 2, 0};
        const Matrix4x4& Mat = T.GetMatrix();

        // Figure out who is largest
        int I = 0;
        if (Mat.Data[1][1] > Mat.Data[0][0])
        {
            I = 1;
        }
        if (Mat.Data[2][2] > Mat.Data[I][I])
        {
            I = 2;
        }
        int J = Next[I];
        int K = Next[J];

        real Scalar =
            std::sqrt((Mat.Data[I][I] - (Mat.Data[J][J] + Mat.Data[K][K])) + MATH_REALC(1.0));
        real Dir[3];
        Dir[I] = Scalar * MATH_REALC(0.5);
        if (Scalar != 0.f)
        {
            Scalar = MATH_REALC(0.5) / Scalar;
        }
        W = (Mat.Data[K][J] - Mat.Data[J][K]) * Scalar;
        Dir[J] = (Mat.Data[J][I] + Mat.Data[I][J]) * Scalar;
        Dir[K] = (Mat.Data[K][I] + Mat.Data[I][K]) * Scalar;
        Vec.X = Dir[0];
        Vec.Y = Dir[1];
        Vec.Z = Dir[2];
    }
}

math::Quaternion math::Quaternion::FromAxisAngleDegrees(const math::Vector3& Axis,
                                                        math::real AngleDegrees)
{
    return FromAxisAngleRadians(Axis, math::Radians(AngleDegrees));
}

math::Quaternion math::Quaternion::FromAxisAngleRadians(const math::Vector3& Axis,
                                                        math::real AngleRadians)
{
    const real S = math::Sin(AngleRadians / 2);
    const real C = math::Cos(AngleRadians / 2);
    const math::Vector3 V = math::Normalize(Axis);
    return {V.X * S, V.Y * S, V.Z * S, C};
}

bool math::Quaternion::HasNaNs() const
{
    return math::IsNaN(W) || Vec.HasNaNs();
}

math::real math::Quaternion::Length() const
{
    return math::Sqrt(LengthSquared());
}

math::real math::Quaternion::LengthSquared() const
{
    return W * W + Vec.LengthSquared();
}

math::Quaternion& math::Quaternion::operator+=(const math::Quaternion& Other)
{
    W += Other.W;
    Vec += Other.Vec;
    return *this;
}

math::Quaternion& math::Quaternion::operator-=(const math::Quaternion& Other)
{
    W -= Other.W;
    Vec -= Other.Vec;
    return *this;
}

math::Quaternion& math::Quaternion::operator*=(const math::Quaternion& Other)
{
    Quaternion Q;
    Q.Vec.X = W * Other.Vec.X + Vec.X * Other.W + Vec.Y * Other.Vec.Z - Vec.Z * Other.Vec.Y;
    Q.Vec.Y = W * Other.Vec.Y + Vec.Y * Other.W + Vec.Z * Other.Vec.X - Vec.X * Other.Vec.Z;
    Q.Vec.Z = W * Other.Vec.Z + Vec.Z * Other.W + Vec.X * Other.Vec.Y - Vec.Y * Other.Vec.X;
    Q.W = W * Other.W - Dot(Vec, Other.Vec);
    *this = Q;

    return *this;
}

math::Quaternion& math::Quaternion::operator*=(math::real Scalar)
{
    W *= Scalar;
    Vec *= Scalar;
    return *this;
}

math::Quaternion math::Quaternion::operator*(math::real Scalar) const
{
    Quaternion Q = *this;
    Q *= Scalar;
    return Q;
}

math::Quaternion& math::Quaternion::operator/=(math::real Scalar)
{
    W /= Scalar;
    Vec /= Scalar;
    return *this;
}

math::Quaternion math::Quaternion::operator/(math::real Scalar) const
{
    Quaternion Q = *this;
    Q /= Scalar;
    return Q;
}

math::Vector3 math::Quaternion::operator*(const math::Vector3& V) const
{
    const Quaternion Q(V.X, V.Y, V.Z, 0);
    const Quaternion Result = *this * Q * Inverse(*this);
    return {Result.Vec.X, Result.Vec.Y, Result.Vec.Z};
}

math::Point3 math::Quaternion::operator*(const math::Point3& P) const
{
    const Quaternion Q(P.X, P.Y, P.Z, 0);
    const Quaternion Result = *this * Q * Inverse(*this);
    return {Result.Vec.X, Result.Vec.Y, Result.Vec.Z};
}

bool math::Quaternion::operator==(const math::Quaternion& Other) const
{
    return W == Other.W && Vec == Other.Vec;
}

bool math::Quaternion::operator!=(const math::Quaternion& Other) const
{
    return !(*this == Other);
}

math::Quaternion math::operator+(const math::Quaternion& Q1, const math::Quaternion& Q2)
{
    Quaternion Q = Q1;
    Q += Q2;
    return Q;
}

math::Quaternion math::operator-(const math::Quaternion& Q1, const math::Quaternion& Q2)
{
    Quaternion Q = Q1;
    Q -= Q2;
    return Q;
}

math::Quaternion math::operator*(const math::Quaternion& Q1, const math::Quaternion& Q2)
{
    Quaternion Q = Q1;
    Q *= Q2;
    return Q;
}

math::Quaternion math::operator*(math::real Scalar, const math::Quaternion& Q)
{
    return Q * Scalar;
}

math::real math::Dot(const math::Quaternion& Q1, const math::Quaternion& Q2)
{
    return Dot(Q1.Vec, Q2.Vec) + Q1.W * Q2.W;
}

math::Quaternion math::Normalize(const math::Quaternion& Q)
{
    return Q / Q.Length();
}

math::Quaternion math::Slerp(const math::Quaternion& Q1,
                             const math::Quaternion& Q2,
                             math::real Param)
{
    // Implementation based on: Understanding Slerp, Then Not Using It, Jonathan Blow
    // http://number-none.com/product/Understanding%20Slerp,%20Then%20Not%20Using%20It/

    constexpr real kEpsilon = MATH_REALC(0.0001);
    assert(IsEqual(Q1.Length(), MATH_REALC(1.0), kEpsilon));
    assert(IsEqual(Q2.Length(), MATH_REALC(1.0), kEpsilon));

    const real CosTheta0 = Dot(Q1, Q2);
    if (CosTheta0 > MATH_REALC(1.0) - kEpsilon)
    {
        return Lerp(Q1, Q2, Param);
    }

    const real Theta0 = std::acos(CosTheta0);
    const real Theta = Theta0 * Param;

    Quaternion Q3 = Q2 - Q1 * CosTheta0;
    Q3 = Normalize(Q3);

    return Q1 * std::cos(Theta) + Q3 * std::sin(Theta);
}

math::Quaternion math::Lerp(const math::Quaternion& Q1,
                            const math::Quaternion& Q2,
                            math::real Param)
{
#if _DEBUG
    constexpr real kEpsilon = MATH_REALC(0.0001);
    assert(IsEqual(Q1.Length(), MATH_REALC(1.0), kEpsilon));
    assert(IsEqual(Q2.Length(), MATH_REALC(1.0), kEpsilon));
#endif

    const Quaternion Q3 = Q1 * (1 - Param) + Q2 * Param;
    return Normalize(Q3);
}

math::Quaternion math::Conjugate(const math::Quaternion& Q)
{
    Quaternion Ret = Q;
    Ret.Vec = -Ret.Vec;
    return Ret;
}

math::Quaternion math::Inverse(const math::Quaternion& Q)
{
    return Conjugate(Q) / Q.LengthSquared();
}
