#ifndef CHOOSELEVELSENCE_H
#define CHOOSELEVELSENCE_H

#include <QMainWindow>
#include <QObject>
#include "displaysence.h"

class ChooseLevelSence : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelSence(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
signals:
    //自定义的信号，返回主场景
    void chooseScenBack();

public slots:
private:
    displaysence *pSence = NULL;
};

#endif // CHOOSELEVELSENCE_H
