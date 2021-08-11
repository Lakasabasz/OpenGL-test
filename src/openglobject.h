#ifndef OPENGLOBJECT_H
#define OPENGLOBJECT_H

#include <GL/glew.h>
#include <string>
#include <iostream>

class OpenGLObject
{
public:
    static std::string lastCatchPoint;
    OpenGLObject();
    virtual void displayErrors(std::string catchPoint);
};

#endif // OPENGLOBJECT_H
