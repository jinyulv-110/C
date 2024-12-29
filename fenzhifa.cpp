
#include<stdio.h>
#define N 100
 
int search(int *a,int left,int right);
int sum_buf(int *a,int left,int right);
 
int main(void)
{
    int a[N];
    int i;
    int s;
    for(i=0;i<N;i++)
        a[i]=1;
    a[29]=2;//���Ϊ29����Ʒ���ϸ� ������Ʒ��0��ʼ���
    s=search(a,0,N-1);
    printf("���ϸ�Ʒ�ı��Ϊ��%d\n",s);
    return 0;
}
 
//��������������Ԫ��֮��
int sum_buf(int *a,int left,int right)
{
    int i;
    int sum=0;
    for(i=left;i<=right;i++)
        sum+=a[i];
    return sum;
}
 
//�۰���ҷ� �ҳ�����������Ԫ��
int search(int *a,int left,int right)
{
    int mid=(left+right)/2;
    if(left==right-1)
    {
        if(a[left]<a[right])
            return right;
        else
            return left;
    }
    if((right-left)%2==0)//������Ԫ��Ϊ����
    {
        if(sum_buf(a,left,mid-1)>sum_buf(a,mid+1,right))
            return search(a,left,mid-1);
        else
            if(sum_buf(a,left,mid-1)<sum_buf(a,mid+1,right))
                return search(a,mid+1,right);
            else
                return mid;
    }
    else//������Ԫ��Ϊż��
        if(sum_buf(a,left,mid)>sum_buf(a,mid+1,right))
            return search(a,left,mid);
        else
            return search(a,mid+1,right);
}

