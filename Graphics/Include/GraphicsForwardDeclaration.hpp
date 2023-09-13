#pragma once

namespace Graphics
{

struct Window;

struct DrawBatchPrivateData;
struct GraphicsContextPrivateData;
struct MeshPrivateData;
struct PipelineStatePrivateData;
struct RenderBufferPrivateData;
struct ShaderPrivateData;
struct SwapChainPrivateData;
struct TexturePrivateData;

using NativeWindow = void *;

struct Vertex
{
    //TODO: Make it customizable. UV, Color layers, etc.
    Float4 pos;
    Float4 normal;
    Float4 uv;
    Float4 data;
};

using Face = StaticArray<uint32_t, 3>;

enum ShaderFlags
{
    None = 0,
    UseInPixelShader = 0x1,
    UseInVertexShader = 0x2,
    UseInAllShaders = UseInPixelShader | UseInVertexShader,
};

}
