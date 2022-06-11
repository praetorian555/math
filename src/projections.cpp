#include "math/projections.h"

#include <cassert>
#include <cmath>

math::Matrix4x4 math::Orhographic_LH_N0(float Left,
                                        float Right,
                                        float Bottom,
                                        float Top,
                                        float Near,
                                        float Far)
{
    Matrix4x4 Mat;
    Mat.Data[0][0] = 2 / (Right - Left);
    Mat.Data[1][1] = 2 / (Top - Bottom);
    Mat.Data[2][2] = 1 / (Far - Near);
    Mat.Data[0][3] = -(Right + Left) / (Right - Left);
    Mat.Data[1][3] = -(Top + Bottom) / (Top - Bottom);
    Mat.Data[2][3] = -Near / (Far - Near);
    return Mat;
}

math::Matrix4x4 math::Orhographic_LH_N1(float Left,
                                        float Right,
                                        float Bottom,
                                        float Top,
                                        float Near,
                                        float Far)
{
    Matrix4x4 Mat;
    Mat.Data[0][0] = 2 / (Right - Left);
    Mat.Data[1][1] = 2 / (Top - Bottom);
    Mat.Data[2][2] = 2 / (Far - Near);
    Mat.Data[0][3] = -(Right + Left) / (Right - Left);
    Mat.Data[1][3] = -(Top + Bottom) / (Top - Bottom);
    Mat.Data[2][3] = -(Near + Far) / (Far - Near);
    return Mat;
}

math::Matrix4x4 math::Orhographic_RH_N0(float Left,
                                        float Right,
                                        float Bottom,
                                        float Top,
                                        float Near,
                                        float Far)
{
    Matrix4x4 Mat;
    Mat.Data[0][0] = 2 / (Right - Left);
    Mat.Data[1][1] = 2 / (Top - Bottom);
    Mat.Data[2][2] = -1 / (Far - Near);
    Mat.Data[0][3] = -(Right + Left) / (Right - Left);
    Mat.Data[1][3] = -(Top + Bottom) / (Top - Bottom);
    Mat.Data[2][3] = -Near / (Far - Near);
    return Mat;
}

math::Matrix4x4 math::Orhographic_RH_N1(float Left,
                                        float Right,
                                        float Bottom,
                                        float Top,
                                        float Near,
                                        float Far)
{
    Matrix4x4 Mat;
    Mat.Data[0][0] = 2 / (Right - Left);
    Mat.Data[1][1] = 2 / (Top - Bottom);
    Mat.Data[2][2] = -2 / (Far - Near);
    Mat.Data[0][3] = -(Right + Left) / (Right - Left);
    Mat.Data[1][3] = -(Top + Bottom) / (Top - Bottom);
    Mat.Data[2][3] = -(Near + Far) / (Far - Near);
    return Mat;
}

math::Matrix4x4 math::Perspective_LH_N0(float VerticalFOV, float AspectRatio, float Near, float Far)
{
    assert(AspectRatio != 0);

    float InvFOVY = 1.0f / std::tan(math::Radians(VerticalFOV) / 2);
    float InvAspectRatio = 1 / AspectRatio;

    Matrix4x4 Mat;
    Mat.Data[0][0] = InvFOVY * InvAspectRatio;
    Mat.Data[1][1] = InvFOVY;
    Mat.Data[2][2] = Far / (Far - Near);
    Mat.Data[2][3] = -(Far * Near) / (Far - Near);
    Mat.Data[3][2] = 1;
    Mat.Data[3][3] = 0;
    return Mat;
}

math::Matrix4x4 math::Perspective_LH_N1(float VerticalFOV, float AspectRatio, float Near, float Far)
{
    assert(AspectRatio != 0);

    float InvFOVY = 1.0f / std::tan(math::Radians(VerticalFOV) / 2);
    float InvAspectRatio = 1 / AspectRatio;

    Matrix4x4 Mat;
    Mat.Data[0][0] = InvFOVY * InvAspectRatio;
    Mat.Data[1][1] = InvFOVY;
    Mat.Data[2][2] = (Far + Near) / (Far - Near);
    Mat.Data[2][3] = -(2 * Far * Near) / (Far - Near);
    Mat.Data[3][2] = 1;
    Mat.Data[3][3] = 0;
    return Mat;
}

math::Matrix4x4 math::Perspective_RH_N0(float VerticalFOV, float AspectRatio, float Near, float Far)
{
    assert(AspectRatio != 0);

    float InvFOVY = 1.0f / std::tan(math::Radians(VerticalFOV) / 2);
    float InvAspectRatio = 1 / AspectRatio;

    Matrix4x4 Mat;
    Mat.Data[0][0] = InvFOVY * InvAspectRatio;
    Mat.Data[1][1] = InvFOVY;

    // NOTE(mkostic): Different from glm::perspectiveRH_ZO it looks like glm implementation doesn't
    // give correct results
    Mat.Data[2][2] = -Far / (Far - Near);

    Mat.Data[2][3] = -(Far * Near) / (Far - Near);
    Mat.Data[3][2] = -1;
    Mat.Data[3][3] = 0;
    return Mat;
}

math::Matrix4x4 math::Perspective_RH_N1(float VerticalFOV, float AspectRatio, float Near, float Far)
{
    assert(AspectRatio != 0);

    float InvFOVY = 1.0f / std::tan(math::Radians(VerticalFOV) / 2);
    float InvAspectRatio = 1 / AspectRatio;

    Matrix4x4 Mat;
    Mat.Data[0][0] = InvFOVY * InvAspectRatio;
    Mat.Data[1][1] = InvFOVY;
    Mat.Data[2][2] = -(Far + Near) / (Far - Near);
    Mat.Data[2][3] = -(2 * Far * Near) / (Far - Near);
    Mat.Data[3][2] = -1;
    Mat.Data[3][3] = 0;
    return Mat;
}
