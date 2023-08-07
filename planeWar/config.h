#ifndef CONFIG_H
#define CONFIG_H

//游戏配置数据
#define GAME_WIDTH 512          //宽度
#define GAME_HEIGHT 768         //高度
#define GAME_TITLE  "飞机大战"   //标题
#define GAME_RES_PATH "./plane.rcc" //二进制资源文件的路径
#define GAME_ICON_PATH ":/res/app.ico"  //图标文件路径
#define GAME_RATE 10    //刷新间隔，毫秒

//地图配置数据
#define MAP_PATH ":/res/img_bg_level_1.jpg" //地图文件路径
#define MAP_SCROLL_SPEED 1 //地图滚动速度

//飞机配置数据
#define HERO_PATH ":/res/hero.png"  //飞机文件路径

//子弹配置数据
#define BULLET_PATH ":/res/bullet_11.png"   //子弹文件路径
#define BULLET_SPEED 3  //子弹速度
#define BULLET_NUM 30   //弹夹中子弹的总数
#define BULLET_INTERVAL 30   //发射子弹间隔

//敌机配置数据
#define ENEMY_PATH ":res/img-plane_3.png"   //敌机文件路径
#define ENEMY_SPEED 3   //敌机速度zm
#define ENEMY_NUM 20  //敌机数量
#define ENEMY_INTERVAL 50  //敌机出场时间间隔

//爆炸配置数据
#define BOMB_PATH ":/res/bomb-%1.png"   //爆炸文件路径
#define BOMB_NUM 20 //爆炸数量
#define BOMB_MAX 7  //爆炸图片最大下标
#define BOMB_INTERVAL 10    //爆炸切图时间间隔

//音效配置数据
#define SOUND_BACKGROUND ":/res/bg.wav"
#define SOUND_BOMB ":/res/bomb.wav"

#endif // CONFIG_H
