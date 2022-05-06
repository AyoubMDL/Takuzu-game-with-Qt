#ifndef TAKUZU_HPP
#define TAKUZU_HPP

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QPen>
#include <QBrush>
#include <QPushButton>

#include "model/Model.hpp"


class takuzuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit takuzuWidget(QWidget *parent = nullptr);
    void setModel(Model * model);
    void mousePressEvent(QMouseEvent *event) override;
    void setShowErrorStatus(bool showError);
    void setCellType(bool circleType);
public slots:
    void drawNewCell();
    void updateShowErrors();
    void updateCellType();

signals:
    void cellClicked(unsigned int row, unsigned int column);
    void draw();
    void updateErrors();
    void updateCells();

protected:
    void paintEvent(QPaintEvent *event) override;
    void drawGrid();
    void drawTokens();
    void drawTokenCircle(int x, int y);
    void drawTokenRectangle(int x, int y);

    void drawConflict();
    void drawScorePerLine();
    void drawError(int lineIndex, bool isColumn);
    void actualizeWidget();

    void paintCell(int row, int column, Cell p);


private:

    Model * _model;
    bool _showError = false;
    bool _circleType = true;
    int _size;
    int _halfSize;

    // Pen & Brush
    QPainter * painter;
    QPen _Pen_big   = QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    QPen _Pen_small = QPen(Qt::gray,  1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    QBrush _Brush_white = QBrush(Qt::white);
    QBrush _Brush_black = QBrush(Qt::black);

    // attribut of size and position
    int _sizeGrid = 300;
    int _baseX = 100, _baseY = 10;
    int _ecart = 0;
    int _ecartText = 30;
    float _retirementLigne = 0.1;
    float _tokenSizePourcent = 0.8;

    typedef void (takuzuWidget::*methodWithtwoInt)(int,int);
    methodWithtwoInt drawToken = &takuzuWidget::drawTokenRectangle;


    // attribut to calculate only one time
    int _sizeTile;

    int _endGridX;
    int _endGridY = _baseY+_sizeGrid;

    int _lineVertical;
    int _lineHorizontal;

    int _tokenSize;
    int _tokenMargin;

    int _totalSize;

    std::pair<int,int> _isLineOK;


};

#endif // TAKUZU_H
