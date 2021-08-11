#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "aktor.h"
#include "vertex.h"
#include <glm/glm.hpp>
#include <vector>

class Triangle: public Aktor
{
private:
    Vertex vertexArray[3];
    GLuint indexes[3];
public:
    Triangle();
    Triangle(std::vector<Vertex> coords);
    virtual ~Triangle();
    void loadData();
    void draw();
};

#endif // TRIANGLE_H
