/*
小明正在分析一本小说中的人物相关性。他想知道在小说中 Alice 和 Bob 有多少次同时出现。

更准确的说，小明定义 Alice 和 Bob "同时出现" 的意思是：在小说文本 中 Alice 和 Bob 之间不超过 K 个字符。

例如以下文本：

This is a story about Alice and Bob.Alice wants to send a private message to Bob.

假设 k= 20，则 Alice 和 Bob 同时出现了 2 次，分别是"Alice and Bob" 和 "Bob. Alice"。前者 Alice 和 Bob 之间有 5 个字符，后者有 2 个字符。

注意:

Alice 和 Bob 是大小写敏感的，alice 或 bob 等并不计算在内。

Alice 和 Bob 应为单独的单词，前后可以有标点符号和空格，但是不能 有字母。例如出现了 Bobbi 并不算出现了 Bob。
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    string ch;
    int a[200005], b[333005],n, k1 = 0, k2 = 0;
    long long ans = 0;
    cin >> n;
    cin.ignore();
    getline(cin, ch);
    size_t pos = 0;
    while((pos = ch.find("Alice", pos)) != string::npos){
        a[++k1] = pos;
        pos += 5;
    }
    pos = 0;
    while((pos = ch.find("Bob", pos)) != string::npos){
        b[++k2] = pos;
        pos += 3;
    }
    for(int i = 1, l = 1, r = 1; i <= k1; i++){
        while(l <= k2 && b[l] < a[i] - n - 3) l++;
        while(r <= k2 && b[r] <= a[i] + n + 5) r++;
        ans += r - l;
    }
    cout << ans;
    return 0;
}
