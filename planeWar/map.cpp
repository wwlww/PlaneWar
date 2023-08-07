#include "map.h"

Map::Map(QObject *parent) : QObject(parent)
{
    //初始化地图加载对象
    map1.load(MAP_PATH);
    map2.load(MAP_PATH);

    //设置地图起始坐标
    map1_pos_y = -GAME_HEIGHT;
    map2_pos_y = 0;

    //设置地图滚动速度
    scroll_speed = MAP_SCROLL_SPEED;
}

void Map::mapPosition()
{
    //处理map1的循环滚动
    map1_pos_y += MAP_SCROLL_SPEED;
    if(map1_pos_y >= 0){
        map1_pos_y = -GAME_HEIGHT;
    }
    //处理map2的循环滚动
    map2_pos_y += MAP_SCROLL_SPEED;
    if(map2_pos_y >= GAME_HEIGHT){
        map2_pos_y = 0;
    }
}
