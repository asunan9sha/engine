#version 450 core

#extension GL_ARB_bindless_texture : require

layout(location = 0) out vec4 color;

uniform float u_setR;
uniform float u_setG;
uniform float u_setB;
uniform vec4 u_setColor;

in vec2 v_TexCoord;
in vec4 v_color;
in vec2 v_texHandle;

void main()
{
  color = texture(sampler2D(uvec2(v_texHandle)), v_TexCoord) * u_setColor;
  //color = texture(sampler2D(uvec2(v_texHandle)), v_TexCoord) * v_color;
}