#ifndef TRAPEZE_H
#define TRAPEZE_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include "vertex.h"
#include "aktor.h"
#include "shader.h"
#include <vector>

class Trapeze: public Aktor
{
private:
    unsigned int vao;
    unsigned int vbo[2];

    std::vector<Vertex> vertexArray;
    unsigned int index[4];
    void loadData();
    glm::mat4 macierzSceny;

    Shader* shader;
public:
    Trapeze(Shader* shader);
    virtual ~Trapeze();
    void draw(glm::mat4 camMatrix, glm::mat4 projectionMatrix);
};

#endif // TRAPEZE_H
