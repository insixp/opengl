/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   3d_primitives.h
 * Author: Tal
 *
 * Created on March 2, 2018, 8:20 PM
 */

#ifndef _3D_PRIMITIVES_H
#define _3D_PRIMITIVES_H

#include <glm/glm.hpp>

using namespace glm;

const unsigned int CUBE_VERTECIES = 8;
const unsigned int CUBE_INDECES   = 36;

const int SIZEOF_POSITION   = 4;
const int SIZEOF_COLOR      = 4;

typedef struct
{
    vec4    position;
    vec4    color;
} VERTEX;

//typedef struct
//{
//    vec4    position;
//    vec2    uv;
//    vec3    normals;
//} VERTEX;

const int VERTEX_SIZE   = sizeof(VERTEX);

#endif /* _3D_PRIMITIVES_H */

