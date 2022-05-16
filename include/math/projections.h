#pragma once

#include "math/base.h"
#include "math/matrix4x4.h"

namespace math
{

/**
 * Create an orthographic projection matrix for left-handed coordinate system where Z maps between 0
 * and 1 (DirectX style).
 *
 * @param Near Distance from a viewer to the near cliping plane. Always positive or zero.
 * @param Far Distance from a viewer to the far cliping plane. Always positive or zero.
 */
Matrix4x4 Orhographic_LH_N0(float Left,
                            float Right,
                            float Bottom,
                            float Top,
                            float Near,
                            float Far);

/**
 * Create an orthographic projection matrix for left-handed coordinate system where Z maps between
 * -1 and 1 (OpenGL style).
 *
 * @param Near Distance from a viewer to the near cliping plane. Always positive or zero.
 * @param Far Distance from a viewer to the far cliping plane. Always positive or zero.
 */
Matrix4x4 Orhographic_LH_N1(float Left,
                            float Right,
                            float Bottom,
                            float Top,
                            float Near,
                            float Far);

/**
 * Create an orthographic projection matrix for right-handed coordinate system where Z maps between
 * 0 and 1 (DirectX style).
 *
 * @param Near Distance from a viewer to the near cliping plane. Always positive or zero.
 * @param Far Distance from a viewer to the far cliping plane. Always positive or zero.
 */
Matrix4x4 Orhographic_RH_N0(float Left,
                            float Right,
                            float Bottom,
                            float Top,
                            float Near,
                            float Far);

/**
 * Create an orthographic projection matrix for right-handed coordinate system where Z maps between
 * -1 and 1 (OpenGL style).
 *
 * @param Near Distance from a viewer to the near cliping plane. Always positive or zero.
 * @param Far Distance from a viewer to the far cliping plane. Always positive or zero.
 */
Matrix4x4 Orhographic_RH_N1(float Left,
                            float Right,
                            float Bottom,
                            float Top,
                            float Near,
                            float Far);

/**
 * Create a perspective projection matrix for left-handed coordinate system where Z maps between 0
 * and 1 (DirectX style).
 *
 * @param VerticalFOV Field of view angle in y direction. In degrees.
 * @param AspectRatio Ratio used to calculate field of view angle in x direction. Defined as ratio
 * between width (x) and height (y).
 * @param Near Distance from a viewer to the near cliping plane. Always positive.
 * @param Far Distance from a viewer to the far cliping plane. Always positive.
 */
Matrix4x4 Perspective_LH_N0(float VerticalFOV, float AspectRatio, float Near, float Far);

/**
 * Create a perspective projection matrix for left-handed coordinate system where Z maps between -1
 * and 1 (OpenGL style).
 *
 * @param VerticalFOV Field of view angle in y direction. In degrees.
 * @param AspectRatio Ratio used to calculate field of view angle in x direction. Defined as ratio
 * between width (x) and height (y).
 * @param Near Distance from a viewer to the near cliping plane. Always positive.
 * @param Far Distance from a viewer to the far cliping plane. Always positive.
 */
Matrix4x4 Perspective_LH_N1(float VerticalFOV, float AspectRatio, float Near, float Far);

/**
 * Create a perspective projection matrix for right-handed coordinate system where Z maps between 0
 * and 1 (DirectX style).
 *
 * @param VerticalFOV Field of view angle in y direction. In degrees.
 * @param AspectRatio Ratio used to calculate field of view angle in x direction. Defined as ratio
 * between width (x) and height (y).
 * @param Near Distance from a viewer to the near cliping plane. Always positive.
 * @param Far Distance from a viewer to the far cliping plane. Always positive.
 */
Matrix4x4 Perspective_RH_N0(float VerticalFOV, float AspectRatio, float Near, float Far);

/**
 * Create a perspective projection matrix for right-handed coordinate system where Z maps between -1
 * and 1 (OpenGL style).
 *
 * @param VerticalFOV Field of view angle in y direction. In degrees.
 * @param AspectRatio Ratio used to calculate field of view angle in x direction. Defined as ratio
 * between width (x) and height (y).
 * @param Near Distance from a viewer to the near cliping plane. Always positive.
 * @param Far Distance from a viewer to the far cliping plane. Always positive.
 */
Matrix4x4 Perspective_RH_N1(float VerticalFOV, float AspectRatio, float Near, float Far);

}  // namespace math