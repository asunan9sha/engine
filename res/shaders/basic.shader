#shader vertex
#version 450 core

layout(location = 0) in vec2 position;
layout(location = 1) in vec2 texCoord;

out vec2 v_TexCoord;

uniform mat4 u_Proj;
uniform mat4 u_Model;

void main()
{
  gl_Position = u_Proj *u_Model *vec4(position, 0.0, 1.0);
  v_TexCoord = texCoord;
}

  #shader fragment
  #version 450 core

  #extension GL_ARB_bindless_texture : require

layout(location = 0) out vec4 color;

in vec2 v_TexCoord;

uniform vec4 u_Color;
//uniform sampler2D u_Texture;
uniform uvec2 u_Handle;

void main()
{
 // color = texture(u_Texture, v_TexCoord) * u_Color;
  color = texture(sampler2D(u_Handle), v_TexCoord) * u_Color;
}