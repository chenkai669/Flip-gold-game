#ifndef DISPLAYSENCE_H
#define DISPLAYSENCE_H

#include <QMainWindow>

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
};

#endif // DISPLAYSENCE_H
