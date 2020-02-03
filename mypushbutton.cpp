#include "mypushbutton.h"
#include <QPixmap>
#include <QDebug>
#include <QPropertyAnimation>


MyPushButton::MyPushButton(QString normalImg,QString pressImg)
{
   this->resize(50,50);
   this->normalImgPath = normalImg;
   this->pressImgPath = pressImg;

   QPixmap pix ;
   bool ret = pix.load(normalImg);
   if(!ret)
   {
       return ;
   }
   //设置图片固定大小
   this->setFixedSize(pix.width(),pix.height());
   //设置不规则图片样式
   this->setStyleSheet("QPushButton{border: 0px}");
   //设置图标
   this->setIcon(pix);
   //设置图标大小
   this->setIconSize(QSize(pix.width()*0.3,pix.width()*0.3));
}

void MyPushButton::zoom1()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this,"geometry"); //b不能创建在栈上
    animation->setDuration(200);
    animation->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
    animation->setEndValue(QRect(this->x(), this->y()+10, this->width(), this->height()));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();


}
void MyPushButton::zoom2()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this,"geometry"); //b不能创建在栈上
    animation->setDuration(200);
    animation->setStartValue(QRect(this->x(), this->y()+10, this->width(), this->height()));
    animation->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}

void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    if(this->pressImgPath != "")
    {
        QPixmap pix ;
        bool ret = pix.load(pressImgPath);
        if(!ret)
        {
            return ;
        }
        //设置图片固定大小
        this->setFixedSize(pix.width(),pix.height());
        //设置不规则图片样式
        this->setStyleSheet("QPushButton{border: 0px}");
        //设置图标
        this->setIcon(pix);
        //设置图标大小
        this->setIconSize(QSize(pix.width()*0.3,pix.width()*0.3));
    }
    return QPushButton::mousePressEvent(e);//将其余事件交还给系统
}
void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(this->pressImgPath != "")
    {
        QPixmap pix ;
        bool ret = pix.load(normalImgPath);
        if(!ret)
        {
            return ;
        }
        //设置图片固定大小
        this->setFixedSize(pix.width(),pix.height());
        //设置不规则图片样式
        this->setStyleSheet("QPushButton{border: 0px}");
        //设置图标
        this->setIcon(pix);
        //设置图标大小
        this->setIconSize(QSize(pix.width()*0.3,pix.width()*0.3));
    }
    return QPushButton::mouseReleaseEvent(e);
}
