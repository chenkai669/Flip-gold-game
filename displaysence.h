#ifndef DISPLAYSENCE_H
#define DISPLAYSENCE_H

#include <QMainWindow>
#include "mycoin.h"

class displaysence : public QMainWindow
{
    Q_OBJECT
public:
    //explicit displaysence(QWidget *parent = 0);
    displaysence(int levelNum);
    void paintEvent(QPaintEvent *event);

signals:
    void chooseSenceback();

public slots:

private:
    int levelIndex;
    int gameArray[4][4];
    MyCoin *coinbtn[4][4];
    bool isWin = false;
};

#endif // DISPLAYSENCE_H
