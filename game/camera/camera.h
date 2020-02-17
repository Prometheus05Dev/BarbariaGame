#ifndef BARBARIA_CAMERA_H
#define BARBARIA_CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "inputs_global.h"

class Camera {
public:
    Camera();
    void updateCamera();
    glm::mat4 viewMatrix;
protected:
private:
};

#endif //BARBARIA_CAMERA_H
