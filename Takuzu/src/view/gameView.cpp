#include "view/gameView.hpp"
#include "ui_gameView.h"
#include "view/takuzuWidget.hpp"

gameView::gameView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainGame)
{
    ui->setupUi(this);
    ui->_circleCells->setChecked(true);
    connect(ui->_check, &QPushButton::clicked, this, &gameView::onCheckPressed);
    connect(ui->_returnToMenu, SIGNAL(triggered()), this, SLOT(returnToMenu()));
    connect(ui->_showErrors, SIGNAL(changed()), this, SLOT(showErrorChecked()));
    connect(ui->_circleCells, SIGNAL(changed()), this, SLOT(changeToCircle()));
    connect(ui->_squareCells, SIGNAL(changed()), this, SLOT(changeToSquare()));
    connect(ui->_quit, SIGNAL(triggered()), this, SLOT(quitGame()));
    connect(ui->_about, SIGNAL(triggered()), this, SLOT(onAboutPressed()));

}


void gameView::showErrorChecked() {
    _takuzuPresenter->showErrors(ui->_showErrors->isChecked());
    emit changeShowErrorsStatus();
}

void gameView::changeToCircle() {
    if(ui->_circleCells->isChecked()) {
         ui->_squareCells->setChecked(false);
        _takuzuPresenter->setCellType(true);
    }
    emit changeCellsType();
}

void gameView::changeToSquare() {
    if(ui->_squareCells->isChecked()) {
         ui->_circleCells->setChecked(false);
        _takuzuPresenter->setCellType(false);
    }
    emit changeCellsType();
}

void gameView::setPresenter(TakuzuPresenter * takuzuPresenter) {
    _takuzuPresenter = takuzuPresenter;
}

takuzuWidget * gameView::getTakView() const {
    return ui->takuzuGame;
}


void gameView::onCheckPressed()
{
    if(_takuzuPresenter->checkGameOver()) {
        QMessageBox::question(this, "Congratulations",
                                           "you have succeeded",
                                           QMessageBox::Ok| QMessageBox::Default);
    } else {
        int button = QMessageBox::question(this, "Sorry",
                                           "It's not over yet, do you want to continue ?",
                                           QMessageBox::Yes, QMessageBox::No | QMessageBox::Default);
        if (button == QMessageBox::No) {
          close();
        }
    }
}


void gameView::onAboutPressed() {
    QMessageBox::information(this, "About Takuzu game", "Takuzu\n (c) Crand Guillaume\n (c) Bih Ayoub",
                                       QMessageBox::Ok, QMessageBox::Default);
}


void gameView::returnToMenu() {
    _takuzuPresenter->returnToMenu();
}

void gameView::quitGame() {
    _takuzuPresenter->quitGame();
}

gameView::~gameView()
{
    delete ui;
}

