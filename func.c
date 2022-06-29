#include <stdio.h>
#include <windows.h>

// 创建并初始化一个变量
#define NEW_VAR(type, var) \
    type var; \
    memset(&var, 0, sizeof(var))

// 按下鼠标左键
void mleft(int num, int time) {
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

// 按下鼠标右键
void mright(int num, int time) {
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

// 增加鼠标坐标
void mmove(int x, int y) {
    NEW_VAR(INPUT, input);
    input.type = INPUT_MOUSE;
    input.mi.dx = x;
    input.mi.dy = y;
    input.mi.dwFlags = MOUSEEVENTF_MOVE;
    SendInput(1, &input, sizeof(input));
}

// 按下键盘按键
void kpress(int key, int num, int time) {
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
