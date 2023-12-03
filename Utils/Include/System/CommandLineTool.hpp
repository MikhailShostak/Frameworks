#pragma once

#include "System/Process.hpp"

namespace System
{

class PUBLIC_API_EXPORT CommandLineTool
{
public:
    System::Path Executable;
    Array<String> Args;

    CommandLineTool(const System::Path &Executable, const Array<String> &Args = {}):
        Executable(Executable),
        Args(Args)
    {
        
    }

    template<typename ...Args>
    inline String GetOutput(Args &&...args)
    {
        return System::GetOutputString(Executable, this->Args, std::forward<Args>(args)...);
    }

    template<typename ...Args>
    inline System::Subprocess Run(Args &&...args)
    {
        return System::Run(Executable, this->Args, std::forward<Args>(args)...);
    }
};

}
