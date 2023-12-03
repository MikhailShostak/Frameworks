#pragma once

//CLASSGEN GENERATED REGION: Includes
#include "DefaultIconItemView.gen.h"

#include <LegacyFoundation.hpp>
#include "Button.gen.h"

//CLASSGEN END REGION
#include <LegacyUIDarkTheme.hpp>
#include "Button.gen.h"
#include "ImageView.gen.h"
#include "Label.gen.h"

//CLASSGEN GENERATED REGION: Namespace
namespace UI
//CLASSGEN END REGION
//CLASSGEN GENERATED REGION: NamespaceBegin
{
//CLASSGEN END REGION

//CLASSGEN GENERATED REGION: ClassHeader
class PUBLIC_API_EXPORT DefaultExpandableItemView : public UI::DefaultIconItemView
//CLASSGEN END REGION
{
//CLASSGEN GENERATED REGION: ClassBody
public:
    typedef DefaultExpandableItemView This;
    typedef UI::DefaultIconItemView Super;
    typedef void Interfaces;
public:
    DefaultExpandableItemView();
#if METAOBJECT_SUPPORT || REFLECTION_SUPPORT
    void serialize(class AJSONObject &object) const;
    void deserialize(const class AJSONObject &object);
#endif //METAOBJECT_SUPPORT || REFLECTION_SUPPORT
    SharedReference<UI::Button> expandButton;
    void onHierarchyCreate();
//CLASSGEN END REGION
private:
    bool expandable = false;
public:

    void applyParameters(size_t depth, const String &text, bool expandable)
    {
        setSizePolicy(SizePolicy::Expanded, SizePolicy::Fixed);
        setSize(Math::IntegerVector{ 0, 20 });

        setDepth(depth);
        setExpandable(expandable);

        title->setSizePolicy(SizePolicy::ContentWrapped, SizePolicy::ContentWrapped);
        title->setText(text);
    }

    void setDepth(SizeInteger Depth) { Padding.left = Depth * 20 + 4; }

    bool isItemExpanded() const
    {
        return expandButton->getBackgroundImage() == SharedReference<Legacy::Graphics::Texture>(::MinusButtonSmall);
    }

    void setItemExpanded(bool expanded)
    {
        expandButton->setBackgroundImage(expanded ? SharedReference<Legacy::Graphics::Texture>(::MinusButtonSmall) : SharedReference<Legacy::Graphics::Texture>(::PlusButtonSmall));
        icon->setImage(expanded ? SharedReference<Legacy::Graphics::Texture>(::OpenedFolderIcon)  : SharedReference<Legacy::Graphics::Texture>(::ClosedFolderIcon));
    }

    bool getExpandable() const
    {
        return expandable;
    }

    void setExpandable(bool expandable)
    {
        this->expandable = expandable;
        expandButton->setVisible(expandable);
        expandButton->setBackgroundImage(expandable ? SharedReference<Legacy::Graphics::Texture>(::PlusButtonSmall) : SharedReference<Legacy::Graphics::Texture>(::MinusButtonSmall));

        icon->setImage(expandable ? SharedReference<Legacy::Graphics::Texture>(::ClosedFolderIcon) : SharedReference<Legacy::Graphics::Texture>(::FileIcon));
    }
    const String &getText() const { return title->getText(); }
    void setText(const String &text) { title->setText(text); }
};

//CLASSGEN GENERATED REGION: NamespaceEnd
}
//CLASSGEN END REGION
