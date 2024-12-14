
/*

一年一度的蓝桥学院运动会开始了！

为了让运动员们保持最佳状态，学院准备了大量的运动饮料和矿泉水。

操场上，一排长长的桌子上一共摆放了 N 瓶水，其中从左往右奇数位置上的水都是能够补充能量的运动饮料，而偶数位置上的水则都是清爽解渴的矿泉水。

现在，有两个班级的代表来取水，他们将轮流从桌子的一端（最左侧或最右侧）取走一瓶水，直到桌子上的水被全部取完。这两个班级的代表都鬼精鬼精的，都想为自己的班级取走尽可能多的运动饮料。

请问，如果这两个代码都采取最佳策略，那么最终优先取水的代表最多可以拿到多少瓶运动饮料呢？
*/
#include <iostream>
using namespace std;
int main()
{
  int n;
  cin>>n;//等待用户从键盘输入一个整数，并将其存储到变量n中。
  if(n%2==1){
    cout<<1;
  }else{
    cout<<n/2;//判断n的奇偶性
  }
  return 0;
}