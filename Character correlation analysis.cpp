/*
С�����ڷ���һ��С˵�е���������ԡ�����֪����С˵�� Alice �� Bob �ж��ٴ�ͬʱ���֡�

��׼ȷ��˵��С������ Alice �� Bob "ͬʱ����" ����˼�ǣ���С˵�ı� �� Alice �� Bob ֮�䲻���� K ���ַ���

���������ı���

This is a story about Alice and Bob.Alice wants to send a private message to Bob.

���� k= 20���� Alice �� Bob ͬʱ������ 2 �Σ��ֱ���"Alice and Bob" �� "Bob. Alice"��ǰ�� Alice �� Bob ֮���� 5 ���ַ��������� 2 ���ַ���

ע��:

Alice �� Bob �Ǵ�Сд���еģ�alice �� bob �Ȳ����������ڡ�

Alice �� Bob ӦΪ�����ĵ��ʣ�ǰ������б����źͿո񣬵��ǲ��� ����ĸ����������� Bobbi ����������� Bob��
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
