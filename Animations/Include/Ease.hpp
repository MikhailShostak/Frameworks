#pragma once

namespace Animations
{
enum class Ease
{
    Linear,
    QuadIn,
    QuadOut,
    QuadInOut,
    QuadOutIn,
    CubicIn,
    CubicOut,
    CubicInOut,
    CubicOutIn,
    QuartIn,
    QuartOut,
    QuartInOut,
    QuartOutIn,
    QuintIn,
    QuintOut,
    QuintInOut,
    QuintOutIn,
    SineIn,
    SineOut,
    SineInOut,
    SineOutIn,
    ExpoIn,
    ExpoOut,
    ExpoInOut,
    ExpoOutIn,
    CircIn,
    CircOut,
    CircInOut,
    CircOutIn,
    ElasticIn,
    ElasticOut,
    ElasticInOut,
    ElasticOutIn,
    BackIn,
    BackOut,
    BackInOut,
    BackOutIn,
    BounceIn,
    BounceOut,
    BounceInOut,
    BounceOutIn,
};
}

namespace Serialization
{
template<>
struct Serializer<InputValue, Animations::Ease>
{
    template<typename InputValue, typename ValueType>
    static void Write(InputValue&& data, ValueType&& value)
    {
        if (data.m_Storage.IsScalar())
        {
            const auto &valueName = data.m_Storage.template as<std::string>();
            if (valueName == "Linear") { value = Animations::Ease::Linear; return; }
            if (valueName == "QuadIn") { value = Animations::Ease::QuadIn; return; }
            if (valueName == "QuadOut") { value = Animations::Ease::QuadOut; return; }
            if (valueName == "QuadInOut") { value = Animations::Ease::QuadInOut; return; }
            if (valueName == "QuadOutIn") { value = Animations::Ease::QuadOutIn; return; }
            if (valueName == "CubicIn") { value = Animations::Ease::CubicIn; return; }
            if (valueName == "CubicOut") { value = Animations::Ease::CubicOut; return; }
            if (valueName == "CubicInOut") { value = Animations::Ease::CubicInOut; return; }
            if (valueName == "CubicOutIn") { value = Animations::Ease::CubicOutIn; return; }
            if (valueName == "QuartIn") { value = Animations::Ease::QuartIn; return; }
            if (valueName == "QuartOut") { value = Animations::Ease::QuartOut; return; }
            if (valueName == "QuartInOut") { value = Animations::Ease::QuartInOut; return; }
            if (valueName == "QuartOutIn") { value = Animations::Ease::QuartOutIn; return; }
            if (valueName == "QuintIn") { value = Animations::Ease::QuintIn; return; }
            if (valueName == "QuintOut") { value = Animations::Ease::QuintOut; return; }
            if (valueName == "QuintInOut") { value = Animations::Ease::QuintInOut; return; }
            if (valueName == "QuintOutIn") { value = Animations::Ease::QuintOutIn; return; }
            if (valueName == "SineIn") { value = Animations::Ease::SineIn; return; }
            if (valueName == "SineOut") { value = Animations::Ease::SineOut; return; }
            if (valueName == "SineInOut") { value = Animations::Ease::SineInOut; return; }
            if (valueName == "SineOutIn") { value = Animations::Ease::SineOutIn; return; }
            if (valueName == "ExpoIn") { value = Animations::Ease::ExpoIn; return; }
            if (valueName == "ExpoOut") { value = Animations::Ease::ExpoOut; return; }
            if (valueName == "ExpoInOut") { value = Animations::Ease::ExpoInOut; return; }
            if (valueName == "ExpoOutIn") { value = Animations::Ease::ExpoOutIn; return; }
            if (valueName == "CircIn") { value = Animations::Ease::CircIn; return; }
            if (valueName == "CircOut") { value = Animations::Ease::CircOut; return; }
            if (valueName == "CircInOut") { value = Animations::Ease::CircInOut; return; }
            if (valueName == "CircOutIn") { value = Animations::Ease::CircOutIn; return; }
            if (valueName == "ElasticIn") { value = Animations::Ease::ElasticIn; return; }
            if (valueName == "ElasticOut") { value = Animations::Ease::ElasticOut; return; }
            if (valueName == "ElasticInOut") { value = Animations::Ease::ElasticInOut; return; }
            if (valueName == "ElasticOutIn") { value = Animations::Ease::ElasticOutIn; return; }
            if (valueName == "BackIn") { value = Animations::Ease::BackIn; return; }
            if (valueName == "BackOut") { value = Animations::Ease::BackOut; return; }
            if (valueName == "BackInOut") { value = Animations::Ease::BackInOut; return; }
            if (valueName == "BackOutIn") { value = Animations::Ease::BackOutIn; return; }
            if (valueName == "BounceIn") { value = Animations::Ease::BounceIn; return; }
            if (valueName == "BounceOut") { value = Animations::Ease::BounceOut; return; }
            if (valueName == "BounceInOut") { value = Animations::Ease::BounceInOut; return; }
            if (valueName == "BounceOutIn") { value = Animations::Ease::BounceOutIn; return; }
            value = Animations::Ease::Linear;

        }
    }
};

template<>
struct Serializer<OutputValue, Animations::Ease>
{
    template<typename OutputValue, typename ValueType>
    static void Write(OutputValue&& data, ValueType&& value)
    {

        switch(value)
        {
        case Animations::Ease::Linear: data.m_Storage = "Linear"; return;
        case Animations::Ease::QuadIn: data.m_Storage = "QuadIn"; return;
        case Animations::Ease::QuadOut: data.m_Storage = "QuadOut"; return;
        case Animations::Ease::QuadInOut: data.m_Storage = "QuadInOut"; return;
        case Animations::Ease::QuadOutIn: data.m_Storage = "QuadOutIn"; return;
        case Animations::Ease::CubicIn: data.m_Storage = "CubicIn"; return;
        case Animations::Ease::CubicOut: data.m_Storage = "CubicOut"; return;
        case Animations::Ease::CubicInOut: data.m_Storage = "CubicInOut"; return;
        case Animations::Ease::CubicOutIn: data.m_Storage = "CubicOutIn"; return;
        case Animations::Ease::QuartIn: data.m_Storage = "QuartIn"; return;
        case Animations::Ease::QuartOut: data.m_Storage = "QuartOut"; return;
        case Animations::Ease::QuartInOut: data.m_Storage = "QuartInOut"; return;
        case Animations::Ease::QuartOutIn: data.m_Storage = "QuartOutIn"; return;
        case Animations::Ease::QuintIn: data.m_Storage = "QuintIn"; return;
        case Animations::Ease::QuintOut: data.m_Storage = "QuintOut"; return;
        case Animations::Ease::QuintInOut: data.m_Storage = "QuintInOut"; return;
        case Animations::Ease::QuintOutIn: data.m_Storage = "QuintOutIn"; return;
        case Animations::Ease::SineIn: data.m_Storage = "SineIn"; return;
        case Animations::Ease::SineOut: data.m_Storage = "SineOut"; return;
        case Animations::Ease::SineInOut: data.m_Storage = "SineInOut"; return;
        case Animations::Ease::SineOutIn: data.m_Storage = "SineOutIn"; return;
        case Animations::Ease::ExpoIn: data.m_Storage = "ExpoIn"; return;
        case Animations::Ease::ExpoOut: data.m_Storage = "ExpoOut"; return;
        case Animations::Ease::ExpoInOut: data.m_Storage = "ExpoInOut"; return;
        case Animations::Ease::ExpoOutIn: data.m_Storage = "ExpoOutIn"; return;
        case Animations::Ease::CircIn: data.m_Storage = "CircIn"; return;
        case Animations::Ease::CircOut: data.m_Storage = "CircOut"; return;
        case Animations::Ease::CircInOut: data.m_Storage = "CircInOut"; return;
        case Animations::Ease::CircOutIn: data.m_Storage = "CircOutIn"; return;
        case Animations::Ease::ElasticIn: data.m_Storage = "ElasticIn"; return;
        case Animations::Ease::ElasticOut: data.m_Storage = "ElasticOut"; return;
        case Animations::Ease::ElasticInOut: data.m_Storage = "ElasticInOut"; return;
        case Animations::Ease::ElasticOutIn: data.m_Storage = "ElasticOutIn"; return;
        case Animations::Ease::BackIn: data.m_Storage = "BackIn"; return;
        case Animations::Ease::BackOut: data.m_Storage = "BackOut"; return;
        case Animations::Ease::BackInOut: data.m_Storage = "BackInOut"; return;
        case Animations::Ease::BackOutIn: data.m_Storage = "BackOutIn"; return;
        case Animations::Ease::BounceIn: data.m_Storage = "BounceIn"; return;
        case Animations::Ease::BounceOut: data.m_Storage = "BounceOut"; return;
        case Animations::Ease::BounceInOut: data.m_Storage = "BounceInOut"; return;
        case Animations::Ease::BounceOutIn: data.m_Storage = "BounceOutIn"; return;
        }

    }
};

}
