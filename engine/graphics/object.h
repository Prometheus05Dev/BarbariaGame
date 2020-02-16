#ifndef BARBARIA_OBJECT_H
#define BARBARIA_OBJECT_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Object {
public:
    Object(float *vertices, int verticesCount, unsigned int *indices, unsigned int indexCount);
    void scale(float x, float y, float z);
    void transform(float x, float y, float z);
    void rotate(float x, float y, float z, float degrees);
    void update();
    void bind();
protected:
private:
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
    unsigned int indexCount;
};


#endif //BARBARIA_OBJECT_H
