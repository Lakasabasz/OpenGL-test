#ifndef WERTEX_H
#define WERTEX_H

struct Vertex{
    // Coords
    float x;
    float y;
    float z;

    float r;
    float g;
    float b;
    float a = 1.0;

    static const int coordsCount = 3;
    static const int sizeOfCoords = sizeof(float)*coordsCount;
    static const int colorCount = 4;
    static const int sizeOfColor = sizeof(float)*colorCount;
    static const int size = sizeOfColor + sizeOfCoords;

    Vertex(float x, float y, float z) : x(x), y(y), z(z), r(0.5), g(1), b(0), a(1){}
    Vertex(float x, float y, float z, float r, float g, float b, float a = 1.0) : x(x), y(y), z(z), r(r), g(g), b(b), a(a){}
};

#endif // WERTEX_H
