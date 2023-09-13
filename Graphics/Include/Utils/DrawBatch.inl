#pragma once

namespace Graphics
{

template<typename Type>
inline std::tuple<size_t/*Count*/, void */*Buffer*/, size_t/*ActualBufferSize*/, size_t/*MaxBufferSize*/> DrawBatch<Type>::GetLayoutInfo()
{
    return {
        Instances.size(),
        Instances.data(),
        sizeof(Type) * Instances.size(),
        sizeof(Type) * MaxSize
    };
}

}
