#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <string>

class Shader
{
private:
    GLuint shaderId;
public:
    Shader(std::string vertexShaderPath, std::string fragmentShaderPath);
    GLuint getShaderId() const;
};

#endif // SHADER_H
