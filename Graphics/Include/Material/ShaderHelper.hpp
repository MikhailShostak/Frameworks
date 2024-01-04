#pragma once

namespace Graphics
{

struct PUBLIC_API_EXPORT ShaderVariableBinding
{
    const char *Type = nullptr;
    StringID Name = nullptr;
    const char *Reg = nullptr;
};

struct PUBLIC_API_EXPORT ShaderMetatype
{
    Array<ShaderVariableBinding> Variables;

    const char* Metatype = nullptr;
    StringID Name;

    size_t TypeID = 0;
    size_t DataSize = 0;
    void *DataPointer = 0;

    template<typename T>
    void Serialize(T &&data)
    {
        data["Name"] & Name;
    }

    template<typename ReturnType>
    ReturnType Register(const char *type, const StringID name, const char *reg = nullptr)
    {
        Variables.push_back({ type, name, reg });
        return ReturnType();
    }

    ShaderMetatype();
    virtual ~ShaderMetatype();
    ShaderMetatype(const ShaderMetatype &other);
    ShaderMetatype &operator =(const ShaderMetatype &other);
    ShaderMetatype(ShaderMetatype &&other);
    ShaderMetatype &operator =(ShaderMetatype &&other);

    ShaderMetatype(const char *Metatype, const StringID &Name, size_t DataSize);

    String GetCode()
    {
        auto t = [](auto &v){
            String result = String("    ") + v.Type + " " + v.Name;
            if (v.Reg)
            {
                result = result + " : " + v.Reg;
            }
            return result + "\n;";
        };

        return String(Metatype) + " " + Name + "\n"
        "{\n"
        + (Variables | ranges::views::transform(t) | ranges::views::cache1 | ranges::views::join | ranges::to<std::string>()) +
        "};\n"
        ;
    }

    InplaceStorage<struct ShaderHelperPrivateData, 8, 8> Data;
};

template<typename Type>
struct PUBLIC_API_EXPORT ShaderVariable : public ShaderMetatype
{
    using Super = ShaderMetatype;

    Type Value {};

    ShaderVariable()
    {
        TypeID = typeid(Type).hash_code();
        DataSize = sizeof(Type);
        DataPointer = &Value;
    }

    ShaderVariable(const StringID &Name)
    {
        this->Name = Name;
        TypeID = typeid(Type).hash_code();
        DataSize = sizeof(Type);
        DataPointer = &Value;
    }

    template<typename T>
    void Serialize(T &&data)
    {
        data["Value"] & Value;
    }
};

template<typename T>
struct ShaderMapping
{
    static constexpr const char *n = nullptr;
};

template<>
struct ShaderMapping<bool>
{
    static constexpr const char *n = "bool";
};

template<>
struct ShaderMapping<int32_t>
{
    static constexpr const char *n = "int";
};

template<>
struct ShaderMapping<uint32_t>
{
    static constexpr const char *n = "uint";
};

template<>
struct ShaderMapping<float>
{
    static constexpr const char *n = "float";
};

template<>
struct ShaderMapping<hlslpp::float1>
{
    static constexpr const char *n = "float";
};

template<>
struct ShaderMapping<hlslpp::float2>
{
    static constexpr const char *n = "float2";
};

template<>
struct ShaderMapping<hlslpp::float3>
{
    static constexpr const char *n = "float3";
};

template<>
struct ShaderMapping<hlslpp::float4>
{
    static constexpr const char *n = "float4";
};

template<>
struct ShaderMapping<hlslpp::float4x4>
{
    static constexpr const char *n = "float4x4";
};

}

#define SHADER_STRUCT_BEGIN(name) struct name : public Graphics::ShaderMetatype\
{\
name():ShaderMetatype("struct", #name, sizeof(name) - sizeof(Graphics::ShaderMetatype)) {

#define SHADER_STRUCT_END() }};

#define SHADER_BUFFER_BEGIN(name) struct name : public Graphics::ShaderMetatype\
{\
name():ShaderMetatype("cbuffer", #name, sizeof(name) - sizeof(Graphics::ShaderMetatype)) {}

#define SHADER_BUFFER_END() };

#define SHADER_LAYOUT(type, name) Register<type>(Graphics::ShaderMapping<type>::n, #name);
#define SHADER_LAYOUT_REG(type, name, reg) Register<type>(Graphics::ShaderMapping<type>::n, #name, #reg);

#define SHADER_VARIABLE(type, name) type name = SHADER_LAYOUT(type, name)
#define SHADER_VARIABLE_REG(type, name, reg) type name = SHADER_LAYOUT(type, name, reg)
