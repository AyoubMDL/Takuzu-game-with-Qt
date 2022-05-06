#ifndef MODEL_HPP
#define MODEL_HPP

#include <QObject>
#include "Grid.hpp"

class Model : public QObject {
    Q_OBJECT
public:
    Model(int gridSize, Difficulty difficulty, QObject *parent = nullptr);
    Grid & getGrid();
    std::pair<int, int> numberOfFillCellsInRow(const unsigned int row) const;
    std::pair<int, int> numberOfFillCellsInColumn(const unsigned int column) const;
    bool conflictInColumn(const unsigned int row, const unsigned int column) const;
    bool conflictInRow(const unsigned int row, const unsigned int column) const;
    bool identicalRows(const int r1, const int r2) const;
    bool identicalColumns(const int c1, const int c2) const;
    bool gameOver();
signals:
        void newCellSelected();
public slots:
    void nextMove(unsigned int row, unsigned int column);


private:
    bool isValidPosition(const unsigned int row, const unsigned int column) const;
    bool isWhite(const Cell cell) const;
    bool isBlack(const Cell cell) const;
    bool isEmpty(const Cell cell) const;
    bool isEqualCells(std::pair<unsigned int, unsigned int> cellNumber) const;


    bool sameCellType(const Cell firstCell, const Cell secondCell) const;

    Cell changeCell(Cell cell);


private:
    Grid _grid;
    unsigned int _gridSize;
};

#endif // MODEL_H
