#include "mycoin.h"
#include <QPixmap>
#include <QDebug>

MyCoin::MyCoin(QString btnImg)
{
    QPixmap pix;
    bool  ret =  pix.load(btnImg);
    if(!ret)
    {
        QString str = QString("图片 %1 加载失败").arg(btnImg);
        return;
    }
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));

    timer1 = new QTimer(this);
    timer2 = new QTimer(this);

    connect(timer1,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str = QString(":/Image/yinbi.jpg");
        pix.load(str);
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border: 0px}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.width()));

            isAnimation = false;
            timer1->stop();

    });
    connect(timer2,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str = QString(":/Image/jinbi.jpg");
        pix.load(str);
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border: 0px}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.width()));

            isAnimation = false;
            timer2->stop();

    });
}

void MyCoin::changeFlag()
{
    //如果是正面
    if(this->flag)
    {
                qDebug()<<"222";
        timer1->start(30);
        isAnimation = true;
        this->flag = false;
    }
    else
    {
        qDebug()<<"222";
        timer2->start(30);
        isAnimation = true;
        this->flag = true;
    }
}

void MyCoin::mousePressEvent(QMouseEvent *e)
{
    if(this->isAnimation || this->isWin)
    {
        qDebug()<<"被拦击了";
          qDebug()<<"isAnimation "<<isAnimation<<"isWin "<<isWin;

       return;
    }
    else
    {
       return QPushButton::mousePressEvent(e);
    }
}
