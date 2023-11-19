
namespace Memory
{

ECS::Entity &GetParentEntity()
{
    static thread_local ECS::Entity Entity;
    return Entity;
}

}
