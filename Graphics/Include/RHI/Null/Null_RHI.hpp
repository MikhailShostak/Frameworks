#pragma once

#define NULL_RHI 1
#if NULL_RHI

namespace Graphics
{

struct ShaderHelperPrivateData
{
    void* Null{};
};

struct DrawBatchPrivateData
{
    void* Null{};
};

struct GraphicsContextPrivateData
{
    void* Null{};
};

struct MeshPrivateData
{
    void* Null{};
};

struct RenderBufferPrivateData
{
    void* Null{};
};

struct ShaderPrivateData
{
    void* Null{};
};

struct SwapChainPrivateData
{
    void* Null{};
};

struct TexturePrivateData
{
    void* Null{};
};

struct PipelineStatePrivateData
{
    void* Null{};
};

}

#endif
