#include "trapeze.h"
#include <iostream>

Trapeze::Trapeze()
    : vertexArray({Vertex(-0.25, 0.5, 0), Vertex(0.25, 0.5, 0), Vertex(0.5, -0.5, 0), Vertex(-0.5, -0.5, 0)}), index{1, 0, 2, 3}
{
    for(auto& v : vertexArray){
        v.r = 1;
        v.g = 0.5;
        v.b = 0;
    }
    loadData();
}

Trapeze::~Trapeze(){}

void Trapeze::loadData()
{
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
    glBufferData(GL_ARRAY_BUFFER, Vertex::size * 3, vertexArray.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index), index, GL_STATIC_DRAW);
}

void Trapeze::draw()
{
    glBindVertexArray(vao);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[1]);
    glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
    glVertexAttribPointer(0, Vertex::coordsCount, GL_FLOAT, GL_FALSE, Vertex::size, 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(3, Vertex::colorCount, GL_FLOAT, GL_FALSE, Vertex::size, reinterpret_cast<const void*>(Vertex::sizeOfCoords));
    glEnableVertexAttribArray(3);

    glDrawElements(GL_TRIANGLE_STRIP, 3, GL_UNSIGNED_INT, 0);
    glDisableVertexAttribArray(3);
    glDisableVertexAttribArray(0);
}
