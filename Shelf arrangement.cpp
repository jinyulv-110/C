/*
С����С��ӦƸ������ͼ��ݵĹ���Ա������һ����������鼮��

����ͼ����� n ���飬�鼮��ʼʱ�� 1��n ��˳��������С�С����� 
m ��ָ�С����Ҫ����ָ����ж�Ӧ�Ĳ����������ϵ���£�
1 p�������Ϊ p ���鱾�ƶ�����һλ��
2 p�������Ϊ p���鱾�ƶ������һλ��
3 p q�������Ϊp���鱾�ƶ������Ϊ q ���鱾���档
�������㣬С������ m �β������鱾�ı������˳��Ϊ���١�*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void Prtlist(list<int> l)
{//��ӡ����
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
  vector< list<int>::iterator> v(n+1);//�洢������ÿһ��Ԫ�ض�Ӧ�ĵ�������
  for(int i=1;i<=n;i++)l.push_back(i);//��ʼ������
  list<int> ::iterator it=l.begin();
  int i=1;
  while(it!=l.end())v[i++]=it++;//������ÿ��Ԫ�ض�Ӧ�ĵ���������������
  //ע��list��ȱ���ǲ���Ԫ��Ч�ʵͣ�������洢ÿ��Ԫ�ص�����������ʱ���޷�100%ͨ��
  while(m--)//m������
  {
     cin>>op;
     if(op<3)
       {
         cin>>p;
         if(op==1){//����1
           l.erase(v[p]);//ֱ������p����Ӧ�ĵ�����ɾ��Ԫ��
           l.push_front(p);//��p����list��ǰ��
           v[p]=l.begin();//�洢p���µĵ�����
           }
         if(op==2){//����2
           l.push_back(p);//��list������p
           l.erase(v[p]);//ɾ���洢��p����Ӧ�ĵ�����λ��Ԫ��
           auto iter=l.end();//����һ��������
           iter--;//��λ���һ��Ԫ��
           v[p]=iter;//�洢��λ�õĵ�����
           }
       }
      if(op==3)//����3
       {
         cin>>p>>q;
         if(p!=q){
         list<int> ::iterator itq=v[q];//����һ�����������洢Ԫ��q����Ӧ�ĵ�����
         l.erase(v[p]);//ɾ��p����Ӧ��Ԫ��
         l.insert(++itq,p);//��q�ĺ������p��ע��itqָ�����q����Ӧ�ĵ�������++itqָ��q��һ��λ��
         }
       }
  }
  Prtlist(l);//������
  return 0;
}
