#ifndef MAINSCENCE_H
#define MAINSCENCE_H

#include <QTimer>
#include <QWidget>
#include <QMouseEvent>
#include <QSound>
#include "config.h"
#include "map.h"
#include "heroplane.h"
#include "bullet.h"
#include "enemyplane.h"
#include <ctime>
#include "bomb.h"
class Mainscence : public QWidget
{
    Q_OBJECT

public:
    Mainscence(QWidget *parent = nullptr);
    ~Mainscence();

    //初始化场景
    void initScene();

    //启动游戏（启动定时器）
    void palyGame();

    //更新坐标
    void updatePosition();

    //绘图事件
    void paintEvent(QPaintEvent *);

    //重写鼠标移动事件
    void mouseMoveEvent(QMouseEvent *);

    //敌机出场
    void enemyToScence();

    //碰撞检测
    void collisionDetection();


public:

    //定时器对象
    QTimer m_Timer;

    //地图对象
    Map m_map;

    //飞机对象
    heroPlane m_Hero;

    //敌机数组
    EnemyPlane m_Enemys[ENEMY_NUM];

    //敌机出场间隔
    int m_Recorder;

    //爆炸数组
    Bomb m_Bombs[BOMB_NUM];

};
#endif // MAINSCENCE_H
