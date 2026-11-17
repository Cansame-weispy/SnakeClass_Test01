#ifndef RENDER_H
#define RENDER_H

#include "types.h"

// 全组共用的蛇
extern Snake g_snake;

// ---- 窗口 ----
void render_init(void);      // 建窗口、设底色、开双缓冲
void render_close(void);     // 关双缓冲、关窗口

// ---- 对外绘制 ----
void draw_all(Point food, int score, int best);   // 画一整帧
void draw_board(void);
void draw_snake(void);
void draw_food(Point p);
void draw_hud(int score, int best);

#endif /* RENDER_H */
