#include "crypton.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <GL/gl.h>
#include <algorithm>

static GLFWwindow* window = nullptr;
static float C_R = 1.0f;
static float C_G = 1.0f;
static float C_B = 0.0f;

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
        if (!window)
        {
            std::cout << "Window creation failed\n";
            glfwTerminate();
            return;
        }
        
        glfwMakeContextCurrent(window);
        Start();
        while (!glfwWindowShouldClose(window))
        {
            glfwPollEvents();
            Update();
            glClearColor(C_R,C_G,C_B,1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            glfwSwapBuffers(window);
        }
        glfwTerminate();
    }
    void bg_color(float r,float g,float b){
        C_R = std::clamp(r,0.0f,1.0f);
        C_G = std::clamp(g,0.0f,1.0f);
        C_B = std::clamp(b,0.0f,1.0f);
    }
}