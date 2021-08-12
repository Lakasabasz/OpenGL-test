#version 450 core
layout(location = 0) in vec3 vertexPosition; //Lokalna pozycja (wewnątrz modelu)
layout(location = 3) in vec4 color_in;

out vec4 pozycja;
out vec4 vcolor;
uniform mat4 macierzSceny = mat4(1.0); // Wsp lokalne -> globalne
uniform mat4 macierzWidoku = mat4(1.0); // Jak kamera widzi obiekt
uniform mat4 macierzRzutowania = mat4(1.0); // Izometryczna/Prespektywiczna
mat4 macierzMVP = macierzRzutowania * macierzWidoku * macierzSceny;

void main(){
    vec4 vLocalPosition = vec4(vertexPosition, 1.0);
    gl_Position = macierzMVP * vLocalPosition;
    pozycja = macierzSceny * vLocalPosition;
    vcolor = color_in;
}
