#version 330 core

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform Light light;

uniform Material material;


in vec3 Normals;
in vec3 FragPos;
in vec3 LightPos;

out vec4 color;

uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 viewPos;

void main()
{
    // Ambient
       vec3 ambient = light.ambient * material.ambient;

       // Diffuse
       vec3 norm = normalize(Normals);
       vec3 lightDir = normalize(LightPos - FragPos);
       float diff = max(dot(norm, lightDir), 0.0);
       vec3 diffuse = light.diffuse * (diff * material.diffuse);

       // Specular
       vec3 viewDir = normalize(viewPos - FragPos);
       vec3 reflectDir = reflect(-lightDir, norm);
       float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
       vec3 specular = light.specular * (spec * material.specular);

       vec3 result = ambient + diffuse + specular;
       color = vec4(result, 1.0f);
}