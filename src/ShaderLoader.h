//
// Created by Jeremiah Korreck on 7/11/20.
//

#ifndef OPENGL_TUT_SHADERLOADER_H
#define OPENGL_TUT_SHADERLOADER_H

#include <GL/glew.h>
#include <string>

class ShaderLoader {
public:
    GLuint CreateProgram(const char* vertexShaderFilename,
                         const char* fragmentShaderFilename);
private:
    std::string readShader(const char *filename);
    GLuint createShader(GLenum shaderType,
                        std::string source,
                        const char* shaderName);
};


#endif //OPENGL_TUT_SHADERLOADER_H
