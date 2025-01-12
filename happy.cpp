/*

小蓝有一个字符串 s， 
s中只包含大小写字母。他想知道这个字符串能否让他变得开心。
只有当 s 满足下面的条件的时候，小蓝才会开心：
s 的开始三个字符为 LAN。
s 的最后四个字符为 QIAO。
前三个字符和后四个字符之间的字符必须全部为小写字母或者不包含其他字符。 
如果字符串 s 可以让小蓝变得开心，则输出 AC，否则输出 WA。
输入格式
*/


#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    string a;
    cin>>a;
    if(a.substr(0, 3) == "LAN" && a.substr(a.size()-4, 4) == "QIAO"){
        for(int i=3;i<a.size()-4;i++){
            if(a[i]<97||a[i]>122){
                cout<<"WA";
                return 0;
            }
        }
        cout<<"AC";
    }
    else cout<<"WA";
    return 0;
}
