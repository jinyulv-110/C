/*

小蓝有两种卡片，卡片上分别写若数字1和数字0.

小蓝非常喜欢进制，他想用进制来表示所有的数字，每个数字可以使用若干张卡片1和卡片0组成.

列如，数字6的二进制表示为110,需要使用2张卡片1和1张卡片0来组成

现在小蓝有a张卡片1和b张卡片0，从数字L开始，依次用卡片表示数字L,L+ 1,L + 2....请问最多能组成多少个数字。*/
#include <iostream>
#include <utility> // for std::pair

using namespace std;

// 函数：计算数字n的二进制表示中1和0的数量
pair<int, int> countBits(int n) {
    int count1 = 0;
    int count0 = 0;
    while (n > 0) {
        if (n & 1) {
            count1++;
        } else {
            count0++;
        }
        n = n >> 1;
    }
    return {count1, count0};
}

int maxNumbers(int a, int b, int L) {
    int count = 0;
    while (true) {
        pair<int, int> bits = countBits(L); // 使用 pair 接收返回值
        int num1 = bits.first;  // 获取 1 的数量
        int num0 = bits.second; // 获取 0 的数量

        if (a >= num1 && b >= num0) {
            a -= num1;
            b -= num0;
            count++;
            L++;
        } else {
            break;
        }
    }
    return count;
}

int main() {
    int a, b, L;
    cout << "请输入卡片1的数量a: ";
    cin >> a;
    cout << "请输入卡片0的数量b: ";
    cin >> b;
    cout << "请输入起始数字L: ";
    cin >> L;

    int result = maxNumbers(a, b, L);
    cout << "最多能组成的数字个数为: " << result << endl;

    return 0;
}
