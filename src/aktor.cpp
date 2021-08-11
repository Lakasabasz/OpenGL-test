#include "aktor.h"
#include <iostream>

Aktor::Aktor()
{
    initBuffers();
}

void Aktor::initBuffers()
{
    glGenVertexArrays(1, &vao);
    glGenBuffers(2, vbo);
}
