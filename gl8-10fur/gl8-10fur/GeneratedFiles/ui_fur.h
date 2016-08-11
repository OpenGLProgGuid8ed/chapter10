/********************************************************************************
** Form generated from reading UI file 'fur.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FUR_H
#define UI_FUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_furClass
{
public:

    void setupUi(QWidget *furClass)
    {
        if (furClass->objectName().isEmpty())
            furClass->setObjectName(QStringLiteral("furClass"));
        furClass->resize(600, 400);

        retranslateUi(furClass);

        QMetaObject::connectSlotsByName(furClass);
    } // setupUi

    void retranslateUi(QWidget *furClass)
    {
        furClass->setWindowTitle(QApplication::translate("furClass", "fur", 0));
    } // retranslateUi

};

namespace Ui {
    class furClass: public Ui_furClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FUR_H
