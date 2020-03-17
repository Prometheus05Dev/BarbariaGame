#include "camera.h"

float Camera::movementSpeed = 0.05f;
float Camera::mouseSensitivity = 0.1f;
float Camera::yaw = 0.0f;
float Camera::pitch = 0.0f;

Camera::Camera(Shader &shader) {
    cameraPosition = glm::vec3(0.0f, 0.0f, 3.0f);
    cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    cameraUP = glm::vec3(0.0f, 1.0f, 0.0f);
    cameraRight = glm::vec3(0.0f);
    worldUP = glm::vec3(0.0f, 1.0f, 0.0f);
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
}

void Camera::moveBackward() {
    cameraPosition -= movementSpeed * cameraFront;
}

void Camera::moveRight() {
    cameraPosition += glm::normalize(glm::cross(cameraFront, cameraUP)) * movementSpeed;
}

void Camera::moveLeft() {
    cameraPosition -= glm::normalize(glm::cross(cameraFront, cameraUP)) * movementSpeed;
}

void Camera::update() {
    cameraFront.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    cameraFront.y = sin(glm::radians(pitch));
    cameraFront.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    cameraFront = glm::normalize(cameraFront);
    cameraRight = glm::normalize(glm::cross(cameraFront, worldUP));
    cameraUP = glm::normalize(glm::cross(cameraRight, cameraFront));
    viewMatrix = glm::lookAt(cameraPosition, cameraPosition + cameraFront, cameraUP);
    this->cameraShader->pushMatrix4f(viewMatrix, "viewMatrix");
}

void Camera::processMouseMovement(float xOffSet, float yOffSet) {
    xOffSet *= mouseSensitivity;
    yOffSet *= mouseSensitivity;
    yaw += xOffSet;
    pitch += yOffSet;
    if(pitch > 89.0f)
        pitch = 89.0f;
    if(pitch < -89.0f)
        pitch = -89.0f;
}
