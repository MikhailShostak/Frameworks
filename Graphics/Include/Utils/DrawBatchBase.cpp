namespace Graphics
{

DrawBatchBase::DrawBatchBase() = default;
DrawBatchBase::~DrawBatchBase() = default;
DrawBatchBase::DrawBatchBase(DrawBatchBase &&other) = default;
DrawBatchBase &DrawBatchBase::operator =(DrawBatchBase &&other) = default;

std::tuple<size_t/*Count*/, void */*Buffer*/, size_t/*ActualBufferSize*/, size_t/*MaxBufferSize*/> DrawBatchBase::GetLayoutInfo()
{
    return { 0, nullptr, 0, 0 };
}

}
