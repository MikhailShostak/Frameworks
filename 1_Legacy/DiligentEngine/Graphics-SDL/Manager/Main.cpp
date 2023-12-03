#include "Boilerplate/Application.hpp"

/*#include <fmt/core.h>

#include "Header.hpp"

int main()
{
#ifdef _DEBUG
	constexpr bool Debug = true;
#else
	constexpr bool Debug = false;
#endif
	fmt::print("Debug: {}\n", Debug);
	return 0;
}*/

int main(int argc, char *argv[]) {
	//Application app(eventHandler);
    //app.Texture.SetPath("W:/sample.png");
	Application::GetApplication().Run();
    return 0;
}