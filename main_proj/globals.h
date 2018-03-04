/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   globals.h
 * Author: Tal
 *
 * Created on March 2, 2018, 8:46 PM
 */

#ifndef GLOBALS_H
#define GLOBALS_H

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>

//  Classes
#include "primitives/CAMERA.h"
#include "primitives/CUBE.h"
#include "shaders/PROGRAM.h"

using namespace glm;

#define WINDOW_TITLE_PREFIX "Main project"

extern int          window_width;
extern int          window_height;

extern mat4         proj_matrix;
extern mat4         view_matrix;

extern GLuint       proj_matrix_uniform_loc;
extern GLuint       view_matrix_uniform_loc;

extern PROGRAM      *main_program;
extern CAMERA       *camera;
extern CUBE         *cube;

#endif /* GLOBALS_H */

