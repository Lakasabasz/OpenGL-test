#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "aktor.h"
#include "vertex.h"
#include <glm/glm.hpp>
#include <vector>

class Triangle: public Aktor
{
private:
    Vertex vertexArray[3];
    GLuint indexes[3];
    GLuint vao;
    GLuint vbo[2];
    void loadData();
    glm::mat4 macierzSceny;
    Shader* shader;
public:
    Triangle(Shader* shader);
    Triangle(Shader* shader, std::vector<Vertex> coords);
    virtual ~Triangle();
    virtual void draw(glm::mat4 camMatrix, glm::mat4 projectionMatrix) override;
    virtual void move(glm::vec3 direction) override;
    virtual void setPosition(glm::vec3 position) override;
    virtual void rotate(float degrees, glm::vec3 vectorAngle, bool radians = false);
};

#endif // TRIANGLE_H
