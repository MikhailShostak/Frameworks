#pragma once

class PUBLIC_API_EXPORT Conan : public System::CommandLineTool
{
public:
    using PackagesStorage = Map<String, Map<String, String>>;

    Conan():
        CommandLineTool("W:/Projects/BuildTools/Run.bat", { "conan" })
    {

    }

    template<typename Type, typename ...Args>
    inline Type GetData(Args &&...args)
    {
        return System::GetOutputObject<Type>(Executable, this->Args, std::forward<Args>(args)..., "--format=json");
    }

    Map<String, String> GetLocalPackages(const String &Pattern = "*")
    {
        return GetData<PackagesStorage>("list", Pattern)["Local Cache"];
    }

    Map<String, Map<String, String>> GetEditablePackages()
    {
        return GetData<Map<String, Map<String, String>>>("editable", "list");
    }
    
    String AddEditablePackage(const String &Name, const String &Version, const String &Path)
    {
        return GetOutput("editable", "add", "--name", Name, "--version", Version, Path);
    }

    String RemoveEditablePackage(const String &Path)
    {
        return GetOutput("editable", "remove", Path);
    }
};
