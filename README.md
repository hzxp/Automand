# Automand

## 快速开始

1. 编写命令文件 (后缀名任意)
2. 命令行执行: `atm [command-file]`

## 命令行语法

`atm [command-file]`

## .atm 文件编写规范

1. 每行只有一个命令
2. 命令参数置于命令名称之后

## 命令列表

| 命令名称        | 含义                |
| --------------- | ------------------- |
| `left-up`       | 松开鼠标左键        |
| `right-up`      | 松开鼠标右键        |
| `left-down`     | 按下鼠标左键        |
| `right-down`    | 按下鼠标右键        |
| `left-click-n`  | 点击鼠标左键若干次  |
| `right-click-n` | 点击鼠标右键若干次  |
| `mouse-move`    | 移动鼠标 (增加坐标) |
| `key-press`     | 点击键盘按键若干次  |
| `wait`          | 等待一段时间        |

## 命令参数 & 范例

* `left-up`
  * 无参数
* `right-up`
  * 无参数
* `left-down`
  * 无参数
* `right-down`
  * 无参数
* `left-click-n`
  * 参数: 点击次数, 每两次点击之间的时间 (单位毫秒)
  * 范例: `left-click-n 10 100`
* `right-click-n`
  * 参数: 点击次数, 每两次点击之间的时间 (单位毫秒)
  * 范例: `right-click-n 10 100`
* `mouse-move`
  * 参数: 增加的横坐标, 增加的纵坐标 (若为负数则减少)
  * 范例: `mouse-move 50 50`
* `key-press`
  * 参数: Virtual-Key 代码 (见附录), 点击次数
  * 范例: `key-press 65 10`
* `wait`
  * 参数: 时间 (单位毫秒)
  * 范例: `wait 1000`

## 附录

* [Windows Virtual-Key](https://dwz.date/fmFy): 对应键盘上的按键
