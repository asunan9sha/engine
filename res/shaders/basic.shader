#shader vertex
#version 450 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 texCoord;
layout(location = 2) in vec4 color;
layout(location = 3) in vec2 texHandle;

out vec2 v_TexCoord;
out vec4 v_color;
out vec2 v_texHandle;

uniform mat4 u_Proj;
uniform mat4 u_Model;

void main()
{
  gl_Position = u_Proj *u_Model *vec4(position, 1.0);
  v_TexCoord = texCoord;
  v_color= color;
  v_texHandle = texHandle;
}

  #shader fragment
  #version 450 core

  #extension GL_ARB_bindless_texture : require

layout(location = 0) out vec4 color;

in vec2 v_TexCoord;
in vec4 v_color;
in vec2 v_texHandle;

void main()
{
  color = texture(sampler2D(uvec2(v_texHandle)), v_TexCoord) * v_color;
}