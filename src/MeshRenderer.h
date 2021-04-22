//
// Created by Jeremiah Korreck on 7/12/20.
//

#ifndef OPENGL_TUT_MESHRENDERER_H
#define OPENGL_TUT_MESHRENDERER_H

#include <vector>
#include "Camera.h"
#include "LightRenderer.h"
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <btBulletDynamicsCommon.h>

class MeshRenderer {
public:
    MeshRenderer(MeshType modelType,
                std::string _name,
                Camera* _camera,
                btRigidBody *_rigidBody,
                LightRenderer *_light,
                float _specularStrength,
                float _ambientStrength);

    ~MeshRenderer();
    void draw();
    void setPosition(glm::vec3 _position);
    void setScale(glm::vec3 _scale);
    void setProgram(GLuint _program);
    void setTexture(GLuint _textureID);
    std::string name = "";
    btRigidBody *rigidBody;
private:
    std::vector<Vertex>vertices;
    std::vector<GLuint>indices;
    glm::mat4 modelMatrix;
    Camera* camera;
    glm::vec3 position, scale;
    GLuint vao, vbo, ebo, texture, program;
    LightRenderer *light;
    float ambientStrength, specularStrenth;
};


#endif //OPENGL_TUT_MESHRENDERER_H
