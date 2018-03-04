/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CUBE.cpp
 * Author: Tal
 * 
 * Created on March 2, 2018, 8:19 PM
 */

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/gtc/type_ptr.hpp>
#include <glm/glm.hpp>

//  Classes
#include "../shaders/BUFFER_ARRAY.h"

//  Headers
#include "3D_PRIMITIVES.h"
#include "CUBE.h"
#include "../globals.h"

using namespace glm;

CUBE::CUBE(){}

CUBE::CUBE(const VERTEX vertecies[CUBE_VERTECIES], const GLubyte indices[CUBE_INDECES]){
    this->buffer_array  = BUFFER_ARRAY();
    this->buffer_array.generate_vao();
    this->buffer_array.bind_buffer();
    this->buffer_array.create_buffer(GL_ARRAY_BUFFER, VERTEX_SIZE * CUBE_VERTECIES, vertecies, GL_STATIC_DRAW);
    this->buffer_array.buffer_attribute(0, 0, SIZEOF_POSITION, GL_FLOAT, GL_FALSE, sizeof(VERTEX), (GLvoid*)0);
    this->buffer_array.buffer_attribute(0, 1, SIZEOF_COLOR, GL_FLOAT, GL_FALSE, sizeof(VERTEX), (GLvoid*)SIZEOF_POSITION);
    this->buffer_array.create_buffer(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLubyte) * CUBE_INDECES, indices, GL_STATIC_DRAW);
    unbind_buffer();
    this->model_matrix              = mat4(1.0);
    this->model_matrix_uniform_loc  = glGetUniformLocation(main_program->get_id(), "ModelMatrix");
}

void CUBE::draw_cube(){
    this->buffer_array.bind_buffer();
    glUniformMatrix4fv(this->model_matrix_uniform_loc, 1, GL_FALSE, value_ptr(this->model_matrix));
    glDrawElements(GL_TRIANGLES, CUBE_INDECES, GL_UNSIGNED_BYTE, (GLvoid*)0);
    unbind_buffer();
}

void CUBE::set_model_matrix(mat4 new_model_matrix)
{
    this->model_matrix  = new_model_matrix;
}

mat4 CUBE::get_model_matrix()
{
    return this->model_matrix;
}

CUBE::~CUBE(){}

