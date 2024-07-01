#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace Engine
{
    class Window
    {
    public:
        Window(int Width, int Height, const char* Title, GLFWmonitor* Monitor, GLFWwindow* Share);
        ~Window();
        void MakeCurrent();
        void PollEvents();
        void SwapBuffers();
        bool ShouldClose();

    private:
        GLFWwindow* m_Window;
    };
}
