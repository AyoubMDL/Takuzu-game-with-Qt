/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_5;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QComboBox *_size;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_3;
    QComboBox *_difficulty;
    QVBoxLayout *verticalLayout_8;
    QPushButton *_playEasy_;
    QPushButton *_playHard_;
    QPushButton *_quit_;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(735, 536);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setEnabled(true);
        centralwidget->setAutoFillBackground(false);
        verticalLayout_5 = new QVBoxLayout(centralwidget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(60);
        label->setFont(font);

        verticalLayout_5->addWidget(label, 0, Qt::AlignHCenter);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        font1.setStyleStrategy(QFont::PreferAntialias);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout->addWidget(label_2);

        _size = new QComboBox(centralwidget);
        _size->addItem(QString());
        _size->addItem(QString());
        _size->addItem(QString());
        _size->setObjectName(QString::fromUtf8("_size"));

        verticalLayout->addWidget(_size);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setSizeConstraint(QLayout::SetMinimumSize);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setItalic(true);
        font2.setWeight(75);
        font2.setStrikeOut(false);
        font2.setKerning(true);
        font2.setStyleStrategy(QFont::PreferAntialias);
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_7->addWidget(label_3);

        _difficulty = new QComboBox(centralwidget);
        _difficulty->addItem(QString());
        _difficulty->addItem(QString());
        _difficulty->setObjectName(QString::fromUtf8("_difficulty"));

        verticalLayout_7->addWidget(_difficulty);

        verticalLayout_7->setStretch(0, 1);
        verticalLayout_7->setStretch(1, 1);

        horizontalLayout->addLayout(verticalLayout_7);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);

        verticalLayout_5->addLayout(horizontalLayout);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(34);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(-1, 200, -1, 40);
        _playEasy_ = new QPushButton(centralwidget);
        _playEasy_->setObjectName(QString::fromUtf8("_playEasy_"));
        _playEasy_->setMinimumSize(QSize(500, 40));
        _playEasy_->setMaximumSize(QSize(400, 50));
        _playEasy_->setLayoutDirection(Qt::RightToLeft);
        _playEasy_->setCheckable(false);

        verticalLayout_8->addWidget(_playEasy_, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        _playHard_ = new QPushButton(centralwidget);
        _playHard_->setObjectName(QString::fromUtf8("_playHard_"));
        _playHard_->setMinimumSize(QSize(500, 40));

        verticalLayout_8->addWidget(_playHard_, 0, Qt::AlignHCenter);

        _quit_ = new QPushButton(centralwidget);
        _quit_->setObjectName(QString::fromUtf8("_quit_"));
        _quit_->setMinimumSize(QSize(500, 40));

        verticalLayout_8->addWidget(_quit_, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        verticalLayout_5->addLayout(verticalLayout_8);

        verticalLayout_5->setStretch(0, 1);
        verticalLayout_5->setStretch(2, 1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 735, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "Takuzu", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Choose the size of the game :", nullptr));
        _size->setItemText(0, QApplication::translate("MainWindow", "Size 6", nullptr));
        _size->setItemText(1, QApplication::translate("MainWindow", "Size 8", nullptr));
        _size->setItemText(2, QApplication::translate("MainWindow", "Size 10", nullptr));

        label_3->setText(QApplication::translate("MainWindow", "Choose the difficulty of the game :", nullptr));
        _difficulty->setItemText(0, QApplication::translate("MainWindow", "Easy", nullptr));
        _difficulty->setItemText(1, QApplication::translate("MainWindow", "Hard", nullptr));

        _playEasy_->setText(QApplication::translate("MainWindow", "start ", nullptr));
        _playHard_->setText(QApplication::translate("MainWindow", "continue", nullptr));
        _quit_->setText(QApplication::translate("MainWindow", "exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
