#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <GL/glew.h>

class Triangle
{
private:
    GLuint VertexArrayID;
    GLuint vertexbuffer;
    const GLfloat g_vertex_buffer_data[9] = {
            -1.0f, -1.0f, 0.0f,
            1.0f, -1.0f, 0.0f,
            0.0f,  1.0f, 0.0f
        };
public:
    Triangle();
    GLuint getVertexBuffer();
};

#endif // TRIANGLE_H
