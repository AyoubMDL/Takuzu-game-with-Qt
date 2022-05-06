/********************************************************************************
** Form generated from reading UI file 'gameView.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEVIEW_H
#define UI_GAMEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "view/chronometerWidget.hpp"
#include "view/takuzuWidget.hpp"

QT_BEGIN_NAMESPACE

class Ui_mainGame
{
public:
    QAction *_quit;
    QAction *_returnToMenu;
    QAction *_circleCells;
    QAction *_squareCells;
    QAction *_showErrors;
    QAction *_about;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QToolButton *_check;
    ChronometerWidget *chronometer;
    takuzuWidget *takuzuGame;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuAbout;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *mainGame)
    {
        if (mainGame->objectName().isEmpty())
            mainGame->setObjectName(QString::fromUtf8("mainGame"));
        mainGame->resize(800, 600);
        mainGame->setStyleSheet(QString::fromUtf8("QWidget#centralwidget {\n"
"	background-color:skyblue;\n"
"}"));
        _quit = new QAction(mainGame);
        _quit->setObjectName(QString::fromUtf8("_quit"));
        _returnToMenu = new QAction(mainGame);
        _returnToMenu->setObjectName(QString::fromUtf8("_returnToMenu"));
        _circleCells = new QAction(mainGame);
        _circleCells->setObjectName(QString::fromUtf8("_circleCells"));
        _circleCells->setCheckable(true);
        _squareCells = new QAction(mainGame);
        _squareCells->setObjectName(QString::fromUtf8("_squareCells"));
        _squareCells->setCheckable(true);
        _showErrors = new QAction(mainGame);
        _showErrors->setObjectName(QString::fromUtf8("_showErrors"));
        _showErrors->setCheckable(true);
        _about = new QAction(mainGame);
        _about->setObjectName(QString::fromUtf8("_about"));
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

        _check = new QToolButton(centralwidget);
        _check->setObjectName(QString::fromUtf8("_check"));
        _check->setMinimumSize(QSize(200, 0));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        _check->setFont(font1);

        verticalLayout->addWidget(_check, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        chronometer = new ChronometerWidget(centralwidget);
        chronometer->setObjectName(QString::fromUtf8("chronometer"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(2);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(chronometer->sizePolicy().hasHeightForWidth());
        chronometer->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(chronometer, 0, Qt::AlignHCenter);

        takuzuGame = new takuzuWidget(centralwidget);
        takuzuGame->setObjectName(QString::fromUtf8("takuzuGame"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(takuzuGame->sizePolicy().hasHeightForWidth());
        takuzuGame->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(takuzuGame);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(3, 10);
        mainGame->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mainGame);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        mainGame->setMenuBar(menubar);
        statusbar = new QStatusBar(mainGame);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        mainGame->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menuFile->addAction(_quit);
        menuFile->addAction(_returnToMenu);
        menuEdit->addAction(_circleCells);
        menuEdit->addAction(_squareCells);
        menuEdit->addSeparator();
        menuEdit->addAction(_showErrors);
        menuAbout->addAction(_about);

        retranslateUi(mainGame);

        QMetaObject::connectSlotsByName(mainGame);
    } // setupUi

    void retranslateUi(QMainWindow *mainGame)
    {
        mainGame->setWindowTitle(QApplication::translate("mainGame", "Takuzu", nullptr));
        _quit->setText(QApplication::translate("mainGame", "Quit", nullptr));
#ifndef QT_NO_SHORTCUT
        _quit->setShortcut(QApplication::translate("mainGame", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        _returnToMenu->setText(QApplication::translate("mainGame", "Return To menu", nullptr));
#ifndef QT_NO_SHORTCUT
        _returnToMenu->setShortcut(QApplication::translate("mainGame", "Ctrl+R", nullptr));
#endif // QT_NO_SHORTCUT
        _circleCells->setText(QApplication::translate("mainGame", "Circle Cells", nullptr));
        _squareCells->setText(QApplication::translate("mainGame", "Square Cells", nullptr));
        _showErrors->setText(QApplication::translate("mainGame", "Show erros", nullptr));
        _about->setText(QApplication::translate("mainGame", "About", nullptr));
        label->setText(QApplication::translate("mainGame", "Enjoy", nullptr));
#ifndef QT_NO_TOOLTIP
        _check->setToolTip(QApplication::translate("mainGame", "<html><head/><body><p>Check game status</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        _check->setText(QApplication::translate("mainGame", "check", nullptr));
        menuFile->setTitle(QApplication::translate("mainGame", "File", nullptr));
        menuEdit->setTitle(QApplication::translate("mainGame", "Edit", nullptr));
        menuAbout->setTitle(QApplication::translate("mainGame", "help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainGame: public Ui_mainGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEVIEW_H
