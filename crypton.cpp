#include "crypton.h"
#include <GLFW/glfw3.h>
#include <iostream>

static GLFWwindow* window = nullptr;

namespace crypton
{
    void create(int width, int height, const char* title)
    {
        if (!glfwInit())
        {
            std::cout << "GLFW init failed\n";
            return;
        }
        window = glfwCreateWindow(width, height, title, NULL, NULL);
        glfwMakeContextCurrent(window);
        Start();
        while (!glfwWindowShouldClose(window))
        {
            glfwPollEvents();
            Update();
            glfwSwapBuffers(window);
        }
        glfwTerminate();
    }
}