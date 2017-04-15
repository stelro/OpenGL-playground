#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "ShaderProgram.h"
#include "DebugLog.h"
#include "FpsLimiter.h"
#include "InputHandler.h"
#include "maths_funcs.h"

#define M_PI 3.14159265359
#define ONE_DEG_IN_RAD (2.0 * M_PI) / 360.0

void log_gl_params () {

    GLenum params[] = {
            GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS,
            GL_MAX_CUBE_MAP_TEXTURE_SIZE,
            GL_MAX_DRAW_BUFFERS,
            GL_MAX_FRAGMENT_UNIFORM_COMPONENTS,
            GL_MAX_TEXTURE_IMAGE_UNITS,
            GL_MAX_TEXTURE_SIZE,
            GL_MAX_VARYING_FLOATS,
            GL_MAX_VERTEX_ATTRIBS,
            GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS,
            GL_MAX_VERTEX_UNIFORM_COMPONENTS,
            GL_MAX_VIEWPORT_DIMS,
            GL_STEREO,
    };

    const char *names[] = {
            "GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS",
            "GL_MAX_CUBE_MAP_TEXTURE_SIZE",
            "GL_MAX_DRAW_BUFFERS",
            "GL_MAX_FRAGMENT_UNIFORM_COMPONENTS",
            "GL_MAX_TEXTURE_IMAGE_UNITS",
            "GL_MAX_TEXTURE_SIZE",
            "GL_MAX_VARYING_FLOATS",
            "GL_MAX_VERTEX_ATTRIBS",
            "GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS",
            "GL_MAX_VERTEX_UNIFORM_COMPONENTS",
            "GL_MAX_VIEWPORT_DIMS",
            "GL_STEREO",
    };

    gl_log("GL Context Params: \n");
    for (int i = 0; i < 10; i++) {
        int v = 0;
        glGetIntegerv(params[i], &v);
        gl_log("%s %i\n", names[i], v);
    }

    //others

    int v[2];
    v[0] = v[1] = 0;
    glGetIntegerv(params[10], v);
    gl_log("%s %i %i\n", names[10], v[0], v[1]);
    unsigned char s = 0;
    glGetBooleanv(params[11], &s);
    gl_log("%s %u\n", names[11], (unsigned int)s);
    gl_log("------------------------------------\n");
}


using namespace std;

