#include "chooselevelsence.h"
#include <QMenuBar>
#include <QPainter>
#include <QPixmap>
#include <mypushbutton.h>
#include <QLabel>
#include "displaysence.h"
#include <QDebug>

ChooseLevelSence::ChooseLevelSence(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(320,588);
    this->setWindowIcon(QPixmap(":/Image/xiaoyuanbao.png"));
    this->setWindowTitle("choose sence");

    //创建菜单栏
    QMenuBar *bar = new QMenuBar(this);
    setMenuBar(bar);

    //添加菜单
    QMenu *barStart = bar->addMenu("start");
    QAction *quitAction = barStart->addAction("exit");

    connect(quitAction,&QAction::triggered,[=](){
        this->close();
    });

    MyPushButton *backBtn = new MyPushButton(":/Image/bac.png",":/Image/bac1.png");
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width()+70,this->height() - backBtn->height()+50);
    connect(backBtn,&QPushButton::clicked,[=](){
        //发送自定义信号
        emit this->chooseScenBack();
    });
    //创建选择关卡
    for(int i = 0;i < 20;i++)
    {
        MyPushButton *menuBtn = new MyPushButton(":/Image/guanka.png");
        menuBtn->setParent(this);
        menuBtn->move(25 + i%4 * 70,130 + i/4 * 70);
        //监听按钮信号
        connect(menuBtn,&QPushButton::clicked,[=](){
            this->hide();
            pSence = new displaysence(i+1);
            pSence->show();

            //监听play返回按钮场景信号 这里有个坑 如果pSence没有被创建出来就区connect是连接不成功的 错误信息QObject::connect: invalid null parameter
            connect(pSence,&displaysence::chooseSenceback,this,[=](){
                this->show();
                delete pSence;
                pSence = NULL;
            });
        });

        QLabel * label = new QLabel;
        label->setParent(this);
        label->setFixedSize(menuBtn->width(),menuBtn->height());
        label->setText(QString::number(1+i));
        label->move(25 + i%4 * 70,130 + i/4 * 70);
        //设置Lebel文字对齐方式
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        //鼠标穿透
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }
}

void ChooseLevelSence::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    bool ret = pix.load(":/Image/background.jpg");
    if(!ret)
    {
        return ;
    }
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //加载标题
    //    pix.load(":/Image/beijingtubiao.jpg");
    //    //图片缩放
    //    pix = pix.scaled(pix.width()*0.7,pix.height()*0.8);
    //    painter.drawPixmap(0,30,80,80,pix);
}
