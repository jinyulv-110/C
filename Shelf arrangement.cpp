/*
小蓝和小红应聘了蓝桥图书馆的管理员，他们一起合作整理书籍。

现在图书馆有 n 本书，书籍初始时按 1～n 的顺序进行排列。小红给出 
m 条指令，小蓝需要根据指令进行对应的操作，具体关系如下：
1 p，将编号为 p 的书本移动到第一位。
2 p，将编号为 p的书本移动到最后一位。
3 p q，将编号为p的书本移动到编号为 q 的书本后面。
现在问你，小蓝进行 m 次操作后，书本的编号排列顺序为多少。*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void Prtlist(list<int> l)
{//打印链表
   list<int>::iterator it=l.begin();
  while(it!=l.end())
    cout<<*it++<<' ';
    cout<<endl;
}
int main()
{
  int n,m,op,p,q;
  cin>>n>>m;
  list<int> l;
  vector< list<int>::iterator> v(n+1);//存储链表中每一个元素对应的跌代器；
  for(int i=1;i<=n;i++)l.push_back(i);//初始化链表
  list<int> ::iterator it=l.begin();
  int i=1;
  while(it!=l.end())v[i++]=it++;//将连表每个元素对应的跌代器存在数组里
  //注：list的缺点是查找元素效率低，如果不存储每个元素跌代器，将超时，无法100%通过
  while(m--)//m个算例
  {
     cin>>op;
     if(op<3)
       {
         cin>>p;
         if(op==1){//操作1
           l.erase(v[p]);//直接引用p所对应的跌代器删除元素
           l.push_front(p);//将p放在list最前面
           v[p]=l.begin();//存储p的新的跌代器
           }
         if(op==2){//操作2
           l.push_back(p);//在list最后加入p
           l.erase(v[p]);//删除存储的p所对应的跌代器位置元素
           auto iter=l.end();//定义一个跌代器
           iter--;//定位最后一个元素
           v[p]=iter;//存储此位置的跌代器
           }
       }
      if(op==3)//操作3
       {
         cin>>p>>q;
         if(p!=q){
         list<int> ::iterator itq=v[q];//定义一个跌代器，存储元素q所对应的跌代器
         l.erase(v[p]);//删除p所对应的元素
         l.insert(++itq,p);//在q的后面插入p，注，itq指向的是q所对应的跌代器，++itq指向q后一个位置
         }
       }
  }
  Prtlist(l);//输出结果
  return 0;
}
