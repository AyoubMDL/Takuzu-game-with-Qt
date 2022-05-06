#include "view/menuView.hpp"
#include "view/gameView.hpp"
#include "ui_menuView.h"
/*
  QString path = QString::fromStdString(":/TakuzuGrids/10_easy.txt");
    _model = new Model(path, 6, 10);


*/

MenuView::MenuView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->_continue->setDisabled(true);
    _menuPresenter = new MenuPresenter();
    setPresenter(_menuPresenter);

    // Buttons
    connect(ui->_start, &QPushButton::clicked, this, &MenuView::onStartPressed);
    connect(ui->_continue, &QPushButton::clicked, this, &MenuView::onContinuePressed);
    connect(ui->_quit_, &QPushButton::clicked, this, &MenuView::onExitPressed);
    connect(ui->_instructions, &QPushButton::clicked, this, &MenuView::onInstructionsPressed);
}



void MenuView::setPresenter(MenuPresenter * menuPresenter) {
    _menuPresenter = menuPresenter;
}


MenuView::~MenuView()
{
    delete _menuPresenter;
    delete ui;
}



void MenuView::setParameters() {
    unsigned int size;
    Difficulty difficulty;
    if(ui->_difficulty->currentText() == "Hard") {
        difficulty = Difficulty::Hard;
    } else {
        difficulty = Difficulty::Easy;
    }
    if(ui->_size->currentText() == "Size 6") {
        size = 6;
    } else if (ui->_size->currentText() == "Size 8") {
        size = 8;
    } else {
        size = 10;
    }
    _menuPresenter->setDifficulty(difficulty);
    _menuPresenter->setSize(size);
}


void MenuView::onStartPressed() {
    setParameters();
    _menuPresenter->setView(this);
    _menuPresenter->startGame();
    ui->_continue->setDisabled(false);
    this->close();
}

void MenuView::onContinuePressed() {
    _menuPresenter->continuePlaying();
    this->close();
}

void MenuView::onExitPressed()
{
    int button = QMessageBox::question(this, "You want to quit...",
                                       "Are you sure that you want to quit?",
                                       QMessageBox::Yes, QMessageBox::No | QMessageBox::Default);
    if (button == QMessageBox::Yes) {
      close();
    }
}


void MenuView::onInstructionsPressed()
{
    QMessageBox::information(this, "How to play",
                             "  Takuzu, also known as Binairo, is a logic puzzle "
                             "involving placement of two symbols, often 1 and 0 or black and white, "
                             "on a rectangular grid. The objective is to fill the grid with "
                             "1 and 0, where there is an equal number of 1s and 0s in each "
                             "row and column and no more than two of either number adjacent to "
                             "each other. Additionally, there can be no identical rows or columns",
                                       QMessageBox::Ok, QMessageBox::Default);
}
