#include "banana.h"
#include "player.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "game.h"
#include <QMediaPlayer>
#include <QRandomGenerator>

extern game * Game;

banana::banana() : QObject(), QGraphicsPixmapItem(){
    int random_number = QRandomGenerator::global()->generate() % 700;
    setPos(random_number, 0);

    setPixmap(QPixmap(":/images/banana.png"));

    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);

    catchsound = new QMediaPlayer();
    catchsound->setMedia(QUrl("qrc:/sounds/catch.wav"));
}

void banana::move(){
    //collision
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(int i=0, n = colliding_items.size(); i<n;++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(player)){

            if(catchsound->state() == QMediaPlayer::PlayingState){
                catchsound->setPosition(0);
            } else if (catchsound->state() == QMediaPlayer::StoppedState){
            catchsound->play();
            }


            //increase the score
            Game->Score->increase();

            scene()->removeItem(this);
            delete this;
        }
    }

    setPos(x(), y()+Game->Score->getVel());
    if(pos().y() + QPixmap().height() < 0){
        scene() -> removeItem(this);
        delete this;
    }


    if(pos().y() > 600){

        Game->Health->decrease();

        scene()->removeItem(this);
        delete this;
    }
}
