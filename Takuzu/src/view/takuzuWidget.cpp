#include "view/takuzuWidget.hpp"


#include <iostream> // TODO
using namespace std;
takuzuWidget::takuzuWidget(QWidget *parent) : QWidget(parent){
    connect(this, SIGNAL(draw()), this, SLOT(update()));
    connect(this , SIGNAL(updateErrors()), this, SLOT(update()));
    connect(this , SIGNAL(updateCells()), this, SLOT(update()));
}

// Public
void takuzuWidget::setModel(Model * model) {
    _model = model;
    _size = _model->getGrid().getSize();
    _halfSize = _size/2;
}

void takuzuWidget::mousePressEvent(QMouseEvent * event){
    if (event->button() == Qt::LeftButton) {
        if (((event->x() > _baseX) && (event->x() < _endGridX))
              && (event->y() > _baseY) && (event->y() < _endGridY)){
            unsigned int x = (event->x()-_baseX)/_sizeTile;
            unsigned int y = (event->y()-_baseY)/_sizeTile;
            emit cellClicked(x, y);
        }
    }
}

// Slots
void takuzuWidget::drawNewCell() {
    emit draw();
}

void takuzuWidget::updateShowErrors() {
    emit updateErrors();
}

void takuzuWidget::updateCellType() {
    emit updateCells();
}

// Private
void takuzuWidget::paintEvent(QPaintEvent * /*event*/){
    actualizeWidget();

    // painter
    painter = new QPainter(this);
    painter->setPen(_Pen_small);


    // draw the view
    drawGrid();

    drawScorePerLine();

    drawTokens();


    //cout << _model->conflict(1, 0) << endl;
    painter->end();
}

void takuzuWidget::drawGrid(){
    for (int i = 0 ; i <= _size ; i++){
        painter->drawLine(_baseX+i*_sizeTile,_baseY,_baseX+i*_sizeTile,_endGridY);
        painter->drawLine(_baseX,_baseY+i*_sizeTile,_endGridX,_baseY+i*_sizeTile);
    }
    if(_showError) {
        drawConflict();
    }
}


void takuzuWidget::setCellType(bool circleType) {
    _circleType = circleType;
}

void takuzuWidget::drawTokens(){
    painter->setPen(_Pen_big);
    for (int y=0 ; y < _size ; y++){
        for (int x=0 ; x < _size ; x++){
            switch(_model->getGrid().getCellType(y, x)) {
                case LockedBlack:
                    painter->setBrush(_Brush_black);
                    if(_circleType) {
                        drawTokenCircle(x, y);
                    } else {
                        drawTokenRectangle(x, y);
                    }
                    break;
                case LockedWhite:
                    painter->setBrush(_Brush_white);
                    if(_circleType) {
                        drawTokenCircle(x, y);
                    } else {
                        drawTokenRectangle(x, y);
                    }
                    break;
                case Black:
                    painter->setBrush(_Brush_black);
                    if(_circleType) {
                        drawTokenCircle(x, y);
                    } else {
                        drawTokenRectangle(x, y);
                    }
                    break;
                case White:
                    painter->setBrush(_Brush_white);
                    if(_circleType) {
                        drawTokenCircle(x, y);
                    } else {
                        drawTokenRectangle(x, y);
                    }
                    break;
                case Empty:
                    // nothing to do
                    break;
            }
        }
    }
}


void takuzuWidget::drawTokenCircle(int x, int y){
    painter->drawEllipse(_baseX+_tokenMargin+x*_sizeTile,\
                        _baseY+_tokenMargin+y*_sizeTile,\
                        _tokenSize,_tokenSize);
}

void takuzuWidget::drawTokenRectangle(int x, int y){
    painter->drawRect(_baseX+_tokenMargin+x*_sizeTile,\
                        _baseY+_tokenMargin+y*_sizeTile,\
                        _tokenSize,_tokenSize);
}


void takuzuWidget::setShowErrorStatus(bool showError) {
    _showError = showError;
}

