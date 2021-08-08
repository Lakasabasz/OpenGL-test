#version 450 core
layout(location = 0) in vec3 vertexPosition_modelspace;

out vec3 pozycja;

void main(){
    gl_Position.xyz = vertexPosition_modelspace;
    pozycja = vertexPosition_modelspace;
    gl_Position.w = 1.0;
}
