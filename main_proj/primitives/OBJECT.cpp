/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OBJECT.cpp
 * Author: Tal
 * 
 * Created on March 3, 2018, 9:08 AM
 */

#include <string>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <iostream>

//  Classes
#include "../shaders/BUFFER_ARRAY.h"

//  Headers
#include "OBJECT.h"
#include "../utils/errors.h"

using namespace glm;

OBJECT::OBJECT(const char *filename) {
    
    this->file = fopen(filename, "rb");
    if(file == NULL){
        throw BAD_FILE;
    }
    
    char    line[MAX_WORD];
    int     res;
    while((res  = fscanf(this->file, "%s", line)) != EOF){
        //  Vertex
        if(strcmp(line, "v") == 0)
        {
            VERTEX    vertex;
            vertex.position.w   = 1.0;
            fscanf(this->file, "%f %f %f\n", &vertex.position.x, &vertex.position.y, &vertex.position.z);
            this->vertecis.push_back(vertex);
        }
        
        //  UV
        if(strcmp(line, "vt") == 0)
        {
            vec2    uv;
            fscanf(this->file, "%f %f\n", &uv.x, &uv.y);
            this->uvs.push_back(uv);
        }
        
        //  Norm
        if(strcmp(line, "vn") == 0)
        {
            vec3    normal;
            fscanf(this->file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
            this->normals.push_back(normal);
        }
        
        //  Index
        if(strcmp(line, "f") == 0)
        {
            GLuint  vertex_index[3];
            GLuint  normal_index[3];
            GLuint  uv_index[3];
            int matches = fscanf(this->file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertex_index[0], &uv_index[0], &normal_index[0], &vertex_index[1], &uv_index[1], &normal_index[1], &vertex_index[2], &uv_index[2], &normal_index[2]);
            if(matches != 9){
                cout << "couldn't parse file: " << filename << endl;
                throw BAD_FILE;
            }
            for(int i = 0; i < 3; i++){
                this->vertecis_index.push_back(vertex_index[i]);
                this->normals_index.push_back(normal_index[i]);
                this->uvs_index.push_back(uv_index[i]);
            }
        }
        
        
        //  Buffers handling
//        this->buffer_array  = BUFFER_ARRAY();
//        this->buffer_array.generate_vao();
//        this->buffer_array.bind_buffer();
//        this->buffer_array.create_buffer(GL_ARRAY_BUFFER, this->vertecis.size(), vertecies, GL_STATIC_DRAW);
//        this->buffer_array.buffer_attribute(0, 0, sizeof(vec4), GL_FLOAT, GL_FALSE, sizeof(vec4), (GLvoid*)0);
//        this->buffer_array.create_buffer(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLubyte) * CUBE_INDECES, indices, GL_STATIC_DRAW);
    }
}

OBJECT::~OBJECT() {
}

