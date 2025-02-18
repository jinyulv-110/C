/*

С�������ֿ�Ƭ����Ƭ�Ϸֱ�д������1������0.

С���ǳ�ϲ�����ƣ������ý�������ʾ���е����֣�ÿ�����ֿ���ʹ�������ſ�Ƭ1�Ϳ�Ƭ0���.

���磬����6�Ķ����Ʊ�ʾΪ110,��Ҫʹ��2�ſ�Ƭ1��1�ſ�Ƭ0�����

����С����a�ſ�Ƭ1��b�ſ�Ƭ0��������L��ʼ�������ÿ�Ƭ��ʾ����L,L+ 1,L + 2....�����������ɶ��ٸ����֡�*/
#include <iostream>
#include <utility> // for std::pair

using namespace std;

// ��������������n�Ķ����Ʊ�ʾ��1��0������
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
        pair<int, int> bits = countBits(L); // ʹ�� pair ���շ���ֵ
        int num1 = bits.first;  // ��ȡ 1 ������
        int num0 = bits.second; // ��ȡ 0 ������

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
    cout << "�����뿨Ƭ1������a: ";
    cin >> a;
    cout << "�����뿨Ƭ0������b: ";
    cin >> b;
    cout << "��������ʼ����L: ";
    cin >> L;

    int result = maxNumbers(a, b, L);
    cout << "�������ɵ����ָ���Ϊ: " << result << endl;

    return 0;
}
