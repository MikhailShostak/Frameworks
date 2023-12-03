#include "Boilerplate/Application.hpp"

#include "../res/bindings/imgui_impl_opengl3.h"
#include "../res/bindings/imgui_impl_opengl3.cpp"
#include "../res/bindings/imgui_impl_opengl3_loader.h"
#include "../res/bindings/imgui_impl_sdl2.h"
#include "../res/bindings/imgui_impl_sdl2.cpp"

#include <functional>
#include <string>

class Texture
{
public:
	void SetPath(const std::string& Path);

	void Draw();

private:
	std::string ImagePath;
	GLuint TextureHandle = 0;
	int TextureWidth = 0;
	int TextureHeight = 0;
};

void Texture::SetPath(const std::string& Path)
{
    ImagePath = Path;
    // Unload the current texture, if any
    if (TextureHandle != 0)
    {
        glDeleteTextures(1, &TextureHandle);
        TextureHandle = 0;
    }
}

void Texture::Draw()
{
    if (TextureHandle == 0 && !ImagePath.empty())
    {
        // Load the texture on demand
        SDL_Surface* ImageSurface = IMG_Load(ImagePath.data());
        TextureWidth = ImageSurface->w;
        TextureHeight = ImageSurface->h;

        GLint InternalFormat;
        GLenum Format;
        switch (ImageSurface->format->BytesPerPixel)
        {
        case 3: // RGB 24bit
            InternalFormat = GL_RGB;
            Format = GL_RGB;
            break;
        case 4: // RGBA 32bit
            InternalFormat = GL_RGBA;
            Format = GL_RGBA;
            break;
        default:
            return; // Unsupported format
        }

        glGenTextures(1, &TextureHandle);
        glBindTexture(GL_TEXTURE_2D, TextureHandle);
        glTexImage2D(GL_TEXTURE_2D, 0, InternalFormat, TextureWidth, TextureHeight, 0, Format, GL_UNSIGNED_BYTE, ImageSurface->pixels);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        SDL_FreeSurface(ImageSurface);
    }

    ImGui::Image((ImTextureID)TextureHandle, ImVec2(TextureWidth, TextureHeight));
}

class SDLApplication : public Application
{
public:
	Application(std::function<void(SDL_Event&)> EventHandler);

	~Application();

	void Run() override;

	std::shared_ptr<Texture> Texture;

private:
	SDL_Window* Window = nullptr;
	SDL_GLContext Context;
	bool Running = true;
	std::function<void(SDL_Event&)> EventHandler;
};

SDLApplication::SDLApplication(std::function<void(SDL_Event&)> EventHandler) : EventHandler(EventHandler)
{
    SDL_Init(SDL_INIT_VIDEO);
    Window = SDL_CreateWindow("Window", 100, 100, 800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    Context = SDL_GL_CreateContext(Window);

    ImGui::CreateContext();
    ImGui_ImplSDL2_InitForOpenGL(Window, Context);
    ImGui_ImplOpenGL3_Init("#version 130");
}

SDLApplication::~SDLApplication()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_GL_DeleteContext(Context);
    SDL_DestroyWindow(Window);
    SDL_Quit();
}

void SDLApplication::Run()
{
    while (Running)
    {
        SDL_Event Event;
        while (SDL_PollEvent(&Event))
        {
            if (Event.type == SDL_WINDOWEVENT && Event.window.event == SDL_WINDOWEVENT_RESIZED)
            {
                int Width = Event.window.data1;
                int Height = Event.window.data2;
                glViewport(0, 0, Width, Height);
            }

            ImGui_ImplSDL2_ProcessEvent(&Event);
            EventHandler(Event);
        }

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame(Window);
        ImGui::NewFrame();

        ImGui::BeginMainMenuBar();
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("Exit"))
            {
                Running = false;
            }
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();

        ImGui::Begin("Root", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus);
        Texture.Draw();
        ImGui::End();

        ImGui::Render();
        glClearColor(1, 1, 1, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        SDL_GL_SwapWindow(Window);
    }
}

Application &Application::GetApplication();
{
    auto eventHandler = [&](SDL_Event &event)
    {
        if (event.type == SDL_QUIT)
        {
            exit(0);
        }
    };

    SDLApplication app;
    return app;
}
