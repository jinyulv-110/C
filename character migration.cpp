/*
С����������һ������Ϊ N ���ַ��� S���������������֡�

С��Ϊ�˿���С�����ַ����Ĵ��������������������һ����ս��������� Q �β�����

ÿ�β��������������� 
l,r,k���� S �ĵ� l ���ַ����� r ���ַ���ѭ������ k �Ρ�
С������С���ش����ڲ�����ɺ� S �Ƕ��٣�С����������������������������
�ַ����Ʊ�ʾΪ����ĸ������ƶ������� a ���� 1 �α�Ϊ b��b ���� 2 �α�Ϊ d���ر�أ�z ���� 1 �α��Ϊ a��
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> diff(n + 1, 0); // �������
    while (q--) {
        ll l, r, k;
        cin >> l >> r >> k;
        k %= 26;
        diff[l - 1] += k;//�±��0��ʼ��
        diff[r] -= k;
    }
    // ����ǰ׺��
    for (int i = 1; i < n; ++i) {
        diff[i] += diff[i - 1];
    }
    for (int i = 0; i < n; ++i) {
        int offset = s[i] - 'a';//���Ĳ�ֵ���Ϊ25Ҳ����z��ȥ��a���Ĳ�ֵ
        offset = (offset + diff[i]) % 26;
        s[i] = 'a' + offset;
        ////
    }
    cout << s << endl;
    return 0;
}
