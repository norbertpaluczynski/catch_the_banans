#include <QApplication>
#include "game.h"
#include "health.h"

game * Game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Game = new game();
    Game->show();

    return a.exec();

}
