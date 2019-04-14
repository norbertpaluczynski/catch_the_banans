#include "bad_banana.h"
#include "player.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "game.h"
#include <QMediaPlayer>
#include <QRandomGenerator>
#include <QDebug>

extern game * Game;

bad_banana::bad_banana() : QObject(), QGraphicsPixmapItem(){
    int random_number = QRandomGenerator::global()->generate() % 700;
    setPos(random_number, 0);


    setPixmap(QPixmap(":/images/banana3.png"));


    QTimer * timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()), this, SLOT(move2()));

    timer2->start(50);

    catchsound = new QMediaPlayer();
    catchsound->setMedia(QUrl("qrc:/sounds/redbananasound.mp3"));
}

void bad_banana::move2(){
    //collision
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(int i=0, n = colliding_items.size(); i<n;++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(player)){

            if(catchsound->state() == QMediaPlayer::PlayingState){
                //catchsound->setPosition(0);
            } else if (catchsound->state() == QMediaPlayer::StoppedState){
            catchsound->play();
            }

            //decrease the score
            Game->Health->decrease();

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
        scene()->removeItem(this);
        delete this;
    }
}
