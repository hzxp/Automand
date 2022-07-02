// Automand v1 - by Avakyr

#include <stdio.h>
#include <string.h>
#include "func.h"

// 比较两个字符串
#define STRCMP(s1, op, s2)  (strcmp(s1, s2) op 0)
// 能将 args 变成 args[0], args[1], args[2]... 的神奇的宏 (num <= 4, 可增加)
#define REPLACE_WITH_LIST(args, num)  _DEFCAT(_REPLACE, num)(args)
#define  _DEFCAT(a, b)   __DEFCAT(a, b)
#define __DEFCAT(a, b)   a##b
#define _REPLACE1(args)  args[0]
#define _REPLACE2(args)  _REPLACE1(args), args[1]
#define _REPLACE3(args)  _REPLACE2(args), args[2]
#define _REPLACE4(args)  _REPLACE3(args), args[3]

#define HELP_INFO       "EMPTY"

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

    char cmd[20] = {0}; // 命令名
    int args[10] = {0}; // 参数列表
    int count = 0; // 第几个命令
    int total = get_line_num(fp); // 总命令数

    printf("======== %d command(s) ========\n", total);

    while (fscanf(fp, "%s", cmd) != EOF) { // 读取命令名
        // 1. 输出序号
        printf("> %d/%d: ", ++count, total);

        // 2. 判断是什么命令并执行
        if (STRCMP(cmd, ==, "left-up")) {
            // 读取参数
            get_args(fp, args, 0);
            // 输出命令和参数
            print_cmd_and_args(cmd, args, 0);
            // 执行命令
            left_up();
        }

        else if (STRCMP(cmd, ==, "right-up")) {
            get_args(fp, args, 0);
            print_cmd_and_args(cmd, args, 0);
            right_up();
        }

        else if (STRCMP(cmd, ==, "left-down")) {
            get_args(fp, args, 0);
            print_cmd_and_args(cmd, args, 0);
            left_down();
        }

        else if (STRCMP(cmd, ==, "right-down")) {
            get_args(fp, args, 0);
            print_cmd_and_args(cmd, args, 0);
            right_down();
        }

        else if (STRCMP(cmd, ==, "left-click-n")) {
            get_args(fp, args, 2);
            print_cmd_and_args(cmd, args, 2);
            left_click_n(REPLACE_WITH_LIST(args, 2));
        }

        else if (STRCMP(cmd, ==, "right-click-n")) {
            get_args(fp, args, 2);
            print_cmd_and_args(cmd, args, 2);
            right_click_n(REPLACE_WITH_LIST(args, 2));
        }

        else if (STRCMP(cmd, ==, "mouse-move")) {
            get_args(fp, args, 2);
            print_cmd_and_args(cmd, args, 2);
            mouse_move(REPLACE_WITH_LIST(args, 2));
        }

        else if (STRCMP(cmd, ==, "key-press")) {
            get_args(fp, args, 3);
            print_cmd_and_args(cmd, args, 3);
            key_press(REPLACE_WITH_LIST(args, 3));
        }

        else if (STRCMP(cmd, ==, "wait")) {
            get_args(fp, args, 1);
            print_cmd_and_args(cmd, args, 1);
            wait(REPLACE_WITH_LIST(args, 1));
        }

        else {
            // 将第 41 行输出的 '>' 替换为 'x'
            printf("\rx\n");
            // 遇到一个错误命令立即终止程序
            return -1;
        }

        // 3. 命令执行成功
        // 将第 41 行输出的 '>' 替换为 ' ' (空格)
        printf("\r \n");
        fscanf(fp, "\n");
    }

    printf("======== All Finished ========\n");

    return 0;
}
