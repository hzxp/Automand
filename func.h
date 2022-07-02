#ifndef _FUNC_H
#define _FUNC_H

// 按下
void left_down(void);
void right_down(void);
// 松开
void left_up(void);
void right_up(void);
// 多次点击
void left_click_n(int num, int time);
void right_click_n(int num, int time);
// 移动
void mouse_move(int x, int y);
// 按下键盘
void key_press(int key, int num, int time);
// 等待
void wait(int time);

// 读取命令参数 (必须在读取命令名后使用)
void get_args(FILE *fp, int *args, int arg_num);
// 输出命令和参数
void print_cmd_and_args(char *cmd, int *args, int arg_num);
// 获取文件行数
int get_line_num(FILE *fp);

#endif /* func.h */
