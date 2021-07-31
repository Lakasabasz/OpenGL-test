#ifndef SHADERLOADEXCEPT_H
#define SHADERLOADEXCEPT_H
#include <string>
#include <stdexcept>

class ShaderLoadExcept : public std::runtime_error
{
private:
    std::string reason;
public:
    enum ReasonType{
        LOAD, COMPILE, LINK
    };
    ShaderLoadExcept(std::string vertexPath, ShaderLoadExcept::ReasonType type);
    const char* what() const throw();
};

#endif // SHADERLOADEXCEPT_H
