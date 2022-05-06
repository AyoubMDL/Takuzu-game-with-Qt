#include "presenter/MenuPresenter.hpp"
#include <iostream>
using namespace std;

void MenuPresenter::setView(MenuView * menuView) {
    _menuView = menuView;
}

MenuPresenter::MenuPresenter()
{

}

void MenuPresenter::setDifficulty(Difficulty difficulty) {
    _difficulty = difficulty;
}

void MenuPresenter::setSize(unsigned int size) {
    _size = size;
}

void MenuPresenter::setTakuzuPresenter(TakuzuPresenter * takuzuPresenter) {
    _takuzuPresenter = takuzuPresenter;
}


unsigned int MenuPresenter::getSize() const {
    return _size;
}

Difficulty MenuPresenter::getDifficulty() const {
    return _difficulty;
}

MenuView * MenuPresenter::getMenuView() const {
    return _menuView;
}

void MenuPresenter::startGame() {
    _gameView = new gameView();
    _takuzuPresenter = new TakuzuPresenter();
    _takuzuPresenter->setMenuPresenter(this);
    _takuzuPresenter->setGameView(_gameView);
    _takuzuPresenter->initializeGame();
    _model = _takuzuPresenter->getModel();
    _gameView->getTakView()->setModel(_model);
    _gameView->setPresenter(_takuzuPresenter);
    _gameView->show();
}

TakuzuPresenter * MenuPresenter::getTakuzuPresenter() const {
    return _takuzuPresenter;
}


void MenuPresenter::continuePlaying() {
    _takuzuPresenter = getTakuzuPresenter();
    _gameView = _takuzuPresenter->getGameView();
    _gameView->show();
}

MenuPresenter::~MenuPresenter() {}

