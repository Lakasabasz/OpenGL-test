#include "shader.h"
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <iostream>
#include <vector>

#include "exceptions/shaderloadexcept.h"

GLuint Shader::getShaderId() const
{
    return shaderId;
}

Shader::Shader(std::string vertexShaderPath, std::string fragmentShaderPath)
{
    GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    std::string vertexShaderCode;
    std::ifstream vertexShaderFS(vertexShaderPath, std::ios::in);
    if(!vertexShaderFS.is_open()){
        throw ShaderLoadExcept(vertexShaderPath, ShaderLoadExcept::LOAD);
    }

    std::stringstream vsstr;
    vsstr << vertexShaderFS.rdbuf();
    vertexShaderCode = vsstr.str();
    vertexShaderFS.close();


    std::string fragmentShaderCode;
    std::ifstream fragmentShaderFS(fragmentShaderPath, std::ios::in);
    if(!fragmentShaderFS.is_open()){
        throw ShaderLoadExcept(fragmentShaderPath, ShaderLoadExcept::LOAD);
    }

    std::stringstream fsstr;
    fsstr << fragmentShaderFS.rdbuf();
    fragmentShaderCode = fsstr.str();
    fragmentShaderFS.close();

    GLint result = GL_FALSE;
    int infoLogLength;

    std::cout << "[INFO] Compiling shader: " << vertexShaderPath << std::endl;
    char const * vertexSourcePtr = vertexShaderCode.c_str();
    glShaderSource(vertexShaderID, 1, &vertexSourcePtr, NULL);
    glCompileShader(vertexShaderID);

    // Check Vertex Shader
    glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &result);
    glGetShaderiv(vertexShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
    if(infoLogLength > 0){
        std::vector<char> vertexShaderErrorMessage(infoLogLength + 1);
        glGetShaderInfoLog(vertexShaderID, infoLogLength, NULL, &vertexShaderErrorMessage[0]);
        std::cout << std::string(vertexShaderErrorMessage.begin(), vertexShaderErrorMessage.end()) << std::endl;
    }

    std::cout << "[INFO] Compiling shader: " << fragmentShaderPath << std::endl;
    char const * fragmentSourcePtr = fragmentShaderCode.c_str();
    glShaderSource(fragmentShaderID, 1, &fragmentSourcePtr , NULL);
    glCompileShader(fragmentShaderID);

    glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &result);
    glGetShaderiv(fragmentShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
    if(infoLogLength > 0){
        std::vector<char> fragmentShaderErrorMessage(infoLogLength+1);
        glGetShaderInfoLog(fragmentShaderID, infoLogLength, NULL, &fragmentShaderErrorMessage[0]);
        std::cout << std::string(fragmentShaderErrorMessage.begin(), fragmentShaderErrorMessage.end()) << std::endl;
    }

    // Link the program
    std::cout << "[INFO] Linking program" << std::endl;
    GLuint programID = glCreateProgram();
    glAttachShader(programID, vertexShaderID);
    glAttachShader(programID, fragmentShaderID);
    glLinkProgram(programID);

    // Check the program
    glGetProgramiv(programID, GL_LINK_STATUS, &result);
    glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &infoLogLength);
    if(infoLogLength > 0){
        std::vector<char> programErrorMessage(infoLogLength+1);
        glGetProgramInfoLog(programID, infoLogLength, NULL, &programErrorMessage[0]);
        std::cout << std::string(programErrorMessage.begin(), programErrorMessage.end()) << std::endl;
    }

    glDetachShader(programID, vertexShaderID);
    glDetachShader(programID, fragmentShaderID);

    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);

    shaderId = programID;
}
