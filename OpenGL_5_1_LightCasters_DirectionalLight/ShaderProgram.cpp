//
// Created by stel on 25/3/2017.
//

#include "ShaderProgram.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

ShaderProgram::ShaderProgram()
        : m_Program(0)
        , m_VertexShader(0)
        , m_FragmentShader(0)
{

}

ShaderProgram::~ShaderProgram() {

    if (m_VertexShader != 0)    glDeleteShader(m_VertexShader);
    if (m_FragmentShader != 0)  glDeleteShader(m_FragmentShader);
    if (m_Program != 0)         glDeleteProgram(m_Program);
}

void ShaderProgram::useShaderProgram() {
    glUseProgram(m_Program);
}

bool ShaderProgram::loadShaders(const std::string &vertexShader, const std::string &fragmentShader) {

    m_VertexShaderPath = vertexShader;
    m_FragmentShaderPath = fragmentShader;

    std::ifstream vs(vertexShader);

    if (!vs.is_open()) {
        std::cerr << "Couldn't open vertex program: " << vertexShader << std::endl;
        exit(1);
    }

    std::ifstream fs(fragmentShader);

    if (!fs.is_open()) {
        std::cerr << "Couldn't open framment program: " << fragmentShader << std::endl;
        exit(1);
    }

    std::string line;

    std::string vertex_programme_str;
    std::string framgnet_programme_str;

    while(std::getline(vs, line)) {
        vertex_programme_str += line;
        vertex_programme_str += "\n";
    }

    line = "";

    while(std::getline(fs, line)) {
        framgnet_programme_str += line;
        framgnet_programme_str += "\n";
    }

    const char* vertex = vertex_programme_str.c_str();
    const char* fragment = framgnet_programme_str.c_str();

    m_VertexShader = glCreateShader(GL_VERTEX_SHADER);
    m_FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(m_VertexShader, 1, &vertex, nullptr);

    //Compile Shader
    glCompileShader(m_VertexShader);

    if (!checkCompileErrors(m_VertexShader)) {
        exit(1);
    }

    glShaderSource(m_FragmentShader, 1, &fragment, nullptr);
    glCompileShader(m_FragmentShader);

    if (!checkCompileErrors(m_FragmentShader)) {
        exit(1);
    }

    //Create shader programm
    m_Program = glCreateProgram();

    //Attach shaders
    glAttachShader(m_Program, m_VertexShader);
    glAttachShader(m_Program, m_FragmentShader);

    //Link shaders
    glLinkProgram(m_Program);

    if (!checkLinkStatus()) {
        exit(1);
    }

    vs.close();
    fs.close();
    return true;
}

bool ShaderProgram::checkCompileErrors(GLuint& shader_id) {

    //Check the compile status
    GLint vs_comipled;
    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &vs_comipled);

    if (!vs_comipled) {
        //if comiplation faild
        //Retrive the compiler message when compilation fails
        GLint infoLenght = 0;

        glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &infoLenght);

        if (infoLenght > 1) {

            char *infoLog = (char*)malloc(sizeof(char) * infoLenght);

            glGetShaderInfoLog(shader_id, infoLenght, nullptr, infoLog);
            std::cerr << "Error compiling shader " << std::endl;
            std::cerr << "Message error : " << infoLog << std::endl;
            free(infoLog);
        }

        glDeleteShader(shader_id);

        return false;
    }

    return true;

}

bool ShaderProgram::checkLinkStatus() {

    GLint linked;
    glGetProgramiv(m_Program, GL_LINK_STATUS, &linked);

    if (!linked) {

        GLint  infoLength = 0;

        glGetProgramiv(m_Program, GL_INFO_LOG_LENGTH, &infoLength);

        if (infoLength > 0) {

            char *infoLog = (char*)malloc(sizeof(char) * infoLength);
            glGetProgramInfoLog(m_Program, infoLength, NULL, infoLog);

            std::cerr << "Error Linking shaders" << std::endl;
            std::cerr << "Message error: " << infoLog << std::endl;

            free(infoLog);

        }

        glDeleteProgram(m_Program);
        return false;
    }

    return  true;

}

void ShaderProgram::refreshShaders() {

    if (m_VertexShader != 0)    glDeleteShader(m_VertexShader);
    if (m_FragmentShader != 0)  glDeleteShader(m_FragmentShader);
    if (m_Program != 0)         glDeleteProgram(m_Program);

    loadShaders(m_VertexShaderPath, m_FragmentShaderPath);

}



