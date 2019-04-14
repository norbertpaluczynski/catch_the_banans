#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include <QMediaPlayer>

class health : public QGraphicsTextItem{
public:
    health(QGraphicsItem * parent = 0);
    void decrease();
    int getHealth();
    void exit_app();
    QMediaPlayer * faintsound;
private:
    int Health;
public slots:
    void quit();
};



#endif // HEALTH_H
