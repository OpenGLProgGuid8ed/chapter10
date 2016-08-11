#version 330 core

layout (location = 0) out vec4 color;
uniform vec4 pass_color;

in vec3 vs_normal;

void main()
{
	vec4 rgb_s = vec4(1.0, 1.0, 1.0, 0.0) * pow(abs(vs_normal.z), 37.0);
    color =  pass_color * (0.2 + pow(abs(vs_normal.z), 4.0)) + rgb_s;
}

        