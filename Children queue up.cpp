/*n个小朋友站成一排。现在要把他们按身高从低到高的顺序排列，但是每次只能交换位置相邻的两个小朋友。

每个小朋友都有一个不高兴的程度。开始的时候，所有小朋友的不高兴程度都是 0。

如果某个小朋友第一次被要求交换，则他的不高兴程度增加 1，如果第二次要求他交换，则他的不高兴程度增加 2（即不高兴程度为 3），
依次类推。当要求某个小朋友第 k 次交换时，他的不高兴程度增加 k。 

请问，要让所有小朋友按从低到高排队，他们的不高兴程度之和最小是多少。

如果有两个小朋友身高一样，则他们谁站在谁前面是没有关系的。*/
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

