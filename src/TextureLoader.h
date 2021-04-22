//
// Created by Jeremiah Korreck on 7/12/20.
//

#ifndef OPENGL_TUT_TEXTURELOADER_H
#define OPENGL_TUT_TEXTURELOADER_H

#include <string>
#include <GL/glew.h>

class TextureLoader {
public:
    TextureLoader();
    ~TextureLoader();
    GLuint getTextureID(std::string  texFileName);
};


#endif //OPENGL_TUT_TEXTURELOADER_H
