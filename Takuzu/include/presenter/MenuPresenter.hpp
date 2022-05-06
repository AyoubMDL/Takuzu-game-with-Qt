#ifndef MENUPRESENTER_HPP
#define MENUPRESENTER_HPP

#include "view/takuzuWidget.hpp"
#include "view/menuView.hpp"
#include "view/gameView.hpp"
#include "model/Model.hpp"


class MenuView;
class TakuzuPresenter;
class gameView;

class MenuPresenter {
public:
    MenuPresenter();
    void setView(MenuView * menuView);
    void startGame();
    void setSize(unsigned int size);
    MenuView * getMenuView() const;
    unsigned int getSize() const;
    Difficulty getDifficulty() const;
    void setDifficulty(Difficulty difficulty);
    void setTakuzuPresenter(TakuzuPresenter * takuzuPresenter);
    TakuzuPresenter * getTakuzuPresenter() const;
    void continuePlaying();
    ~MenuPresenter();
private:
    MenuView * _menuView;
    TakuzuPresenter * _takuzuPresenter;
    gameView * _gameView;
    Difficulty _difficulty;
    unsigned int _size;
    Model * _model;


};
#endif // PRESENTER_H



