#pragma once

#define OPENGL_RHI 1
#if OPENGL_RHI

#include <GL/glew.h>

namespace Graphics
{

struct ShaderHelperPrivateData
{
    void* Null{};
};

struct DrawBatchPrivateData
{
    union
    {
        void* Null {};
        struct
        {
            GLuint Handle;
        };
    };
};

struct GraphicsContextPrivateData
{
    void* Null{};
};

struct MeshPrivateData
{
    union
    {
        void* Null {};
        struct
        {
            GLuint VAO;
            GLuint VBO;
            GLuint EBO;
        };
    };
};

struct RenderBufferPrivateData
{
    Array<Graphics::Texture *> RenderTargets = {};
    union
    {
        void* Null {};
        struct
        {
            GLuint FBO;
            Graphics::Texture *DepthStencilBuffer;
        };
    };
    bool HasDepthBuffer = false;
    bool HasStencilBuffer = false;
};

struct ShaderPrivateData
{
    union
    {
        void* Null {};
        struct
        {
            GLuint Handle;
        };
    };
};

struct SwapChainPrivateData
{
    void* Null{};
};

struct TexturePrivateData
{
    union
    {
        void* Null {};
        struct
        {
            GLuint Handle;
        };
    };
};

struct PipelineStatePrivateData
{
    union
    {
        void* Null;
        struct
        {
            GLuint VAO;
            GLuint Shader;
        };
    };
    Graphics::Material *Material = nullptr;
};

}

#endif
