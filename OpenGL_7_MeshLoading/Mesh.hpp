//
// Created by stel on 20/5/2017.
//

#ifndef OPENGLBOOK_MESH_HPP
#define OPENGLBOOK_MESH_HPP

#include <string>
#include <vector>

#include <glm/glm.hpp>
#include <GL/glew.h>

#include "shader.hpp"

struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec3 TexCoords;
};

struct Texture {
    GLuint id;
    std::string type;
};

class Mesh {
public:
    Mesh();
    ~Mesh();

    // Mesh Data
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    std::vector<Texture> textures;

    // Functions
    Mesh(const std::vector<Vertex>& _vertices, const std::vector<GLuint>& _indices,const std::vector<Texture>& _textures);
    void Draw(const Shader& shader);

private:
    // Render Data
    GLuint VAO, VBO, EBO;
    // Functions
    void setupMesh();
};


#endif //OPENGLBOOK_MESH_HPP
