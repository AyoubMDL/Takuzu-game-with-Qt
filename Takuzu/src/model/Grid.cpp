#include "model/Grid.hpp"
using namespace std;

Grid::Grid() : _size(6){}


unsigned int Grid::getSize() const {
    return _size;
}

const Cell & Grid::getCellType(unsigned int row, unsigned int column) const {
    return _grid.at(row * _size + column % _size);
}

const Cell & Grid::operator[](const std::pair<int,int> & position) const{
    return _grid.at(position.first * _size + position.second % _size);
}

void Grid::setCharGrid(string charGrid) {
    _charGrid = charGrid;
}


string Grid::getCharGrid() const {
    return _charGrid;
}

vector<Cell> Grid::getCellGrid() const {
    return _grid;
}

void Grid::setGridSize(const unsigned int size) {
    _size = size;
}




Cell Grid::convertToCell(char cellChar) {
    switch(cellChar) {
        case '.':
            return Empty;
        case 'B':
            return LockedBlack;
        case 'W':
            return LockedWhite;
        default :
            throw "Unknown character";

    }
}

void Grid::setCellGrid() {
    for(unsigned int i = 0; i < _size * _size; ++i) {
        _grid.push_back(convertToCell(_charGrid[i]));
    }
}


void Grid::selectGrid() {
    std::random_device generator;
    std::mt19937 rng(generator());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, _gridNumber-1);
    setCharGrid(_grids.at(dist6(rng)));
    setCellGrid();
}


void Grid::setCellType(unsigned int row, unsigned int column, Cell cell) {
    _grid[row * _size + column] = cell;
}

void Grid::chooseGrid(const Difficulty difficulty, const unsigned int size) {
    QString name = QString::number(size);
    if (difficulty == Easy) {
        name.append("_easy.txt");
    } else {
        name.append("_hard.txt");
    }
    loadGrid(name);
    selectGrid();
}


void Grid::loadGrid(const QString & path) {
    _gridFile = new QFile(":/TakuzuGrids/"+path);
    if(!_gridFile->open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::information(0, "error", _gridFile->errorString());
    }
    QTextStream in(_gridFile);

    bool firstLine = true;
    while(!in.atEnd()) {
        QString line = in.readLine();
        if(firstLine) {
            setGridNumber(line.toUInt());
            firstLine = false;
        } else {
            _grids.push_back(line.toStdString());
        }
    }
    _gridFile->close();
}



unsigned int Grid::getGridNumber() const {
    return _gridNumber;
}

void Grid::setGridNumber(unsigned int gridNumber) {
    _gridNumber = gridNumber;
}


std::vector<std::string> Grid::getGrids() const {
    return _grids;
}


char Grid::convertToChar(Cell type) {
    switch(type) {
        case Empty:
            return '.';
        case Black:
            return 'B';
        case White:
            return 'W';
        default :
            throw "Unknown cell type";

    }
}
