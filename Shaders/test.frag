#version 410

in vec3 colour;
out vec4 frag_color;

void main() {
   vec3 tmp_color = colour;
   tmp_color.r = sin(90);
    frag_color = vec4(tmp_color, 1.0);
}