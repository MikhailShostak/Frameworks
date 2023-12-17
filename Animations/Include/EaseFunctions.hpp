#pragma once

#include "Ease.hpp"

#include <numbers>

namespace Animations
{

using EaseFunctionPointer = float (*)(float);

namespace Functions
{

inline float linear(float value)
{
    return value;
}

inline float sineIn(float value)
{
    return 1 - cosf(value * (std::numbers::pi_v<float> / 2));
}

inline float sineOut(float value)
{
    return sinf(value * (std::numbers::pi_v<float> / 2));
}

inline float sineInOut(float value)
{
    return (value *= 2) < 1.0f ? 0.5f * sineIn(value) : 0.5f * sineOut(value - 1) + 0.5f;
}

inline float sineOutIn(float value)
{
    return (value *= 2) < 1.0f ? 0.5f * sineOut(value) : 0.5f * sineIn(value - 1) + 0.5f;
}

inline float quadIn(float value)
{
    return value * value;
}

inline float quadOut(float value)
{
    return 1 - (value -= 1) * value;
}

inline float quadInOut(float value)
{
    return (value *= 2) < 1.0f ? 0.5f * quadIn(value) : 0.5f * quadOut(value - 1) + 0.5f;
}

inline float quadOutIn(float value)
{
    return (value *= 2) < 1.0f ? 0.5f * quadOut(value) : 0.5f * quadIn(value - 1) + 0.5f;
}

inline float cubicIn(float value)
{
    return value * value * value;
}

inline float cubicOut(float value)
{
    return 1 + (value -= 1) * value * value;
}

inline float cubicInOut(float value)
{
    return (value *= 2) < 1.0f ? 0.5f * cubicIn(value) : 0.5f * cubicOut(value - 1) + 0.5f;
}

inline float cubicOutIn(float value)
{
    return (value *= 2) < 1.0f ? 0.5f * cubicOut(value) : 0.5f * cubicIn(value - 1) + 0.5f;
}

inline float quartIn(float value)
{
    return value * value * value * value;
}

inline float quartOut(float value)
{
    return 1 - (value -= 1) * value * value * value;
}

inline float quartInOut(float value)
{
    return (value *= 2) < 1.0f ? 0.5f * quartIn(value) : 0.5f * quartOut(value - 1) + 0.5f;
}

inline float quartOutIn(float value)
{
    return (value *= 2) < 1.0f ? 0.5f * quartOut(value) : 0.5f * quartIn(value - 1) + 0.5f;
}

inline float quintIn(float value)
{
    return value * value * value * value * value;
}

inline float quintOut(float value)
{
    return 1 + (value -= 1) * value * value * value * value;
}

inline float quintInOut(float value)
{
    return (value *= 2) < 1.0f ? 0.5f * quintIn(value) : 0.5f * quintOut(value - 1) + 0.5f;
}

inline float quintOutIn(float value)
{
    return (value *= 2) < 1.0f ? 0.5f * quintOut(value) : 0.5f * quintIn(value - 1) + 0.5f;
}

inline float circIn(float value)
{
    return 1 - sqrtf(1 - value * value);
}

inline float circOut(float value)
{
    return sqrtf(1 - (value = 1 - value) * value);
}

inline float circInOut(float value)
{
    return (value *= 2) < 1.0f ? 0.5f * circIn(value) : 0.5f * circOut(value - 1) + 0.5f;
}

inline float circOutIn(float value)
{
    return (value *= 2) < 1.0f ? 0.5f * circOut(value) : 0.5f * circIn(value - 1) + 0.5f;
}

inline float expoIn(float value)
{
    return powf(2, 10 * value - 10);
}

inline float expoOut(float value)
{

    return 1 - powf(2, -10 * value);
}

inline float expoInOut(float value)
{
    return (value *= 2) < 1.0f ? 0.5f * expoIn(value) : 0.5f * expoOut(value - 1) + 0.5f;
}

inline float expoOutIn(float value)
{
    return (value *= 2) < 1.0f ? 0.5f * expoOut(value) : 0.5f * expoIn(value - 1) + 0.5f;
}

/*template <typename Type>
inline Type linear(const Type &b, const Type &c, float t, float d)
{
    return c * (t /= d) + b;
}

template <typename Type>
inline Type quadIn(const Type &b, const Type &c, float t, float d)
{
    return c * (t /= d) * t + b;
}

template <typename Type>
inline Type quadOut(const Type &b, const Type &c, float t, float d)
{
    return -c * (t /= d)*(t - 2) + b;
}

template <typename Type>
inline Type quadInOut(const Type &b, const Type &c, float t, float d)
{
    if ((t /= d / 2) < 1) return c / 2 * t * t + b;
    return -c / 2 * ((--t)*(t - 2) - 1) + b;
}

template <typename Type>
inline Type cubicIn(const Type &b, const Type &c, float t, float d)
{
    return c * (t /= d) * t * t + b;
}

template <typename Type>
inline Type cubicOut(const Type &b, const Type &c, float t, float d)
{
    return c * ((t = t / d - 1) * t * t + 1) + b;
}

template <typename Type>
inline Type cubicInOut(const Type &b, const Type &c, float t, float d)
{
    if ((t /= d / 2) < 1) return c / 2 * t * t * t + b;
    return c / 2 * ((t -= 2) * t * t + 2) + b;
}

template <typename Type>
inline Type quartIn(const Type &b, const Type &c, float t, float d)
{
    return c * (t /= d) * t * t * t + b;
}

template <typename Type>
inline Type quartOut(const Type &b, const Type &c, float t, float d)
{
    return -c * ((t = t / d - 1) * t * t * t - 1) + b;
}

template <typename Type>
inline Type quartInOut(const Type &b, const Type &c, float t, float d)
{
    if ((t /= d / 2) < 1) return c / 2 * t * t * t * t + b;
    return -c / 2 * ((t -= 2) * t * t * t - 2) + b;
}

template <typename Type>
inline Type quintIn(const Type &b, const Type &c, float t, float d)
{
    return c * (t /= d) * t * t * t * t + b;
}

template <typename Type>
inline Type quintOut(const Type &b, const Type &c, float t, float d)
{
    return c * ((t = t / d - 1) * t * t * t * t + 1) + b;
}

template <typename Type>
inline Type quintInOut(const Type &b, const Type &c, float t, float d)
{
    if ((t /= d / 2) < 1) return c / 2 * t * t * t * t * t + b;
    return c / 2 * ((t -= 2) * t * t * t * t + 2) + b;
}

template <typename Type>
inline Type sineIn(const Type &b, const Type &c, float t, float d)
{
    return -c * cosf(t / d * (M_PI / 2)) + c + b;
}

template <typename Type>
inline Type sineOut(const Type &b, const Type &c, float t, float d)
{
    return c * sinf(t / d * (M_PI / 2)) + b;
}

template <typename Type>
inline Type sineInOut(const Type &b, const Type &c, float t, float d)
{
    return -c / 2 * (cosf(M_PI * t / d) - 1) + b;
}

template <typename Type>
inline Type expoIn(const Type &b, const Type &c, float t, float d)
{
    return (t == 0) ? b : c * powf(2, 10 * (t / d - 1)) + b;
}

template <typename Type>
inline Type expoOut(const Type &b, const Type &c, float t, float d)
{
    return (t == d) ? b + c : c * (-powf(2, -10 * t / d) + 1) + b;
}

template <typename Type>
inline Type expoInOut(const Type &b, const Type &c, float t, float d)
{
    if (t == 0) return b;
    if (t == d) return b + c;
    if ((t /= d / 2) < 1) return c / 2 * powf(2, 10 * (t - 1)) + b;
    return c / 2 * (-powf(2, -10 * --t) + 2) + b;
}

template <typename Type>
inline Type circIn(const Type &b, const Type &c, float t, float d)
{
    return -c * (sqrtf(1 - (t /= d) * t) - 1) + b;
}

template <typename Type>
inline Type circOut(const Type &b, const Type &c, float t, float d)
{
    return c * sqrtf(1 - (t = t / d - 1) * t) + b;
}

template <typename Type>
inline Type circInOut(const Type &b, const Type &c, float t, float d)
{
    if ((t /= d / 2) < 1) return -c / 2 * (sqrtf(1 - t * t) - 1) + b;
    return c / 2 * (sqrtf(1 - (t -= 2) * t) + 1) + b;
}*/

/*	template <typename Type>
inline Type elasticIn(const Type &b, const Type &c, float t, float d)
{
    float s = 1.70158f;
    float p = 0;
    Type a = c;
    if (t == 0) return b;
    if ((t /= d) == 1) return b + c;
    if (!p) p = d * 0.3f;
    if (a < abs(c)) {
        a = c;
        float s = p / 4;
    } else float s = p / (2 * M_PI) * asinf(c / a);
    return -(a * powf(2, 10 * (t -= 1)) * sinf((t * d - s)*(2 * M_PI) / p)) + b;
}

template <typename Type>
inline Type elasticOut(const Type &b, const Type &c, float t, float d)
{
    float s = 1.70158f;
    float p = 0;
    Type a = c;
    if (t == 0) return b;
    if ((t /= d) == 1) return b + c;
    if (!p) p = d * 0.3f;
    if (a < abs(c)) {
        a = c;
        float s = p / 4;
    } else float s = p / (2 * M_PI) * asinf(c / a);
    return a * powf(2, -10 * t) * sinf((t * d - s)*(2 * M_PI) / p) + c + b;
}

template <typename Type>
inline Type elasticInOut(const Type &b, const Type &c, float t, float d)
{
    float s = 1.70158f;
    float p = 0;
    Type a = c;
    if (t == 0) return b;
    if ((t /= d / 2) == 2) return b + c;
    if (!p) p = d * (0.3f * 1.5f);
    if (a < abs(c)) {
        a = c;
        float s = p / 4;
    } else float s = p / (2 * M_PI) * asinf(c / a);
    if (t < 1) return -0.5f * (a * powf(2, 10 * (t -= 1)) * sinf((t * d - s)*(2 * M_PI) / p)) + b;
    return a * powf(2, -10 * (t -= 1)) * sinf((t * d - s)*(2 * M_PI) / p)*0.5f + c + b;
}*/

/*template <typename Type>
inline Type backIn(const Type &b, const Type &c, float t, float d)
{
    float s = 1.70158f;
    return c * (t /= d) * t * ((s + 1) * t - s) + b;
}

template <typename Type>
inline Type backOut(const Type &b, const Type &c, float t, float d)
{
    float s = 1.70158f;
    return c * ((t = t / d - 1) * t * ((s + 1) * t + s) + 1) + b;
}

template <typename Type>
inline Type backInOut(const Type &b, const Type &c, float t, float d)
{
    float s = 1.70158f;
    if ((t /= d / 2) < 1) return c / 2 * (t * t * (((s *= (1.525f)) + 1) * t - s)) + b;
    return c / 2 * ((t -= 2) * t * (((s *= (1.525f)) + 1) * t + s) + 2) + b;
}*/

/*	template <typename Type>
inline Type bounceOut(const Type &b, const Type &c, float t, float d)
{
    if ((t /= d) < (1.0f / 2.75f)) {
        return c * (7.5625f * t * t) + b;
    } else if (t < (2.0f / 2.75f)) {
        return c * (7.5625f * (t -= (1.5f / 2.75f)) * t + 0.75f) + b;
    } else if (t < (2.5f / 2.75f)) {
        return c * (7.5625f * (t -= (2.25f / 2.75f)) * t + 0.9375f) + b;
    } else {
        return c * (7.5625f * (t -= (2.625f / 2.75f)) * t + 0.984375f) + b;
    }
}

template <typename Type>
inline Type bounceIn(const Type &b, const Type &c, float t, float d)
{
    return c - bounceOut<Type>((Type)(d - t), (Type)0, c, d) + b;
}

template <typename Type>
inline Type bounceInOut(const Type &b, const Type &c, float t, float d)
{
    if (t < d / 2) return bounceOut<Type>((Type)(t * 2), (Type)0, c, d) * 0.5f + b;
    return  bounceOut<Type>((Type)(t * 2 - d), (Type)0, c, d) * 0.5f + c * 0.5f + b;
}*/

}

inline EaseFunctionPointer GetEaseFunction(Animations::Ease Ease)
{
    switch (Ease)
    {
    case Animations::Ease::Linear:
        return Functions::linear;
    case Animations::Ease::QuadIn:
        return Functions::quadIn;
    case Animations::Ease::QuadOut:
        return Functions::quadOut;
    case Animations::Ease::QuadInOut:
        return Functions::quadInOut;
    case Animations::Ease::QuadOutIn:
        return Functions::quadOutIn;
    case Animations::Ease::CubicIn:
        return Functions::cubicIn;
    case Animations::Ease::CubicOut:
        return Functions::cubicOut;
    case Animations::Ease::CubicInOut:
        return Functions::cubicInOut;
    case Animations::Ease::CubicOutIn:
        return Functions::cubicOutIn;
    case Animations::Ease::QuartIn:
        return Functions::quartIn;
    case Animations::Ease::QuartOut:
        return Functions::quartOut;
    case Animations::Ease::QuartInOut:
        return Functions::quartInOut;
    case Animations::Ease::QuartOutIn:
        return Functions::quartOutIn;
    case Animations::Ease::QuintIn:
        return Functions::quintIn;
    case Animations::Ease::QuintOut:
        return Functions::quintOut;
    case Animations::Ease::QuintInOut:
        return Functions::quintInOut;
    case Animations::Ease::QuintOutIn:
        return Functions::quintOutIn;
    case Animations::Ease::SineIn:
        return Functions::sineIn;
    case Animations::Ease::SineOut:
        return Functions::sineOut;
    case Animations::Ease::SineInOut:
        return Functions::sineInOut;
    case Animations::Ease::SineOutIn:
        return Functions::sineOutIn;
    case Animations::Ease::ExpoIn:
        return Functions::expoIn;
    case Animations::Ease::ExpoOut:
        return Functions::expoOut;
    case Animations::Ease::ExpoInOut:
        return Functions::expoInOut;
    case Animations::Ease::ExpoOutIn:
        return Functions::expoOutIn;
    case Animations::Ease::CircIn:
        return Functions::circIn;
    case Animations::Ease::CircOut:
        return Functions::circOut;
    case Animations::Ease::CircInOut:
        return Functions::circInOut;
    case Animations::Ease::CircOutIn:
        return Functions::circOutIn;
    /*case ElasticIn:
        return Functions::elasticIn;
    case ElasticOut:
        return Functions::elasticOut;
    case ElasticInOut:
        return Functions::elasticInOut;*/
    /*case BackIn:
        return Functions::backIn;
    case BackOut:
        return Functions::backOut;
    case BackInOut:
        return Functions::backInOut;*/
    /*case BounceIn:
        return Functions::bounceIn;
    case BounceOut:
        return Functions::bounceOut;
    case BounceInOut:
        return Functions::bounceInOut;*/
    default:
        return nullptr;
    }
}

}
