#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normals;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform vec3 lightPos;

out vec3 Normals;
out vec3 FragPos;
out vec3 LightPos;

void main()
{
    gl_Position = projection * view * model * vec4(position, 1.0f);
    FragPos = vec3(view * model * vec4(position, 1.0f));
    Normals = mat3(transpose(inverse(view * model))) * normals;
    LightPos = vec3(view * vec4(lightPos, 1.0f));
}