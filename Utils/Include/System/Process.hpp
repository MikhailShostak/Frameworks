#pragma once

#pragma once

//#include <winsock2.h>
//#include <windows.h>
#include <boost/process.hpp>

namespace System
{

using Environment = boost::process::environment;
using Subprocess = boost::process::child;
using InputStream = boost::process::ipstream;
using OutputStream = boost::process::opstream;

template<typename ...Args>
inline auto GetCurrentEnvironment()
{
    return boost::this_process::environment();
}

template<typename ...Args>
inline System::Path SearchPath(const System::Path &Path)
{
    //TODO: use System::Path instead of boost::filesystem::path
    
    if (Path.is_relative())
    {
        std::vector<boost::process::filesystem::path> Paths = boost::this_process::path();
        Paths.push_back(Path.parent_path().generic_string());
        return boost::process::search_path(Path.generic_string(), Paths).generic_string();
    }

    return boost::process::search_path(Path.generic_string()).generic_string();
}

template<typename ...Args>
inline System::Subprocess Run(const System::Path &Executable, Args &&...args)
{
    return System::Subprocess((Executable.is_relative() ? SearchPath(Executable) : Executable).generic_string(), std::forward<Args>(args)...);
}

template<typename ...Args>
inline std::tuple<System::Subprocess, System::InputStream> GetOutputStream(const System::Path &Executable, Args &&...args)
{
    System::InputStream pipe;
    System::Subprocess subprocess = Run(Executable, std::forward<Args>(args)..., boost::process::std_out > pipe);
    return { std::move(subprocess), std::move(pipe) };
}

template<typename ...Args>
inline String GetOutputString(const System::Path &Executable, Args &&...args)
{
    auto [subprocess, stream] = GetOutputStream(Executable, std::forward<Args>(args)...);

    std::stringstream ss;
    String line;
    while (subprocess.running() && std::getline(stream, line) && !line.empty())
    {
        ss << std::move(line) << std::endl;
    }
    subprocess.wait();
    return std::move(ss.str());
}

template<typename ...Args>
inline Array<String> GetOutputLines(const System::Path &Executable, Args &&...args)
{
    auto [subprocess, stream] = GetOutputStream(Executable, std::forward<Args>(args)...);

    Array<String> lines;
    String line;
    while (subprocess.running() && std::getline(stream, line) && !line.empty())
    {
        lines.push_back(std::move(line));
    }    
    return lines;
}

template<typename Type, typename ...Args>
inline Type GetOutputObject(const System::Path &Executable, Args &&...args)
{
    String output = GetOutputString(Executable, std::forward<Args>(args)...);

    Type Value;
    Serialization::FromString(output, Value); //TODO: FromStream
    return Value;
}

template<typename ...Args>
inline auto RunAndWait(const System::Path &Executable, Args &&...args)
{
    auto process = Run(Executable, std::forward<Args>(args)...);
    process.wait();
    return process.exit_code();
}

}
