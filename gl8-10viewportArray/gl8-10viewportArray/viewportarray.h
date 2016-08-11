#ifndef VIEWPORTARRAY_H
#define VIEWPORTARRAY_H

#include <QtWidgets/QWidget>
#include "ui_viewportarray.h"
#include "LoadShaders.h"
#include "vbm.h"
#include "vmath.h"
#include <qgl.h>
class viewportArray : public QGLWidget
{
	Q_OBJECT

public:
	viewportArray(QGLWidget *parent = 0);
	~viewportArray();
	void initializeGL();
	void paintGL();
	void resizeGL(int w,int h);
	void timerEvent(QTimerEvent*);

private:
	Ui::viewportArrayClass ui;
	// Member variables
    float aspect;
    GLuint prog;
    GLuint vao;
    GLuint vbo;
    VBObject object;

    GLint model_matrix_pos;
    GLint projection_matrix_pos;
};

#endif // VIEWPORTARRAY_H
