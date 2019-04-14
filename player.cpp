#include "player.h"
#include <QKeyEvent>
#include "banana.h"
#include "bad_banana.h"
#include "banana_faster.h"
#include "game.h"
#include <QGraphicsScene>
#include <QTimer>

extern game * Game;


void player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left){
        if(pos().x() > 0)
        setPos(x()-20, y());
    }
    else if(event->key() == Qt::Key_Right){
        if(pos().x() + 100 < 800)
        setPos(x()+20, y());
    }
}

void player::spawn()
{
    //create an enemy
    banana * Enemy = new banana();
    scene()->addItem(Enemy);
}

void player::spawn2()
{
    //create an enemy
    bad_banana * Enemy2 = new bad_banana();
    scene()->addItem(Enemy2);
}
void player::spawn3()
{
    //create an enemy
    if(Game->Score->getScore() > 5){
    Game->timer->stop();
    banana_faster * Enemy3 = new banana_faster();
    scene()->addItem(Enemy3);
    }
}


