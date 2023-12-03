#pragma once

#include "UIGestureRecognizer.h"
#include "UILine.h"

namespace UI
{

    class PUBLIC_API_EXPORT LinkingSourceGestureAdapter
    {
    public:
        virtual bool canBeLinkedAsSouce() const { return true; }
        virtual AVariant getLinkingSourceData() const { return AVariant(); }
        virtual void onSourceLink(UI::View &targetView, const Math::IntegerVector &point, const AVariant &sourceData) {}
    };

    class PUBLIC_API_EXPORT LinkingTargetGestureAdapter
    {
    public:
        virtual bool canBeLinkedAsTarget(const UI::View &sourceView, const AVariant &sourceData) { return true; }
        virtual void onTargetLink(UI::View &sourceView, const Math::IntegerVector &point, const AVariant &sourceData) {}

        virtual void onLinkingHighlight() {}
        virtual void onLinkingUnhighlight() {}

    };

    class PUBLIC_API_EXPORT LinkingGestureRecognizer : public GestureRecognizer
    {
        bool viewTouched = false;
        Math::Vector startPosition;

        LinkingSourceGestureAdapter *source = nullptr;
        LinkingTargetGestureAdapter *target = nullptr;

        SharedReference<Line> line = std::make_shared<Line>();
        AVariant data;
    public:

        using GestureRecognizer::GestureRecognizer;

        bool shouldProcessTouchMove(AWindowTouchMoveEvent &event) const override
        {
            return viewTouched || GestureRecognizer::shouldProcessTouchMove(event);
        }

        bool shouldProcessTouchUp(AWindowTouchUpEvent &event) const override
        {
            return viewTouched || GestureRecognizer::shouldProcessTouchUp(event);
        }

        void onTouchDown(AWindowTouchDownEvent &event, const Math::IntegerVector &point, bool isInside, const Array<APair<SharedReference<View>, Math::IntegerVector>> &views) override;
        void onTouchMove(AWindowTouchMoveEvent &event, const Math::IntegerVector &point, bool isInside, const Array<APair<SharedReference<View>, Math::IntegerVector>> &views) override;
        void onTouchUp(AWindowTouchUpEvent &event, const Math::IntegerVector &point, bool isInside, const Array<APair<SharedReference<View>, Math::IntegerVector>> &views) override;
    private:
        LinkingTargetGestureAdapter *findTarget(const Math::IntegerVector &screenPosition, View &view);
    };
}
