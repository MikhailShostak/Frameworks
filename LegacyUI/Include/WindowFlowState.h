#pragma once

#include <memory>

#include <LegacyFoundation.hpp>
#include "ViewWindow.gen.h"

class PUBLIC_API_EXPORT FlowState
{
public:
    virtual void onCreate() = 0;
    virtual void onDestroy() = 0;
    virtual void onEnter() = 0;
    virtual void onExit() = 0;
};

template<typename FlowType>
class PUBLIC_API_EXPORT FlowApplicationComponent : public ApplicationComponent
{
    FlowType flow;
    void onApplicationStart(const AApplication& application)
    {
        flow.sm.enter();
        ApplicationComponent::onApplicationStart(application);
    }
    void onApplicationFinish(const AApplication& application)
    {
        ApplicationComponent::onApplicationFinish(application);
        flow.sm.exit();
    }
};

namespace UI
{

class PUBLIC_API_EXPORT WindowFlowState : public FlowState
{
    std::unique_ptr<UI::Window> instance;
public:
    const std::unique_ptr<UI::Window> &getInstance() const { return this->instance; }
    void setInstance(std::unique_ptr<UI::Window> &&instance) { this->instance = std::move(instance); }
    void onCreate() override {}
    void onDestroy() override {}
    void onEnter() override { instance->show(); }
    void onExit() override { instance->hide(); }
};

}
