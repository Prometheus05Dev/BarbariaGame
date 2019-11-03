#version 330 core

in vec4 vertexColor;
in vec2 v_textureCoordinates;

out vec4 fragmentColor;

uniform sampler2D u_texture;

void main() {
    vec4 textureColor = texture(u_texture, v_textureCoordinates);
    fragmentColor = textureColor;
}
