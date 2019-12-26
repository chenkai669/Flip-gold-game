#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyPushButton(QWidget *parent = 0);
    //参数1正常显示  参数2 按下后显示图片
    MyPushButton(QString normalImg,QString pressImg = "");

    void zoom1();
    void zoom2();

    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

signals:

public slots:

private:
    QString normalImgPath;
    QString pressImgPath;
};

#endif // MYPUSHBUTTON_H
