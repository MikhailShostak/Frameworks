#pragma once

namespace Gameplay
{
struct PUBLIC_API_EXPORT FactionDefinition
{
    using This = FactionDefinition;
    StringID Name {};
    Array<StringID> Allies {};
    Array<StringID> Enemies {};

    template<typename T>
    void Serialize(T &&data)
    {
        data["Name"] & Name;
        data["Allies"] & Allies;
        data["Enemies"] & Enemies;
    }
    virtual bool/*Result*/ IsAlly(const StringID & Faction);
    virtual bool/*Result*/ IsEnemy(const StringID & Faction);
    virtual bool/*Result*/ IsNeutral(const StringID & Faction);
    virtual Gameplay::FactionRelation/*Result*/ GetRelation(const StringID & Faction);

    void Initialize()
    {
    }
};
}
