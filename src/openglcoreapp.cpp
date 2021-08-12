#include "openglcoreapp.h"
#include <stdexcept>
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>

void GLAPIENTRY MessageCallback(GLenum source, GLenum type, GLuint, GLenum severity, GLsizei, const GLchar* message, const void*)
{
    std::cout << "OpenGL CALLBACK: ";
    switch(type){
    case GL_DEBUG_TYPE_ERROR:
        std::cout << "[ERROR ";
        break;
    case GL_DEBUG_TYPE_PERFORMANCE:
        std::cout << "[PERFORMANCE ";
        break;
    case GL_DEBUG_TYPE_OTHER:
        std::cout << "[OTHER ";
        break;
    default:
        std::cout << "[GL " << type << " ";
        break;
    }
    switch(severity){
    case GL_DEBUG_SEVERITY_HIGH:
        std::cout << "HIGH] ";
        break;
    case GL_DEBUG_SEVERITY_MEDIUM:
        std::cout << "MEDIUM] ";
        break;
    case GL_DEBUG_SEVERITY_LOW:
        std::cout << "LOW] ";
        break;
    case GL_DEBUG_SEVERITY_NOTIFICATION:
        std::cout << "INFO] ";
        break;
    default:
        std::cout << severity << "] ";
        break;
    }
    switch(source){
    case GL_DEBUG_SOURCE_API:
        std::cout << "<API> ";
        break;
    case GL_DEBUG_SOURCE_APPLICATION:
        std::cout << "<APPLICATION> ";
        break;
    case GL_DEBUG_SOURCE_SHADER_COMPILER:
        std::cout << "<SHADER COMPILER> ";
        break;
    default:
        std::cout << "<" << source << "> ";
        break;
    }

    std::cout << message << "\n";
}

OpenGLCoreApp::OpenGLCoreApp()
{
    antialiasing = 4;
    width = 800;
    height = 600;
    title = "OpenGL core app";
    frame = 0;
    cameraMatrix = glm::translate(glm::mat4(1.0), glm::vec3(0, 0, -3.0));
    projectionMatrix = glm::frustum(-1.0, 1.0, (height * -1.0)/width, (height * 1.0)/width, 1.0, 10.0);
}

OpenGLCoreApp::~OpenGLCoreApp()
{
    for(auto actor : actors)
        delete actor;
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

    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(MessageCallback, 0);

    shader = new Shader("shaders/simpleShader.vert", "shaders/simpleShader.frag");

    glClearColor(.0f, .0f, .0f, .0f);
    actors.push_back(new Trapeze(shader));
    actors.push_back(new Triangle(std::vector<Vertex>{Vertex(-0.5, -0.75, 0), Vertex(0.5, -0.75, 0), Vertex(0, 0.25, 0)}));
}

void OpenGLCoreApp::mainLoop(){
    do{
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glUseProgram(shader->getShaderId());

        auto faza = glGetUniformLocation(shader->getShaderId(), "faza");
        glUniform1f(faza, frame * 0.1);

        for(const auto actor : actors)
            actor->draw(cameraMatrix, projectionMatrix);

        // Swap buffers
        glfwSwapBuffers(window);
        frame++;
        glfwPollEvents();
    } while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
}
