#pragma once

#include "EaseFunctions.hpp"

namespace Math
{
    template<typename Type, typename FloatType = float>
    inline Type Lerp(const Type &A, const Type &B, FloatType Alpha) { return A + (B - A) * Alpha; }
}

namespace Animations
{

using Clock = DateTime::Steady::Clock;
using Duration = Clock::duration;
using Time = DateTime::Templates::Time<Clock>;

struct PUBLIC_API_EXPORT Animation
{
    DateTime::Timer<DateTime::Steady::Clock> Timer;
    std::function<void(float Progress)> TickCallback;
    std::function<void(bool Completed)> FinishCallback;
};

using AnimationHandle = size_t;

class PUBLIC_API_EXPORT Subsystem : public Core::Subsystem
{
	friend class Application;
	friend class AnimationInterface;
public:
    using Super = Core::Subsystem;

    const Map<AnimationHandle, Animations::Animation> &GetAnimations() const { return Animations; }

    AnimationHandle PlayAnimation(
        const DateTime::SecondRatio &Duration,
        const std::function<void(float Progress)> &TickCallback,
        const std::function<void(bool Completed)> &FinishCallback = {}
    );

    AnimationHandle PlayAnimation(
        const Animations::Time &StartTime,
        const DateTime::SecondRatio &Duration,
        const std::function<void(float Progress)> &TickCallback,
        const std::function<void(bool Completed)> &FinishCallback = {}
    );

    AnimationHandle PlayAnimation(
        const Animations::Time &StartTime,
        const Animations::Time &EndTime,
        const std::function<void(float Progress)> &TickCallback,
        const std::function<void(bool Completed)> &FinishCallback = {}
    );

    template<typename Type, typename TickCallbackType>
    AnimationHandle PlayEaseAnimation(
        const Type &StartValue,
        const Type &EndValue,
        const DateTime::SecondRatio &Duration,
        Animations::Ease Ease,
        const TickCallbackType &TickCallback,
        const std::function<void(bool Completed)> &FinishCallback = {});

    template<typename Type, typename TickCallbackType>
    AnimationHandle PlayEaseAnimation(
        const Type &StartValue,
        const Type &EndValue,
        const Animations::Time &StartTime,
        const DateTime::SecondRatio &Duration,
        Animations::Ease Ease,
        const TickCallbackType &TickCallback,
        const std::function<void(bool Completed)> &FinishCallback = {});

    template<typename Type, typename TickCallbackType>
    AnimationHandle PlayEaseAnimation(
        const Type &StartValue,
        const Type &EndValue,
        const Animations::Time &StartTime,
        const Animations::Time &EndTime,
        Animations::Ease Ease,
        const TickCallbackType &TickCallback,
        const std::function<void(bool Completed)> &FinishCallback = {});

    template<typename Type>
    AnimationHandle PlayVariableAnimation(
        Type &Value,
        const Type &EndValue,
        const DateTime::SecondRatio &Duration = 0.5f,
        Animations::Ease Ease = Ease::SineOut,
        const std::function<void(bool Completed)> &FinishCallback = {});

    template<typename Type>
    AnimationHandle PlayVariableAnimation(
        Type &Value,
        const Type &EndValue,
        const Animations::Time &StartTime,
        const DateTime::SecondRatio &Duration = 0.5f,
        Animations::Ease Ease = Ease::SineOut,
        const std::function<void(bool Completed)> &FinishCallback = {});

    template<typename Type>
    AnimationHandle PlayVariableAnimation(
        Type &Value,
        const Type &EndValue,
        const Animations::Time &StartTime,
        const Animations::Time &EndTime,
        Animations::Ease Ease = Ease::SineOut,
        const std::function<void(bool Completed)> &FinishCallback = {});

    void StopAnimation(AnimationHandle Handle);
    void StopAnimations(const Array<AnimationHandle> &Handles);
    void StopAnimations();

protected:

    void RemoveAnimations(const Array<AnimationHandle> &Handles)
    {
        for (AnimationHandle Handle : Handles)
        {
            Animations.erase(Handle);
        }
    }

	void Update();

