#version 400

layout(location=0) in vec4 in_Position;
layout(location=1) in vec2 in_uv;
out vec2 UV;

uniform mat4 ModelMatrix;
uniform mat4 ViewMatrix;
uniform mat4 ProjectionMatrix;

void main(void)
{
  gl_Position = (ProjectionMatrix * ViewMatrix * ModelMatrix) * in_Position;
  out_uv = in_uv;
}