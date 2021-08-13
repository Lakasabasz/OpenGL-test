#ifndef AKTOR_H
#define AKTOR_H

#include <GL/glew.h>
#include <glm/mat4x4.hpp>
#include "openglobject.h"
#include "shader.h"

class Aktor : public virtual OpenGLObject
{
public:
    virtual void draw(glm::mat4 camMatrix, glm::mat4 projectionMatrix) = 0;
    virtual void move(glm::vec3);
    virtual void setPosition(glm::vec3);
    virtual void rotate(float degrees, glm::vec3 vectorAngle, bool radians = false);
    virtual ~Aktor();
};

typedef Aktor Actor;

#endif // AKTOR_H
