#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H

#include <QObject>
#include <QPixmap>
#include "config.h"
#include <QRect>

class EnemyPlane : public QObject
{
    Q_OBJECT
public:
    explicit EnemyPlane(QObject *parent = nullptr);

    //更新坐标
    void updatePosition();
public:
    //敌机资源对象
    QPixmap m_Enemy;

    //位置
    int m_X;
    int m_Y;

    //敌机的矩形边框
    QRect m_Rect;

    //状态
    bool m_Free;

    //速度
    int m_Speed;

};

#endif // ENEMYPLANE_H
