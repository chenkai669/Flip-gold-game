#include "mainscene.h"
#include "ui_mainscene.h"
#include <QPainter>
#include <QPixmap>
#include "mypushbutton.h"
#include <QDebug>
#include <QTimer>

MainScene::MainScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScene)
{
    ui->setupUi(this);
    chooseSence = new ChooseLevelSence;
    //设定固定大小
    setFixedSize(600,700);
    setWindowIcon(QIcon(":/Image/xiaoyuanbao.png"));
    //退出按钮
    connect(ui->actionExit,&QAction::triggered,this,&QMainWindow::close);
    MyPushButton *startBtn = new MyPushButton(":/Image/start.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5 - startBtn->width()*0.5,this->height()*0.7);

    //监听back信号
    connect(chooseSence,&ChooseLevelSence::chooseScenBack,this,[=](){

        QTimer::singleShot(300,this,[=](){
            chooseSence->hide();
            this->show();
        });
    });
    connect(startBtn,&QPushButton::clicked,[=](){
        startBtn->zoom1();
        startBtn->zoom2();
        //延时
        QTimer::singleShot(500,this,[=](){
            //自身隐藏 显示选择管卡
            this->hide();
            chooseSence->show();
        });
    });

}

void MainScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/Image/background.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    pix.load(":/Image/beijingtubiao.jpg");
    //图片缩放
    pix = pix.scaled(pix.width()*0.7,pix.height()*0.8);
    painter.drawPixmap(0,30,80,80,pix);
}

MainScene::~MainScene()
{
    delete ui;
}
