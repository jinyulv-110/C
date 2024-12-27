/*
小蓝为了寻宝来到了一个迷宫，这个迷宫是一个 
n
×
m
n×m 的矩阵，矩阵元素由 
0
0 和 
1
1 构成，小蓝现在需要从起点走到终点，他只能 上下左右移动且走值为 
1
1 ** 的格子。当他走到终点时，他可以 **获得矩阵中值为 
0
0 的格子的数量的金币。现在小蓝可以使用一个魔法，该魔法只能使用 一次，魔法的功能为在他 开始出发前 可以将 **任意个值为 
1
1 的格子变成 
0
0**，现在问你小蓝在走到终点后能获得的最大金币为多少？

数据保证在一开始时，有一条起点通往终点的路线，你无法将起点与终点变成 
0
0。
*/

#include <iostream>
#include <queue>
using namespace std;
int n, m; // 矩阵大小
int startX, startY, endX, endY, total; // 起点和终点坐标
int arr[310][310];
int al[310][310]; // 是否已经加入到队列中
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

struct node {
    int x;
    int y;
    int step;
    node(int qq, int b, int ss) {
        x = qq;
        y = b;
        step = ss;
    }
};
queue<node> q;

void bfs() {
    while (!q.empty()) {
        node aa = q.front(); // 取出第一个
        q.pop();

        for (int i = 0; i < 4; i++) {
            int xx = aa.x + dx[i];  // 新的点的坐标
            int yy = aa.y + dy[i];

            if (xx <= 0 || xx > n || yy <= 0 || yy > m) continue; //越界了
            if (!al[xx][yy] && arr[xx][yy] == 1) { // 如果xx yy 坐标还没有被加入到队列中
                if (xx == endX && yy == endY) { // 如果新的坐标就是目标坐标的话直接返回
                    total = aa.step + 1;
                    
                    return;
                }
                q.push(node(xx, yy, aa.step + 1));
                al[xx][yy] = 1;
            }
        }
    }
    return;
};


int main() {
    cin >> n >> m;
    cin >> startX >> startY >> endX >> endY;
    getchar();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {   
            char a = getchar();
            if (a == '\n') a = getchar();
            arr[i][j] = a - '0';
        }
    }

    q.push(node(startX, startY, 1));
    al[startX][startY] = 1;
    bfs();
    cout << n * m - total << endl; // 总数据减去最短路径
    return 0;
}
