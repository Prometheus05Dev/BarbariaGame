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
    static void processMouseMovement(float xOffSet, float yOffSet);
    void update();
    static void updateMouse();
protected:
private:
    static float movementSpeed;
    static float mouseSensitivity;
    static float yaw;
    static float pitch;
    Shader *cameraShader;
    glm::vec3 cameraPosition;
    glm::vec3 worldUP;
    glm::vec3 cameraFront;
    glm::vec3 cameraUP;
    glm::vec3 cameraRight;
    glm::mat4 projectionMatrix;
    glm::mat4 viewMatrix;
};

#endif //BARBARIA_CAMERA_H
