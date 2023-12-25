#pragma once

#include <LegacyExperimental.hpp>

#include <LegacyFoundation.hpp>

#include "OSProjectTargetDataInstance.h"
#include "OSSettings.h"

namespace Ui {
class OSTargetSettingsView;
}

class OSTargetSettingsView : public UI::View
{
    /*Array<SharedReference<QWidget>> widgetItems;
    Array<SharedReference<QWidget>> widgets;*/

    SharedReference<OSSettings> data;

public:

    explicit OSTargetSettingsView();
    ~OSTargetSettingsView();

    const SharedReference<OSSettings> &getData() const
    {
        return this->data;
    }

    void setData(const SharedReference<OSSettings> &data)
    {
        this->data = data;
        updateData();
    }

private:

    void updateData();

};
