#include "model/Model.hpp"
#include <string>
using namespace std;

Model::Model(int gridSize, Difficulty difficulty, QObject *parent) : QObject(parent), _gridSize(gridSize)
{
    _grid.setGridSize(gridSize);
    _grid.chooseGrid(difficulty, _gridSize);
}



bool Model::isWhite(const Cell cell) const {
    return cell == White || cell == LockedWhite;
}

bool Model::isBlack(const Cell cell) const {
    return cell == Black || cell == LockedBlack;
}

bool Model::isEmpty(const Cell cell) const {
    return cell == Empty;
}


Grid & Model::getGrid(){
    return _grid;
}



bool Model::identicalRows(const int r1, const int r2) const {
    for(unsigned int column = 0; column < _grid.getSize(); column++) {
        std::pair<int,int> first(r1, column);
        std::pair<int,int> second(r2, column);
        if (!sameCellType(_grid[first], _grid[second])) {
            return false;
        }
    }
    return true;
}


bool Model::isValidPosition(const unsigned int row, const unsigned int column) const {
    return (row <= _gridSize-1) && (column <= _gridSize-1);
}

bool Model::conflictInRow(const unsigned int row, const unsigned int column) const {
    const std::pair<int,int> currentPosition(row, column);
    if(column > 0 && column < _gridSize-1 && !isEmpty(_grid[currentPosition])) {
        const std::pair<int,int> leftPosition(row, column-1);
        const std::pair<int,int> rightPosition(row, column+1);

        Cell currentCell = _grid[currentPosition];
        Cell leftCell = _grid[leftPosition];
        Cell rightCell = _grid[rightPosition];

        return (sameCellType(currentCell, leftCell) && sameCellType(currentCell, rightCell));
    }
    return false;
}

bool Model::conflictInColumn(const unsigned int row, const unsigned int column) const {
    const std::pair<int,int> currentPosition(row, column);
    if(row > 0 && row < _gridSize-1 && !isEmpty(_grid[currentPosition])) {
        const std::pair<int,int> behindPosition(row+1, column);
        const std::pair<int,int> frontPosition(row-1, column);
        Cell currentCell = _grid[currentPosition];
        Cell behindCell = _grid[behindPosition];
        Cell frontCell = _grid[frontPosition];
        return (sameCellType(currentCell, frontCell) && sameCellType(currentCell, behindCell));
    }
    return false;
}

bool Model::isEqualCells(std::pair<unsigned int, unsigned int> cellNumber) const {
      return cellNumber.first == _gridSize/2 && cellNumber.second == _gridSize/2;
}

bool Model::gameOver() {
    for(unsigned int i = 0 ; i < _gridSize; ++i) {
        std::pair<int, int> countCellRow = numberOfFillCellsInRow(i);
        std::pair<int, int> countCellColumn = numberOfFillCellsInColumn(i);
        if(!isEqualCells(countCellRow) || !isEqualCells(countCellColumn)) {
            return false;
        }
        for(unsigned int j = 0; j < _gridSize; ++j) {
            if(i != j) {
                if(identicalColumns(i, j) || identicalRows(i, j)) {
                    return false;
                }
            }
            if(conflictInColumn(i, j) || conflictInRow(i, j)) {
                return false;
            }

        }
    }
    return true;
}


bool Model::identicalColumns(const int c1, const int c2) const {
    for(unsigned int row = 0; row < _grid.getSize(); row++) {
        std::pair<int,int> first(row, c1);
        std::pair<int,int> second(row, c2);
        if (!sameCellType(_grid[first], _grid[second])) {
            return false;
        }
    }
    return true;
}


bool Model::sameCellType(const Cell firstCell, const Cell secondCell) const {
    if(isWhite(firstCell)) {
        return isWhite(secondCell);
    } else if(isBlack(firstCell)) {
        return isBlack(secondCell);
    }
    return isEmpty(secondCell);
}


std::pair<int, int> Model::numberOfFillCellsInRow(const unsigned int row) const {
    std::pair<int, int> counter;
    int blackCells = 0;
    int whiteCells = 0;

    for(unsigned int column = 0; column < _grid.getSize(); column++) {
        std::pair<int,int> currentPos(row, column);
        if(isBlack(_grid[currentPos])) {
            blackCells++;
        } else if (isWhite(_grid[currentPos])) {
            whiteCells++;
        }
    }
    counter.first = blackCells;
    counter.second = whiteCells;

    return counter;

}

std::pair<int, int> Model::numberOfFillCellsInColumn(const unsigned int column) const {
    std::pair<int, int> counter;
    int blackCells = 0;
    int whiteCells = 0;

    for(unsigned int row = 0; row < _grid.getSize(); row++) {
        std::pair<int,int> currentPos(row, column);
        if(isBlack(_grid[currentPos])) {
            blackCells++;
        } else if (isWhite(_grid[currentPos])) {
            whiteCells++;
        }
    }
    counter.first = blackCells;
    counter.second = whiteCells;

    return counter;
}

void Model::nextMove(unsigned int row, unsigned int column) {
    std::pair<int,int> currentPos(column, row);
    Cell newCell = changeCell(_grid[currentPos]);
    getGrid().setCellType(column, row, newCell);
    emit newCellSelected();
}



Cell Model::changeCell(Cell cell) {
    if (cell == Empty) {
        return Black;
    } else if (cell == Black) {
        return White;
    } else if(cell == White) {
        return Empty;
    } else if(cell == LockedBlack) {
        return LockedBlack;
    } else {
        return LockedWhite;
    }
}


