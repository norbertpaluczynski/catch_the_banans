#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "banana.h"
#include "score.h"
#include "health.h"
#include <QMediaPlayer>
#include <QGraphicsScene>
#include <QDebug>

extern game * Game;


game::game(){

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/images/bg.jpg")));



    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);


    Player = new player();
    Player->setPixmap(QPixmap(":/images/monkey.png"));
    Player->setPos(330,470);

    Player->setFlag(QGraphicsItem::ItemIsFocusable);
    Player->setFocus();

    scene->addItem(Player);


    Score = new score();
    scene->addItem(Score);
    Health = new health();
    Health->setPos(Health->x()+685, Health->y());
    scene->addItem(Health);




    timer = new QTimer(this);
    QObject::connect(timer,SIGNAL(timeout()),Player,SLOT(spawn()));
    timer->start(1300);


    timer2 = new QTimer(this);
    QObject::connect(timer2,SIGNAL(timeout()),Player,SLOT(spawn2()));
    timer2->start(5000);


    timer3 = new QTimer(this);
    QObject::connect(timer3,SIGNAL(timeout()),Player,SLOT(spawn3()));
    timer3->start(750);


    //bg music
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/bgsound.mp3"));
    music->play();

    show();
}
