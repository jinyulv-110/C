/*
123123 �����λ��Ϊż�����Ҵ��м�ֿ��õ�����������ͬ��
Ҳ���� 123 �ظ��� 2 �飬�൱�� 123��1000+123��55��3333�� 80968096 Ҳ���ظ��� 2 ��������� 
333��809680 �Ȳ�����Ҫ������������ n �� m��ͳ�� [n,m] ��Χ���ж��ٸ������ظ��� 2 �������
*/



#include <iostream>
using namespace std;
int main()
{
  int n,m; cin>>n>>m;
    int n1,m1;
    int len1=0,len2=0;
    int p1,p2;
    int t=n,r;
    while(t){
        len1++;t/=10;
    }
    r=1;
    for(int i=1;i<=len1/2;i++)
        r*=10;
    if(len1%2) n1=r;
    else {
        p1=n/r,p2=n%r;
        if(p1>p2) n1=p1;
        else if(p1<p2) n1=p1+1;
        else n1=p1;  
    }
    t=m;
    while(t){
        len2++;t/=10;
    }
    if(len2%2){
        r=1;
        for(int i=1;i<=len2/2;i++)
                r*=10;
        m1=r-1;
    } 
    else{
        r=1;
        for(int i=1;i<=len2/2;i++)
        r*=10;
        p1=m/r;p2=m%r;
        if(p1>p2){
            m1=p1-1;
        }
        else if(p1<p2) m1=p1;
        else m1=p1;
    }    
    cout<<m1-n1+1<<endl;
  return 0;
}
