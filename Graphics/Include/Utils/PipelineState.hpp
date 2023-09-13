#pragma once

namespace Graphics
{
struct PUBLIC_API_EXPORT PipelineState
{
    using This = PipelineState;
    InplaceStorage<PipelineStatePrivateData, 768, 8, false> Data;
    PipelineState();
    PipelineState(PipelineState &&other);
    PipelineState &operator =(PipelineState &&other);

     ~PipelineState();
    template<typename T>
    void Serialize(T &&data)
    {
    }

    void Initialize()
    {
    }
};
}
