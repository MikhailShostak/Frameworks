#pragma once

namespace Core
{
struct PUBLIC_API_EXPORT Application
{
    using This = Application;
    Array<UniqueReference<Core::ApplicationComponent>> Components {};
    bool Running {};
    int ErrorCode {};
    Application() = default;
    Application(const Application &other) = delete;
    Application &operator =(const Application &other) = delete;

    virtual ~Application() {}
    template<typename T>
    void Serialize(T &&data)
    {
        data["Components"] & Components;
    }
    virtual int/*Result*/ Run();

    void Initialize()
    {
    }
};
}
