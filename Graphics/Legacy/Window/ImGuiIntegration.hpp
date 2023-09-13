#pragma once

struct ImFont;
struct ImFontConfig;

namespace ImGui
{

void Initialize(void *window, Graphics::GraphicsContext &Context, Graphics::SwapChain &SwapChain, const char *ConfigFile);
void Deinitialize(void* window);

void BeginRender(void* window);
void EndRender();

bool CharEvent(void *window, unsigned int c);
bool KeyEvent(void *window, int key, int scancode, int state, int mods);
bool ScrollEvent(void *window, double dx, double dy);

void PushUIFont();
void PushMonospacedFont();

ImFont* LoadFont(const System::Path& Path, const fpixel_t Size, ImFontConfig* Config = nullptr, const unsigned short* GlyphRange = nullptr);

void* TexID(Graphics::Texture &texture);
void* TexID(SharedReference<Graphics::Texture> &texture);

}
