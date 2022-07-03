// Automand v2 - by Avakyr

#include <stdio.h>
#include <string.h>
#include "func.h"

// 将 args 变成 args[0], args[1], args[2]... 的神奇的宏 (num <= 5, 可增加)
// 注意: num 必须是一个事先指明的整数常量, 不能为整型变量
#define   ARG_LIST(args, num) _DEFCAT(_REPLACE, num)(args)
#define  _DEFCAT(a, b)       __DEFCAT(a, b)
#define __DEFCAT(a, b)         a##b
#define  _REPLACE1(args)       args[0]
#define  _REPLACE2(args)      _REPLACE1(args), args[1]
#define  _REPLACE3(args)      _REPLACE2(args), args[2]
#define  _REPLACE4(args)      _REPLACE3(args), args[3]
#define  _REPLACE5(args)      _REPLACE4(args), args[4]

#define   HELP_INFO           "EMPTY"

int main(int argc, char **argv) {
    if (argc == 1) {
        printf(HELP_INFO);
        return 0;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("File not found\n");
        return -1;
    }

    char c1, c2; // 命令名的第一个字符, 第二个字符
    int args[5] = {0}; // 参数列表
    int count = 0; // 第几个命令
    int total = get_line_num(fp); // 总命令数

    printf("======== %d command(s) ========\n", total);

    while (fscanf(fp, "%c%c ", &c1, &c2) != EOF) {
        printf("> %d/%d: %c%c ", ++count, total, c1, c2);

        /*__*/ if (c1 == 'l' && c2 == 'u') {
            left_up();
        } else if (c1 == 'l' && c2 == 'd') {
            left_down();
        } else if (c1 == 'l' && c2 == 'n') {
            get_args(fp, args, 2);
            print_args(args, 2);
            left_click_n(ARG_LIST(args, 2));
        } else if (c1 == 'r' && c2 == 'u') {
            right_up();
        } else if (c1 == 'r' && c2 == 'd') {
            right_down();
        } else if (c1 == 'r' && c2 == 'n') {
            get_args(fp, args, 2);
            print_args(args, 2);
            right_click_n(ARG_LIST(args, 2));
        } else if (c1 == 'm' && c2 == 'v') {
            get_args(fp, args, 2);
            print_args(args, 2);
            move(ARG_LIST(args, 2));
        } else if (c1 == 'k' && c2 == 'b') {
            get_args(fp, args, 3);
            print_args(args, 3);
            keyboard(ARG_LIST(args, 3));
        } else if (c1 == 'w' && c2 == 't') {
            get_args(fp, args, 1);
            print_args(args, 1);
            wait(ARG_LIST(args, 1));
        } else {
            printf("\rx\n");
            return -1;
        }

        printf("\r \n");
        fscanf(fp, "\n");
    }

    printf("======== All Finished ========\n");

    return 0;
}
