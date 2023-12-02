#pragma once

namespace Gameplay
{
enum class FactionRelation
{
    Ally,
    Enemy,
    Neutral,
};
}

namespace Serialization
{
template<>
struct Serializer<InputValue, Gameplay::FactionRelation>
{
    template<typename InputValue, typename ValueType>
    static void Write(InputValue&& data, ValueType&& value)
    {
        if (data.m_Storage.IsScalar())
        {
            const auto &valueName = data.m_Storage.template as<std::string>();
            if (valueName == "Ally") { value = Gameplay::FactionRelation::Ally; return; }
            if (valueName == "Enemy") { value = Gameplay::FactionRelation::Enemy; return; }
            if (valueName == "Neutral") { value = Gameplay::FactionRelation::Neutral; return; }
            value = Gameplay::FactionRelation::Ally;

        }
    }
};

template<>
struct Serializer<OutputValue, Gameplay::FactionRelation>
{
    template<typename OutputValue, typename ValueType>
    static void Write(OutputValue&& data, ValueType&& value)
    {

        switch(value)
        {
        case Gameplay::FactionRelation::Ally: data.m_Storage = "Ally"; return;
        case Gameplay::FactionRelation::Enemy: data.m_Storage = "Enemy"; return;
        case Gameplay::FactionRelation::Neutral: data.m_Storage = "Neutral"; return;
        }

    }
};

}
