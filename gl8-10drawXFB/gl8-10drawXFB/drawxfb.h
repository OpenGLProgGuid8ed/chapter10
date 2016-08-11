#ifndef DRAWXFB_H
#define DRAWXFB_H

#include <QtWidgets/QWidget>
#include "ui_drawxfb.h"
#include "LoadShaders.h"
#include "vmath.h"
#include "vbm.h"
#include <qgl.h>
class drawXFB : public QGLWidget
{
	Q_OBJECT

public:
	drawXFB(QGLWidget *parent = 0);
	~drawXFB();
	void initializeGL();
	void paintGL();
	void resizeGL(int w,int h);
	void timerEvent(QTimerEvent*);

private:
	Ui::drawXFBClass ui;
	 // Member variables
    float aspect;
    GLuint sort_prog;
    GLuint render_prog;
    GLuint vao[2];
    GLuint vbo[2];
    GLuint xfb;
    VBObject object;

    GLint model_matrix_pos;
    GLint projection_matrix_pos;
};

#endif // DRAWXFB_H
