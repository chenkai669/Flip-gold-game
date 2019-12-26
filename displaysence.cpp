#include "displaysence.h"
#include "QDebug"
#include <QMenuBar>
#include <QPixmap>
#include <QPainter>
#include "mypushbutton.h"
#include <QTimer>
#include <QLabel>
#include "mycoin.h"

displaysence::displaysence(int num)
{

    QString str = QString("enter %1 guan").arg(num);
    qDebug()<<str;
    levelIndex = num;
    //配置场景
    this->setFixedSize(320,588);
    this->setWindowIcon(QPixmap(":/Image/xiaoyuanbao.png"));
    this->setWindowTitle("choose sence");

    //创建菜单栏
    QMenuBar *bar = menuBar();
    QMenu *startbar = bar->addMenu("start");
    QAction *exitbar = startbar->addAction("exit");

    connect(exitbar,&QAction::triggered,[=](){
        this->close();
    });
    //返回按钮
    MyPushButton *backBtn = new MyPushButton(":/Image/bac.png",":/Image/bac1.png");
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width()+70,this->height() - backBtn->height()+50);

    connect(backBtn,&QPushButton::clicked,[=](){
        //发送自定义信号
        QTimer::singleShot(300,this,[=](){
            emit this->chooseSenceback();
        });
    });

    QLabel *label = new QLabel;
    label->setParent(this);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    //将字体设置到控件中
    label->setFont(font);
    QString str1 = QString("Level: %1").arg(num);
    label->setText(str1);
    label->setAlignment(Qt::AlignLeft);
    label->setGeometry(30,this->height() -50,120,50);

    //显示金币背景图案
    for(int i = 0;i<4;i++)
    {
        for(int j = 0;j<4;j++)
        {
             QLabel *label = new QLabel;
             QPixmap pix = QPixmap(":/Image/beijing.jpg");
             label->setGeometry(0,0,pix.width(),pix.height());
             label->setStyleSheet("QLabel{border: 0px}");
             label->setParent(this);
             label->setPixmap(pix);
             label->move(57+i*53,200+j*53);

             //创建金币或者银币
             MyCoin *coin = new MyCoin(":/Image/yinbi.jpg");
             coin->setParent(this);
             coin->move(57+i*53,200+j*53);

        }


    }



}

void displaysence::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    bool ret = pix.load(":/Image/background.jpg");
    if(!ret)
    {
        return;
    }
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
