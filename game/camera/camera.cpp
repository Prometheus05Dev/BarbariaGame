#include "camera.h"

Camera::Camera() {

}

void Camera::updateCamera() {
    viewMatrix = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUP);
}
