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
using namespace std;//定义了一个宏N表示数组的最大长度为100002，并声明使用std命名空间
struct Node{
    int h;
    long long swap;
}arr[N],t[N];//定义了Node 结构体，其中有成员h用于存储小朋友的身高，成员swap，用于记录该位置元素对应的逆序对数量或者和交换等相关的一个统计量（初始化为0）
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
            arr[i].swap += j - （mid +1）;
            t[index++] = arr[i++];
        }
    }
    while(i<=mid) arr[i].swap += r-mid,t[index++] = arr[i++];
    while(j<=r)t[index++] = arr[j++];
    for(int x = l,i = 0;x<=r;x++,i++)arr[x] = t[i];
}//实现归并排序的函数
int main(){
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>arr[i].h;//通过循环读取每个小朋友的身高存入arr组中，并初始化每个元素的swap值为0。
        arr[i].swap = 0;
    }
    merge_sort(0,n-1);//调用merge_sort函数对整个数组进行归并排序并统计逆序对的相关信息。
    long long res = 0;
    for(int i = 0; i < n; i++){
        res += (1+arr[i].swap)*arr[i].swap/2;
    }
    cout<<res;
    return 0;
}

