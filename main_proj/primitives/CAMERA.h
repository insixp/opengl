/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CAMERA.h
 * Author: Tal
 *
 * Created on March 3, 2018, 3:00 AM
 */

#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>

using namespace glm;

class CAMERA {
private:
    vec3    position;
    vec3    focus;
    mat4    view_matrix;
    
public:
    CAMERA(vec3 position, vec3 focus);
    void translate(vec3 translation);
    vec3 get_position();
    vec3 get_focus();
    void set_position(vec3 position);
    void set_focus(vec3 focus);
    void draw_camera();
    virtual ~CAMERA();

};

#endif /* CAMERA_H */

