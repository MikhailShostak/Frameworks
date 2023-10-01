namespace Core::Details
{
    
PUBLIC_API_EXPORT UniqueReference<Core::Application> CreateMainApplication()
{
    auto Applications = Reflection::FindAllDerived<Core::Application>();
    return Applications.front()->Create();
}

}
