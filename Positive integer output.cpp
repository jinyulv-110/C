/*给定若干行数据，每行数据为一个正整数，该正整数范围在 int 范围内。

你的任务是将这些数据全部输出。

输入格式
输入若干行数据，每行一个正整数。*/
#include <iostream>
using namespace std;

int main() {
    int number;
    // 使用 while 循环持续读取输入，直到输入结束
    while (cin >> number) {
        cout << number << endl; // 输出读取的正整数
    }
    return 0;
}
