#pragma once

//CLASSGEN GENERATED REGION: Includes
#include "View.gen.h"
#include <LegacyMath.hpp>

//CLASSGEN END REGION
#include "View.gen.h"
#include "Button.gen.h"
//CLASSGEN GENERATED REGION: Namespace
namespace UI
//CLASSGEN END REGION
//CLASSGEN GENERATED REGION: NamespaceBegin
{
//CLASSGEN END REGION

//CLASSGEN GENERATED REGION: ClassHeader
class PUBLIC_API_EXPORT Switch : public UI::View
//CLASSGEN END REGION
{
//CLASSGEN GENERATED REGION: ClassBody
public:
    typedef Switch This;
    typedef UI::View Super;
    typedef void Interfaces;
protected:
    Boolean On;
public:
    Switch();
#if METAOBJECT_SUPPORT || REFLECTION_SUPPORT
    void serialize(class AJSONObject &object) const;
    void deserialize(const class AJSONObject &object);
#endif //METAOBJECT_SUPPORT || REFLECTION_SUPPORT
    Boolean getOn() const;
    void setOn(Boolean const &On);
    void setOn(Boolean &&On);
//CLASSGEN END REGION
    ADelegate<void()> OnChange;
    ADelegate<void()> OnSwitch;
private:
    SharedReference<Button> button;
protected:
    void onLoad(ALoadEvent &event) override;
    void onLayout(AUpdateEvent &event) override;
    void onUnload(AUnloadEvent &event) override;
    void SendSwitchEvent();
    void UpdateIcon();
public:
    Boolean isOn() const { return getOn(); }
};

class PUBLIC_API_EXPORT SwitchEvent : public UIPropertyChangeEvent<bool>
{
public:
    using Super = UIPropertyChangeEvent<bool>;
    using Super::Super;
};

class PUBLIC_API_EXPORT UserSwitchEvent : public UIPropertyChangeEvent<bool>
{
public:
    using Super = UIPropertyChangeEvent<bool>;
    using Super::Super;
};

//CLASSGEN GENERATED REGION: NamespaceEnd
}
//CLASSGEN END REGION
