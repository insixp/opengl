/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CUBE.h
 * Author: Tal
 *
 * Created on March 2, 2018, 8:19 PM
 */

#ifndef CUBE_H
#define CUBE_H

#include <glm/glm.hpp>

//  Classes
#include "../shaders/BUFFER_ARRAY.h"

//  Headers
#include "3d_primitives.h"

using namespace glm;


class CUBE{
private:
    VERTEX          *vertecies;
    GLubyte         *indices;
    BUFFER_ARRAY    buffer_array;
    mat4            model_matrix;
    GLuint          model_matrix_uniform_loc;

public:
    CUBE();
    CUBE(const VERTEX vertecies[CUBE_VERTECIES], const GLubyte indices[CUBE_INDECES]);
    void set_model_matrix(mat4 new_model_matrix);
    mat4 get_model_matrix();
    void draw_cube();
    virtual ~CUBE();

};

#endif /* CUBE_H */

