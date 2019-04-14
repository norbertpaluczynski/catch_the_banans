#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
#include <QTimer>

class banana : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    banana();
    QMediaPlayer * catchsound;

public slots:
    void move();
};


#endif // ENEMY_H
