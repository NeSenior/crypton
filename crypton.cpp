#include "crypton.h"
#include <GLFW/glfw3.h>
#include <iostream>

static GLFWwindow* window = nullptr;
static float clearR = 0.0f;
static float clearG = 0.0f;
static float clearB = 0.0f;//coomit

void create(int width, int height, const char* name)
{
    glfwInit();
    window = glfwCreateWindow(width, height, name, NULL, NULL);
    glfwMakeContextCurrent(window);
}

void setBackGroundColor(float r, float g, float b){
    clearR = r;
    clearG = g;
    clearB = b;
}

void run(){
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(clearR,clearG,clearB,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        Update();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
}
void destroy()
{
    glfwTerminate();
}