/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PROGRAM.h
 * Author: Tal
 *
 * Created on March 2, 2018, 8:22 PM
 */

#ifndef PROGRAM_H
#define PROGRAM_H

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <vector>

//  Classes
#include "SHADER.h"

using namespace std;

void unuse_program();
void unbind_buffer();

class PROGRAM{
private:
    GLuint                  _program_id;
    vector<SHADER>          shaders;

public:
    PROGRAM();
    void attach_shader(SHADER shader);
    void link();
    void use();
    GLuint  get_id();
    ~PROGRAM();
};

#endif /* PROGRAM_H */

