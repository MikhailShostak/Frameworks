namespace Graphics
{

bool IsValid(const hlslpp::quaternion &q)
{
    return std::isfinite(q.f32[0]) && std::isfinite(q.f32[1]) && std::isfinite(q.f32[2]) && std::isfinite(q.f32[3]);
}

Matrix4/*Transform*/ Transform::GetMatrix()
{
    Matrix4 result = Matrix4::translation(Position);
    auto r = hlslpp::quaternion::rotation_euler_zxy(hlslpp::radians(Rotation));
    if (IsValid(r))
    {
        result = hlslpp::mul(Matrix4(r), result);
    }
    if (Scale[0] != 1.0f || Scale[1] != 1.0f || Scale[2] != 1.0f)
    {
        result = hlslpp::mul(Matrix4::scale(Scale), result);
    }
    return result;
}

Matrix4/*Transform*/ Transform::GetInverseMatrix()
{
    Matrix4 result = Matrix4::translation(-Position);
    auto r = hlslpp::quaternion::rotation_euler_zxy(hlslpp::radians(Rotation));
    if (IsValid(r))
    {
        result = hlslpp::mul(result, Matrix4(r));
    }
    if (Scale[0] != 1.0f || Scale[1] != 1.0f || Scale[2] != 1.0f)
    {
        result = hlslpp::mul(Matrix4::scale(1.0f / Scale), result);
    }
    return result;
}


}
