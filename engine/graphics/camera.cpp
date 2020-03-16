#include "camera.h"

float Camera::movementSpeed = 0.05f;

Camera::Camera(Shader shader) {
    this->cameraShader = &shader;
    projectionMatrix = glm::perspective(glm::radians(45.0f), 400.0f/200.0f, 0.1f, 100.0f);
    this->cameraShader->pushMatrix4f(projectionMatrix, "projectionMatrix");
    viewMatrix = glm::translate(viewMatrix, glm::vec3(0.0f, 0.0f, -3.0f));
    this->cameraShader->pushMatrix4f(viewMatrix, "viewMatrix");
}

void Camera::moveForward() {
    std::cout << "Moving forward"  << std::endl;
    cameraPosition += movementSpeed * cameraFront;
    this->update();
}

void Camera::moveBackward() {
    std::cout << "Moving backward"  << std::endl;
    cameraPosition -= movementSpeed * cameraFront;
    this->update();
}

void Camera::moveRight() {
    std::cout << "Moving right"  << std::endl;
    cameraPosition += glm::normalize(glm::cross(cameraFront, cameraUP)) * movementSpeed;
    this->update();
}

void Camera::moveLeft() {
    std::cout << "Moving left"  << std::endl;
    cameraPosition -= glm::normalize(glm::cross(cameraFront, cameraUP)) * movementSpeed;
    this->update();
}

void Camera::update() {
    viewMatrix = glm::lookAt(cameraPosition, cameraPosition + cameraFront, cameraUP);
    this->cameraShader->pushMatrix4f(viewMatrix, "viewMatrix");
}