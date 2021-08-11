#ifndef AKTOR_H
#define AKTOR_H

#include <GL/glew.h>
#include "openglobject.h"

class Aktor : public OpenGLObject
{
protected:
    GLuint vao;
    GLuint vbo[2];
public:
    Aktor();
    void initBuffers();
    virtual void loadData() = 0;
    virtual void draw() = 0;

};

#endif // AKTOR_H
