#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QPixmap>
#include "config.h"
class Bullet : public QObject
{
    Q_OBJECT
public:
    explicit Bullet(QObject *parent = nullptr);

    //更新子弹坐标
    void updatePositon();
public:
    //子弹资源对象
    QPixmap m_Bullet;

    //子弹坐标
    int m_X;
    int m_Y;

    //子弹移动速度
    int m_Speed;

    //子弹是否闲置
    bool m_Free;

    //子弹的矩形边框
    QRect m_Rect;

signals:

};

#endif // BULLET_H
