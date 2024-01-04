#define OPENGL_RHI 1
#if OPENGL_RHI

namespace Graphics
{

void CheckOpenGLError()
{
    GLenum err;
    while((err = glGetError()) != GL_NO_ERROR)
    {
        std::cerr << "OpenGL error: " << gluErrorString(err) << std::endl;
        std::terminate();
    }
}

void SetShaderVariable(GLuint Shader, const char *Name, size_t hash, const void *Data)
{
    if(hash == typeid(int32_t).hash_code())
    {
        glUniform1iv(glGetUniformLocation(Shader, Name), 1, ReinterpretCast<const GLint>(Data));
    }
    else if(hash == typeid(Int2).hash_code())
    {
        glUniform2iv(glGetUniformLocation(Shader, Name), 1, ReinterpretCast<const GLint>(Data));
    }
    else if(hash == typeid(Int3).hash_code())
    {
        glUniform3iv(glGetUniformLocation(Shader, Name), 1, ReinterpretCast<const GLint>(Data));
    }
    else if(hash == typeid(Int4).hash_code())
    {
        glUniform4iv(glGetUniformLocation(Shader, Name), 1, ReinterpretCast<const GLint>(Data));
    }
    else if(hash == typeid(float).hash_code())
    {
        glUniform1fv(glGetUniformLocation(Shader, Name), 1, ReinterpretCast<const GLfloat>(Data));
    }
    else if(hash == typeid(Float2).hash_code())
    {
        glUniform2fv(glGetUniformLocation(Shader, Name), 1, ReinterpretCast<const GLfloat>(Data));
    }
    else if(hash == typeid(Float3).hash_code())
    {
        glUniform3fv(glGetUniformLocation(Shader, Name), 1, ReinterpretCast<const GLfloat>(Data));
    }
    else if(hash == typeid(Float4).hash_code())
    {
        glUniform4fv(glGetUniformLocation(Shader, Name), 1, ReinterpretCast<const GLfloat>(Data));
    }
    else if(hash == typeid(Matrix3).hash_code())
    {
        glUniformMatrix3fv(glGetUniformLocation(Shader, Name), 1, GL_FALSE, ReinterpretCast<const GLfloat>(Data));
    }
    else if(hash == typeid(Matrix4).hash_code())
    {
        glUniformMatrix4fv(glGetUniformLocation(Shader, Name), 1, GL_FALSE, ReinterpretCast<const GLfloat>(Data));
    }
}

GraphicsContext::GraphicsContext() = default;
GraphicsContext::GraphicsContext(GraphicsContext && other) = default;
GraphicsContext& GraphicsContext::operator =(GraphicsContext && other) = default;
GraphicsContext::~GraphicsContext() = default;

Map<Graphics::Material *, Graphics::PipelineState> Pipelines;
Graphics::PipelineState *CurrentState = nullptr;


bool/*Result*/ GraphicsContext::Initialize(const Graphics::NativeWindow &NativeWindow, Graphics::SwapChain &SwapChain)
{
    return true;
}

void GraphicsContext::CreateDrawBatch(Graphics::DrawBatchBase &Batch)
{
    auto [count, buffer, size, max] = Batch.GetLayoutInfo();
    if (Batch.Data->Handle == 0)
    {
        glGenBuffers(1, &Batch.Data->Handle);
    }
    glBindBuffer(GL_ARRAY_BUFFER, Batch.Data->Handle);
    glBufferData(GL_ARRAY_BUFFER, size, buffer, GL_DYNAMIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    CheckOpenGLError();
}

void GraphicsContext::CreateConstants(Graphics::ShaderMetatype &Constants)
{

}

void GraphicsContext::CreateMesh(Graphics::Mesh &Mesh)
{
    // Bind VBO
    glGenBuffers(1, &Mesh.Data->VBO);
    glBindBuffer(GL_ARRAY_BUFFER, Mesh.Data->VBO);
    glBufferData(GL_ARRAY_BUFFER, Mesh.Vertices.size() * sizeof(Graphics::Vertex), Mesh.Vertices.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    CheckOpenGLError();

    // Bind EBO
    glGenBuffers(1, &Mesh.Data->EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Mesh.Data->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, Mesh.Faces.size() * sizeof(Graphics::Face), Mesh.Faces.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    CheckOpenGLError();

    Mesh.IsCompiled = true;
}

enum class TextureBufferType
{
    Texture,
    RenderTarget,
    DepthStencil
};

void GraphicsContext::Create2DTexture(Graphics::Texture &Texture)
{
    glGenTextures(1, &Texture.Data->Handle);
    glBindTexture(GL_TEXTURE_2D, Texture.Data->Handle);

    auto Channels = [&](){
        switch(Texture.Channels)
        {
        case 0:
            return GL_DEPTH_COMPONENT;
        case 1:
            return GL_R;
        case 2:
            return GL_RG;
        case 3:
            return GL_RGB;
        case 4:
            return GL_RGBA;
        }
    }();

    auto Format = [&](){
        switch(Texture.Channels)
        {
        case 0:
            return GL_DEPTH_COMPONENT;
        case 1:
            return Texture.HDR ? GL_R32F : GL_R;
        case 2:
            return Texture.HDR ? GL_RG32F : GL_RG;
        case 3:
            return Texture.HDR ? GL_RGB32F : GL_RGB;
        case 4:
            return Texture.HDR ? GL_RGBA32F : GL_RGBA;
        }
    }();

    if (Texture.Buffer.size())
    {
        glTexImage2D(GL_TEXTURE_2D, 0, Format, Texture.Size[0], Texture.Size[1], 0, Channels, Texture.HDR ? GL_FLOAT : GL_UNSIGNED_BYTE, Texture.Buffer.data());
    }
    else
    {
        glTexImage2D(GL_TEXTURE_2D, 0, Format, Texture.Size[0], Texture.Size[1], 0, Channels, Texture.HDR ? GL_FLOAT : GL_UNSIGNED_BYTE, nullptr);
    }

    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    const bool NeedsMipmaps = Texture.Filtration == Graphics::TextureFiltration::Trilinear;

    if (NeedsMipmaps)
    {
        glGenerateMipmap(GL_TEXTURE_2D);
    }

    switch(Texture.Filtration)
    {
    case Graphics::TextureFiltration::Nearest:
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        break;
    case Graphics::TextureFiltration::Bilinear:
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        break;
    case Graphics::TextureFiltration::Trilinear:
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        break;
    case Graphics::TextureFiltration::Anisotropic:
    {
        GLfloat maxAnisotropyLevel {};
        glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &maxAnisotropyLevel);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, maxAnisotropyLevel);
    }
        break;
    }

    glBindTexture(GL_TEXTURE_2D, 0);
    CheckOpenGLError();

    Texture.IsCompiled = true;
}

void GraphicsContext::CreateRenderTarget(Graphics::RenderTarget &RenderTarget)
{
    /*glGenFramebuffers(1, &RenderTarget.Data->FBO);
    glBindFramebuffer(GL_FRAMEBUFFER, RenderTarget.Data->FBO);

    RenderTarget.Data->Handles.resize(RenderTarget.Targets.size());
    Array<GLenum> DrawBuffers;
    DrawBuffers.resize(RenderTarget.Targets.size());
    for (int i = 0; i < RenderTarget.Targets; ++i)
    {
        Graphics::Texture &Texture = *RenderTarget.Targets[i];
        if (!Texture.IsCompiled())
        {
            Create2DTexture(Texture);
        }
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + i, GL_TEXTURE_2D, Texture.Data->Handle, 0);
        DrawBuffers[i] = GL_COLOR_ATTACHMENT0 + i;
    }

    glDrawBuffers(DrawBuffers.size(), DrawBuffers.data());

    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
    {
        std::cerr << "Framebuffer not complete!" << std::endl;
    }

    glBindFramebuffer(GL_FRAMEBUFFER, 0);*/
}

void CompileShader(auto Type, Graphics::Shader &Shader)
{
    Shader.Data->Handle = glCreateShader(Type);
    const GLchar* StringPointer = Shader.SourceCode.data();
    glShaderSource(Shader.Data->Handle, 1, &StringPointer, nullptr);
    glCompileShader(Shader.Data->Handle);
    CheckOpenGLError();
}

void GraphicsContext::CreateMaterial(Graphics::Material &Material)
{
    CompileShader(GL_VERTEX_SHADER, Material.VertexShader);
    CompileShader(GL_FRAGMENT_SHADER, Material.PixelShader);

    //glDeleteShader(vertexShaderHandle);
    //glDeleteShader(fragmentShaderHandle);
}

void GraphicsContext::ClearRenderBuffers(const hlslpp::float4 &Color)
{

}

void GraphicsContext::ClearDepthBuffer(float Value)
{

}

void GraphicsContext::ClearStencilBuffer(uint8_t Value)
{

}

void GraphicsContext::ClearDepthStencilBuffers(float DepthValue, uint8_t StencilValue)
{

}

void GraphicsContext::SetRenderBuffer(const Graphics::RenderBuffer &buffer)
{

}
void GraphicsContext::Render(Graphics::SwapChain &SwapChain)
{

}

void GraphicsContext::Upload(Graphics::DrawBatchBase &Batch)
{
    CreateDrawBatch(Batch);
}

void GraphicsContext::ApplyConstants(Graphics::ShaderMetatype &Constants)
{

}

void GraphicsContext::SetState(PipelineState &State)
{

}

void GraphicsContext::Draw(Graphics::Mesh &Mesh, Graphics::DrawBatchBase &Batch)
{
    // >5k draw calls is high
    // >10k draw calls is critical

    if (!Mesh.IsCompiled)
    {
        if (Mesh.Vertices.empty() && !Mesh.SourcePath.empty() && !Mesh.SourceName.empty())
        {
            Graphics::AssetLoader::LoadMesh(Mesh);
        }

        CreateMesh(Mesh);
    }

    Upload(Batch);
    if (!CurrentState->Data->VAO)
    {
        // Bind VAO
        glGenVertexArrays(1, &CurrentState->Data->VAO);
        glBindVertexArray(CurrentState->Data->VAO);
        {
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Mesh.Data->EBO);

            glBindBuffer(GL_ARRAY_BUFFER, Mesh.Data->VBO);
            // Bind VBO layout
            GLint posAttrib = 0;
            glVertexAttribPointer(posAttrib, 4, GL_FLOAT, GL_FALSE, sizeof(Graphics::Vertex), reinterpret_cast<void*>(sizeof(Float4) * 0));
            glEnableVertexAttribArray(posAttrib);

            GLint normalAttrib = 1;
            glVertexAttribPointer(normalAttrib, 4, GL_FLOAT, GL_FALSE, sizeof(Graphics::Vertex), reinterpret_cast<void*>(sizeof(Float4) * 1));
            glEnableVertexAttribArray(normalAttrib);

            GLint texAttrib = 2;
            glVertexAttribPointer(texAttrib, 4, GL_FLOAT, GL_FALSE, sizeof(Graphics::Vertex), reinterpret_cast<void*>(sizeof(Float4) * 2));
            glEnableVertexAttribArray(texAttrib);

            GLint customAttrib = 3;
            glVertexAttribPointer(customAttrib, 4, GL_FLOAT, GL_FALSE, sizeof(Graphics::Vertex), reinterpret_cast<void*>(sizeof(Float4) * 3));
            glEnableVertexAttribArray(customAttrib);
            CheckOpenGLError();
        }

        {
            auto [count, buffer, size, max] = Batch.GetLayoutInfo();
            size_t type_size = size / count;
            size_t rows = size / sizeof(Float4) / count;
            GLint instanceAttrib = 4;
            for (size_t i = 0; i < rows; ++i)
            {
                glBindBuffer(GL_ARRAY_BUFFER, Batch.Data->Handle);
                glVertexAttribPointer(instanceAttrib + i, 4, GL_FLOAT, GL_FALSE, type_size, reinterpret_cast<void*>(sizeof(Float4) * i));
                glEnableVertexAttribArray(instanceAttrib + i);
                glVertexAttribDivisor(instanceAttrib + i, 1);
            }
        CheckOpenGLError();
        }
        glBindVertexArray(0);
    }

    glBindVertexArray(CurrentState->Data->VAO);
    auto [count, buffer, size, max] = Batch.GetLayoutInfo();
    glDrawElementsInstanced(GL_TRIANGLES, Mesh.Faces.size() * 3, GL_UNSIGNED_INT, 0, count);
    glBindVertexArray(0);
}

void ApplyMaterialRenderingSettings(const MaterialRenderingSettings& settings)
{
    if (settings.StencilEnabled)
    {
        glEnable(GL_STENCIL_TEST);
        glStencilMask(settings.StencilWriteMask);
        glStencilFunc(GL_ALWAYS, 0, settings.StencilReadMask);
    }
    else
    {
        glDisable(GL_STENCIL_TEST);
    }

    if (settings.DepthTestEnabled)
    {
        glEnable(GL_DEPTH_TEST);
    }
    else
    {
        glDisable(GL_DEPTH_TEST);
    }

    glDepthMask(settings.DepthWriteEnabled ? GL_TRUE : GL_FALSE);

    if (settings.Wireframe)
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    else
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }

