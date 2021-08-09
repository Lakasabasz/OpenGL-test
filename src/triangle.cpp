#include "triangle.h"
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <iostream>

Triangle::Triangle()
{
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
}

Triangle::Triangle(glm::mat3 coords)
{
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*9 + sizeof(this->deafult_colors), nullptr, GL_STATIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(float)*9, glm::value_ptr(glm::transpose(glm::transpose(coords))));
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(float)*9, sizeof(this->deafult_colors), this->deafult_colors);
}

GLuint Triangle::getVBO()
{
    return VBO;
}

void Triangle::draw()
{
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, 0, reinterpret_cast<const void*>(sizeof(float)*9));
    glEnableVertexAttribArray(3);


    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableVertexAttribArray(3);
    glDisableVertexAttribArray(0);
}
