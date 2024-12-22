/*
小蓝在黑板上写了一个形如 AopB=C 的算式，其中 A、B、C 都是非负整数，
op 是 +、-、*、/（整除）四种运算之一。不过 
A、op、B、C 这四部分有一部分被不小心的同学擦掉了。 
给出这个不完整的算式，其中被擦掉的部分（被擦掉的部分是被完整的擦掉，
不会出现留下若干位数字的情况）用 ? 代替。请你输出被擦掉的部分。
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
