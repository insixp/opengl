/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.h
 * Author: Tal
 *
 * Created on March 2, 2018, 8:36 PM
 */

#ifndef MAIN_H
#define MAIN_H

void initialize(int, char*[]);
void init_window(int, char*[]);
void resize_function(int, int);
void render_function(void);
void load_function();
void keyboard_function(unsigned char Key, int x, int y);
void close_function(void);

#endif /* MAIN_H */

