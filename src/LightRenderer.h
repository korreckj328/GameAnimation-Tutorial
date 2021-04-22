//
// Created by Jeremiah Korreck on 7/11/20.
//

#ifndef OPENGL_TUT_LIGHTRENDERER_H
#define OPENGL_TUT_LIGHTRENDERER_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Mesh.h"
#include "ShaderLoader.h"
#include "Camera.h"

class LightRenderer {
public:
    LightRenderer(MeshType meshType, Camera* camera);
    ~LightRenderer();
    void draw();
    void setPosition(glm::vec3 _position);
    void setColor(glm::vec3 _color);
    void setProgram(GLuint _program);
    glm::vec3 getPosition();
    glm::vec3 getColor();
private:
    Camera* camera;
    std::vector<Vertex>vertices;
    std::vector<GLuint>indices;
    glm::vec3 position, color;
    GLuint vbo, ebo, vao, program;
};


#endif //OPENGL_TUT_LIGHTRENDERER_H
