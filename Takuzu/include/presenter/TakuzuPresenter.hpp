#ifndef TAKUZUPRESENTER_HPP
#define TAKUZUPRESENTER_HPP



#include "model/Model.hpp"
#include "presenter/MenuPresenter.hpp"
#include "view/gameView.hpp"
#include "view/takuzuWidget.hpp"
#include <QUndoStack>

class MenuPresenter;
class takuzuWidget;
class gameView;
class MenuView;

class TakuzuPresenter : QObject {
public:
    TakuzuPresenter(QObject * parent= nullptr);
    void setGameView(gameView * gameView);
    void setMenuPresenter(MenuPresenter * menuPresenter);
    bool checkGameOver();
    void returnToMenu();
    void quitGame();
    gameView * getGameView() const;
    Model * getModel() const;
    void showErrors(bool showError) const;
    void setCellType(bool circleType) const;

    void initializeGame();
private:
    Model * _model;
    gameView * _gameView;
    MenuView * _menuView;
    MenuPresenter * _menuPresenter;
    QUndoStack * _stack;
};



#endif // TAKUZUPRESENTER_HPP
