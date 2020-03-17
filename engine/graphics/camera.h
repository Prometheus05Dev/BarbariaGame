#ifndef BARBARIA_CAMERA_H
#define BARBARIA_CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"

class Camera {
public:
    Camera(Shader &shader);
    void moveForward();
    void moveBackward();
    void moveRight();
    void moveLeft();
    void update();
protected:
private:
    static float movementSpeed;
    Shader *cameraShader;
    glm::vec3 cameraPosition;
    glm::vec3 cameraFront;
    glm::vec3 cameraUP;
    glm::mat4 projectionMatrix;
    glm::mat4 viewMatrix;
};

#endif //BARBARIA_CAMERA_H
