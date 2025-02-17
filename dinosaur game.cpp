/*

С������һ�����޵���Ϸ����Ϸ����nֻ���ޣ�ÿֻ�������������ԣ�����ֵhi�͹�����ai��С����
ʼ��m������ֵ��
С����˳�����������ս����ÿ��ս��С������ѡ���������ֲ���֮һ��
�������ޣ�ʹ���޵�����ֵ����1�㡣����������ֵ��Ϊ0������ޱ����ܣ�С�����Լ�������һֻ��
��ս����
�������˻غ�С�������ܵ����޹�������Ҳ����Թ�������˺���
��С��������ֵ��Ϊ0ʱ����Ϸ�������������С���Ƿ��ܹ��������й��ޣ�������ԣ���� YES����
����� NO��
�������ʽ��
��һ�а�����������n��m���ֱ��ʾ���޵�������С���ĳ�ʼ����ֵ��
������n�У�ÿ�а�����������hi��ai���ֱ��ʾ��iֻ���޵�����ֵ�͹�������
�������ʽ��
��� YES �� NO����ʾС���Ƿ��ܹ��������й��ޡ�
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// �ȽϺ��������������Ӹߵ�������
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}

string canDefeatAllMonsters(int n, int m, vector<pair<int, int>>& monsters) {
    // ���������Ӹߵ�������
    sort(monsters.begin(), monsters.end(), compare);

    // �������˺�
    long long totalDamage = 0;
    for (const auto& monster : monsters) {
        int hi = monster.first;  // ���޵�����ֵ
        int ai = monster.second; // ���޵Ĺ�����
        totalDamage += (long long)hi * ai; // ���ܵ�ǰ������Ҫ�����˺�
    }

    // �ж����˺��Ƿ�С�ڵ���С���ĳ�ʼ����ֵ
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

    // ���ú�����������
    string result = canDefeatAllMonsters(n, m, monsters);
    cout << result << endl;

    return 0;
}
