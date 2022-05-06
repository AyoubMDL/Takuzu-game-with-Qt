#include "presenter/TakuzuPresenter.hpp"
#include <iostream>
using namespace std;
TakuzuPresenter::TakuzuPresenter(QObject * parent) : QObject(parent) {

}


void TakuzuPresenter::initializeGame() {
    _model = new Model(_menuPresenter->getSize(), _menuPresenter->getDifficulty());
    connect(_gameView->getTakView(), SIGNAL(cellClicked(uint,uint)), _model, SLOT(nextMove(uint,uint)));
    connect(_model, SIGNAL(newCellSelected()), _gameView->getTakView(), SLOT(drawNewCell()));
    connect(_gameView, SIGNAL(changeShowErrorsStatus()), _gameView->getTakView(), SLOT(updateShowErrors()));
    connect(_gameView, SIGNAL(changeCellsType()), _gameView->getTakView(), SLOT(updateCellType()));
}

Model * TakuzuPresenter::getModel() const {
    return _model;
}

bool TakuzuPresenter::checkGameOver() {
    return _model->gameOver();
}

void TakuzuPresenter::setMenuPresenter(MenuPresenter * menuPresenter) {
    _menuPresenter = menuPresenter;
}

void TakuzuPresenter::setGameView(gameView * gameView) {
    _gameView = gameView;
}

void TakuzuPresenter::showErrors(bool showError) const{
    _gameView->getTakView()->setShowErrorStatus(showError);
}
void TakuzuPresenter::setCellType(bool circleType) const {
    _gameView->getTakView()->setCellType(circleType);
}

void TakuzuPresenter::returnToMenu() {
    _menuView = _menuPresenter->getMenuView();
    _gameView->hide();
    _menuView->show();
}

void TakuzuPresenter::quitGame() {
    _gameView->close();
}

gameView * TakuzuPresenter::getGameView() const {
    return _gameView;
}
