/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   keyboard_function.cpp
 * Author: Tal
 *
 * Created on March 2, 2018, 8:32 PM
 */

#include <glm/glm.hpp>
#include <iostream>

//  Classes
#include "primitives/CAMERA.h"

//  Headers
#include "globals.h"

using namespace glm;

void keyboard_function(unsigned char Key, int x, int y){
    
    vec3    forward_vec;
    
    switch(Key)
    {
        case 'w':
            forward_vec  = normalize(camera->get_focus() - camera->get_position())/10.0f;
            camera->set_position(camera->get_position() + forward_vec);
            camera->set_focus(camera->get_focus() + forward_vec);
            break;
        case 's':
            forward_vec  = normalize(camera->get_focus() - camera->get_position())/10.0f;
            camera->set_position(camera->get_position() - forward_vec);
            camera->set_focus(camera->get_focus() - forward_vec);
            break;
        case 'a':
            // cam_focus[0] = 0.01;
            break;
        case 'd':
            // cam_focus[0] = -0.01;
            break;
    }
    
    for(int i = 0; i < 3; i++){
        cout << forward_vec[i] << ",";
    }
    cout << endl;
    for(int i = 0; i < 3; i++){
        cout << camera->get_focus()[i] << ",";
    }
    cout << endl;
}