namespace ClassGen
{

void ParticleSystemCompiler::Compile(const SharedReference<ClassGen::BaseInfo>& BaseInfo, const System::Path& OutputFilePath)
{
    auto t = DynamicCast<ClassGen::ParticleSystemInfo>(BaseInfo);
    if (!t)
    {
        return;
    }
    auto& textureInfo = *t;

    auto name = OutputFilePath.stem().generic_string();
    auto Namespace = boost::replace_all_copy(textureInfo.Namespace, ".", "::");

    std::ofstream file;
    file.open(OutputFilePath.generic_string(), std::ios::binary);
    fmt::print("Write: {}\n", OutputFilePath.generic_string());

    file << "#pragma once\n";
    if (!Namespace.empty())
    {
        file << "\n";
        file << "namespace " << Namespace << "\n";
        file << "{\n";
    }

    file << "\n";
    file << "inline DynamicAsset<Graphics::Texture> " << name << " = { \"" << name << "\", [](auto &instance)\n{\n";
    //file << "Graphics::LoadTexture(instance, \"" << Serialization::ToString(textureInfo.Path) << "\");\n"
    file << "} };\n";

    if (!Namespace.empty())
    {
        file << "}\n";
    }
}

}
