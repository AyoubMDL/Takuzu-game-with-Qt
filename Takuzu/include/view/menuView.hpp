#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "presenter/MenuPresenter.hpp"
#include "view/gameView.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MenuPresenter;
class gameView;

class MenuView : public QMainWindow
{
    Q_OBJECT

public:
    MenuView(QWidget *parent = nullptr);
    ~MenuView();
    void setPresenter(MenuPresenter * menuPresenter);
    void setParameters();

public slots:
    void onExitPressed();
    void onStartPressed();
    void onContinuePressed();
    void onInstructionsPressed();
private:
    Ui::MainWindow * ui;
    gameView * _gameView;

    MenuPresenter * _menuPresenter;
};
#endif // MAINWINDOW_H
