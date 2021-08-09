#version 450 core
out vec4 color;
in vec3 pozycja;
in vec4 vcolor;

float czestotliwosc = 10.0;
uniform float faza = 0.0;
float amplituda = 0.125;
float przesuniecie = -0.25;

void main(void)
{
    if(pozycja.y < amplituda * sin(czestotliwosc * pozycja.x + faza) + przesuniecie) color = vec4(1.0, 1.0, 0.25, 1.0);
    else color = vcolor;
}
