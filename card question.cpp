/*

小蓝有很多数字卡片，每张卡片上都是数字0到9。
小蓝准备用这些卡片来拼一些数，他想从1开始拼出正整数，每拼一个，就保存起来，卡片就不能用来
拼其它数了。小蓝想知道自己能从1拼到多少。
例如，当小蓝有30 张卡片，其中0到9各3张，则小蓝可以拼出1到10，但是拼11时卡片1已经只有一张
了，不够拼出11。
现在小蓝手里有0到9各2021张卡片，共20210 张，请问小蓝可以从 1 拼到多少？
使用贪心策略完成。
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 统计数字n的每一位数字的卡片消耗情况
bool canFormNumber(int n, vector<int>& cardCount) {
    while (n > 0) {
        int digit = n % 10; // 获取当前位的数字
        if (cardCount[digit] == 0) {
            return false; // 如果卡片不足，返回false
        }
        cardCount[digit]--; // 消耗卡片
        n /= 10; // 去掉当前位
    }
    return true;
}

int main() {
    // 初始化卡片数量，0到9各有2021张
    vector<int> cardCount(10, 2021);

    int num = 1; // 从1开始拼数字
    while (true) {
        if (!canFormNumber(num, cardCount)) {
            break; // 如果卡片不足，停止拼数字
        }
        num++; // 继续拼下一个数字
    }

    // 输出结果
    cout << "小蓝可以从1拼到" << num - 1 << endl;

    return 0;
}
