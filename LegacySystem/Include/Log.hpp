#pragma once

#include "Str.hpp"

#include <chrono>

class Logger
{
public:

};

namespace Log
{

template<typename FormatType, typename ...Args>
inline void Internal(FormatType &&format, Args &&...args)
{
	auto now = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
    auto f = Str::Format(fmt::runtime("[{:%Y-%m-%d %H:%M:%S}] {}\r\n"), now, format);
	fmt::print(fmt::runtime(f), std::forward<Args>(args)...);
}

template<typename FormatType, typename ...Args>
inline void Error(FormatType &&format, Args &&...args)
{
    Internal(std::forward<FormatType>(format), std::forward<Args>(args)...);
}

template<typename FormatType, typename ...Args>
inline void Warning(FormatType &&format, Args &&...args)
{
    Internal(std::forward<FormatType>(format), std::forward<Args>(args)...);
}

template<typename FormatType, typename ...Args>
inline void Info(FormatType &&format, Args &&...args)
{
    Internal(std::forward<FormatType>(format), std::forward<Args>(args)...);
}

template<typename FormatType, typename ...Args>
inline void Print(FormatType &&format, Args &&...args)
{
    Internal(std::forward<FormatType>(format), std::forward<Args>(args)...);
}

template<typename FormatType, typename MapType, typename ...Args>
inline void Print(FormatType &&format, Str::NamedArgs<MapType> &&map, Args &&...args)
{
	Print(Str::Format(std::forward<FormatType>(format), std::forward<Str::NamedArgs<MapType>>(map), std::forward<Args>(args)...));
}

template<typename FormatType, typename ...Args>
inline void Debug(FormatType &&format, Args &&...args)
{
    Internal(std::forward<FormatType>(format), std::forward<Args>(args)...);
}

}
