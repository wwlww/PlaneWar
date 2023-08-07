#include "heroplane.h"

heroPlane::heroPlane(QObject *parent) : QObject(parent)
{
    //初始化飞机图片
    m_Palne.load(HERO_PATH);

    //初始化飞机坐标
    m_X = (GAME_WIDTH - m_Palne.width()) * 0.5;
    m_Y = GAME_HEIGHT - m_Palne.height();

    //初始化矩形边框
    m_Rect.setWidth(m_Palne.width());
    m_Rect.setHeight(m_Palne.height());
    m_Rect.moveTo(m_X,m_Y);
}

void heroPlane::shoot()
{
    //累加时间间隔的记录
    m_recorder++;

    //如果未达到发射子弹的时间间隔，则不发射
    if(m_recorder < BULLET_INTERVAL){
        return ;
    }

    //达到发射间隔
    m_recorder = 0;

    //发射子弹
    for(int i = 0;i < BULLET_NUM;i++){
        //如果是空闲的子弹，则发射
        if(m_bullets[i].m_Free){
            //改变子弹状态
            m_bullets[i].m_Free = false;
            //设置子弹坐标
            m_bullets[i].m_X = m_X + m_Rect.width() * 0.5 - 10;
            m_bullets[i].m_Y = m_Y - 25;
            break;
        }
    }
}

void heroPlane::setPosition(int x,int y)
{
    m_X = x;
    m_Y = y;
    m_Rect.moveTo(m_X,m_Y);
}
