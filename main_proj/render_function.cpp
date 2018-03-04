/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   render_function.cpp
 * Author: Tal
 *
 * Created on March 2, 2018, 8:33 PM
 */

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>

//  Classes
#include "primitives/CUBE.h"
#include "shaders/SHADER.h"

//  Headers
#include "globals.h"

using namespace glm;

void render_function(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    main_program->use();
    camera->draw_camera();
    cube->draw_cube();
    unuse_program();
    glutSwapBuffers();
    glutPostRedisplay();
}