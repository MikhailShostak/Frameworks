namespace Graphics
{

Graphics::RenderBuffer/*RenderBuffer*/ RenderTarget::GetBuffer()
{
    Graphics::RenderBuffer buffer;
    buffer.Data->RenderTargets.resize(Targets.size());
    size_t i = 0;
    for (auto &texture : Targets)
    {
        buffer.Data->RenderTargets[i++] = texture.get();
    }

    if (DepthStencil)
    {
        buffer.Data->DepthStencilBuffer = DepthStencil.get();
    }

    return { std::move(buffer) };
}

void RenderTarget::Resize(const Int2 &Size)
{
    auto newSize = Int3{ Size, 1 };
    for (auto &texture : Targets)
    {
        texture->Data->Handle = 0; //TODO: fix deletion
        texture->Size = newSize;
        texture->Channels = 4;
    }
    if (DepthStencil)
    {
        DepthStencil->Data->Handle = 0; //TODO: fix deletion
        DepthStencil->Size = newSize;
        DepthStencil->Channels = 4;
    }

    IsCompiled = false;
}

}