    AnimationHandle NextHandle = 0;
	Map<AnimationHandle, Animations::Animation> Animations;
};

inline AnimationHandle Subsystem::PlayAnimation(
    const DateTime::SecondRatio &Duration,
    const std::function<void(float Progress)> &TickCallback,
    const std::function<void(bool Completed)> &FinishCallback)
{
    return PlayAnimation(Animations::Clock::now(), std::chrono::duration_cast<Animations::Duration>(Duration), TickCallback, FinishCallback);
}

inline AnimationHandle Subsystem::PlayAnimation(
    const Animations::Time &StartTime,
    const DateTime::SecondRatio &Duration,
    const std::function<void(float Progress)> &TickCallback,
    const std::function<void(bool Completed)> &FinishCallback)
{
    return PlayAnimation(StartTime, StartTime + std::chrono::duration_cast<Animations::Duration>(Duration), TickCallback, FinishCallback);
}

inline AnimationHandle Subsystem::PlayAnimation(
    const Animations::Time &StartTime,
    const Animations::Time &EndTime,
    const std::function<void(float Progress)> &TickCallback,
    const std::function<void(bool Completed)> &FinishCallback)
{
    AnimationHandle handle = NextHandle++;
    Animation &animation = Animations[handle];
    animation.TickCallback = TickCallback;
    animation.FinishCallback = FinishCallback;
    animation.Timer.Start(StartTime, EndTime);
    return handle;
}

template<typename Type, typename TickCallbackType>
inline AnimationHandle Subsystem::PlayEaseAnimation(
    const Type &StartValue,
    const Type &EndValue,
    const DateTime::SecondRatio &Duration,
    Animations::Ease Ease,
    const TickCallbackType &TickCallback,
    const std::function<void(bool Completed)> &FinishCallback)
{
    return PlayEaseAnimation(StartValue, EndValue, Animations::Clock::now(), std::chrono::duration_cast<Animations::Duration>(Duration), Ease, TickCallback, FinishCallback);
}

template<typename Type, typename TickCallbackType>
inline AnimationHandle Subsystem::PlayEaseAnimation(
    const Type &StartValue,
    const Type &EndValue,
    const Animations::Time &StartTime,
    const DateTime::SecondRatio &Duration,
    Animations::Ease Ease,
    const TickCallbackType &TickCallback,
    const std::function<void(bool Completed)> &FinishCallback)
{
    return PlayEaseAnimation(StartValue, EndValue, StartTime, StartTime + std::chrono::duration_cast<Animations::Duration>(Duration), Ease, TickCallback, FinishCallback);
}

template<typename Type, typename TickCallbackType>
inline AnimationHandle Subsystem::PlayEaseAnimation(
    const Type &StartValue,
    const Type &EndValue,
    const Animations::Time &StartTime,
    const Animations::Time &EndTime,
    Animations::Ease Ease,
    const TickCallbackType &TickCallback,
    const std::function<void(bool Completed)> &FinishCallback)
{
    auto EaseFunction = GetEaseFunction(Ease);
    const auto &LerpCallback = [StartValue, EndValue, EaseFunction, TickCallback](float Progress)
    {
        const auto Alpha = EaseFunction(Progress);
        const auto Value = Math::Lerp(StartValue, EndValue, Alpha);
        TickCallback(Value);
    };
    return PlayAnimation(StartTime, EndTime, LerpCallback, FinishCallback);
}

template<typename Type>
inline AnimationHandle Subsystem::PlayVariableAnimation(
    Type &Value,
    const Type &EndValue,
    const DateTime::SecondRatio &Duration,
    Animations::Ease Ease,
    const std::function<void(bool Completed)> &FinishCallback)
{
    return PlayVariableAnimation(Value, EndValue, Animations::Clock::now(), std::chrono::duration_cast<Animations::Duration>(Duration), Ease, FinishCallback);
}

template<typename Type>
inline AnimationHandle Subsystem::PlayVariableAnimation(
    Type &Value,
    const Type &EndValue,
    const Animations::Time &StartTime,
    const DateTime::SecondRatio &Duration,
    Animations::Ease Ease,
    const std::function<void(bool Completed)> &FinishCallback)
{
    return PlayVariableAnimation(Value, EndValue, StartTime, StartTime + std::chrono::duration_cast<Animations::Duration>(Duration), Ease, FinishCallback);
}

template<typename Type>
inline AnimationHandle Subsystem::PlayVariableAnimation(
    Type &Value,
    const Type &EndValue,
    const Animations::Time &StartTime,
    const Animations::Time &EndTime,
    Animations::Ease Ease,
    const std::function<void(bool Completed)> &FinishCallback)
{
    auto EaseFunction = GetEaseFunction(Ease);
    const Type &StartValue = Value;
    const auto &LerpCallback = [&Value, StartValue, EndValue, EaseFunction](float Progress)
    {
        const auto Alpha = EaseFunction(Progress);
        Value = Math::Lerp(StartValue, EndValue, Alpha);
    };
    return PlayAnimation(StartTime, EndTime, LerpCallback, FinishCallback);
}

inline void Subsystem::StopAnimation(AnimationHandle Handle)
{
    auto it = Animations.find(Handle);
    if (it == Animations.end())
    {
        return;
    }

    if (it->second.FinishCallback)
    {
        it->second.FinishCallback(false);
    }

    Animations.erase(Handle);
}

inline void Subsystem::StopAnimations(const Array<AnimationHandle> &Handles)
{
    for (auto &Handle : Handles)
    {
        StopAnimation(Handle);
    }
}

inline void Subsystem::StopAnimations()
{
    for (auto &[Handle, Animation] : Animations)
    {
        if (Animation.FinishCallback)
        {
            Animation.FinishCallback(false);
        }
    }

    Animations.clear();
}

inline void Subsystem::Update()
{
    Array<AnimationHandle> FinishedAnimations;
    for (auto &[Handle, Animation] : Animations)
    {
        if (Animation.Timer.IsElapsed())
        {
            Animation.TickCallback(1.0f);
            if (Animation.FinishCallback)
            {
                Animation.FinishCallback(true);
            }
            FinishedAnimations.push_back(Handle);
        }
        else if (Animation.Timer.IsRunning())
        {
            Animation.TickCallback(Animation.Timer.GetProgress());
        }
    }
    RemoveAnimations(FinishedAnimations);
}

}
