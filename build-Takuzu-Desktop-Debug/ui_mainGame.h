/********************************************************************************
** Form generated from reading UI file 'mainGame.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINGAME_H
#define UI_MAINGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "view/takuzuView.hpp"

QT_BEGIN_NAMESPACE

class Ui_mainGame
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    takuzuView *takuzuGame;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *mainGame)
    {
        if (mainGame->objectName().isEmpty())
            mainGame->setObjectName(QString::fromUtf8("mainGame"));
        mainGame->resize(800, 600);
        centralwidget = new QWidget(mainGame);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(17);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        takuzuGame = new takuzuView(centralwidget);
        takuzuGame->setObjectName(QString::fromUtf8("takuzuGame"));

        verticalLayout->addWidget(takuzuGame);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 10);
        mainGame->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mainGame);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        mainGame->setMenuBar(menubar);
        statusbar = new QStatusBar(mainGame);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        mainGame->setStatusBar(statusbar);

        retranslateUi(mainGame);

        QMetaObject::connectSlotsByName(mainGame);
    } // setupUi

    void retranslateUi(QMainWindow *mainGame)
    {
        mainGame->setWindowTitle(QApplication::translate("mainGame", "MainWindow", nullptr));
        label->setText(QApplication::translate("mainGame", "Enjoy", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainGame: public Ui_mainGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINGAME_H
