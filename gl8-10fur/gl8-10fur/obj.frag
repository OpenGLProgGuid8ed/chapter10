#version 410
layout (location = 0) out vec4 color;

in VS_FS_VERTEX
{
     vec3 normal;
} vertex_in;
void main()
{
    vec3 normal	= vertex_in.normal;
	color				= normalize(vec4(248, 240, 229, 255)) * (0.2 + pow(abs(normal.z), 4.0)) + vec4(0.8, 0.8, 0.8, 0.0) * pow(abs(normal.z), 137.0);;
}