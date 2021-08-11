#include "openglcoreapp.h"
#include <stdexcept>
#include <iostream>

void GLAPIENTRY
MessageCallback( GLenum source,
                 GLenum type,
                 GLuint id,
                 GLenum severity,
                 GLsizei length,
                 const GLchar* message,
                 const void* userParam )
{
  fprintf( stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
           ( type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "" ),
            type, severity, message );
}

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
    delete trapez;
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
    glClearColor(.0f, .0f, .0f, .0f);
    trapez = new Trapeze();
    triangle = new Triangle(std::vector<Vertex>{Vertex(-0.5, -0.75, 0), Vertex(0.5, -0.75, 0), Vertex(0, 0.25, 0)});
    //triangle = new Triangle();

    shader = new Shader("shaders/simpleShader.vert", "shaders/simpleShader.frag");
}

void OpenGLCoreApp::mainLoop(){
    do{
        displayErrors("Begin main loop");
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glUseProgram(shader->getShaderId());
        auto faza = glGetUniformLocation(shader->getShaderId(), "faza");
        glUniform1f(faza, frame * 0.1);

        //trapez->draw();
        triangle->draw();

        // Swap buffers
        glfwSwapBuffers(window);
        frame++;
        glfwPollEvents();
    } while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
}
