 #ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
//#include <QMediaPlayer>

class player : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
   // QMediaPlayer * moveright;
   // QMediaPlayer * moveleft;
    QTimer * timer;
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
    void spawn2();
    void spawn3();


};

#endif // MYRECT_H
