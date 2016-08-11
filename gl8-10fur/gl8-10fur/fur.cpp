#include "fur.h"
#include <iostream>
fur::fur(QGLWidget *parent)
	: QGLWidget(parent)
{
	ui.setupUi(this);
	startTimer(100);
}

fur::~fur()
{
	glUseProgram(0);
	glDeleteProgram(base_prog);
    glDeleteProgram(fur_prog);
}

void fur::initializeGL()
{
	if(glewInit())
	{
		std::cout<<"Unable to Init GLEW"<<std::endl;
		exit(EXIT_FAILURE);
	}
	base_prog = glCreateProgram();
	ShaderInfo obj_shaders[] ={
		{GL_VERTEX_SHADER,		"obj.vert"},
		{GL_FRAGMENT_SHADER,	"obj.frag"},
		{GL_NONE,						NULL}
	};
	base_prog = LoadShaders(obj_shaders);
	glLinkProgram(base_prog);
    glUseProgram(base_prog);
	base_model_matrix_pos = glGetUniformLocation(base_prog, "model_matrix");
    base_projection_matrix_pos = glGetUniformLocation(base_prog, "projection_matrix");

    fur_prog = glCreateProgram();
	ShaderInfo fur_shaders[] ={
		{GL_VERTEX_SHADER,		"fur.vert"},
		{GL_GEOMETRY_SHADER,	"fur.geo"},
		{GL_FRAGMENT_SHADER,	"fur.frag"},
		{GL_NONE,						NULL}
	};
	fur_prog = LoadShaders(fur_shaders);
	glLinkProgram(fur_prog);
    glUseProgram(fur_prog);
	fur_model_matrix_pos = glGetUniformLocation(fur_prog, "model_matrix");
    fur_projection_matrix_pos = glGetUniformLocation(fur_prog, "projection_matrix");

    glGenTextures(1, &fur_texture);
    unsigned char * tex = (unsigned char *)malloc(1024 * 1024 * 4);
    memset(tex, 0, 1024 * 1024 * 4);

    int n, m;

    for (n = 0; n < 256; n++)
    {
        for (m = 0; m < 1270; m++)
        {
            int x = rand() & 0x3FF;
            int y = rand() & 0x3FF;
            tex[(y * 1024 + x) * 4 + 0] = (rand() & 0x3F) + 0xC0;
            tex[(y * 1024 + x) * 4 + 1] = (rand() & 0x3F) + 0xC0;
            tex[(y * 1024 + x) * 4 + 2] = (rand() & 0x3F) + 0xC0;
            tex[(y * 1024 + x) * 4 + 3] = n;
        }
    }

    glBindTexture(GL_TEXTURE_2D, fur_texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 1024, 1024, 0, GL_RGBA, GL_UNSIGNED_BYTE, tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    free(tex);

    object.LoadFromVBM("C:/Vermilion-Book/trunk/Code/media/ninja.vbm", 0, 1, 2);
}

void fur::paintGL()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	float t = float(GetTickCount() & 0x3FFF) / float(0x3FFF);
    static const vmath::vec3 X(1.0f, 0.0f, 0.0f);
    static const vmath::vec3 Y(0.0f, 1.0f, 0.0f);
    static const vmath::vec3 Z(0.0f, 0.0f, 1.0f);

    vmath::mat4 p(vmath::frustum(-1.0f, 1.0f, aspect, -aspect, 1.0f, 5000.0f));
    vmath::mat4 m;
    m = vmath::mat4(vmath::translate(0.0f,
                                       0.0f,
                                       100.0f * sinf(6.28318531f * t) - 130.0f) *
								vmath::rotate(360.0f * t, X) *
								vmath::rotate(360.0f * t * 1.0f, Y) *
								vmath::rotate(180.0f, Z) *
								vmath::translate(0.0f, -80.0f, 0.0f));

    glUseProgram(base_prog);
    glUniformMatrix4fv(base_model_matrix_pos, 1, GL_FALSE, m[0]);
    glUniformMatrix4fv(base_projection_matrix_pos, 1, GL_FALSE, p);

    glDisable(GL_BLEND);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_FRONT);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    object.Render();

    glUseProgram(fur_prog);

    glUniformMatrix4fv(fur_model_matrix_pos, 1, GL_FALSE, m[0]);
    glUniformMatrix4fv(fur_projection_matrix_pos, 1, GL_FALSE, p);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glDepthMask(GL_FALSE);

    object.Render();

    glDepthMask(GL_TRUE);
    glDisable(GL_BLEND);

}

void fur::resizeGL(int w,int h)
{
	if(0 == h)
		h = 1;
	aspect = (float)h/w;
	glViewport(0,0,w,h);
	glLoadIdentity();
}

void fur::timerEvent(QTimerEvent*)
{
	updateGL();
}

void fur::keyPressEvent(QKeyEvent *e)
{
	switch (e->key())
	{
	case Qt::Key_Space :{
	    static GLenum mode = GL_FILL;
	    mode = ( mode == GL_FILL ? GL_LINE : GL_FILL );
	    glPolygonMode( GL_FRONT_AND_BACK, mode );
	} break;
	default:
		break;
	}
}