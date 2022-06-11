#include "math/rotator.h"

#include <cmath>

math::Rotator::Rotator(float Pitch, float Yaw, float Roll) : Pitch(Pitch), Yaw(Yaw), Roll(Roll) {}

math::Vector3 math::Rotator::ToVector()
{
    const float PitchNoWinding = std::fmod(Pitch, 360.0f);
    const float YawNoWinding = std::fmod(Yaw, 360.0f);

    const float SP = std::sin(math::Radians(PitchNoWinding));
    const float CP = std::cos(math::Radians(PitchNoWinding));
    const float SY = std::sin(math::Radians(YawNoWinding));
    const float CY = std::cos(math::Radians(YawNoWinding));

    return Vector3{CP * CY, SP, -CP * SY};
}

math::Rotator math::Rotator::operator+(Rotator Other) const
{
    return Rotator{Pitch + Other.Pitch, Yaw + Other.Yaw, Roll + Other.Roll};
}

math::Rotator& math::Rotator::operator+=(Rotator Other)
{
    Pitch += Other.Pitch;
    Yaw += Other.Yaw;
    Roll += Other.Roll;

    return *this;
}

math::Rotator math::Rotator::operator*(float Val) const
{
    return Rotator(Pitch * Val, Yaw * Val, Roll * Val);
}

math::Rotator& math::Rotator::operator*=(float Val)
{
    Pitch *= Val;
    Yaw *= Val;
    Roll *= Val;

    return *this;
}

math::Rotator math::operator*(float Val, const Rotator& Other)
{
    return Other * Val;
}
