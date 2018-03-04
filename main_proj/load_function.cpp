/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

//  Classes
#include "shaders/SHADER.h"
#include "shaders/PROGRAM.h"
#include "primitives/CAMERA.h"
#include "primitives/CUBE.h"
#include "primitives/OBJECT.h"

//  Headers
#include "primitives/3d_primitives.h"
#include "utils/utils.h"
#include "globals.h"

using namespace glm;

PROGRAM     *main_program;
CAMERA      *camera;
CUBE        *cube;
OBJECT      *object;

GLuint      view_matrix_uniform_loc;
GLuint      proj_matrix_uniform_loc;

mat4        proj_matrix = mat4(1.0);
mat4        view_matrix = mat4(1.0);

vec3        cam_focus = vec3(0.0);

void load_function(){
    const VERTEX vertices1[] =
    {
        { { -.5f, -.5f,  .5f, 1 }, { 0, 0, 1, 1 } },
        { { -.5f,  .5f,  .5f, 1 }, { 1, 0, 0, 1 } },
        { {  .5f,  .5f,  .5f, 1 }, { 0, 1, 0, 1 } },
        { {  .5f, -.5f,  .5f, 1 }, { 1, 1, 0, 1 } },
        { { -.5f, -.5f, -.5f, 1 }, { 1, 1, 1, 1 } },
        { { -.5f,  .5f, -.5f, 1 }, { 1, 0, 0, 1 } },
        { {  .5f,  .5f, -.5f, 1 }, { 1, 0, 1, 1 } },
        { {  .5f, -.5f, -.5f, 1 }, { 0, 0, 1, 1 } }
    };

    const VERTEX vertices2[] =
    {
        { {  .5f,  .5f, 1.5f, 1 }, { 0, 0, 1, 1 } },
        { {  .5f, 1.5f, 1.5f, 1 }, { 1, 0, 0, 1 } },
        { { 1.5f, 1.5f, 1.5f, 1 }, { 0, 1, 0, 1 } },
        { { 1.5f,  .5f, 1.5f, 1 }, { 1, 1, 0, 1 } },
        { {  .5f,  .5f,  .5f, 1 }, { 1, 1, 1, 1 } },
        { {  .5f, 1.5f,  .5f, 1 }, { 1, 0, 0, 1 } },
        { { 1.5f, 1.5f,  .5f, 1 }, { 1, 0, 1, 1 } },
        { { 1.5f,  .5f,  .5f, 1 }, { 0, 0, 1, 1 } }
    };

    const GLubyte indices[] =
    {
    0,2,1,  0,3,2,
    4,3,0,  4,7,3,
    4,1,5,  4,0,1,
    3,6,2,  3,7,6,
    1,6,5,  1,2,6,
    7,5,6,  7,4,5
    };


    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    DetectGLError("couldn't set OpenGL depth testing options.");

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);
    DetectGLError("couldn't set OpenGL culling options.");

    SHADER      vertex_shader("primitive.vertex.glsl", GL_VERTEX_SHADER);
    SHADER      fragment_shader("primitive.fragment.glsl", GL_FRAGMENT_SHADER);
    main_program    = new PROGRAM();
    main_program->attach_shader(fragment_shader);
    main_program->attach_shader(vertex_shader);
    main_program->link();
    view_matrix_uniform_loc = glGetUniformLocation(main_program->get_id(), "ViewMatrix");
    proj_matrix_uniform_loc = glGetUniformLocation(main_program->get_id(), "ProjectionMatrix");

    camera  = new CAMERA(vec3(0, 0, -2), vec3(0, 0, 0));
    cube    = new CUBE(vertices1, indices);
    object  = new OBJECT("objects/cube.obj");
}