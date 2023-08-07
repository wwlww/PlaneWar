#include "mainscence.h"

#include <QIcon>
#include <QPainter>

Mainscence::Mainscence(QWidget *parent)
    : QWidget(parent)
{
    //调用初始化场景
    initScene();

    //定时器设置
    m_Timer.setInterval(GAME_RATE);

    //开始游戏
    palyGame();
}

Mainscence::~Mainscence()
{
}

void Mainscence::initScene()
{
    //设置窗口的固定尺寸
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);

    //设置标题
    setWindowTitle(GAME_TITLE);

    //加载图标
    setWindowIcon(QIcon(GAME_ICON_PATH));

    //敌机出场时间间隔初始化
    m_Recorder = 0;

    //随机数种子
    srand((unsigned int)time(NULL));
}

void Mainscence::palyGame()
{
    //启动背景音乐
    QSound::play(SOUND_BACKGROUND);
    //启动定时器
    m_Timer.start();

    //监听定时器
    connect(&m_Timer,&QTimer::timeout,[=](){
        //敌机出场
        enemyToScence();
        //更新游戏中的坐标
        updatePosition();
        //重新绘制图片
        update();   //paintEvent的自带更新函数
        //碰撞检测
        collisionDetection();
    });
}

void Mainscence::updatePosition()
{
    //更新地图的坐标
    m_map.mapPosition();

    //发射子弹
    m_Hero.shoot();

    //计算所有非空闲子弹的坐标
    for(int i = 0;i < BULLET_NUM;i++){
        //如果非空闲，计算发射位置
        if(m_Hero.m_bullets[i].m_Free == false){
            m_Hero.m_bullets[i].updatePositon();
        }
    }

    //敌机出场
    for(int i = 0;i < ENEMY_NUM;i++){
        //判断是否空闲，非空闲则更新坐标
        if(m_Enemys[i].m_Free == false){
            m_Enemys[i].updatePosition();
        }
    }

    //计算爆炸播放图片
    for(int i = 0;i < BOMB_NUM;i++){
        //遍历所有非空闲的爆炸
        if(!m_Bombs[i].m_Free){
            m_Bombs[i].updateInfo();
        }
    }
}

void Mainscence::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    //绘制地图
    painter.drawPixmap(0,m_map.map1_pos_y,m_map.map1);
    painter.drawPixmap(0,m_map.map2_pos_y,m_map.map2);

    //绘制飞机
    painter.drawPixmap(m_Hero.m_X,m_Hero.m_Y,m_Hero.m_Palne);

    //绘制子弹
    for(int i = 0;i < BULLET_NUM;i++){
        //如果非空闲，绘制
        if(m_Hero.m_bullets[i].m_Free == false){
            painter.drawPixmap(m_Hero.m_bullets[i].m_X,m_Hero.m_bullets[i].m_Y,m_Hero.m_bullets[i].m_Bullet);
        }
    }

    //绘制敌机
    for(int i = 0;i < ENEMY_NUM;i++){
        //判断是否空闲
        if(m_Enemys[i].m_Free == false){
            painter.drawPixmap(m_Enemys[i].m_X,m_Enemys[i].m_Y,m_Enemys[i].m_Enemy);
        }
    }

    //绘制爆炸
    for(int i = 0;i < BOMB_NUM;i++){
        //遍历所有非空闲的爆炸
        if(!m_Bombs[i].m_Free){
            painter.drawPixmap(m_Bombs[i].m_X,m_Bombs[i].m_Y,m_Bombs[i].m_PixArr[m_Bombs[i].m_Index]);
        }
    }
}

void Mainscence::mouseMoveEvent(QMouseEvent *event)
{
    //捕获鼠标点击位置并偏移到飞机中心
    int x = event->x() - m_Hero.m_Rect.width() * 0.5;
    int y = event->y() - m_Hero.m_Rect.height() * 0.5;

    //边界检测
    if(x <= 0){
        x = 0;
    }
    if(x >= GAME_WIDTH - m_Hero.m_Rect.width()){
        x = GAME_WIDTH - m_Hero.m_Rect.width();
    }
    if(y <= 0){
        y = 0;
    }
    if(y >= GAME_HEIGHT - m_Hero.m_Rect.height()){
        y = GAME_HEIGHT - m_Hero.m_Rect.height();
    }

    m_Hero.setPosition(x,y);
}

void Mainscence::enemyToScence()
{
    m_Recorder++;

    //如果未达到时间间隔，直接返回
    if(m_Recorder < ENEMY_INTERVAL){
        return;
    }

    //重置计算器
    m_Recorder = 0;

    for(int i = 0;i < ENEMY_NUM;i++){
        //判断是否空闲
        if(m_Enemys[i].m_Free){
            m_Enemys[i].m_Free = false;

            //坐标
            m_Enemys[i].m_X = rand()%(GAME_WIDTH-m_Enemys[i].m_Rect.width());
            m_Enemys[i].m_Y = - m_Enemys[i].m_Rect.height();
            break;
        }
    }
}

void Mainscence::collisionDetection()
{
    //遍历所有非空闲的敌机
    for(int i = 0;i < ENEMY_NUM;i++){
        if(m_Enemys[i].m_Free){
            continue;
        }
        //遍历所有非空闲的子弹
        for(int j = 0;j < BULLET_NUM;j++){
            if(m_Hero.m_bullets[i].m_Free){
                continue;
            }

            //如果子弹和飞机相加，则发生了碰撞
            if(m_Enemys[i].m_Rect.intersects(m_Hero.m_bullets[j].m_Rect)){
                m_Enemys[i].m_Free = true;
                m_Hero.m_bullets[j].m_Free = true;

                //播放爆炸效果
                for(int k = 0;k < BOMB_NUM;k++){
                    //遍历空闲的爆炸
                    if(m_Bombs[k].m_Free){
                        m_Bombs[k].m_Free = false;
                        //爆炸位置为击毁的敌机位置
                        m_Bombs[k].m_X = m_Enemys[i].m_X;
                        m_Bombs[k].m_Y = m_Enemys[i].m_Y;
                        //播放爆炸音效
                        QSound::play(SOUND_BOMB);
                        break;
                    }
                }
            }
        }
    }
}

