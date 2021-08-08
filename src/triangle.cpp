#include "triangle.h"
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <iostream>

Triangle::Triangle()
{
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
}

Triangle::Triangle(glm::mat3 coords)
{
    std::vector<float> dane;
    for(int i = 0; i<9; i++){
        dane.push_back(coords[i/3][i%3]);
    }
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, dane.size()*sizeof(float), dane.data(), GL_STATIC_DRAW);
}

GLuint Triangle::getVertexBuffer()
{
    return VBO;
}
