#ifndef MAP_H
#define MAP_H

#include <QObject>
#include <QPixmap>
#include "config.h"
class Map : public QObject  //用QObject做父类是为了利用qt的内存管理机制自动释放内存，防止内存泄露
{
    Q_OBJECT
public:
    //构造函数
    explicit Map(QObject *parent = nullptr);

    //地图坐标滚动实现
    void mapPosition();

public:
    //地图对象
    QPixmap map1;
    QPixmap map2;

    //地图y轴坐标
    int map1_pos_y;
    int map2_pos_y;

    //地图滚动幅度
    int scroll_speed;

signals:

};

#endif // MAP_H
