#include "model/Command.hpp"


Command::Command(Model * model, int row, int column) {
    _model = model;
    _row = row;
    _column = column;
}


Command::~Command() {

}


void Command::undo()
{
    _model->backMove(_row, _column);
}

void Command::redo()
{
    _model->nextMove(_row, _column);
}
