#version 330 core

in vec3 ourColor;
in vec2 TexCoord;

out vec4 color;

uniform sampler2D ourTexture;
uniform sampler2D ourTexture2;


void main() {

    color = mix(texture(ourTexture, TexCoord), texture(ourTexture2, vec2(TexCoord.x , -1.0f * TexCoord.y)), 0.0);
}