#ifndef _FUNC_H
#define _FUNC_H

void left_up(void);
void left_down(void);
void left_click_n(int num, int time);
void right_up(void);
void right_down(void);
void right_click_n(int num, int time);
void move(int x, int y);
void keyboard(int key, int num, int time);
void wait(int time);

void get_args(FILE *fp, int *args, int arg_num);
void print_args(int *args, int arg_num);
int get_line_num(FILE *fp);

#endif /* func.h */
