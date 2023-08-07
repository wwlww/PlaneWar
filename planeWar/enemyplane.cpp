#include "enemyplane.h"

EnemyPlane::EnemyPlane(QObject *parent) : QObject(parent)
{
    //初始化敌机图片
    m_Enemy.load(ENEMY_PATH);

    //初始化敌机坐标
    m_X = 0;
    m_Y = 0;

    //敌机状态
    m_Free = true;

    //敌机速度
    m_Speed = ENEMY_SPEED;

    //敌机矩形边框
    m_Rect.setWidth(m_Enemy.width());
    m_Rect.setHeight(m_Enemy.height());
    m_Rect.moveTo(m_X,m_Y);

}

void EnemyPlane::updatePosition()
{
    //空闲状态敌机，不计算坐标
    if(m_Free){
        return;
    }

    //敌机向下移动
    m_Y += m_Speed;
    m_Rect.moveTo(m_X,m_Y);

    //如果超出屏幕，重置空闲状态
    if(m_Y >= GAME_HEIGHT + m_Rect.height()){
        m_Free = true;
    }
}
