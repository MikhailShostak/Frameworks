#pragma once

namespace DateTime
{

template<typename ClockType>
class Timer
{
public:

    using Clock = ClockType;
    using Time = typename Clock::time_point;
    using Duration = typename Clock::duration;

    [[nodiscard]] bool IsStarted() const noexcept { return GetCurrentTime() >= m_StartTime; }
    [[nodiscard]] bool IsElapsed() const noexcept { return GetCurrentTime() >= m_FinishTime; }
    [[nodiscard]] bool IsRunning() const noexcept { return IsStarted() && !IsElapsed(); }

    [[nodiscard]] const Time &GetStartTime() const noexcept { return m_StartTime; }
    [[nodiscard]] const Time &GetFinishTime() const noexcept { return m_FinishTime; }
    [[nodiscard]] Duration GetDuration() const noexcept { return m_FinishTime - m_StartTime; }
    [[nodiscard]] Time GetCurrentTime() const noexcept { return Clock::now(); }
    [[nodiscard]] Duration GetElapsedTime() const noexcept { return GetCurrentTime() - m_StartTime; }
    [[nodiscard]] Duration GetRemainingTime() const noexcept { return m_FinishTime - GetCurrentTime(); }

    template<typename Type = float>
    [[nodiscard]] Type GetProgress(bool Clamp = false) const noexcept
    {
        if(m_StartTime == m_FinishTime)
        {
            return 0;
        }

        const Type progress = Type(GetElapsedTime().count()) / Type(GetDuration().count());
        return Clamp ? std::clamp<Type>(progress, 0, 1) : progress;
    }

    void Start(const Time &startTime, const Time &finishTime) noexcept
    {
        m_StartTime = startTime;
        m_FinishTime = finishTime;
    }
    void Start(const Time &startTime, const Duration &duration) noexcept { Start(startTime, startTime + duration); }
    void Start(const Time &finishTime) noexcept { Start(GetCurrentTime(), finishTime); }
    void Start(const Duration &duration) noexcept { Start(GetCurrentTime(), duration); }

    void Reset() noexcept
    {
        m_StartTime = {};
        m_FinishTime = {};
    }

private:

    Time m_StartTime{};
    Time m_FinishTime{};
};

}
