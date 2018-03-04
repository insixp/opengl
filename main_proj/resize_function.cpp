/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

//  Classes
#include "primitives/CUBE.h"
#include "shaders/PROGRAM.h"

//  Headers
#include "globals.h"

using namespace glm;

void resize_function(int Width, int Height)
{
    window_width = Width;
    window_height = Height;
    glViewport(0, 0, window_width, window_height);
    main_program->use();
    proj_matrix     = perspective( radians(80.0f), (float)window_width / window_height, 0.1f, 100.0f);
    glUniformMatrix4fv(proj_matrix_uniform_loc, 1, GL_FALSE, value_ptr(proj_matrix));
    unuse_program();
}