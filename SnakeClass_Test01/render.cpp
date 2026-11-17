/* =========================================================================
 *  render.cpp —— 显示模块实现
 *
 *  只负责“把数据画到屏幕上”，不含任何游戏规则。
 *  外部只需要 #include "render.h"。
 * ========================================================================= */

#include <graphics.h>
#include <tchar.h>
#include <stdio.h>

#include "config.h"      /* 尺寸宏 */
#include "render.h"      /* 自己的声明 */

/* ===================== 全局数据（真正的定义在这里） ===================== */
Snake g_snake;

/* ===================== 内部工具（static：只本文件可见） ===================== */

/* 画一个格子：左上角对齐 */
static void draw_cell(Point p, COLORREF color)
{
    int px = BOARD_X + p.x * CELL_SIZE;
    int py = BOARD_Y + p.y * CELL_SIZE;

    setfillcolor(color);
    solidrectangle(px + 1, py + 1, px + CELL_SIZE - 1, py + CELL_SIZE - 1);
}

/* 在 (x, y) 左对齐写字 */
static void draw_text(int x, int y, int size, COLORREF color, LPCTSTR s)
{
    settextstyle(size, 0, _T("微软雅黑"));
    settextcolor(color);
    setbkmode(TRANSPARENT);
    outtextxy(x, y, s);
}

/* 在 right_x 处右对齐写字 */
static void draw_text_right(int right_x, int y, int size, COLORREF color, LPCTSTR s)
{
    settextstyle(size, 0, _T("微软雅黑"));
    settextcolor(color);
    setbkmode(TRANSPARENT);
    outtextxy(right_x - textwidth(s), y, s);
}

/* ===================== 对外绘制函数 ===================== */

/* 画棋盘：底板 + 网格线 + 外框 */
void draw_board(void)
{
    setfillcolor(RGB(36, 41, 54));
    solidrectangle(BOARD_X, BOARD_Y, BOARD_X + BOARD_W, BOARD_Y + BOARD_H);

    setlinecolor(RGB(46, 52, 67));
    for (int c = 1; c < GRID_COLS; ++c) {
        int x = BOARD_X + c * CELL_SIZE;
        line(x, BOARD_Y, x, BOARD_Y + BOARD_H - 1);
    }
    for (int r = 1; r < GRID_ROWS; ++r) {
        int y = BOARD_Y + r * CELL_SIZE;
        line(BOARD_X, y, BOARD_X + BOARD_W - 1, y);
    }

    setlinecolor(RGB(90, 101, 126));
    rectangle(BOARD_X - 2, BOARD_Y - 2,
              BOARD_X + BOARD_W + 2, BOARD_Y + BOARD_H + 2);
}

/* 画蛇：从尾往头画，蛇头最后画，压在最上面 */
void draw_snake(void)
{
    for (int i = g_snake.length - 1; i >= 0; --i) {
        if (i == 0)
            draw_cell(g_snake.body[i], RGB(140, 235, 170));   /* 蛇头：浅绿 */
        else
            draw_cell(g_snake.body[i], RGB(72, 199, 116));    /* 蛇身：深绿 */
    }
}

/* 画食物：参数是格子坐标 */
void draw_food(Point p)
{
    int cx = BOARD_X + p.x * CELL_SIZE + CELL_SIZE / 2;
    int cy = BOARD_Y + p.y * CELL_SIZE + CELL_SIZE / 2;

    setfillcolor(RGB(235, 87, 87));
    solidcircle(cx, cy, CELL_SIZE / 2 - 3);
}

/* 画顶部信息栏 */
void draw_hud(int score, int best)
{
    TCHAR buf[64];

    _stprintf_s(buf, 64, _T("得分  %d"), score);
    draw_text(20, 20, 30, RGB(255, 196, 87), buf);

    _stprintf_s(buf, 64, _T("最高分  %d"), best);
    draw_text_right(WIN_WIDTH - 20, 30, 20, RGB(128, 138, 160), buf);
}

/* ===================== 窗口控制 ===================== */

void render_init(void)
{
    initgraph(WIN_WIDTH, WIN_HEIGHT, SHOWCONSOLE);
    setbkcolor(RGB(26, 29, 38));
    cleardevice();
    BeginBatchDraw();          /* 开双缓冲 */
}

void render_close(void)
{
    EndBatchDraw();
    closegraph();
}

/* ===================== 合成一整帧 ===================== */

void draw_all(Point food, int score, int best)
{
    cleardevice();
    draw_board();
    draw_food(food);
    draw_hud(score, best);
    draw_snake();
    FlushBatchDraw();          /* 内存里画完，一次性上屏 */
}
