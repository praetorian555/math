#include "math/rotator.h"

#include <cmath>

#include "math/transform.h"

math::Rotator::Rotator(real Pitch, real Yaw, real Roll) : Pitch(Pitch), Yaw(Yaw), Roll(Roll) {}

math::Vector3 math::Rotator::ToVector() const
{
    const real PitchNoWinding = Mod(Pitch, 360.0f);
    const real YawNoWinding = Mod(Yaw, 360.0f);

    const real SP = std::sin(math::Radians(PitchNoWinding));
    const real CP = std::cos(math::Radians(PitchNoWinding));
    const real SY = std::sin(math::Radians(YawNoWinding));
    const real CY = std::cos(math::Radians(YawNoWinding));

    return Vector3{CP * CY, SP, -CP * SY};
}

math::Vector3 math::Rotator::ToEuler() const
{
    return Vector3{Roll, Yaw, Pitch};
}

bool math::Rotator::operator==(const Rotator& Other) const
{
    return Pitch == Other.Pitch && Yaw == Other.Yaw && Roll == Other.Roll;
}

bool math::Rotator::operator!=(const Rotator& Other) const
{
    return !(*this == Other);
}

math::Rotator math::Rotator::operator+(const Rotator& Other) const
{
    return Rotator{Pitch + Other.Pitch, Yaw + Other.Yaw, Roll + Other.Roll};
}

math::Rotator& math::Rotator::operator+=(const Rotator& Other)
{
    Pitch += Other.Pitch;
    Yaw += Other.Yaw;
    Roll += Other.Roll;

    return *this;
}

math::Rotator math::Rotator::operator-(const Rotator& Other) const
{
    Rotator Res;
    Res.Pitch = Pitch - Other.Pitch;
    Res.Yaw = Yaw - Other.Yaw;
    Res.Roll = Roll - Other.Roll;
    return Res;
}

math::Rotator& math::Rotator::operator-=(const Rotator& Other)
{
    Pitch -= Other.Pitch;
    Yaw -= Other.Yaw;
    Roll -= Other.Roll;
    return *this;
}

math::Rotator math::Rotator::operator*(real Val) const
{
    return {Pitch * Val, Yaw * Val, Roll * Val};
}

math::Rotator& math::Rotator::operator*=(real Val)
{
    Pitch *= Val;
    Yaw *= Val;
    Roll *= Val;

    return *this;
}

void math::Rotator::Add(real DeltaPitch, real DeltaYaw, real DeltaRoll)
{
    Pitch += DeltaPitch;
    Yaw += DeltaYaw;
    Roll += DeltaRoll;
}

math::Vector3 math::Rotator::RotateVector(const Vector3& Vec) const
{
    return Rotate(*this)(Vec);
}

math::Rotator math::operator*(real Val, const Rotator& Other)
{
    return Other * Val;
}
