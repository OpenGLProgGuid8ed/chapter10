#include "viewportarray.h"
#include <iostream>
using namespace vmath;

viewportArray::viewportArray(QGLWidget *parent)
	: QGLWidget(parent)
{
	ui.setupUi(this);
	startTimer(100);
}

viewportArray::~viewportArray()
{
	glUseProgram(0);
    glDeleteBuffers(1, &vbo);
    glDeleteProgram(prog);
    glDeleteVertexArrays(1, &vao);
}

void viewportArray::initializeGL()
{
	if(glewInit())
	{
		std::cout<<"Unable to Init GLEW"<<std::endl;
		exit(EXIT_FAILURE);
	}
	prog = glCreateProgram();
	ShaderInfo obj_shaders[] ={
		{GL_VERTEX_SHADER,			"obj.vert"},
		{GL_GEOMETRY_SHADER,		"obj.geo"},
		{GL_FRAGMENT_SHADER,		"obj.frag"},
		{GL_NONE,							NULL}
	};
	prog = LoadShaders(obj_shaders);
	
	glLinkProgram(prog);
    glUseProgram(prog);

    model_matrix_pos = glGetUniformLocation(prog, "model_matrix");
    projection_matrix_pos = glGetUniformLocation(prog, "projection_matrix");

    object.LoadFromVBM("C:/Vermilion-Book/trunk/Code/media/ninja.vbm", 0, 1, 2);
}

void viewportArray::paintGL()
{
	float t = float(GetTickCount() & 0x3FFF) / float(0x3FFF);
	static const vec3 X(1.0f,0.0f,0.0f);
	static const vec3 Y(0.0f,1.0f,0.0f);
	static const vec3 Z(0.0f,0.0f,1.0f);

	glClearColor( 0.3f, 0.1f, 0.2f, 1.0f );
    glClearDepth( 1.0f );
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	glUseProgram(prog);

	mat4 p(vmath::frustum(-1.0f, 1.0f, aspect, -aspect, 1.0f, 5000.0f));
	mat4 m[4];
	for (int i = 0; i < 4; i++)
    {
         m[i] = vmath::mat4(vmath::translate(0.0f, 0.0f, 100.0f * sinf(6.28318531f * t + i) - 230.0f) *
										vmath::rotate(360.0f * t * float(i + 1), X) *
										vmath::rotate(360.0f * t * float(i + 2), Y) *
										vmath::rotate(360.0f * t * float(5 - i), Z) *
										vmath::translate(0.0f, -80.0f, 0.0f));
    }
	glUniformMatrix4fv(model_matrix_pos, 4, GL_FALSE, m[0]);
    glUniformMatrix4fv(projection_matrix_pos, 1, GL_FALSE, p);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_FRONT);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    object.Render();
}

void viewportArray::resizeGL(int w,int h)
{
	if(0 == h)
		h = 1;
	
	const float wot = float(w) * 0.5f;
    const float hot = float(h) * 0.5f;
	aspect =hot / wot;
    glViewportIndexedf(0, 0.0f, 0.0f, wot, hot);
    glViewportIndexedf(1, wot, 0.0f, wot, hot);
    glViewportIndexedf(2, 0.0f, hot, wot, hot);
    glViewportIndexedf(3, wot, hot, wot, hot);
	
}

void viewportArray::timerEvent(QTimerEvent*)
{
	updateGL();
}