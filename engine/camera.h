#ifndef BARBARIACLION_CAMERA_H
#define BARBARIACLION_CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

extern glm::mat4 cameraView;

class Camera {
public:
    Camera();
    void updateCamera(glm::vec3 cameraPosition, glm::vec3 cameraFront, glm::vec3 cameraUp);
protected:
    glm::vec3 upBuffer;
    glm::vec3 cameraPosition;
    glm::vec3 cameraTarget;
    glm::vec3 cameraFront;
    glm::vec3 cameraUp;
    glm::vec3 cameraDirection;
    glm::vec3 cameraSpaceY;
    glm::vec3 cameraSpaceX;
};

#endif //BARBARIACLION_CAMERA_H