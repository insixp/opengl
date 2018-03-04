/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>

#include "utils.h"

void DetectGLError(const char* error_msg){
    GLuint  error_value = glGetError();

    while(error_value != GL_NO_ERROR){
        fprintf(stderr, "%s: %s\n", error_msg, gluErrorString(error_value));
        exit(EXIT_FAILURE);
    }
}
