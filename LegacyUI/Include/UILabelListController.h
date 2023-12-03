#pragma once

#include <LegacyFoundation.hpp>

#include "ListView.gen.h"
#include "TextField.gen.h"
#include "DefaultTextItemView.gen.h"

namespace UI
{

template<typename Item, typename Base = AObject>
class PUBLIC_API_EXPORT LabelListController : public ItemController<Item, Base>
{
public:
    using This = LabelListController<Item, Base>;
    using Super = ItemController<Item, Base>;
    using ItemType = Item;
    //using TemplateItemAdapter<Type>::data;

    virtual String getTitle(const AObject &sender, const ItemType &item) const = 0;

    SharedReference<View> provideViewForItem(const AObject &sender, SizeType index) override
    {
        auto v = Create<DefaultTextItemView>();
        v->setText(getTitle(sender, This::data[index]));
        return SharedReference<View>(v);
    }
};

class PUBLIC_API_EXPORT StringListController : public LabelListController<String>
{
public:

    String getTitle(const AObject &sender, const ItemType &item) const override
    {
        return item;
    }

    ItemType createNewItem(const AObject &sender) const override
    {
        return "New Item";
    }
};

}
