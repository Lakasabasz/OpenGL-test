#ifndef AKTOR_H
#define AKTOR_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include "openglobject.h"
#include "shader.h"

class Aktor : public virtual OpenGLObject
{
public:
    virtual void draw(glm::mat4 camMatrix, glm::mat4 projectionMatrix) = 0;
    virtual ~Aktor();
};

#endif // AKTOR_H