void takuzuWidget::drawScorePerLine(){
    QFont bold("Verdana", 20);
    bold.setBold(true);
    painter->setFont(bold);
    for (int i = 0 ; i < _size ; i++){
        // horizontal
        std::pair<int,int> rowCount = _model->numberOfFillCellsInRow(i);

        if (rowCount != _isLineOK){
            painter->setPen(Qt::black);
            painter->drawText(_endGridX+_ecart, _baseY+i*_sizeTile, _sizeTile, _sizeTile, Qt::AlignCenter, QString::number(rowCount.first));
            painter->setPen(Qt::white);
            painter->drawText(_endGridX+_ecart+_sizeTile, _baseY+i*_sizeTile, _sizeTile, _sizeTile, Qt::AlignCenter, QString::number(rowCount.second));

        } else {
            painter->setPen(Qt::yellow);
            painter->drawText(_endGridX+_ecart, _baseY+i*_sizeTile, _sizeTile, _sizeTile, Qt::AlignCenter, QString("O"));
            painter->setPen(Qt::yellow);
            painter->drawText(_endGridX+_ecart+_sizeTile, _baseY+i*_sizeTile, _sizeTile, _sizeTile, Qt::AlignCenter, QString("K"));
        }
        if ((rowCount.first > _halfSize) || (rowCount.second > _halfSize)){
            if(_showError) {
                drawError(i,0);
            }

        }

        // vertical
        std::pair<int,int> columnCount = _model->numberOfFillCellsInColumn(i);
        if (columnCount != _isLineOK){
            painter->setPen(Qt::black);
            painter->drawText(_baseX+i*_sizeTile,_endGridY+_ecart, _sizeTile, _sizeTile, Qt::AlignCenter, QString::number(columnCount.first));
            painter->setPen(Qt::white);
            painter->drawText(_baseX+i*_sizeTile, _endGridY+_ecart+_sizeTile,  _sizeTile, _sizeTile, Qt::AlignCenter, QString::number(columnCount.second));
        } else {
            painter->setPen(Qt::yellow);
            painter->drawText(_baseX+i*_sizeTile,_endGridY+_ecart, _sizeTile, _sizeTile, Qt::AlignCenter, QString("O"));
            painter->setPen(Qt::yellow);
            painter->drawText(_baseX+i*_sizeTile, _endGridY+_ecart+_sizeTile,  _sizeTile, _sizeTile, Qt::AlignCenter, QString("K"));
        }
        if ((columnCount.first > _halfSize) || (columnCount.second > _halfSize)){
            if(_showError) {
                drawError(i,1);
            }
        }
    }
}



void takuzuWidget::drawError(int lineIndex, bool isColumn){
    painter->setBrush(Qt::yellow);

    if (isColumn){
        for (int x=0 ; x<_size ; x++){
            painter->drawRect(_baseX+lineIndex*_sizeTile,_baseY+x*_sizeTile,_sizeTile,_sizeTile);
        }
    } else {
        for (int x=0 ; x<_size ; x++){
            painter->drawRect(_baseX+x*_sizeTile,_baseY+lineIndex*_sizeTile,_sizeTile,_sizeTile);
        }
    }
}

void takuzuWidget::drawConflict() {
    painter->setBrush(Qt::red);
    for(int i = 0; i < _size; ++i) {
        for(int j = 0; j < _size; ++j) {
            if(_model->conflictInRow(i, j)) {
                painter->drawRect(_baseX+(j-1)*_sizeTile,_baseY+i*_sizeTile,_sizeTile*3,_sizeTile);
            } else if(_model->conflictInColumn(i, j)) {
                painter->drawRect(_baseX+j*_sizeTile,_baseY+(i-1)*_sizeTile,_sizeTile,_sizeTile*3);
            }
        }
    }
}


void takuzuWidget::actualizeWidget(){
    _sizeTile = _sizeGrid/_size;

    _baseX = (size().width()/2)-((_sizeGrid+_ecart+_sizeTile+_sizeTile)/2);
    _endGridX = _baseX+_sizeGrid;

    _lineVertical   = _endGridX+_ecart+_ecartText+_sizeTile/2;
    _lineHorizontal = _endGridY+_ecart+_ecartText+_sizeTile/2;
    _tokenSize      = _tokenSizePourcent*_sizeTile;
    _tokenMargin    = (_sizeTile-_tokenSize)/2;
    _isLineOK = std::pair<int,int>(_size/2, _size/2);

}


