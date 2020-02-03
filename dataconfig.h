#ifndef DATACONFIG_H
#define DATACONFIG_H

#include <QObject>
#include <QMap>
#include <QVector>

class dataConfig
{
    //Q_OBJECT
public:
    dataConfig();

     QMap<int,QVector<QVector<int>>> mData;
private:

};

#endif // DATACONFIG_H
