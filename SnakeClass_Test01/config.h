//头文件保护
//如果CONFIG_H没有出现过则定义CONFIG_H，否则跳过代码块
#ifndef CONFIG_H
#define CONFIG_H
//像素24
#define CELL_SIZE 24
//横向 25 格
#define GRID_COLS 25
//纵向 20 格
#define GRID_ROWS 20
//棋盘左右两边的留白 
#define MARGIN_X 20
//顶部信息栏高度（以后放分数用）
#define HUD_HEIGHT 80
//棋盘下方留白
#define MARGIN_BOTTOM 20
//棋盘宽 = 25 格 × 24 = 600
#define BOARD_W          (GRID_COLS * CELL_SIZE)
//棋盘高 = 20 格 × 24 = 480
#define BOARD_H          (GRID_ROWS * CELL_SIZE)
//棋盘的左上角：x 是 20（左边让出来的白边）
#define BOARD_X          MARGIN_X
//y 是 80（上面让给分数栏)
#define BOARD_Y          HUD_HEIGHT
//窗口宽 = 左白边 20 + 棋盘 600 + 右白边 20 = 640
#define WIN_WIDTH        (MARGIN_X * 2 + BOARD_W) 
//窗口高 = 分数栏 80 + 棋盘 480 + 下白边 20 = 580
#define WIN_HEIGHT       (HUD_HEIGHT + BOARD_H + MARGIN_BOTTOM)
//结束命令（#ifndef和#endif是一对）
#endif /* CONFIG_H */
