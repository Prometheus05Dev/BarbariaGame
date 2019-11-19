#version 330 core
layout(location = 0) in vec3 aPos;

uniform mat4 transform;
uniform mat4 view;
uniform mat4 projection;

//cameraLoc after view
//new

void main(){
    gl_Position = projection * view * transform * vec4(aPos.x, aPos.y, aPos.z, 1.0);
}