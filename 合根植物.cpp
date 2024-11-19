/*
w 星球的一个种植园，被分成mxn个小格子（东西方向 m行，南北方向 n 列）。每个格子里种了一株合根植物。

这种植物有个特点，它的根可能会沿着南北或东西方向伸展，从而与另一个格子的植物合成为一体。

如果我们告诉你哪些小格子间出现了连根现象，你能说出这个园中一共有多少株合根植物吗？

输入描述
第一行，两个整数 
m,n，用空格分开，表示格子的行数、列数（1≤m,n≤1000）。

接下来一行，一个整数 k (0≤k≤10 ^5 )，表示下面还有k 行数据。
接下来 k 行，每行两个整数a，b，表示编号为 a的小格子和编号为 b的小格子合根了。

格子的编号一行一行，从上到下，从左到右编号。
*/
#include <bits/stdc++.h>
using namespace std;

int m,n;
int k;
int f[1000005] = {0};
set<int> s;

void init_cha(){
    for(int i=1;i<=m*n;i++){
        f[i] = i;
    }
}

int find_cha(int n){
    if(f[n]==n){
        return n;
    }else{
        f[n] = find_cha(f[n]);
        return f[n];
    }
}

void merge_cha(int a,int b){
    f[find_cha(a)] = find_cha(b);
} 

int main(){
    cin>>m>>n>>k;
    init_cha();
    for(int i=0;i<k;i++){
        int a,b;
        cin>>a>>b;
        merge_cha(a,b);
    }
    for(int i=1;i<=m*n;i++){
        s.insert(find_cha(i));
    }
    cout<<s.size();
    
    return 0;
}
