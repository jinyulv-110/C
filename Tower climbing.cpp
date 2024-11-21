/*
问题描述小蓝正在玩一个攀登高塔的游戏。
高塔的层数是无限的，但游戏最多只有 n 回合。
小蓝一开始拥有 m 点能量，在每个回合都有一个值 Ai表示小蓝的角色状态。
小蓝每回合可以选择消费任意点能量 Ci（最低消费 1 点，没有上限），他在这回合将最多可以向上攀爬 Ai·Ci层。
实际攀爬的层数取决于小蓝自己在这回合的表现，不过最差也会向上爬一层。
当某回合小蓝的能量点数耗尽,那么在完成这个回合后,游戏结束。
n 回合结束后，不管能量还有没有剩余，游戏都会直接结束。
给出小蓝每回合的Ai和自己一开始的能量点数 m。
小蓝想知道有多少种不同的可能出现的游玩过程。
如果小蓝在两种游玩过程中的任一对应回合花费的能量点数不同或该回合结束时所处层数不同，那么这两种游玩过程就被视为不同。
输入格式输入的第一行包含两个整数 n,m，用一个空格分隔。
第二行包含n 个整数 Ai
，相邻整数之间使用一个空格分隔，表示小蓝每回合的状态值。
输出格式输出一行包含一个整数表示给定条件下不同游玩过程的数量。
由于答案可能很大，你只需要输出答案对 998244353 取模的结果。

*/ 


#include  <bits/stdc++.h>
#define MOD 998244353//计算不同游玩过程中的数量 
using namespace std;
int countPlayProcesses(int n,int m,int*A){
	int dp[n + 1][m + 1];//初始化dp数组
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j<=m; j++)
		
		{
			dp[i][j]=0;
			
		}
	} 
	
	dp[0][0] =1;
	//动态规划计算不同游玩过程数量
	for (int i =1;i<=n; i++)
	{
		for (int j = 0; j<=m;j++)
		{
			//考虑本回合不消耗能量的情况
			dp[i][j] +=dp[i-1][j];
			dp[i][j] %=MOD;
			//考虑本回合消耗能量的情况
			for (int k =1;k<=j;k++){
				dp[i][j] +=dp[i-1][j-k]*((A[i-1]*k >=1)? 1 : 0);
				dp[i][j] %=MOD;
			} 
		}
	 } 
	 int result = 0;
	 //累加n回合结束后不同能力剩余情况下的游玩过程数量
	 for (int j =0;j<= m;j++){
	 	result += dp[n][j];
	 	result %= MOD;
	 	
	 } 
	 return result;
	 
}
int main(){
	int n , m;
	scanf("%d %d",&n,&m);
	int *A=(int *)malloc(n * sizeof(int));
	for (int i=0;i<n;i++){
		scanf("%d",&A[i]);
		
	}
	int result=countPlayProcesses(n,m,A);
	printf("%d\n",result);
	free(A);
	return 0;
}
 
