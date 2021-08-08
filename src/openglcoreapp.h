#ifndef OPENGLCOREAPP_H
#define OPENGLCOREAPP_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <memory>
#include "triangle.h"
#include "shader.h"

class OpenGLCoreApp
{
private:
    GLFWwindow* window;
    int antialiasing;
    int width;
    int height;
    std::string title;
    Triangle* triangle;
    Shader* shader;
    uint32_t frame;
    GLuint VAO;
public:
    OpenGLCoreApp();
    OpenGLCoreApp(int width, int height, std::string title, int antialiasingLevel);
    ~OpenGLCoreApp();

    void run();
    void init();
    void mainLoop();
};

#endif // OPENGLCOREAPP_H
