#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "ShaderProgram.h"

using namespace std;

int main()
{

    //SDL - OpenGL Initialization -------------------------------------------------------------------------------------
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_Window *window = nullptr;
    window = SDL_CreateWindow("Example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, SDL_WINDOW_OPENGL);
    SDL_GLContext glContext = SDL_GL_CreateContext(window);
    glewInit();
    glClearColor(0.4f, 0.4f, 0.4f, 1.0f);
    //Window state
    bool w_state = true;
    SDL_Event e;
    //SDL - OpenGL Initialization End ---------------------------------------------------------------------------------


    GLfloat points[] = {
             0.0f,  0.5f, 0.0f,
             0.5f, -0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f
    };

    GLuint vbo = 0; // Create vertex buffer object
    glGenBuffers (1, &vbo); // generate vertex buffer object
    glBindBuffer (GL_ARRAY_BUFFER, vbo); // set vbo as the current buffer in OpenGL's state machine
    glBufferData (GL_ARRAY_BUFFER, sizeof (points), points, GL_STATIC_DRAW); // the buffer is the size of 9 floating point numbers
    //and we give the address of the first value

    GLuint vao = 0; //Create vertex array object
    glGenVertexArrays (1, &vao); // generate vertex array object
    glBindVertexArray (vao); // bind the vao to OpenGL's State machine
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);


    ShaderProgram shaderProgram;
    shaderProgram.loadShaders("Shaders/test.vert", "Shaders/test.frag");




    while (w_state) {

        //Wipe the drawing surfface clear
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shaderProgram.useShaderProgram();
        glBindVertexArray(vao);

        //draw points 0-3 from the currently bound VAO with current in-use shader
        glDrawArrays(GL_TRIANGLES, 0, 3);


        //Poll event ----------
        while(SDL_PollEvent(&e)) {
            if ((e.type == SDL_QUIT) || (e.key.keysym.sym == SDLK_ESCAPE)) {
                w_state = false;
            }
        } // While event
        //---------------------

        SDL_GL_SwapWindow(window);

    }

    return 0;
}