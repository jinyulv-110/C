/*n��С����վ��һ�š�����Ҫ�����ǰ���ߴӵ͵��ߵ�˳�����У�����ÿ��ֻ�ܽ���λ�����ڵ�����С���ѡ�

ÿ��С���Ѷ���һ�������˵ĳ̶ȡ���ʼ��ʱ������С���ѵĲ����˳̶ȶ��� 0��

���ĳ��С���ѵ�һ�α�Ҫ�󽻻��������Ĳ����˳̶����� 1������ڶ���Ҫ���������������Ĳ����˳̶����� 2���������˳̶�Ϊ 3����
�������ơ���Ҫ��ĳ��С���ѵ� k �ν���ʱ�����Ĳ����˳̶����� k�� 

���ʣ�Ҫ������С���Ѱ��ӵ͵����Ŷӣ����ǵĲ����˳̶�֮����С�Ƕ��١�

���������С�������һ����������˭վ��˭ǰ����û�й�ϵ�ġ�*/
#include <iostream>
#include <cstring>
#include <algorithm>
#define N 100002
using namespace std;
struct Node{
    int h;
    long long swap;
}arr[N],t[N];
int n;
void merge_sort(int l,int r){
    if(l>=r) return;
    int mid = (l + r)>>1;
    merge_sort(l,mid),merge_sort(mid + 1,r);
    int i=l,j=mid+1,index = 0;
    while(i<=mid&&j<=r){
        if(arr[i].h>arr[j].h){
            arr[j].swap += mid-i+1;
            t[index++] = arr[j++];
        }else{
            arr[i].swap += j - mid -1;
            t[index++] = arr[i++];
        }
    }
    while(i<=mid) arr[i].swap += r-mid,t[index++] = arr[i++];
    while(j<=r)t[index++] = arr[j++];
    for(int x = l,i = 0;x<=r;x++,i++)arr[x] = t[i];
}
int main(){
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>arr[i].h;
        arr[i].swap = 0;
    }
    merge_sort(0,n-1);
    long long res = 0;
    for(int i = 0; i < n; i++){
        res += (1+arr[i].swap)*arr[i].swap/2;
    }
    cout<<res;
    return 0;
}

