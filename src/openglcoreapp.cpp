#include "openglcoreapp.h"
#include <stdexcept>

OpenGLCoreApp::OpenGLCoreApp()
    : triangle()
{
    antialiasing = 4;
    width = 800;
    height = 600;
    title = "OpenGL core app";
    frame = 0;
}

OpenGLCoreApp::~OpenGLCoreApp()
{
    delete triangle;
    delete shader;
    glfwTerminate();
}

void OpenGLCoreApp::run()
{
    init();
    mainLoop();
}

void OpenGLCoreApp::init()
{
    if(!glfwInit()){
        throw std::runtime_error("GLFW init failed");
    }

    glfwWindowHint(GLFW_SAMPLES, antialiasing);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, title.data(), nullptr, nullptr);
    if(window == nullptr){
        throw std::runtime_error("GLFW window create failed");
    }
    glfwMakeContextCurrent(window);

    if(glewInit() != GLEW_OK){
        throw std::runtime_error("GLEW init failed");
    }

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    glClearColor(.0f, .2f, .5f, .0f);
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glm::vec3 a(-0.5, -0.5, 0);
    glm::vec3 b(0.5, -0.5, 0);
    glm::vec3 c(0, 0.5, 0);
    triangle = new Triangle(glm::mat3(a, b, c));
    //triangle = new Triangle();

    shader = new Shader("shaders/simpleShader.vert", "shaders/simpleShader.frag");
}

void OpenGLCoreApp::mainLoop(){
    do{
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glUseProgram(shader->getShaderId());
        auto faza = glGetUniformLocation(shader->getShaderId(), "faza");
        glUniform1f(faza, frame * 0.1);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, triangle->getVertexBuffer());
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glDisableVertexAttribArray(0);

        // Swap buffers
        glfwSwapBuffers(window);
        frame++;
        glfwPollEvents();
    } while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
}
