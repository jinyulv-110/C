/*给定L,R，问 L≤x≤R 中有多少个数 
x 满足存在整数 
1.对于原题中的
x=y^2-z^2 ，发现
x只要满足是奇数或者4的倍数就是一种答案，严格证明如下??

由于 
x=(y+z)*(y-z)

不妨令

A=(y+z) ，

B=(y-z)

那么有 
A-B=y+z-y+z=2z

不难看出, 2z 为偶数的一般表达形式。也就是说，对于任意两个整数的平方差若能凑出 x，那么这两个整数相差一定为偶数，
相应的，上式A、B的组合形式也只能是奇*奇或者偶*偶。

对于所有的奇*奇的形式，可以表示为奇数其本身和1相乘，相差一定为偶数，所以所有的奇数满足条件。 其次，对于所有偶*偶的形式，两个偶数相乘一定是4的倍数。

2.有了以上结论，由于题目范围 
10^9，显然遍历区间会超时，我们考虑用除法来求解奇数和4的倍数的个数，其中奇数利用 

x/2 上取整，4的倍数利用 
x/4 下取整，举点儿例子就可以轻松发现此规律??

x/2上取整可以获得[1,x]奇数个数: [9 / 2] = 5（1，3，5，7，9为[1,x]的奇数）

x/4下取整可以获得[1,x]4的倍数的个数[5 / 4] = 1（只有4一个为4的倍数）

3.分别获取[1...r]和[1...l-1]区间内两种数字个数做差减去交集，即可得到答案。

1.两乘积若做差可以消元，那么做差看看，发现两者之间的规律之后，从而推出
x的规律和性质

2.奇数利用 
x/2 上取整，4的倍数利用 
x/4 下取整可以分别获 
[1,x] 内的数量

时间复杂度
O(1)

*/
#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

//获取[1...x]中 4的倍数 和 奇数的个数，前者下取整，后者上取整
LL get_sum(LL x)
{
    return x / 4 + (x + 1) / 2;
}

int main()
{
    LL l, r;
    cin >> l >> r;
    
    cout << get_sum(r) - get_sum(l - 1); //减去集合重合的部分即可
    return 0;
}
