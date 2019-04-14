#include "banana_faster.h"
#include "player.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "game.h"
#include <QMediaPlayer>
#include <QRandomGenerator>

extern game * Game;

banana_faster::banana_faster() : QObject(), QGraphicsPixmapItem(){
    int random_number = QRandomGenerator::global()->generate() % 700;
    setPos(random_number, 0);

    //drew graphics
    setPixmap(QPixmap(":/images/banana.png"));

    //connect
    QTimer * timer3 = new QTimer(this);
    connect(timer3, SIGNAL(timeout()), this, SLOT(move3()));

    timer3->start(50);

    catchsound = new QMediaPlayer();
    catchsound->setMedia(QUrl("qrc:/sounds/catch.wav"));
}

void banana_faster::move3(){
    //if enemy collides with player, destroy enemy
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(int i=0, n = colliding_items.size(); i<n;++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(player)){

            if(catchsound->state() == QMediaPlayer::PlayingState){
                catchsound->setPosition(0);
            } else if (catchsound->state() == QMediaPlayer::StoppedState){
            catchsound->play();
            }

            //decrease the score
            Game->Score->increase();

            scene()->removeItem(this);
            delete this;

        }
    }


    //move enemy down
    setPos(x(), y()+Game->Score->getVel());
    if(pos().y() + QPixmap().height() < 0){
        scene() -> removeItem(this);
        delete this;
    }

    //destroy enemy and health
    if(pos().y() > 600){
        //decrease the health
        Game->Health->decrease();

        scene()->removeItem(this);
        delete this;
    }
}
