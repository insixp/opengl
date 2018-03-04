/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <string.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

#include "main.h"
#include "globals.h"

int window_width    = 800;
int window_height   = 600;

int main(int argc, char* argv[])
{
    initialize(argc, argv);

    glutMainLoop();

    exit(EXIT_SUCCESS);
}

void initialize(int argc, char* argv[])
{
    GLenum GlewInitResult;

    init_window(argc, argv);

    glewExperimental = GL_TRUE;
    GlewInitResult   = glewInit();

    if (GLEW_OK != GlewInitResult) {
        fprintf(
        stderr,
        "ERROR: %s\n",
        glewGetErrorString(GlewInitResult)
        );
        exit(EXIT_FAILURE);
    }

    fprintf(
        stdout,
        "INFO: OpenGL Version: %s\n",
        glGetString(GL_VERSION)
    );

    glGetError();
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    load_function();
}

void init_window(int argc, char* argv[])
{
    glutInit(&argc, argv);

    glutInitContextVersion(4, 0);
    glutInitContextFlags(GLUT_FORWARD_COMPATIBLE);
    glutInitContextProfile(GLUT_CORE_PROFILE);

    glutSetOption(
    GLUT_ACTION_ON_WINDOW_CLOSE,
    GLUT_ACTION_GLUTMAINLOOP_RETURNS
    );

    glutInitWindowSize(window_width, window_height);

    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

    int WindowHandle = glutCreateWindow(WINDOW_TITLE_PREFIX);

    if(WindowHandle < 1) {
        fprintf(
            stderr,
            "ERROR: Could not create a new rendering window.\n"
        );
        exit(EXIT_FAILURE);
    }

    glutReshapeFunc(resize_function);
    glutDisplayFunc(render_function);
    glutKeyboardFunc(keyboard_function);
    glutCloseFunc(close_function);
}