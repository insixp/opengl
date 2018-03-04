/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PROGRAM.cpp
 * Author: Tal
 * 
 * Created on March 2, 2018, 8:22 PM
 */

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>

//  Classes
#include "PROGRAM.h"

//  Headers
#include "../utils/utils.h"

using namespace std;

void unuse_program(){
    glUseProgram(0);
}

//  Program
PROGRAM::PROGRAM(){
    this->_program_id   = glCreateProgram();
    DetectGLError("couldn't create program.");
    cout << "Program(" << this->_program_id << ") Created" << endl;
}

void PROGRAM::attach_shader(SHADER shader){
    glAttachShader(this->_program_id, shader.get_id());
    DetectGLError("couldn't Attach shader.");
    this->shaders.push_back(shader);
    cout << "SHADER(" << shader.get_id() << ") Attached to Program(" << this->_program_id << ")" << endl;
}

void PROGRAM::link(){
    glLinkProgram(this->_program_id);
    DetectGLError("couldn't link program.");
    cout << "Program(" << this->_program_id << ") is Linked" << endl;
}

void PROGRAM::use(){
    glUseProgram(this->_program_id);
    DetectGLError("Couldn`t use program.");
}

GLuint PROGRAM::get_id(){
    return this->_program_id;
}

PROGRAM::~PROGRAM(){
    //  Detach
    for(int i = 0; i < shaders.size(); i++){
        glDetachShader(this->_program_id, this->shaders.back().get_id());
        this->shaders.pop_back();
    }

    //  Delete program
    glDeleteProgram(this->_program_id);
}
