#ifndef ENEMY3_H
#define ENEMY3_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
#include <QTimer>

class banana_faster : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    banana_faster();
    QMediaPlayer * catchsound;

public slots:
    void move3();
};

#endif // ENEMY3_H
