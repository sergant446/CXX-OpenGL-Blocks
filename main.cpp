#include <iostream>
#include "Window/Window.hpp"

int main()
{
    std::cout << "its only start..." << std::endl;
    Engine::Window window(800, 600, "Blocks", nullptr, nullptr);

    while(!window.ShouldClose())
    {
        window.PollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(.14f, .14f, .14f, 1.f);
        window.SwapBuffers();
    }

    glfwTerminate();
    return 0;
}
