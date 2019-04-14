#include "score.h"
#include <QFont>
#include "game.h"
#include "player.h"
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QDebug>

extern game * Game;

score::score(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    Score = 0;

    vel = 5;

    //draw the text
    setPlainText(QString("Wynik: ") + QString::number(Score));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("times",20, QFont::Bold));
}


void score::increase()
{
    Score++;
    setPlainText(QString("Wynik: ") + QString::number(Score));
    if(Score>2) Game->setBackgroundBrush(QBrush(QImage(":/images/bg2.jpg")));
}

void score::decrease(){
    Score--;
    setPlainText(QString("Wynik: ") + QString::number(Score));
}

void score::incVel(){
    if(Score > 4) vel=7;
    if(Score>9) vel = 9;
    if(Score>14) vel = 12;
    if(Score>19) vel = 15;
    if(Score>25) vel = 18;
    if(Score>35) vel = 23;

}
int score::getVel(){
    return vel;
}


int score::getScore()
{
    return Score;
}
