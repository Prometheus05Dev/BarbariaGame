#include "camera.h"

float Camera::movementSpeed = 0.05f;

Camera::Camera(Shader &shader) {
    cameraPosition = glm::vec3(0.0f, 0.0f, 3.0f);
    cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    cameraUP = glm::vec3(0.0f, 1.0f, 0.0f);
    projectionMatrix = glm::mat4(1.0f);
    viewMatrix = glm::mat4(1.0f);
    this->cameraShader = &shader;
    projectionMatrix = glm::perspective(glm::radians(45.0f), 400.0f/200.0f, 0.1f, 100.0f);
    this->cameraShader->pushMatrix4f(projectionMatrix, "projectionMatrix");
    viewMatrix = glm::translate(viewMatrix, glm::vec3(0.0f, 0.0f, -3.0f));
    this->cameraShader->pushMatrix4f(viewMatrix, "viewMatrix");
}

void Camera::moveForward() {
    cameraPosition += movementSpeed * cameraFront;
    this->update();
}

void Camera::moveBackward() {
    cameraPosition -= movementSpeed * cameraFront;
    this->update();
}

void Camera::moveRight() {
    cameraPosition += glm::normalize(glm::cross(cameraFront, cameraUP)) * movementSpeed;
    this->update();
}

void Camera::moveLeft() {
    cameraPosition -= glm::normalize(glm::cross(cameraFront, cameraUP)) * movementSpeed;
    this->update();
}

void Camera::update() {
    viewMatrix = glm::lookAt(cameraPosition, cameraPosition + cameraFront, cameraUP);
    this->cameraShader->pushMatrix4f(viewMatrix, "viewMatrix");
}