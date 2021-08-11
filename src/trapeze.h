#ifndef TRAPEZE_H
#define TRAPEZE_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include "vertex.h"
#include "aktor.h"
#include <vector>

class Trapeze: public Aktor
{
private:
    unsigned int vao;
    unsigned int vbo[2];

    std::vector<Vertex> vertexArray;
    unsigned int index[4];
public:
    Trapeze();
    virtual ~Trapeze();
    void loadData();
    void draw();
};

#endif // TRAPEZE_H
