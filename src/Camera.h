//
// Created by Jeremiah Korreck on 7/11/20.
//

#ifndef OPENGL_TUT_CAMERA_H
#define OPENGL_TUT_CAMERA_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:

    Camera(GLfloat FOV, GLfloat width, GLfloat height, GLfloat nearplane, GLfloat farPlane, glm::vec3 camPos);
    ~Camera();

    glm::mat4 getViewMatrix();
    glm::mat4 getprojectionMatrix();
    glm::vec3 getCameraPosition();


private:


    glm::mat4 viewMatrix;
    glm::mat4 projectionMatrix;
    glm::vec3 cameraPos;


};


#endif //OPENGL_TUT_CAMERA_H
