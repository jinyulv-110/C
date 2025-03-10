/*我们都知道大富翁里面有两种特殊卡一种是均富卡，一种是均贫卡，两种卡牌都可以影响玩家之间的金钱分配。

均贫卡：使用均贫卡的玩家可以将自己的金币平均分配给其他玩家。具体而言，如果一个玩家拥有 X 个金币，
使用均贫卡后，他可以将自己的金币平均分配给其他玩家，使得每个玩家最后都有 X/N 个金币，其中 N 为玩家总数（包括使用均贫卡的玩家本身）。

均富卡：使用均富卡的玩家可以将其他玩家的金币平均分配给自己。具体而言，如果一个玩家拥有 
X 个金币，使用均富卡后，他可以将其他玩家总共拥有的金币平均分配给自己，使得他最后拥有的金币数量为总金币数除以玩家总数，而其他玩家的金币数量为 0 。

肖恩根据这两种特殊卡牌的规则给自己的大富翁设计了一种新的特殊卡牌平局卡。平均卡可以同时选住 V 名玩家，并使这 V 名玩家数
(V∈[1,cnt 玩家数]）玩家拥有的金币平均以后分给每个人。每个人在游戏开始时拥有的金币数是 A[i] ，肖恩认为金币数高于 X 的为富人。
请你帮肖恩求出使用任意多次（可以是 0 次）平均卡以后最多有多少富人。*/
#include <iostream>
#include<algorithm>
using namespace std;
int n, x;
int coin[100004];
void find()
{
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
        cin >> coin[i];
    sort(coin + 1, coin + n + 1, greater<int>());
    long long all = 0;
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        all += coin[i];
        if (1.0 * all / i >= x)
            ans = i;
        else
            break;
    }
    cout << ans << endl;
}
int main()
{
    // 请在此输入您的代码
    int t;
    cin >> t;
    while (t--) 
    {
        find();
    }
    return 0;
}
