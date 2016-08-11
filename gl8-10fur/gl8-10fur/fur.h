#ifndef FUR_H
#define FUR_H

#include <QtWidgets/QWidget>
#include "ui_fur.h"
#include "LoadShaders.h"
#include "vmath.h"
#include "vbm.h"
#include <qgl.h>
#include <QKeyEvent>
class fur : public QGLWidget
{
	Q_OBJECT

public:
	fur(QGLWidget *parent = 0);
	~fur();
	void initializeGL();
	void paintGL();
	void resizeGL(int w,int h);
	void timerEvent(QTimerEvent*);
	void keyPressEvent(QKeyEvent *e);

private:
	Ui::furClass ui;
	// Member variables
    float aspect;
    GLuint base_prog;
    GLuint fur_prog;
    GLuint fur_texture;
    VBObject object;

    GLint fur_model_matrix_pos;
    GLint fur_projection_matrix_pos;
    GLint base_model_matrix_pos;
    GLint base_projection_matrix_pos;
};

#endif // FUR_H
