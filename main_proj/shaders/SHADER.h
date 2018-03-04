/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SHADER.h
 * Author: Tal
 *
 * Created on March 2, 2018, 8:22 PM
 */

#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <GL/freeglut.h>

class SHADER{
private:
    GLuint   _shader_id;

public:
    SHADER();
    SHADER(const char* filename, GLenum share_type);
    GLuint  get_id();
    ~SHADER();
};

#endif /* SHADER_H */

