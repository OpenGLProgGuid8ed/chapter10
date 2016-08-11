/********************************************************************************
** Form generated from reading UI file 'drawxfb.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWXFB_H
#define UI_DRAWXFB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_drawXFBClass
{
public:

    void setupUi(QWidget *drawXFBClass)
    {
        if (drawXFBClass->objectName().isEmpty())
            drawXFBClass->setObjectName(QStringLiteral("drawXFBClass"));
        drawXFBClass->resize(600, 400);

        retranslateUi(drawXFBClass);

        QMetaObject::connectSlotsByName(drawXFBClass);
    } // setupUi

    void retranslateUi(QWidget *drawXFBClass)
    {
        drawXFBClass->setWindowTitle(QApplication::translate("drawXFBClass", "drawXFB", 0));
    } // retranslateUi

};

namespace Ui {
    class drawXFBClass: public Ui_drawXFBClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWXFB_H
