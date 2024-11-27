/*小明冒充 
X
X 星球的骑士，进入了一个奇怪的城堡。

城堡里边什么都没有，只有方形石头铺成的地面。

假设城堡地面是 
n
×
n
n×n 个方格。如下图所示。
按习俗，骑士要从西北角走到东南角。可以横向或纵向移动，但不能斜着走，也不能跳跃。每走到一个新方格，就要向正北方和正西方各射一箭。（城堡的西墙和北墙内各有 
n
n 个靶子）同一个方格只允许经过一次。但不必走完所有的方格。如果只给出靶子上箭的数目，你能推断出骑士的行走路线吗？有时是可以的，比如上图中的例子。

本题的要求就是已知箭靶数字，求骑士的行走路径（测试数据保证路径唯一）

输入描述
第一行一个整数 
N
N (
0
≤
N
≤
20
0≤N≤20)，表示地面有 
N
×
N
N×N 个方格。

第二行 
N
N 个整数，空格分开，表示北边的箭靶上的数字（自西向东）

第三行 
N
N 个整数，空格分开，表示西边的箭靶上的数字（自北向南）

输出描述
输出一行若干个整数，表示骑士路径。

为了方便表示，我们约定每个小格子用一个数字代表，从西北角开始编号: 0,1,2,3 
?
?

比如，上图中的方块编号为：

0 1 2 3

4 5 6 7

8 9 10 11

12 13 14 15
*/ 



#include <stdio.h>
#include <stdlib.h>

int zhuanyix[4] = {1, 0, -1,0};
int zhuanyiy[4] = {0, 1, 0,-1};
int d[200] = {0};
int j = 0;
int num = 1;

void dfs(int ab[][20], int a[][20], int b[], int c[], int x, int y, int n) {
    // 判断是否越界
    if (x < 0 || x >= n || y < 0 || y >= n) {
        return;
    }
    // 判断是否已经走过
    if (ab[x][y] != -1) {
        return;
    }
    // 判断是否满足向北和向西射箭的条件
    if (b[x] > 0 && c[y] > 0) {
        ab[x][y] = j;
        b[x]--;
        c[y]--;
        d[j] = a[x][y];
        j++;
        // 判断是否到达终点
        if (x == n - 1 && y == n - 1) {
            for (int i = 0; i < n; i++) {
                if (b[i] == 0 && c[i] == 0) {
                    num++;
                }
            }
            if (num == n) {
                for (int i = 0; i < j; i++) {
                    printf("%d ", d[i]);
                }
                return;
            }
            num = 0;
        }
        for (int i = 0; i < 4; i++) {
            dfs(ab, a, b, c, x + zhuanyix[i], y + zhuanyiy[i], n);
        }
        ab[x][y] = -1;
        b[x]++;
        c[y]++;
        j--;
    }
}

int main() {
    int n;
    int b[20], c[20];
    scanf("%d", &n);
    int a[20][20];
    int ab[20][20];
    // 初始化棋盘
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ab[i][j] = -1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = i * n + j;
        }
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    dfs(ab, a, b, c, 0, 0, n);
    return 0;
}
