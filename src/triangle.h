#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <GL/glew.h>
#include <glm/glm.hpp>

class Triangle
{
private:
    GLuint VBO;
    const GLfloat g_vertex_buffer_data[9] = {
            -1.0f, -1.0f, 0.0f,
            1.0f, -1.0f, 0.0f,
            0.0f,  1.0f, 0.0f
        };
public:
    Triangle();
    Triangle(glm::mat3 coords);
    GLuint getVertexBuffer();
};

#endif // TRIANGLE_H
