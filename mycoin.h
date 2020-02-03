#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>
#include <QTimer>
#include <QMouseEvent>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    MyCoin(QString btnImg);

    void changeFlag();
    bool isAnimation = false;

    void mousePressEvent(QMouseEvent *);

    //金币位置以及属性
    int posX;
    int posY;
    bool flag;
    QTimer *timer1;//正面翻反面
    QTimer *timer2;//反面翻正面

    bool isWin = false;

signals:

};

#endif // MYCOIN_H
