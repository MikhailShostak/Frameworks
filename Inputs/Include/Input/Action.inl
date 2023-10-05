#pragma once

namespace Input
{

inline bool Action::Trigger(const Event &event)
{
    for (const auto &Handler : Handlers)
    {
        if (Handler(event))
        {
            return true;
        }
    }

    return false;
}

}
