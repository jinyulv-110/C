/*在毕业多年后，你看着手机相册里的照片，陷入了沉思…

那是张拍摄于许多年前的班级照，照片里教室的黑板上面写着 N 个整数 A1,,…,AN。你猜测这些整数之间可能有一些特殊的关系，但此刻的你并不知道。

于是你决定使用黑板上的这些数字来进行一项计算，以期望从中获得答案。但在计算之前，你需要进行一些准备工作。你可以选择其中一个数字，然后用一个 1到 10^9
之间的整数来替换它，当然你也可以选择不替换。你希望在替换后，这 N 个整数的最大公约数最大。因为你的直觉告诉你，最大公约数越大，答案就会离你越近。

为了达到这个目的，你需要准备一个程序来帮助你进行计算。请你编写这个程序，来计算替换后这 N 个整数的最大公约数最大可以达到多少。

输入格式
第一行包含一个整数 N（1≤N≤10^3），表示黑板上的整数个数。第二行包含 N 个整数 A1,A2,…,AN（1≤Ai10^9） 
，表示黑板上原来写的数字。*/
 
 #include<iostream>
#include<cmath>
using namespace std;
const int n=1005;
long a[n];

long gcd(long a, long b) {
    while (b != 0) {
        long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(){
    int N;cin>>N;
    for(int i=0;i<N;i++){
        cin>>a[i];
    }
    long other_gcd;
    long max_gcd=0;
    for(int i=0;i<N;i++){
        if(i==0) other_gcd=a[1];
        else other_gcd=a[0];
        for(int j=0;j<N;j++){
            if(j!=i){
                other_gcd=gcd(other_gcd,a[j]);
            }
        }
        max_gcd=max(max_gcd,other_gcd);
    }
    cout<<max_gcd;
}
