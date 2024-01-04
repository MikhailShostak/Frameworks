#pragma once

namespace Graphics
{
struct PUBLIC_API_EXPORT Camera
{
    using This = Camera;
    Graphics::Transform Transform {};
    Int2 Resolution {};
    float NearPlane { 1 };
    float FarPlane { 10000 };
    float FieldOfView { 45.0 };

    template<typename T>
    void Serialize(T &&data)
    {
        data["Transform"] & Transform;
        data["Resolution"] & Resolution;
        data["NearPlane"] & NearPlane;
        data["FarPlane"] & FarPlane;
        data["FieldOfView"] & FieldOfView;
    }
    virtual Matrix4/*Matrix*/ GetOrthographicProjection();
    virtual Matrix4/*Matrix*/ GetPerspectiveProjection();
    virtual Matrix4/*Matrix*/ GetProjection();
    virtual Matrix4/*Matrix*/ GetView();
    virtual Matrix4/*Matrix*/ GetViewProjection();

    void Initialize()
    {
    }
};
}
