#version 330 core

layout(location = 0) in vec3 a_Pos;
layout(location = 1) in vec2 a_textureCoordinates;

out vec4 vertexColor;
out vec2 v_textureCoordinates;

uniform mat4 modelMatrix;

void main() {
    gl_Position = modelMatrix * vec4(a_Pos, 1.0f);
    vertexColor = vec4(0.5, 0.0, 0.0, 0.0);
    v_textureCoordinates = a_textureCoordinates;
}
