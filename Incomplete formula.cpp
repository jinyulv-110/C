/*
С���ںڰ���д��һ������ AopB=C ����ʽ������ A��B��C ���ǷǸ�������
op �� +��-��*��/����������������֮һ������ 
A��op��B��C ���Ĳ�����һ���ֱ���С�ĵ�ͬѧ�����ˡ� 
�����������������ʽ�����б������Ĳ��֣��������Ĳ����Ǳ������Ĳ�����
���������������λ���ֵ�������� ? ���档��������������Ĳ��֡�
*/
#include <bits/stdc++.h>
using namespace std;
int a, b, c;
char op;
int main() {
    string s; cin >> s;
    int p1 = s.find('?');
    int p2 = s.find('=');
    if (p1 == p2 + 1) {
        int i;
        for (i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                a = a * 10 + (s[i] - '0');
            } else break;
        }
        op = s[i++];
        for (int j = i; j < p2; ++j) b = b * 10 + (s[j] - '0');
        if (op == '+') c = a + b;
        else if (op == '-') c = a - b;
        else if (op == '*') c = a * b;
        else c = a / b;
        cout << c << '\n';
    } else if (p1 == p2 - 1) {
        int i;
        for (i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                a = a * 10 + (s[i] - '0');
            } else break;
        }
        op = s[i];
        for (int j = p2 + 1; j < s.size(); ++j) c = c * 10 + (s[j] - '0');
        if (op == '+') b = c - a;
        else if (op == '-') b = a - c;
        else if (op == '*') b = c / a;
        else b = a / c;
        cout << b << '\n';
    } else if (p1 == 0) {
        op = s[1];
        for (int j = 2; j < p2; ++j) b = b * 10 + (s[j] - '0');
        for (int j = p2 + 1; j < s.size(); ++j) c = c * 10 + (s[j] - '0');
        if (op == '+') a = c - b;
        else if (op == '-') a = c + b;
        else if (op == '*') a = c / b;
        else a = c * b;
        cout << a << '\n';
    } else {
        int i;
        for (i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                a = a * 10 + (s[i] - '0');
            } else break;
        }
        for (int j = i + 1; j < p2; ++j) b = b * 10 + (s[j] - '0');
        for (int j = p2 + 1; j < s.size(); ++j) c = c * 10 + (s[j] - '0');
        if (a + b == c) cout << '+';
        else if (a - b == c) cout << '-';
        else if (a * b == c) cout << '*';
        else cout << '/';
    }
    return 0;
}
