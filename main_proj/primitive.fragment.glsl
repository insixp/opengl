#version 400

in vec2 UV;
out vec3 color; 
uniform sampler2D _texture;

void main(void)
{
  color = texture(_texture, in_uv).rgb;
}