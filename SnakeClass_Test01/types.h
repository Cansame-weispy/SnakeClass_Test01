#ifndef TYPES_H
#define TYPES_H

//*********** 方向 ***********
enum Direction { DIR_UP, DIR_DOWN, DIR_LEFT, DIR_RIGHT };

//*********** 格子坐标 ***********
struct Point {
    int x;      // 第几列（0 ~ 24）
    int y;      // 第几行（0 ~ 19）
};

//*********** 蛇 ***********
struct Snake {
    Point body[500];    // body[0] 是蛇头
    int   length;
    int   dir;
};

#endif /* TYPES_H */