    if (settings.Cullback)
    {
        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);
    }
    else
    {
        glDisable(GL_CULL_FACE);
    }
}

void GraphicsContext::ApplyMaterial(Graphics::Material &Material)
{
    if (!Material.VertexShader.Data->Handle)
    {
        if (!Material.SourceShaderPath.empty())
        {
            if (Material.VertexShader.SourceCode.empty())
            {
                System::Path VertPath = Material.SourceShaderPath;
                VertPath += ".vert";
                System::LoadFile(VertPath, Material.VertexShader.SourceCode);
            }

            if (Material.PixelShader.SourceCode.empty())
            {
                System::Path FragPath = Material.SourceShaderPath;
                FragPath += ".frag";
                System::LoadFile(FragPath, Material.PixelShader.SourceCode);
            }
        }
        CreateMaterial(Material);
    }

    auto it = Pipelines.find(&Material);
    if (it == Pipelines.end())
    {
        Graphics::PipelineState state;
        it = Pipelines.insert({ &Material, std::move(state) }).first;

        //if (!Material.RenderBuffer.Data->RenderTargets[0])
        //{
        //    fmt::print("WARNING: Material Render is not set, current will be used instead...\n");
        //    Material.RenderBuffer = CurrentRenderBuffer;
        //}
        it->second.Data->Material = &Material;
        //it->second.Data->CompileState(*this);
        it->second.Data->Shader = glCreateProgram();
        glAttachShader(it->second.Data->Shader, Material.VertexShader.Data->Handle);
        glAttachShader(it->second.Data->Shader, Material.PixelShader.Data->Handle);
        glLinkProgram(it->second.Data->Shader);
        CheckOpenGLError();
    }
    auto &pipeline = it->second;
    CurrentState = &pipeline;

    ApplyMaterialRenderingSettings(Material.Settings);

    glUseProgram(CurrentState->Data->Shader);

    for (size_t i = 0; i < Material.TextureSamplers.size(); ++i)
    {
        auto &Sampler = Material.TextureSamplers[i];
        glActiveTexture(GL_TEXTURE0 + i);
        glUniform1i(glGetUniformLocation(CurrentState->Data->Shader, Sampler.Name.data()), i);
        GLuint handle = Sampler.Texture->Data->Handle;
        glBindTexture(GL_TEXTURE_2D, handle);
        CheckOpenGLError();
    }

    for (const SharedReference<Graphics::ShaderMetatype> &Variable : Material.VertexShader.Variables)
    {
        ApplyShaderVariable(*Variable);
    }

    for (const SharedReference<Graphics::ShaderMetatype> &Variable : Material.PixelShader.Variables)
    {
        ApplyShaderVariable(*Variable);
    }
}

void GraphicsContext::ApplyShaderVariable(Graphics::ShaderMetatype & Variable)
{
    SetShaderVariable(CurrentState->Data->Shader, Variable.Name.data(), Variable.TypeID, Variable.DataPointer);
    CheckOpenGLError();
}

void GraphicsContext::InvalidateMaterial(Graphics::Material& material)
{
    Pipelines.erase(&material);
}

void GraphicsContext::InvalidateTexture(Graphics::Texture& texture)
{

}

}

#endif
