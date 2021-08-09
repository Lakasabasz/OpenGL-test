#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <GL/glew.h>
#include <glm/glm.hpp>

class Triangle
{
private:
    GLuint VAO;
    GLuint VBO;
    const GLfloat g_vertex_buffer_data[9] = {
            -1.0f, -1.0f, 0.0f,
            1.0f, -1.0f, 0.0f,
            0.0f,  1.0f, 0.0f
        };
    const float deafult_colors[12] = {
        0, 1, 1, 1,
        0, 1, 1, 1,
        0, 1, 1, 1
    };
public:
    Triangle();
    Triangle(glm::mat3 coords);
    GLuint getVBO();
    void draw();
};

#endif // TRIANGLE_H
