#pragma once

#include <LegacyFoundation.hpp>
#include <LegacyData.hpp>

#include "ACamera.h"
#include "ARenderer.h"
#include "AMaterial.h"
#include "AMesh.h"
#include "GraphicsContext.h"

class AWindow;
class AEntity;
class AAddToWindowEvent;
class ARemoveFromWindowEvent;
class AUpdateEvent;
class UIResizeEvent;


class PUBLIC_API_EXPORT ASpace : public AObject, public Legacy::Graphics::GraphicsContext
{
//CLASSGEN_GENERATED_REGION_OBJECT
public:
    typedef ASpace This;
    typedef AObject Super;
private:
    AWindow * window = nullptr;
    ACamera * camera = nullptr;
    Legacy::Graphics::ARenderer * renderer = nullptr;
public:
    virtual void serialize(AJSONObject &object) const;
    virtual void deserialize(const AJSONObject &object);
    virtual AWindow * getWindow() const;
    virtual ACamera * getCamera() const;
    virtual Legacy::Graphics::ARenderer * getRenderer() const;
//CLASSGEN_END_REGION
    Array<::SharedReference<AEntity>> entities; //TODO: Array
public:

    AEventChannel eventChannel;

    ASpace();
    ASpace(Legacy::Graphics::ARenderer &renderer, ACamera &camera);
    virtual ~ASpace();

    virtual Math::IntegerVector getViewport() const override { return camera->resolution; }
    virtual void onActive() override;
    virtual void onDeactive() override;
    virtual void draw(const ::SharedReference<Legacy::Graphics::Mesh> &mesh, const ::SharedReference<Legacy::Graphics::MaterialInterface> &material) override
    {
        renderer->addMesh(mesh, material);
    }

    void update(AUpdateEvent &event);

    const Array<::SharedReference<AEntity>> &getEntities() const;
    void setEntities(const Array<::SharedReference<AEntity>> &entities);
    void setEntities(Array<::SharedReference<AEntity>> &&entities);
    void addEntity(const ::SharedReference<AEntity> &entity);
    void addEntities(const Array<::SharedReference<AEntity>> &entities);
    void addEntities(Array<::SharedReference<AEntity>> &&entities);
    void removeEntity(const ::SharedReference<AEntity> &entity);
    void removeEntities(const Array<::SharedReference<AEntity>> &entities);
    void removeAllEntities();

protected:

    virtual void onAddToWindow(AAddToWindowEvent &event);
    virtual void onRemoveFromWindow(ARemoveFromWindowEvent &event);

private:

    void notifyAddedEntities(const Array<::SharedReference<AEntity>> &entities);
    void notifyRemovedEntities(const Array<::SharedReference<AEntity>> &entities);
    void notifyAddedEntity(AEntity &entity);
    void notifyRemovedEntity(AEntity &entity);

};