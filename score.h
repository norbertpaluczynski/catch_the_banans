#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QTimer>

class score : public QGraphicsTextItem{
public:
    score(QGraphicsItem * parent = 0);
    void increase();
    void decrease();
    void incVel();
    int getScore();
    int getVel();


private:
    int Score;
    int vel;
};

#endif // SCORE_H
