// Automand v1 - by Avakyr

#include <stdio.h>
#include <string.h>

// 比较两个字符串
#define CMP(s1, op, s2) (strcmp(s1, s2) op 0)
#define HELP_INFO       "EMPTY"

void mleft(int num, int time);
void mright(int num, int time);
void mmove(int x, int y);
void kpress(int key, int num, int time);
void wait(int time);
int get_line_num(FILE *fp);

int main(int argc, char **argv) {
    if (argc == 1) {
        printf(HELP_INFO);
        return 0;
    } else
        argc--, argv++;

    FILE *fp = fopen(argv[0], "r");
    if (fp == NULL)
        return -1;

    char cmd[10] = {0}; // 单个命令
    int args[10] = {0}; // 命令参数列表
    int count = 0; // 第几个命令
    int total = get_line_num(fp); // 总命令数

    printf("==== %d command(s) ====\n", total);

    while (fscanf(fp, "%s", cmd) != EOF) {
        printf("> %d/%d: %s ", ++count, total, cmd);
        // command: mleft, args: 22
        if (CMP(cmd, ==, "mleft")) {
            fscanf(fp, "%d %d", args, args+1);
            printf("%d %d", args[0], args[1]);
            mleft(args[0], args[1]);
        }
        // command: mright, args: 2
        else if (CMP(cmd, ==, "mright")) {
            fscanf(fp, "%d %d", args, args+1);
            printf("%d %d", args[0], args[1]);
            mright(args[0], args[1]);
        }
        // command: mmove, args: 2
        else if (CMP(cmd, ==, "mmove")) {
            fscanf(fp, "%d %d", args, args+1);
            printf("%d %d", args[0], args[1]);
            mmove(args[0], args[1]);
        }
        // command: kpress, args: 3
        else if (CMP(cmd, ==, "kpress")) {
            fscanf(fp, "%d %d %d", args, args+1, args+2);
            printf("%d %d %d", args[0], args[1], args[2]);
            kpress(args[0], args[1], args[2]);
        }
        // command: wait, args: 1
        else if (CMP(cmd, ==, "wait")) {
            fscanf(fp, "%d", args);
            printf("%d", args[0]);
            wait(args[0]);
        }
        // invalid commands
        else {
            // 将第 36 行输出的 '>' 替换为 'x'
            printf("\rx\n");
            // 遇到一个错误命令立即终止程序
            return -1;
        }

        // 将第 36 行输出的 '>' 替换为 ' ' (空格)
        printf("\r \n");
        fscanf(fp, "\n");
    }

    printf("==== All Finished ====\n");

    return 0;
}

int get_line_num(FILE *fp) {
    char ch;
    int count = 1;
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            count++;
        }
    }
    rewind(fp); // 很重要
    return count;
}
