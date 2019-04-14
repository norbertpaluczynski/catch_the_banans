#include "health.h"
#include <QFont>
#include <QApplication>
#include <QTimer>


health::health(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    Health = 3;

    //text
    setPlainText(QString("Życia: ") + QString::number(Health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",20, QFont::Bold));

    faintsound = new QMediaPlayer();
    faintsound->setMedia(QUrl("qrc:/sounds/fainted.mp3"));
}

void health::quit(){
    qApp->quit();
}

void health::decrease()
{
    Health--;
    setPlainText(QString("Życia: ") + QString::number(Health));
    if(Health <= 0){
        faintsound->play();
        QTimer::singleShot(2000, qApp, SLOT(quit()));
    }
}

int health::getHealth()
{
    return Health;
}



