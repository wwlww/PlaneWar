#include "bullet.h"

Bullet::Bullet(QObject *parent) : QObject(parent)
{
    //加载子弹资源
    m_Bullet.load(BULLET_PATH);

    //子弹坐标
    m_X = GAME_WIDTH * 0.5 - m_Bullet.width() * 0.5;
    m_Y = GAME_HEIGHT;

    //子弹状态（默认空闲）
    m_Free = true;

    //子弹速度
    m_Speed = BULLET_SPEED;

    //子弹边框
    m_Rect.setWidth(m_Bullet.width());
    m_Rect.setHeight(m_Bullet.height());
    m_Rect.moveTo(m_X,m_Y);
}

void Bullet::updatePositon()
{
    //无需计算空闲子弹
    if(m_Free){
        return;
    }

    //子弹向上移动
    m_Y -= m_Speed;
    m_Rect.moveTo(m_X,m_Y);

    //子弹位置超出页面，重新变为空闲
    if(m_Y <= -m_Rect.height()){
        m_Free = true;
    }
}
