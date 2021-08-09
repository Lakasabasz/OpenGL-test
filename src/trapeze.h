#ifndef TRAPEZE_H
#define TRAPEZE_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include "vertex.h"


class Trapeze
{
private:
    unsigned int vao;
    unsigned int vbo;

    Vertex default_vertex[4];
public:
    Trapeze();
};

#endif // TRAPEZE_H
