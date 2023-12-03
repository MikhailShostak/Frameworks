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

inline std::vector<boost::process::filesystem::path> GetLocalPaths(const System::Path &Path)
{
    //TODO: use System::Path instead of boost::filesystem::path
    const auto ParentPath = Path.parent_path();
    std::vector<boost::process::filesystem::path> Paths;
    if (Path.is_relative())
    {
        Paths = {
            ParentPath.generic_string(),
            System::GetAbsolute(ParentPath).generic_string(),
        };
    }
    else
    {
        Paths = {
            ParentPath.generic_string(),
        };
    }
    return Paths;
}

inline System::Path SearchFile(const System::Path &Path)
{
    //TODO: use System::Path instead of boost::filesystem::path
    auto SearchIn = [&Path](const std::vector<boost::process::filesystem::path> &Paths) -> System::Path
    {
        System::Path Result;
        for (const auto &Folder : Paths)
        {
            const System::Path FullPath = System::Path(Folder.generic_string()) / Path;
            if (System::IsRegularFile(FullPath))
            {
                Result = std::move(FullPath);
                break;
            }
        }
        return Result;
    };

    System::Path Result = SearchIn(GetLocalPaths(Path));
    if (Result.empty())
    {
        Result = SearchIn(::boost::this_process::path());
    }

    return Result;
}

inline System::Path SearchExecutable(const System::Path &Path)
{
    //TODO: use System::Path instead of boost::filesystem::path

    if (Path.has_parent_path())
    {
        std::vector<boost::process::filesystem::path> Paths = GetLocalPaths(Path);
        const auto Filename = Path.filename();
        const auto FoundPath = boost::process::search_path(Filename.generic_string(), Paths);
        if (!FoundPath.empty())
        {
            return FoundPath.generic_string();
        }
    }

    return boost::process::search_path(Path.generic_string()).generic_string();
}

template<typename ...Args>
inline System::Subprocess Run(const System::Path &Executable, Args &&...args)
{
    return System::Subprocess(SearchExecutable(Executable).generic_string(), std::forward<Args>(args)...);
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
