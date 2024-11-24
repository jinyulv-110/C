/*有一个名叫Lanqiao 的公司，公司的总裁非常喜欢自己公司的名字。
他认为只要是字母的排列组合能够组成公司的名字，那么这个组合就是公司名字的正确拼写。
比如说，Lanqioa、anqiaoL、qiaoLan 和 Lnqiaao 都是公司名字的正确拼写。
不过，他有一个要求，公司名字开头的字母 L 必须是大写字母，其它字母必须都是小写字母。
今天，总裁写了一个长度为n的字符串s，由大写或小写字母组成。他想让你判断这个字符串是否是他公司的名字的正确拼写。
用这题说明字符串的处理：C/C++组需要掌握STL String库



#include<bits/stdc++.h>
using namespace std;
int main() {
    string A = "Lanqiao";
    sort(A.begin(), A.end());
    int t;
    cin >> t; // 输入测试用例的数量
    for (int i = 0; i < t; ++i) {
        int n;       cin >> n;  
        string s;    cin >> s;  
        sort(s.begin(), s.end()); // 对输入字符串排序
        if (s == A)  
		cout << "YES"<< endl;
        else      
		cout << "NO" << endl;
    }
    return 0;
*/



#include<bits/stdc++.h>
using namespace std;

int main() {
    // 定义并初始化字符串A为"Lanqiao"
    string A = "Lanqiao";
    // 对字符串A进行排序，使其字符按字典序排列
    sort(A.begin(), A.end());

    int t;
    cin >> t; 
    for (int i = 0; i < t; ++i) {
        // 这里原本有读取整数n的代码，因未使用已删除

        string s;
        cin >> s;  
        // 对输入的字符串s进行排序，以便后续与A比较
        sort(s.begin(), s.end()); 

        if (s == A)  
            cout << "YES"<< endl;
        else      
            cout << "NO" << endl;
    }

    return 0;
}
