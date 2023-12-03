#pragma once

#include "View.gen.h"
#include "UITouchGestureRecognizer.h"
#include "UILabelListController.h"

namespace UI
{

class PUBLIC_API_EXPORT MenuAction
{
public:
    String text;
    ADelegate<void(TapGestureEvent &event)> delegate;
};

class PUBLIC_API_EXPORT MenuView : public LabelListController<MenuAction, View>
{
//CLASSGEN_GENERATED_REGION_OBJECT
//CLASSGEN_END_REGION
    SharedReference<ListView> list = SharedReference<ListView>(Create<ListView>());
public:
    using Super = LabelListController<MenuAction, View>;

    void onLoad(ALoadEvent &event);


    void addAction(const MenuAction &action)
    {
        data.push_back(action);
        if (isLoaded())
        {
            list->notifyInsertItems(data.size() - 1);
        }
    }

    void removeAction(size_t index)
    {
        ArrayUtils::Remove(data, index);
        if (isLoaded())
        {
            list->notifyRemoveItems(index);
        }
    }

    void removeAllActions()
    {
        data.clear();
        if (isLoaded())
        {
            list->notifyUpdateAllItems();
        }
    }

    String getTitle(const AObject &sender, const ItemType &item) const override
    {
        return item.text;
    }

    ItemType createNewItem(const AObject &sender) const
    {
        return MenuAction();
    }

    void onUpdate(AUpdateEvent &event);

    void onItemTapped(const AObject &sender, TapGestureEvent &event, SizeType index) override;

private:
    void hideMenu();
};

using MenuGeometryCallback = ADelegate<Math::IntegerRectangle(UI::TapGestureEvent &event, const SharedReference<UI::View> &view, const SharedReference<UI::View> &menu)>;

PUBLIC_API_EXPORT void AttachMenuToView(const SharedReference<UI::View> &view, const SharedReference<UI::View> &menu, ATouchID touchID = ATouchID::RightMouseButton, const MenuGeometryCallback &GeometryCallback = MenuGeometryCallback());

}
