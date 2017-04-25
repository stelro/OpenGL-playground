//
// Created by stel on 25/3/2017.
//

#ifndef OPENGLTUTORIAL_SHADERPROGRAM_H
#define OPENGLTUTORIAL_SHADERPROGRAM_H

#include <string>
#include <GL/glew.h>


class ShaderProgram {
public:
    ShaderProgram();
    ~ShaderProgram();

    bool loadShaders(const std::string& vertexShader, const std::string& fragmentShader);
    void useShaderProgram();
    GLuint& getShaderProgram() { return m_Program; }
    void refreshShaders();

private:

    bool checkCompileErrors(GLuint& shader_id);
    bool checkLinkStatus();

    GLuint m_Program;
    GLuint m_VertexShader;
    GLuint m_FragmentShader;

    std::string m_VertexShaderPath;
    std::string m_FragmentShaderPath;

};


#endif //OPENGLTUTORIAL_SHADERPROGRAM_H
