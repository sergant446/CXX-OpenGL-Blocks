#include <iostream>
#include "Window/Window.hpp"
#include "VertexBuffer/VertexBuffer.hpp"

int main()
{
    std::cout << "its only start... first triangle!" << std::endl;
    Engine::Window window(800, 600, "Blocks", nullptr, nullptr);

    float triangle[] = 
    {
        -0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f
    };

    Engine::VertexBuffer vbo(sizeof(triangle), triangle, GL_STATIC_DRAW);
    vbo.Bind();

    while(!window.ShouldClose())
    {
        window.PollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(.14f, .14f, .14f, 1.f);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        window.SwapBuffers();
    }

    vbo.Unbind();
    glfwTerminate();
    return 0;
}
