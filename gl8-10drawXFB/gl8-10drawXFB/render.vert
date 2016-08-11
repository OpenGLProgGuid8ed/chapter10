#version 410 core

layout (location = 0) in vec4 position;
layout (location = 1) in vec3 normal;

out vec3 vs_normal;

void main()
{
    vs_normal = normal;
	gl_Position = position;
}