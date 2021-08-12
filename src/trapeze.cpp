#include "trapeze.h"
#include <iostream>
#include <glm/gtc/type_ptr.hpp>

Trapeze::Trapeze(Shader* shader)
    : vertexArray({Vertex(-0.25, 0.5, 0), Vertex(0.25, 0.5, 0), Vertex(0.5, -0.5, 0), Vertex(-0.5, -0.5, 0)}), index{1, 0, 2, 3}
{
    for(auto& v : vertexArray){
        v.r = 1;
        v.g = 0.5;
        v.b = 0;
    }
    loadData();
    this->shader = shader;
    macierzSceny = glm::mat4(1.0);
}

Trapeze::~Trapeze(){}

void Trapeze::loadData()
{
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glGenBuffers(2, vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
    glBufferData(GL_ARRAY_BUFFER, Vertex::size * 4, vertexArray.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index), index, GL_STATIC_DRAW);
    glVertexAttribPointer(0, Vertex::coordsCount, GL_FLOAT, GL_FALSE, Vertex::size, 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(3, Vertex::colorCount, GL_FLOAT, GL_FALSE, Vertex::size, reinterpret_cast<const void*>(Vertex::sizeOfCoords));
    glEnableVertexAttribArray(3);
}

void Trapeze::draw(glm::mat4 camMatrix, glm::mat4 projectionMatrix)
{
    auto scene = glGetUniformLocation(shader->getShaderId(), "macierzSceny");
    glUniformMatrix4fv(scene, 1, false, glm::value_ptr(macierzSceny));

    auto cam = glGetUniformLocation(shader->getShaderId(), "macierzWidoku");
    glUniformMatrix4fv(cam, 1, false, glm::value_ptr(camMatrix));

    auto proj = glGetUniformLocation(shader->getShaderId(), "macierzRzutowania");
    glUniformMatrix4fv(proj, 1, false, glm::value_ptr(projectionMatrix));

    glUseProgram(shader->getShaderId());
    glBindVertexArray(vao);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[1]);
    glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);

    glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, 0);
}
