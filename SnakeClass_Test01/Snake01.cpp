/* =========================================================================
 *  Snake01.cpp —— 显示模块的“最小可运行示例”
 *
 *  这个文件只做三件事：摆一条蛇、调显示模块、等按键退出。
 *  一个 EasyX 函数都没有出现——全部被 render_init / draw_all / render_close 包住了。
 * ========================================================================= */

#include <conio.h>

#include "render.h"

int main()
{
    /* 食物位置（正式版由食物模块给出） */
    Point food = { 5, 5 };

    /* 摆一条 3 节的蛇（正式版由逻辑组员赋值） */
    g_snake.length = 3;
    g_snake.dir    = DIR_RIGHT;

    g_snake.body[0].x = 12;  g_snake.body[0].y = 10;   /* 蛇头 */
    g_snake.body[1].x = 11;  g_snake.body[1].y = 10;
    g_snake.body[2].x = 10;  g_snake.body[2].y = 10;   /* 蛇尾 */

    render_init();              /* 建窗口、设底色、开双缓冲 */

    draw_all(food, 0, 0);       /* 画一整帧：得分 0，最高分 0 */

    (void)_getch();             /* 停住看画面 */

    render_close();             /* 关双缓冲、关窗口 */
    return 0;
}
