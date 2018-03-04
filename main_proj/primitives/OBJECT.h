/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OBJECT.h
 * Author: Tal
 *
 * Created on March 3, 2018, 9:08 AM
 */

#ifndef OBJECT_H
#define OBJECT_H

#include <fstream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector>

//  Classes
#include "../shaders/BUFFER_ARRAY.h"

//  Headers
#include "3d_primitives.h"

using namespace std;
using namespace glm;

const int MAX_WORD    = 128;

class OBJECT {
private:
    BUFFER_ARRAY        buffer_array;
    FILE                *file;
    vector<VERTEX>      vertecis;
    vector<GLuint>      vertecis_index;
    vector<vec3>        normals;
    vector<GLuint>      normals_index;
    vector<vec2>        uvs;
    vector<GLuint>      uvs_index;
    
public:
    OBJECT(const char *filename);
    virtual ~OBJECT();
};

#endif /* OBJECT_H */

