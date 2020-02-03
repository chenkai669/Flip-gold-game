#include "displaysence.h"
#include "QDebug"
#include <QMenuBar>
#include <QPixmap>
#include <QPainter>
#include "mypushbutton.h"
#include <QTimer>
#include <QLabel>
#include "dataconfig.h"
#include <QPropertyAnimation>

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

    dataConfig config;
    for(int i = 0;i<4;i++)
    {
        for(int j = 0;j<4;j++)
        {
            this->gameArray[i][j] = config.mData[this->levelIndex][i][j];
        }
    }

    QLabel *winLabel = new QLabel;
    QPixmap tmpPix;
    tmpPix.load(":/Image/shenglil.PNG");
    winLabel->setGeometry(0,0,tmpPix.width(),tmpPix.height());
    winLabel->setStyleSheet("QLabel{border: 0px}");
    winLabel->setParent(this);
    winLabel->setPixmap(tmpPix);
    winLabel->move(this->width()-tmpPix.width()*1.1,tmpPix.height()-500);

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
            QString str;
            if(this->gameArray[i][j] == 1)
            {
                str = ":/Image/jinbi.jpg";//金币
            }
            else
            {
                str = ":/Image/yinbi.jpg";//银币
            }
            MyCoin *coin = new MyCoin(str);
            coin->setParent(this);
            coin->move(57+i*53,200+j*53);
            coin->posX = i;
            coin->posY = j;
            coin->flag = this->gameArray[i][j];

            coinbtn[i][j] = coin;//维护按钮

            connect(coin,&MyCoin::clicked,[=](){
                qDebug()<<"点击了按钮";
                coin->changeFlag();
                this->gameArray[i][j] = this->gameArray[i][j] == 0 ? 1:0;


                //翻转金币周围
                QTimer::singleShot(300,this,[=](){

                    //X右
                    if(coin->posX +1<=3)//右侧周围
                    {
                        coinbtn[coin->posX+1][coin->posY]->changeFlag();
                        this->gameArray[coin->posX+1][coin->posY] = this->gameArray[coin->posX+1][coin->posY] == 0?1:0;//维护二维数组
                    }
                    //X左
                    if(coin->posX-1 >= 0)
                    {
                        coinbtn[coin->posX-1][coin->posY]->changeFlag();
                        this->gameArray[coin->posX-1][coin->posY] = this->gameArray[coin->posX-1][coin->posY] == 0?1:0;//维护二维数组
                    }
                    //Y上
                    if(coin->posY +1<=3)//右侧周围
                    {
                        coinbtn[coin->posX][coin->posY+1]->changeFlag();
                        this->gameArray[coin->posX][coin->posY+1] = this->gameArray[coin->posX][coin->posY+1] == 0?1:0;//维护二维数组
                    }
                    //Y下
                    if(coin->posY -1>=0)//右侧周围
                    {
                        coinbtn[coin->posX][coin->posY-1]->changeFlag();
                        this->gameArray[coin->posX][coin->posY-1] = this->gameArray[coin->posX][coin->posY-1] == 0?1:0;//维护二维数组
                    }

                    this->isWin = true;
                    for(int i = 0;i<4;i++)
                    {
                        for(int j = 0;j<4;j++)
                        {
                            if(coinbtn[i][j]->flag == false)
                            {
                                this->isWin = false;
                                break;
                            }
                        }
                    }
                    if(this->isWin == true)
                    {
                        qDebug()<<"胜利了";
                        for(int i = 0;i<4;i++)
                        {
                            for(int j = 0;j<4;j++)
                            {
                                coinbtn[i][j]->isWin = true;
                            }
                        }
                        //将胜利图片砸下来
                        QPropertyAnimation *animation = new QPropertyAnimation(winLabel,"geometry");
                        animation->setDuration(1000);
                        //设置开始位置
                        animation->setStartValue(QRect(winLabel->x(),winLabel->y(),winLabel->width(),winLabel->height()));
                        //设置结束位置
                        animation->setEndValue(QRect(winLabel->x(),-winLabel->y()*0.05,winLabel->width(),winLabel->height()));
                        //设置曲线
                        animation->setEasingCurve(QEasingCurve::OutBounce);
                        animation->start();
                    }
                });
            });
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
