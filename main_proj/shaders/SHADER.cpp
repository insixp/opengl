/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SHADER.cpp
 * Author: Tal
 * 
 * Created on March 2, 2018, 8:22 PM
 */

#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>

//  Classes
#include "SHADER.h"

//  Headers
#include "../utils/utils.h"

using namespace std;

//  SHADER
SHADER::SHADER(){
    this->_shader_id = 0;
}

SHADER::SHADER(const char* filename, GLenum share_type){
    FILE* file;
    long file_size = -1;
    char* glsl_source;

    if((file = fopen(filename, "rb")) != NULL   &&
        fseek(file, 0, SEEK_END) == 0           &&
        (file_size = ftell(file)) != -1)
    {

        rewind(file);

        if((glsl_source = (char*)malloc(file_size + 1)) != NULL){
            if((file_size == (long)fread(glsl_source, sizeof(char), file_size, file))){
                glsl_source[file_size] = '\0';

                if((this->_shader_id = glCreateShader(share_type)) != 0){
                    glShaderSource(this->_shader_id, 1, &glsl_source, NULL);
                    glCompileShader(this->_shader_id);
                    DetectGLError("couldn't compile shader.");
                } else {
                    cout << "couldn't Create a shader\n" << endl;
                }
            } else {
                cout << "couldn't read file\n" << endl;
            }
        } else {
            cout << "couldn't allocate " << file_size << " bytes\n" << endl;
        }

        fclose(file);
    } else {
        cout << "couldn't Open file " << filename << ": " << strerror(errno) << "\n" << endl;
    }

    cout << "SHADER(" << this->_shader_id << ") Created" << endl;
}

GLuint  SHADER::get_id(){
    return this->_shader_id;
}

SHADER::~SHADER(){
    glDeleteShader(this->_shader_id);
}