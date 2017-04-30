//C++ Includes
#include <iostream>

//OpenGL Includes
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <SOIL/SOIL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//Internal
#include "ShaderProgram.h"
#include "Camera.h"

const int WINDOW_WIDTH = 1024;
const int WINDOW_HEIGHT = 768;

GLfloat lastX = WINDOW_WIDTH/2;
GLfloat lastY = WINDOW_HEIGHT/2;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void do_movement();

//FPS Style camera
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));

GLfloat deltaTime = 0.0f;
GLfloat lastFrame = 0.0f;

bool firstMouse = true;

bool keys[1024];

glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
glm::vec3 lightColor(1.0f, 1.0f, 1.0f);

int main()
{
    //------------------------------OPENGL SETUP------------------------------------//
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Example", nullptr, nullptr);
    if (window == nullptr) {
        std::cerr << "Faild to create GLFW Window" << "\n";
        glfwTerminate();
        return -1;
    }


    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Faild to initialize GLEW" << "\n";
        return -1;
    }

    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    int width, height;
    glfwGetFramebufferSize(window, &width,&height);
    glViewport(0,0, WINDOW_WIDTH, WINDOW_HEIGHT);

    glEnable(GL_DEPTH_TEST);

    GLfloat vertices[] = {
            -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

            -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
            0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
            0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
            0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
            -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
            -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,

            -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

            0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
            0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
            0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
            0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
            0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
            0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

            -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
            0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
            0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
            0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

            -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
            0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
            0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
            0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
            -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
            -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
    };

    ShaderProgram objectShader, lampShader;
    objectShader.loadShaders("Shaders/objectVertex.glsl", "Shaders/objectFragment.glsl");
    lampShader.loadShaders("Shaders/lampVertex.glsl", "Shaders/lampFragment.glsl");

    GLuint vao, vbo;
    vao = vbo = 0;

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT,GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);

    //Lamp vao
    GLuint lampVao = 0;
    glGenVertexArrays(1, &lampVao);
    glBindVertexArray(lampVao);
    glBindBuffer(GL_ARRAY_BUFFER,vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);


    while (!glfwWindowShouldClose(window))
    {
        GLfloat currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glfwPollEvents();
        do_movement();

        //---------- OBJECT SHADER UNIFORMS --------------------//

        objectShader.useShaderProgram();
        glm::mat4 obj_model;
        glm::mat4 obj_view = camera.GetViewMatrix();
        glm::mat4 obj_proj = glm::perspective(camera.Zoom, (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, 0.1f, 100.0f);

        GLint modelLocation = glGetUniformLocation(objectShader.getShaderProgram(), "model");
        GLint viewLocation = glGetUniformLocation(objectShader.getShaderProgram(), "view");
        GLint projLocation = glGetUniformLocation(objectShader.getShaderProgram(), "projection");

        glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(obj_model));
        glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(obj_view));
        glUniformMatrix4fv(projLocation, 1, GL_FALSE, glm::value_ptr(obj_proj));

        GLint objectColorLoc = glGetUniformLocation(objectShader.getShaderProgram(), "objectColor");
        GLint objectLightColorLoc = glGetUniformLocation(objectShader.getShaderProgram(), "lightColor");
        GLint lightPosLoc = glGetUniformLocation(objectShader.getShaderProgram(), "lightPos");
        GLint viewPosLoc = glGetUniformLocation(objectShader.getShaderProgram(), "viewPos");

        glUniform3f(viewPosLoc, camera.Position.x, camera.Position.y, camera.Position.z);
        glUniform3f(lightPosLoc, lightPos.x, lightPos.y, lightPos.z);
        glUniform3f(objectColorLoc,1.0f, 0.5f, 0.31f);
        glUniform3f(objectLightColorLoc, lightColor.x, lightColor.y, lightColor.z);

        GLint matAmbientLoc  = glGetUniformLocation(objectShader.getShaderProgram(), "material.ambient");
        GLint matDiffuseLoc  = glGetUniformLocation(objectShader.getShaderProgram(), "material.diffuse");
        GLint matSpecularLoc = glGetUniformLocation(objectShader.getShaderProgram(), "material.specular");
        GLint matShineLoc    = glGetUniformLocation(objectShader.getShaderProgram(), "material.shininess");

        glUniform3f(matAmbientLoc,  0.24725f, 0.1995f, 0.0745f);
        glUniform3f(matDiffuseLoc,  0.75164f, 0.60648f, 0.22648f);
        glUniform3f(matSpecularLoc, 0.628281f, 0.555802f, 0.366065f);
        glUniform1f(matShineLoc,    0.4f);

        GLint lightAmbientLoc  = glGetUniformLocation(objectShader.getShaderProgram(), "light.ambient");
        GLint lightDiffuseLoc  = glGetUniformLocation(objectShader.getShaderProgram(), "light.diffuse");
        GLint lightSpecularLoc = glGetUniformLocation(objectShader.getShaderProgram(), "light.specular");

        glUniform3f(lightAmbientLoc,  1.0f, 1.0f, 1.0f);
        glUniform3f(lightDiffuseLoc,  1.0f, 1.0f, 1.0f); // Let's darken the light a bit to fit the scene
        glUniform3f(lightSpecularLoc, 1.0f, 1.0f, 1.0f);

        //------------------------------------------------------//

        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glBindVertexArray(0);

        //-------- Light Shader uniforms ------------------------//

        lampShader.useShaderProgram();
        obj_model = glm::mat4();
        obj_model = glm::translate(obj_model, lightPos);
        obj_model = glm::scale(obj_model, glm::vec3(0.2f));

        modelLocation = glGetUniformLocation(lampShader.getShaderProgram(), "model");
        viewLocation = glGetUniformLocation(lampShader.getShaderProgram(), "view");
        projLocation = glGetUniformLocation(lampShader.getShaderProgram(), "projection");

        glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(obj_model));
        glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(obj_view));
        glUniformMatrix4fv(projLocation, 1, GL_FALSE, glm::value_ptr(obj_proj));

        objectLightColorLoc = glGetUniformLocation(lampShader.getShaderProgram(), "lightColor");
        glUniform3f(objectLightColorLoc, lightColor.x, lightColor.y, lightColor.z);

        glBindVertexArray(lampVao);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glBindVertexArray(0);

        //-------------------------------------------------------//


        glfwSwapBuffers(window);
    }


    glfwTerminate();

    return 0;

}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }


    if(action == GLFW_PRESS)
        keys[key] = true;
    else if(action == GLFW_RELEASE) {
        keys[key] = false;
    }

}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{

    if(firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    GLfloat xoffset = xpos - lastX;
    GLfloat yoffset = lastY - ypos;  // Reversed since y-coordinates go from bottom to left

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(yoffset);

}

void do_movement()
{
    // Camera controls
    if(keys[GLFW_KEY_W])
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if(keys[GLFW_KEY_S])
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if(keys[GLFW_KEY_A])
        camera.ProcessKeyboard(LEFT, deltaTime);
    if(keys[GLFW_KEY_D])
        camera.ProcessKeyboard(RIGHT, deltaTime);
}








