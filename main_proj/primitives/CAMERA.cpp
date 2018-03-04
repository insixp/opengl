/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CAMERA.cpp
 * Author: Tal
 * 
 * Created on March 3, 2018, 3:00 AM
 */

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

//  Headers
#include "CAMERA.h"
#include "../globals.h"

using namespace glm;

CAMERA::CAMERA(vec3 position, vec3 focus)
{
    this->view_matrix   = lookAt(position, focus, vec3(0, 1, 0));
    this->position      = position;
    this->focus         = focus;
}

void CAMERA::set_position(vec3 position)
{
    this->position  = position;
}

void CAMERA::set_focus(vec3 focus)
{    
    this->focus  = focus;
}

vec3 CAMERA::get_position()
{
    return this->position;
}

vec3 CAMERA::get_focus()
{
    return this->focus;
}


void CAMERA::draw_camera(){
    this->view_matrix   = lookAt(position, focus, vec3(0, 1, 0));
    glUniformMatrix4fv(view_matrix_uniform_loc       , 1, GL_FALSE, value_ptr(this->view_matrix));
}

CAMERA::~CAMERA() {
}

