#include "math/rotator.h"

#include <cmath>

#include "math/transform.h"

math::Rotator::Rotator(float Pitch, float Yaw, float Roll) : Pitch(Pitch), Yaw(Yaw), Roll(Roll) {}

math::Vector3 math::Rotator::ToVector() const
{
    const float PitchNoWinding = std::fmod(Pitch, 360.0f);
    const float YawNoWinding = std::fmod(Yaw, 360.0f);

    const float SP = std::sin(math::Radians(PitchNoWinding));
    const float CP = std::cos(math::Radians(PitchNoWinding));
    const float SY = std::sin(math::Radians(YawNoWinding));
    const float CY = std::cos(math::Radians(YawNoWinding));

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

math::Rotator math::Rotator::operator*(float Val) const
{
    return {Pitch * Val, Yaw * Val, Roll * Val};
}

math::Rotator& math::Rotator::operator*=(float Val)
{
    Pitch *= Val;
    Yaw *= Val;
    Roll *= Val;

    return *this;
}

void math::Rotator::Add(float DeltaPitch, float DeltaYaw, float DeltaRoll)
{
    Pitch += DeltaPitch;
    Yaw += DeltaYaw;
    Roll += DeltaRoll;
}

math::Vector3 math::Rotator::RotateVector(const Vector3& Vec) const
{
    return Rotate(*this)(Vec);
}

math::Rotator math::operator*(float Val, const Rotator& Other)
{
    return Other * Val;
}
