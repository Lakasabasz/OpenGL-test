#version 450 core
layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 3) in vec4 color_in;

out vec3 pozycja;
out vec4 vcolor;

void main(){
    gl_Position.xyz = vertexPosition_modelspace;
    gl_Position.w = 1.0;
    pozycja = vertexPosition_modelspace;
    vcolor = color_in;
}
