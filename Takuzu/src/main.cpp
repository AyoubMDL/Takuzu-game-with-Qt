#include "view/menuView.hpp"

#include <QApplication>
#include "view/gameView.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MenuView w;
    w.show();

    return a.exec();
}
