/*

С���кܶ����ֿ�Ƭ��ÿ�ſ�Ƭ�϶�������0��9��
С��׼������Щ��Ƭ��ƴһЩ���������1��ʼƴ����������ÿƴһ�����ͱ�����������Ƭ�Ͳ�������
ƴ�������ˡ�С����֪���Լ��ܴ�1ƴ�����١�
���磬��С����30 �ſ�Ƭ������0��9��3�ţ���С������ƴ��1��10������ƴ11ʱ��Ƭ1�Ѿ�ֻ��һ��
�ˣ�����ƴ��11��
����С��������0��9��2021�ſ�Ƭ����20210 �ţ�����С�����Դ� 1 ƴ�����٣�
ʹ��̰�Ĳ�����ɡ�
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ͳ������n��ÿһλ���ֵĿ�Ƭ�������
bool canFormNumber(int n, vector<int>& cardCount) {
    while (n > 0) {
        int digit = n % 10; // ��ȡ��ǰλ������
        if (cardCount[digit] == 0) {
            return false; // �����Ƭ���㣬����false
        }
        cardCount[digit]--; // ���Ŀ�Ƭ
        n /= 10; // ȥ����ǰλ
    }
    return true;
}

int main() {
    // ��ʼ����Ƭ������0��9����2021��
    vector<int> cardCount(10, 2021);

    int num = 1; // ��1��ʼƴ����
    while (true) {
        if (!canFormNumber(num, cardCount)) {
            break; // �����Ƭ���㣬ֹͣƴ����
        }
        num++; // ����ƴ��һ������
    }

    // ������
    cout << "С�����Դ�1ƴ��" << num - 1 << endl;

    return 0;
}
