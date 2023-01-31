#include "math/projections.h"

#include <cassert>
#include <cmath>

math::Matrix4x4 math::Orhographic_LH_N0(real Left,
                                        real Right,
                                        real Bottom,
                                        real Top,
                                        real Near,
                                        real Far)
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

math::Matrix4x4 math::Orhographic_LH_N1(real Left,
                                        real Right,
                                        real Bottom,
                                        real Top,
                                        real Near,
                                        real Far)
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

math::Matrix4x4 math::Orhographic_RH_N0(real Left,
                                        real Right,
                                        real Bottom,
                                        real Top,
                                        real Near,
                                        real Far)
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

math::Matrix4x4 math::Orhographic_RH_N1(real Left,
                                        real Right,
                                        real Bottom,
                                        real Top,
                                        real Near,
                                        real Far)
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

math::Matrix4x4 math::Perspective_LH_N0(real VerticalFOV, real AspectRatio, real Near, real Far)
{
    assert(AspectRatio != 0);

    const real InvFOVY = 1.0f / std::tan(math::Radians(VerticalFOV) / 2);
    const real InvAspectRatio = 1 / AspectRatio;

    Matrix4x4 Mat;
    Mat.Data[0][0] = InvFOVY * InvAspectRatio;
    Mat.Data[1][1] = InvFOVY;
    Mat.Data[2][2] = Far / (Far - Near);
    Mat.Data[2][3] = -(Far * Near) / (Far - Near);
    Mat.Data[3][2] = 1;
    Mat.Data[3][3] = 0;
    return Mat;
}

math::Matrix4x4 math::Perspective_LH_N1(real VerticalFOV, real AspectRatio, real Near, real Far)
{
    assert(AspectRatio != 0);

    const real InvFOVY = 1.0f / std::tan(math::Radians(VerticalFOV) / 2);
    const real InvAspectRatio = 1 / AspectRatio;

    Matrix4x4 Mat;
    Mat.Data[0][0] = InvFOVY * InvAspectRatio;
    Mat.Data[1][1] = InvFOVY;
    Mat.Data[2][2] = (Far + Near) / (Far - Near);
    Mat.Data[2][3] = -(2 * Far * Near) / (Far - Near);
    Mat.Data[3][2] = 1;
    Mat.Data[3][3] = 0;
    return Mat;
}

math::Matrix4x4 math::Perspective_RH_N0(real VerticalFOV, real AspectRatio, real Near, real Far)
{
    assert(AspectRatio != 0);

    const real InvFOVY = 1.0f / std::tan(math::Radians(VerticalFOV) / 2);
    const real InvAspectRatio = 1 / AspectRatio;

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

math::Matrix4x4 math::Perspective_RH_N1(real VerticalFOV, real AspectRatio, real Near, real Far)
{
    assert(AspectRatio != 0);

    const real InvFOVY = 1.0f / std::tan(math::Radians(VerticalFOV) / 2);
    const real InvAspectRatio = 1 / AspectRatio;

    Matrix4x4 Mat;
    Mat.Data[0][0] = InvFOVY * InvAspectRatio;
    Mat.Data[1][1] = InvFOVY;
    Mat.Data[2][2] = -(Far + Near) / (Far - Near);
    Mat.Data[2][3] = -(2 * Far * Near) / (Far - Near);
    Mat.Data[3][2] = -1;
    Mat.Data[3][3] = 0;
    return Mat;
}
