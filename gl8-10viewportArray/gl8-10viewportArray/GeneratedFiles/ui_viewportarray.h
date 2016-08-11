/********************************************************************************
** Form generated from reading UI file 'viewportarray.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWPORTARRAY_H
#define UI_VIEWPORTARRAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_viewportArrayClass
{
public:

    void setupUi(QWidget *viewportArrayClass)
    {
        if (viewportArrayClass->objectName().isEmpty())
            viewportArrayClass->setObjectName(QStringLiteral("viewportArrayClass"));
        viewportArrayClass->resize(600, 400);

        retranslateUi(viewportArrayClass);

        QMetaObject::connectSlotsByName(viewportArrayClass);
    } // setupUi

    void retranslateUi(QWidget *viewportArrayClass)
    {
        viewportArrayClass->setWindowTitle(QApplication::translate("viewportArrayClass", "viewportArray", 0));
    } // retranslateUi

};

namespace Ui {
    class viewportArrayClass: public Ui_viewportArrayClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWPORTARRAY_H
