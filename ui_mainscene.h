/********************************************************************************
** Form generated from reading UI file 'mainscene.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCENE_H
#define UI_MAINSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainScene
{
public:
    QAction *actionExit;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainScene)
    {
        if (MainScene->objectName().isEmpty())
            MainScene->setObjectName(QString::fromUtf8("MainScene"));
        MainScene->resize(308, 469);
        actionExit = new QAction(MainScene);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralWidget = new QWidget(MainScene);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainScene->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainScene);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 308, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainScene->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainScene);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainScene->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionExit);

        retranslateUi(MainScene);

        QMetaObject::connectSlotsByName(MainScene);
    } // setupUi

    void retranslateUi(QMainWindow *MainScene)
    {
        MainScene->setWindowTitle(QCoreApplication::translate("MainScene", "\347\277\273\351\207\221\345\270\201", nullptr));
        actionExit->setText(QCoreApplication::translate("MainScene", "\351\200\200\345\207\272", nullptr));
        menu->setTitle(QCoreApplication::translate("MainScene", "\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainScene: public Ui_MainScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCENE_H