int main()
{

    //SDL - OpenGL Initialization -------------------------------------------------------------------------------------
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_Window *window = nullptr;
    char title[128] = "Example";
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, SDL_WINDOW_OPENGL);
    SDL_GLContext glContext = SDL_GL_CreateContext(window);
    glewInit();
    glClearColor(0.6f, 0.6f, 0.8f, 1.0f);
    //Window state
    bool w_state = true;

    InputHandler *input = InputHandler::instance();

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CW);

    if (!restart_gl_log()) {
        exit(1);
    }
    //SDL - OpenGL Initialization End ---------------------------------------------------------------------------------

    GLfloat points[] = {
             0.0f,  0.5f, 0.0f,
             0.5f, -0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f,
    };

    GLfloat points2[] = {
            0.0f,  0.2f, -0.5f,
            0.2f, -0.2f, -0.5f,
            -0.2f, -0.2f, -0.5f,
    };


    GLfloat color[] = {
            1.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 1.0f,
    };

    GLfloat color2[] = {
            1.0f, 1.0f, 0.0f,
            0.0f, 1.0f, 0.0f,
            1.0f, 0.0f, 1.0f,
    };

    float matrix[] = {
            1.0f, 0.0f, 0.0f, 0.0f, //first column
            0.0f, 1.0f, 0.0f, 0.0f, //second column
            0.0f, 0.0f, 1.0f, 0.0f, //thrid column
            0.0f, 0.0f, 0.0f, 1.0f //fourth column
    };



    GLuint points_vbo = 0; // Create vertex buffer object
    glGenBuffers (1, &points_vbo); // generate vertex buffer object
    glBindBuffer (GL_ARRAY_BUFFER, points_vbo); // set vbo as the current buffer in OpenGL's state machine
    glBufferData (GL_ARRAY_BUFFER, sizeof (points), points, GL_STATIC_DRAW); // the buffer is the size of 9 floating point numbers
    //and we give the address of the first value

    GLuint color_vbo = 0;
    glGenBuffers(1, &color_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, color_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(color), color, GL_STATIC_DRAW);


    GLuint vao = 0; //Create vertex array object
    glGenVertexArrays (1, &vao); // generate vertex array object
    glBindVertexArray (vao); // bind the vao to OpenGL's State machine
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, points_vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, color_vbo);
    glVertexAttribPointer(1,3, GL_FLOAT, GL_FALSE, 0, NULL);

    GLuint points2_vb0 = 0;
    glGenBuffers(1, &points2_vb0);
    glBindBuffer(GL_ARRAY_BUFFER, points2_vb0);
    glBufferData(GL_ARRAY_BUFFER, sizeof(points2), points2, GL_STATIC_DRAW);

    GLuint color2_vbo = 0;
    glGenBuffers(1,&color2_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, color2_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(color2), color2, GL_STATIC_DRAW);

    GLuint vao2 = 0;
    glGenVertexArrays(1, &vao2);
    glBindVertexArray(vao2);
    glBindBuffer(GL_ARRAY_BUFFER, points2_vb0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 1, NULL);
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, color2_vbo);
    glVertexAttribPointer(1,3, GL_FLOAT, GL_FALSE, 1, NULL);


    ShaderProgram shaderProgram;
    shaderProgram.loadShaders("Shaders/test.vert", "Shaders/test.frag");

    int matrix_location = glGetUniformLocation(shaderProgram.getShaderProgram(), "matrix");
    glUseProgram(shaderProgram.getShaderProgram());
    glUniformMatrix4fv(matrix_location, 1, GL_FALSE, matrix);


    FpsLimiter fpsLimiter;


    double timer = 0.0f;
    int countedFrames = 0;
    timer = SDL_GetTicks();

    float cam_speed = 1.0f;
    float cam_yaw_speed = 10.0f;

    float cam_pos[] = {0.0f, 0.0f, 2.0f};
    float cam_yaw = 0.0f;

    mat4 T = translate(identity_mat4(), vec3(-cam_pos[0], -cam_pos[1], -cam_pos[2]));
    mat4 R = rotate_y_deg(identity_mat4(), -cam_yaw);
    mat4 view_mat = R * T;


    float near = 0.1f; //clipping plane
    float far = 100.0f; //clipping plane
    float fov = 67.0f * ONE_DEG_IN_RAD; // field of view
    float aspect = (float)1024 / (float)768; // aspect ratio
    float range = tan(fov * 0.5f) * near;
    float Sx = (2.0f * near) / (range * aspect + range * aspect);
    float Sy = near / range;
    float Sz = -(far + near) / (far - near);
    float Pz = -(2.0f * far * near) / (far - near);

    float proj_matrix[] = {
            Sx, 0.0f, 0.0f, 0.0f,
            0.0f, Sy, 0.0f, 0.0f,
            0.0f, 0.0f, Sz, -1.0f,
            0.0f, 0.0f, Pz, 0.0f
    };

    int view_mat_location = glGetUniformLocation(shaderProgram.getShaderProgram(), "view");
    glUseProgram(shaderProgram.getShaderProgram());
    glUniformMatrix4fv(view_mat_location, 1, GL_FALSE, view_mat.m);
    int proj_matrix_location = glGetUniformLocation(shaderProgram.getShaderProgram(), "proj");
    glUseProgram(shaderProgram.getShaderProgram());
    glUniformMatrix4fv(proj_matrix_location, 1, GL_FALSE, proj_matrix);

    double elapsed_seconds = 0.1f;
    FpsLimiter newtimer;

    newtimer.start();

    while (w_state) {


        fpsLimiter.start();
        //elapsed_seconds = newtimer.end();
        newtimer.start();


        //INPU HANDLER

        input->update();

        if (input->isHoldDown(SDLK_ESCAPE)) {
            w_state = false;
        }



        //INPUT HANDLER END

        //Wipe the drawing surfface clear
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shaderProgram.useShaderProgram();
        glBindVertexArray(vao);



        //draw points 0-3 from th currently bound VAO with current in-use shader
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glBindVertexArray(vao2);
        glDrawArrays(GL_TRIANGLES, 1, 3);

        // control keys
        bool cam_moved = false;
        if (input->isPressed(SDLK_a)) {
            cam_pos[0] -= cam_speed * elapsed_seconds;
            cam_moved = true;
        }
        if (input->isPressed(SDLK_d)) {
            cam_pos[0] += cam_speed * elapsed_seconds;
            cam_moved = true;
        }
        if (input->isPressed(SDLK_e) ) {
            cam_pos[1] += cam_speed * elapsed_seconds;
            cam_moved = true;
        }
        if (input->isPressed(SDLK_q)) {
            cam_pos[1] -= cam_speed * elapsed_seconds;
            cam_moved = true;
        }
        if (input->isPressed(SDLK_w)) {
            cam_pos[2] -= cam_speed * elapsed_seconds;
            cam_moved = true;
        }
        if (input->isPressed(SDLK_s)) {
            cam_pos[2] += cam_speed * elapsed_seconds;
            cam_moved = true;
        }
        if (input->isPressed(SDLK_r)) {
            cam_yaw += cam_yaw_speed * elapsed_seconds;
            cam_moved = true;
        }
        if (input->isPressed(SDLK_t)) {
            cam_yaw -= cam_yaw_speed * elapsed_seconds;
            cam_moved = true;
        }

        if (cam_moved) {
            mat4 T = translate (identity_mat4 (), vec3 (-cam_pos[0], -cam_pos[1], -cam_pos[2])); // cam translation
            mat4 R = rotate_y_deg (identity_mat4 (), -cam_yaw); //
            mat4 view_mat = R * T;
            glUniformMatrix4fv (view_mat_location, 1, GL_FALSE, view_mat.m);
        }

        float avgFPS = countedFrames / ((SDL_GetTicks() - timer) / 1000.f);
        if (avgFPS > 2000000) {
            avgFPS = 0;
        }

        sprintf(title, "opengl @ fps: %.2f", avgFPS);
        SDL_SetWindowTitle(window,title);


        SDL_GL_SwapWindow(window);

        ++countedFrames;
        fpsLimiter.end();

    }

    log_gl_params();

    return 0;
}