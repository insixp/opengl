/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BUFFER_ARRAY.cpp
 * Author: Tal
 * 
 * Created on March 2, 2018, 8:22 PM
 */

#include "BUFFER_ARRAY.h"
#include <GL/glew.h>
#include <GL/freeglut.h>

//  Headers
#include "../utils/utils.h"

void unbind_buffer(){
    glBindVertexArray(0);
}

//  Buffer array
void BUFFER_ARRAY::generate_vao(){
    glGenVertexArrays(1, &this->vao);
    DetectGLError("Can`t create Vertex array object");
}

void BUFFER_ARRAY::bind_buffer(){
    glBindVertexArray(this->vao);
    DetectGLError("Can`t bind buffer");
}

GLuint BUFFER_ARRAY::create_buffer(GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage){
    GLuint  vbo_id;
    glGenBuffers(1, &vbo_id);
    DetectGLError("Can`t generate buffer");
    glBindBuffer(target, vbo_id);
    glBufferData(target, size, data, usage);
    DetectGLError("Can`t bind vbo to vao");
    VBO_ID_T vbo_id_t   = {vbo_id, target};
    this->vbo.push_back(vbo_id_t);
}

GLuint BUFFER_ARRAY::buffer_attribute(GLuint index, GLuint location, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer){
    glBindBuffer(this->vbo[index].target, this->vbo[index].vbo_index);
    DetectGLError("Can`t bind vbo to vao");
    glVertexAttribPointer(location, size, type, normalized, stride, pointer);
    glEnableVertexAttribArray(location);
    DetectGLError("Can`t enable vertex attributes");
}

GLuint BUFFER_ARRAY::get_vao(){
    return this->vao;
}

BUFFER_ARRAY::~BUFFER_ARRAY(){
    for(int i = 0; i < this->vbo.size(); i++){
        glDeleteBuffers(1, &this->vbo[i].vbo_index);
    }
    glDeleteVertexArrays(1, &this->vao);
}