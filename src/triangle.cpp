#include "triangle.h"
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <iostream>

Triangle::Triangle(Shader *shader)
    : indexes{0, 1, 2}
{
    vertexArray[0] = Vertex(-1, -1, 0);
    vertexArray[1] = Vertex(1, -1, 0);
    vertexArray[2] = Vertex(0, 1, 0);
    this->shader = shader;
    macierzSceny = glm::mat4(1.0);
    loadData();
}

Triangle::Triangle(Shader *shader, std::vector<Vertex> coords)
    : indexes{0, 1, 2}
{
    for(auto i = 0ull; i<coords.size(); i++)
        vertexArray[i] = coords[i];
    this->shader = shader;
    macierzSceny = glm::mat4(1.0);
    loadData();
}

Triangle::~Triangle(){}

void Triangle::loadData()
{
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glGenBuffers(2, vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
    glBufferData(GL_ARRAY_BUFFER, Vertex::size * 3, vertexArray, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexes), indexes, GL_STATIC_DRAW);
    glVertexAttribPointer(0, Vertex::coordsCount, GL_FLOAT, GL_FALSE, Vertex::size, 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(3, Vertex::colorCount, GL_FLOAT, GL_FALSE, Vertex::size, reinterpret_cast<const void*>(Vertex::sizeOfCoords));
    glEnableVertexAttribArray(3);
}

void Triangle::draw(glm::mat4 camMatrix, glm::mat4 projectionMatrix)
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

    glDrawElements(GL_TRIANGLE_STRIP, 3, GL_UNSIGNED_INT, 0);
}

void Triangle::move(glm::vec3 direction)
{
    macierzSceny = glm::translate(macierzSceny, direction);
}

void Triangle::setPosition(glm::vec3 position)
{
    macierzSceny = glm::translate(glm::mat4(1.0), position);
}

void Triangle::rotate(float degrees, glm::vec3 vectorAngle, bool radians)
{
    if(radians) macierzSceny = glm::rotate(macierzSceny, degrees, vectorAngle);
    else macierzSceny = glm::rotate(macierzSceny, glm::radians(1.0f), vectorAngle);
}
