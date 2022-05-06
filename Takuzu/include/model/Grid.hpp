#ifndef GRID_HPP
#define GRID_HPP

#include <iostream>
#include <vector>
#include <random>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>

enum Cell {
    Empty,
    Black,
    White,
    LockedBlack,
    LockedWhite
};


enum Difficulty {
    Easy,
    Hard
};



class Grid
{
public:
    Grid();

    const Cell & getCellType(unsigned int row, unsigned int column) const;
    void setCellType(unsigned int row, unsigned int column, Cell cell);

    const Cell & operator[](const std::pair<int,int> & position) const;


    void setCharGrid(std::string charGrid);
    std::string getCharGrid() const;


    std::vector<Cell> getCellGrid() const;

    unsigned int getSize() const;
    void setGridSize(const unsigned int size);


    Cell convertToCell(char cellChar);
    char convertToChar(Cell type);


    void loadGrid(const QString &);
    std::vector<std::string> getGrids() const;


    unsigned int getGridNumber() const;
    void setGridNumber(unsigned int gridNumber);


    void setCellGrid();
    void chooseGrid(const Difficulty difficulty, const unsigned int size);



    void selectGrid();




private:
    unsigned int _size;
    std::vector<Cell> _grid;
    std::string _charGrid;
    QFile * _gridFile;
    std::vector<std::string> _grids;
    unsigned int _gridNumber;

};

#endif // GRID_H
