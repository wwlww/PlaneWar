#include "bomb.h"

Bomb::Bomb(QObject *parent) : QObject(parent)
{
    //将所有爆炸pixmap放入数组
    for(int i = 0;i < BOMB_NUM;i++){
        //拼接图片下标
        QString str = QString(BOMB_PATH).arg(i);
        m_PixArr.push_back(QPixmap(str));
    }

    //坐标
    m_X = 0;
    m_Y = 0;

    //空闲状态
    m_Free = true;

    //当前播放图片下标
    m_Index = 0;

    //爆炸播放间隔记录
    m_Recorder = 0;
}

void Bomb::updateInfo()
{
    //跳过空闲状态的爆炸
    if(m_Free){
        return;
    }

    //间隔计数
    m_Recorder++;

    //如果未达到爆炸间隔，直接返回
    if(m_Recorder < BOMB_INTERVAL){
        return;
    }

    //重置记录
    m_Recorder = 0;

    //播放完爆炸的最后一张图片，重置下标
    if(m_Index > BOMB_MAX - 1){
        m_Index = 0;
        m_Free = true;
    }

    //切换爆炸播放的图片下标
    m_Index++;
}
