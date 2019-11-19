#include "camera.h"

glm::mat4 cameraView(1.0f);
//new
Camera::Camera() {
    cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
    cameraDirection = glm::normalize(cameraPosition - cameraTarget);
    upBuffer = glm::vec3(0.0f, 1.0f, 0.0f);
    cameraSpaceX = glm::normalize(glm::cross(upBuffer, cameraDirection));
    cameraSpaceY = glm::cross(cameraDirection, cameraSpaceX);
}

void Camera::updateCamera(glm::vec3 cameraPosition, glm::vec3 cameraFront, glm::vec3 cameraUp) {
    cameraView = glm::lookAt(cameraPosition, cameraPosition + cameraFront, cameraUp);
}