#ifndef ENEMY2_H
#define ENEMY2_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
#include <QTimer>

class bad_banana : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    bad_banana();
    QMediaPlayer * catchsound;

public slots:
    void move2();
};


#endif // ENEMY2_H
