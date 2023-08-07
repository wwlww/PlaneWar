#ifndef BOMB_H
#define BOMB_H

#include <QObject>
#include <QPixmap>
#include <QVector>
#include "config.h"
class Bomb : public QObject
{
    Q_OBJECT
public:
    explicit Bomb(QObject *parent = nullptr);

    //更新信息（播放图片下标，播放间隔
    void updateInfo();

public:
    //爆炸资源数组
    QVector<QPixmap> m_PixArr;

    //爆炸位置
    int m_X;
    int m_Y;

    //爆炸状态
    bool m_Free;

    //爆炸时间间隔
    int m_Recorder;

    //爆炸的图片下标
    int m_Index;

signals:

};

#endif // BOMB_H
