#include "camera.h"

Camera::Camera(Shader shader) {
    this->cameraShader = &shader;
    projectionMatrix = glm::perspective(glm::radians(45.0f), 400.0f/200.0f, 0.1f, 100.0f);
    this->cameraShader->pushMatrix4f(projectionMatrix, "projectionMatrix");
    viewMatrix = glm::translate(viewMatrix, glm::vec3(0.0f, 0.0f, -3.0f));
    this->cameraShader->pushMatrix4f(viewMatrix, "viewMatrix");
}

void Camera::update() {

}