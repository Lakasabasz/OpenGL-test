#include "openglobject.h"

OpenGLObject::OpenGLObject(){}

std::string OpenGLObject::lastCatchPoint = "";

void OpenGLObject::displayErrors(std::string catchPoint)
{
    GLenum err;
    while((err = glGetError()) != GL_NO_ERROR){
        //std::cout << "Catch point: " << catchPoint << " last catch point: " << lastCatchPoint << " OpenGL error " << err << std::endl;
    }
    lastCatchPoint = catchPoint;
}
