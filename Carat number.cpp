/*
在奇幻的克拉图斯星球，存在一种神秘的数字法术。一个数字被称为克拉数，
当且仅当它以及从它右边开始每次移除一个数字后的每一个子数字都是由星际法师们认定的神秘数字。
神秘数字的定义为：一个大于 1 的自然数，除了 1 和它本身外，不能被其他自然数整除的数。
例如，数字 53 是一个克拉数，因为 53 和 5 都是被星际法师们认定的神秘数字。
你能够求出区间 
[n,m] 之间有多少个克拉数吗？
*/



#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;//定义了一个常量N表示数组的大小，用于后续存储质数等操作；

int n, m;
int prime[N], cnt;
bool st[N];//prime数组用来存储筛选出的质数，cnt记录质数的个数，st数组用于标记某个数是否为合数（true表示是合数，false表示是质数）。

void init(int n)//埃氏筛法来标记出1到n范围内的合数
{
    st[0] = st[1] = true;//首先将0和1标记为合数（true），然后从2开始遍历，
    for(int i = 2; i <= n; i ++)
    {
        if(!st[i]) prime[cnt ++] = i;//如果当前数i没有被标记为合数（即st[i]为false），则将其加入到prime数组中作为质数记录下来，
        for(int j = 0; prime[j] * i <= n; j ++)
        {
            st[i * prime[j]] = true;
            if(i % prime[j] == 0) break;
        }//接着通过内层循环，用已经找到的质数prime[j]去筛掉其倍数i * prime[j]（标记为合数true），
		//当i能整除prime[j]时停止内层循环，这样可以保证每个合数只被其最小质因数筛掉一次，优化筛法的效率。
    }
}

bool check(int x)
{
    while(x)
    {
        if(st[x]) return false;//用于判断给定数字x以及从它右边开始每次移除一个数字后的每一个子数字是否都是质数。
        x /= 10;//通过不断地去掉数字的最后一位（x /= 10操作），并检查剩余数字在st数组中的标记情况，
    } //如果有任何一个数字被标记为合数（st[x]为true），则返回false，只有当所有子数字都是质数时才返回true。
    return true;
}

int main()
{
    cin >> n >> m;
    init(m);

    int ans = 0;
    for(int i = 0; i < cnt; i ++)
    {
        int t = prime[i];
        if(t >= n && t <= m && !st[t] && check(t)) ans ++;
    }

    cout << ans << endl;
    return 0;
}//在main函数中，首先从标准输入读取区间端点n和m，然后调用init函数来初始化st数组，
//标记出1到m范围内的合数。接着通过循环遍历prime数组中存储的质数，对于每个在区间[n, m]内的质数prime[i]（满足t >= n && t <= m且本身不是合数!st[t]），
//再调用check函数判断其是否满足 “克拉数” 的条件，如果满足则将统计答案的ans变量加1，最后输出ans的值，即区间内 “克拉数” 的个数。
