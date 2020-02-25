#ifndef BARBARIA_CAMERA_H
#define BARBARIA_CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"

class Camera {
public:
    Camera(Shader shader);
    void update();
protected:
private:
    Shader *cameraShader;
    glm::mat4 projectionMatrix = glm::mat4(1.0f);
    glm::mat4 viewMatrix = glm::mat4(1.0f);
};

#endif //BARBARIA_CAMERA_H
