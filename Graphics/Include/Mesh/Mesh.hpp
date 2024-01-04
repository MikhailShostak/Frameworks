#pragma once

namespace Graphics
{
struct PUBLIC_API_EXPORT Mesh
{
    using This = Mesh;
    System::Path SourcePath {};
    StringID SourceName {};
    Array<Vertex> Vertices {};
    Array<Face> Faces {};
    InplaceStorage<MeshPrivateData, 16, 8, false> Data;
    bool IsCompiled {};
    Mesh();
    Mesh(Mesh &&other);
    Mesh &operator =(Mesh &&other);

     ~Mesh();
    template<typename T>
    void Serialize(T &&data)
    {
        data["SourcePath"] & SourcePath;
        data["SourceName"] & SourceName;
    }

    void Initialize()
    {
    }
};
}
