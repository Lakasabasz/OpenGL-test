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
    GLuint vao;
    GLuint vbo[2];
    void loadData();
public:
    Triangle();
    Triangle(std::vector<Vertex> coords);
    virtual ~Triangle();
    void draw(glm::mat4 camMatrix, glm::mat4 projectionMatrix);
};

#endif // TRIANGLE_H
