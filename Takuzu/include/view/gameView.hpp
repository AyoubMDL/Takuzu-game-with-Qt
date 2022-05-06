#ifndef MAINGAME_HPP
#define MAINGAME_HPP

#include <QMainWindow>
#include "presenter/TakuzuPresenter.hpp"

class TakuzuPresenter;
class takuzuWidget;
namespace Ui {
class mainGame;
}

class gameView : public QMainWindow
{
    Q_OBJECT

public:
    explicit gameView(QWidget *parent = nullptr);
    takuzuWidget * getTakView() const;
    void setPresenter(TakuzuPresenter * takuzuPresenter);
    ~gameView();

private slots:
    void onCheckPressed();
    void returnToMenu();
    void showErrorChecked();
    void changeToCircle();
    void changeToSquare();
    void quitGame();
    void onAboutPressed();

signals:
    void changeShowErrorsStatus();
    void changeCellsType();
private:
    Ui::mainGame *ui;
    TakuzuPresenter * _takuzuPresenter;
    takuzuWidget * _takuzuV;
};

#endif // MAINGAME_H
