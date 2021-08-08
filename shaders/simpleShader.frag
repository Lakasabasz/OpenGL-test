#version 450 core
out vec3 color;
in vec3 pozycja;

float czestotliwosc = 10.0;
uniform float faza = 0.0;
float amplituda = 0.25;
float przesuniecie = -0.5;

void main(void)
{
    if(pozycja.y < amplituda * sin(czestotliwosc * pozycja.x + faza) + przesuniecie) color = vec3(1.0, 1.0, 0.25);
    else color = vec3(1, 0.25, 0);
}
