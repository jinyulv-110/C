/*

小明在玩一款打怪兽的游戏。游戏中有n只怪兽，每只怪兽有两个属性：生命值hi和攻击力ai。小明初
始有m点生命值。
小明按顺序依次与怪兽战斗，每次战斗小明可以选择以下两种操作之一：
攻击怪兽，使怪兽的生命值减少1点。若怪兽生命值降为0，则怪兽被击败，小明可以继续与下一只怪
兽战斗。
防御，此回合小明不会受到怪兽攻击，但也不会对怪兽造成伤害。
当小明的生命值降为0时，游戏结束。请你计算小明是否能够击败所有怪兽，如果可以，输出 YES，否
则输出 NO。
【输入格式】
第一行包含两个整数n和m，分别表示怪兽的数量和小明的初始生命值。
接下来n行，每行包含两个整数hi和ai，分别表示第i只怪兽的生命值和攻击力。
【输出格式】
输出 YES 或 NO，表示小明是否能够击败所有怪兽。
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 比较函数，按攻击力从高到低排序
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}

string canDefeatAllMonsters(int n, int m, vector<pair<int, int>>& monsters) {
    // 按攻击力从高到低排序
    sort(monsters.begin(), monsters.end(), compare);

    // 计算总伤害
    long long totalDamage = 0;
    for (const auto& monster : monsters) {
        int hi = monster.first;  // 怪兽的生命值
        int ai = monster.second; // 怪兽的攻击力
        totalDamage += (long long)hi * ai; // 击败当前怪兽需要的总伤害
    }

    // 判断总伤害是否小于等于小明的初始生命值
    if (totalDamage <= m) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> monsters(n);
    for (int i = 0; i < n; ++i) {
        int hi, ai;
        cin >> hi >> ai;
        monsters[i] = {hi, ai};
    }

    // 调用函数并输出结果
    string result = canDefeatAllMonsters(n, m, monsters);
    cout << result << endl;

    return 0;
}
