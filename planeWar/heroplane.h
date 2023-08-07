#ifndef HEROPLANE_H
#define HEROPLANE_H

#include <QObject>
#include <QPixmap>
#include <QRect>
#include "config.h"
#include "bullet.h"
class heroPlane : public QObject
{
    Q_OBJECT
public:
    explicit heroPlane(QObject *parent = nullptr);

    //发射子弹
    void shoot();

    //设置飞机位置
    void setPosition(int x,int y);

public:
    //飞机资源对象
    QPixmap m_Palne;

    //飞机坐标
    int m_X;
    int m_Y;

    //飞机的矩形边框
    QRect m_Rect;

    //弹夹
    Bullet m_bullets[BULLET_NUM];

    //发射间隔记录
    int m_recorder;

};

#endif // HEROPLANE_H
