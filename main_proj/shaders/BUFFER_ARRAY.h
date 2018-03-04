/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BUFFER_ARRAY.h
 * Author: Tal
 *
 * Created on March 2, 2018, 8:22 PM
 */

#ifndef BUFFER_ARRAY_H
#define BUFFER_ARRAY_H

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <vector>

using namespace std;

typedef struct {
    GLuint      vbo_index;
    GLenum      target;
} VBO_ID_T;

class BUFFER_ARRAY{
private:
    GLuint              vao;
    vector<VBO_ID_T>    vbo;
public:
    void generate_vao();
    void bind_buffer();
    GLuint create_buffer(GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage);
    GLuint buffer_attribute(GLuint index, GLuint location, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer);
    GLuint get_index();
    GLuint get_vao();
    ~BUFFER_ARRAY();
};

#endif /* BUFFER_ARRAY_H */

