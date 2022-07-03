#include <stdio.h>
#include <windows.h>

// 创建并初始化一个变量
#define NEW_VAR(type, var) \
    type var; \
    memset(&var, 0, sizeof(var))

// 松开左键
void left_up(void) {
    NEW_VAR(INPUT, input);
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(1, &input, sizeof(input));
}

// 按下左键
void left_down(void) {
    NEW_VAR(INPUT, input);
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1, &input, sizeof(input));
}

// 左键点击若干次
void left_click_n(int num, int time) {
    NEW_VAR(INPUT, input);
    input.type = INPUT_MOUSE;
    while (num--) {
        input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
        SendInput(1, &input, sizeof(input));
        input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
        SendInput(1, &input, sizeof(input));
        Sleep(time);
    }
}

// 松开右键
void right_up(void) {
    NEW_VAR(INPUT, input);
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
    SendInput(1, &input, sizeof(input));
}

// 按下右键
void right_down(void) {
    NEW_VAR(INPUT, input);
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
    SendInput(1, &input, sizeof(input));
}

// 右键点击若干次
void right_click_n(int num, int time) {
    NEW_VAR(INPUT, input);
    input.type = INPUT_MOUSE;
    while (num--) {
        input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
        SendInput(1, &input, sizeof(input));
        input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
        SendInput(1, &input, sizeof(input));
        Sleep(time);
    }
}

// 移动鼠标 (增加坐标)
void move(int x, int y) {
    NEW_VAR(INPUT, input);
    input.type = INPUT_MOUSE;
    input.mi.dx = x;
    input.mi.dy = y;
    input.mi.dwFlags = MOUSEEVENTF_MOVE;
    SendInput(1, &input, sizeof(input));
}

// 按下键盘按键
void keyboard(int key, int num, int time) {
    NEW_VAR(INPUT, input);
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = key;
    while (num--) {
        input.ki.dwFlags = 0;
        SendInput(1, &input, sizeof(input));
        input.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &input, sizeof(input));
        Sleep(time);
    }
}

// 等待一段时间
void wait(int time) {
    Sleep(time);
}

// 读取命令参数 (必须在读取命令名后使用)
void get_args(FILE *fp, int *args, int arg_num) {
    if (arg_num != 0) {
        for (int i = 0; i < arg_num; i++) {
            fscanf(fp, "%d", args + i);
        }
    }
}

// 输出命令参数
void print_args(int *args, int arg_num) {
    if (arg_num != 0) {
        for (int i = 0; i < arg_num; i++) {
            printf("%d ", args[i]);
        }
    }
}

// 获取文件行数
int get_line_num(FILE *fp) {
    int ch; // int: 其值可能为 EOF
    int count = 1;
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            count++;
        }
    }
    rewind(fp); // 很重要
    return count;
}
