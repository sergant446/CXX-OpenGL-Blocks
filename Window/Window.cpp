#include "Window.hpp"

namespace Engine
{
    Window::Window(int Width, int Height, const char* Title, GLFWmonitor* Monitor, GLFWwindow* Share)
    {
        if (!glfwInit())
        {
            std::cerr << "ERROR::GLFW: FAILED TO INITIALIZE GLFW!" << std::endl;
            exit(-1);
        }
        m_Window = glfwCreateWindow(Width, Height, Title, Monitor, Share);
        if (!m_Window)
        {
            std::cerr << "ERROR::GLFW: FAILED TO INITIALIZE WINDOW!" << std::endl;
            glfwTerminate();
            exit(-1);
        }
        MakeCurrent();
        if (glewInit() != GLEW_OK)
        {
            std::cerr << "ERROR::GLEW: FAILED TO INITIALIZE GLEW!" << std::endl;
            glfwTerminate();
            exit(-1);
        }
    }

    Window::~Window() {}

    void Window::MakeCurrent() { glfwMakeContextCurrent(m_Window); }
    void Window::PollEvents() { glfwPollEvents(); }
    void Window::SwapBuffers() { glfwSwapBuffers(m_Window); }

    bool Window::ShouldClose() { return glfwWindowShouldClose(m_Window); }
}
