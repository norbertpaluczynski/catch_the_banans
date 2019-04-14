#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "Score.h"
#include "health.h"
#include <QTimer>

class game: public QGraphicsView{
public:
    game();
    QTimer * timer;
    QTimer * timer2;
    QTimer * timer3;
    QGraphicsScene * scene;
    player * Player;
    score * Score;
    health * Health;
};


#endif // GAME_H
