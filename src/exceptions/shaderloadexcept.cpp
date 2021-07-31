#include "shaderloadexcept.h"
#include <iostream>

ShaderLoadExcept::ShaderLoadExcept(std::string shaderPath, ShaderLoadExcept::ReasonType type)
    : std::runtime_error("")
{
    switch (type) {
    case LOAD:
        reason = "[FATAL] Could not load shader at: " + shaderPath;
        break;
    case COMPILE:
        reason = "[FATAL] Could not compile shader from: " + shaderPath;
        break;
    case LINK:
        reason = "[FATAL] Could not link shaders form: " + shaderPath;
        break;
    default:
        reason = "[FATAL] Unknown reason (" + shaderPath + "";
        break;
    }
}

const char *ShaderLoadExcept::what() const throw()
{
    std::cout << reason << std::endl;
    std::cerr << reason << std::endl;
    return "";
}
