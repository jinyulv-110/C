//由于本题的结点不超过2500个,故直接暴力dfs枚举验证是否存在环即可 
#include <bits/stdc++.h>

using namespace std;

const int N = 100;

char matrix[N][N];//矩阵 
bool flag = 0;//flag=1,已经找到了环 
bool visit[N][N];//visit[i][j]=1,表示(i,j)已访问 
int start_x, start_y;//起点 
int n, m;

bool in_map(int x, int y)//(x,y)是否在地图中 
{
    if (x > n || y > m || x <= 0 || y <= 0)return false;//不能超范围 
    return true;
}

void dfs(int x, int y, int step)
{
    //cout<<"x = "<<x<<", y = "<<y<<", step = "<<step<<endl;
    if (x == start_x && y == start_y && step >= 4)//回到起点,步数大于4 
    {
        flag = 1;//找到答案 
        return;
    }
    if (in_map(x, y + 1))//可以向右,下同 
    {
        if (matrix[x][y] == matrix[x][y + 1] && !visit[x][y + 1])//相等且之前未访问 
        {
            visit[x][y + 1] = 1;//访问之 
            dfs(x, y + 1, step + 1);//向右递归 
            visit[x][y + 1] = 0;//退出递归时清空标志位 
        }
    }
    if (in_map(x + 1, y))//可以向下 
    {
        if (matrix[x][y] == matrix[x + 1][y] && !visit[x + 1][y])
        {
            visit[x + 1][y] = 1;
            dfs(x + 1, y, step + 1);
            visit[x + 1][y] = 0;
        }
    }
    if (in_map(x, y - 1))//可以向左 
    {
        if (matrix[x][y] == matrix[x][y - 1] && !visit[x][y - 1])
        {
            visit[x][y - 1] = 1;
            dfs(x, y - 1, step + 1);
            visit[x][y - 1] = 0;
        }
    }
    if (in_map(x - 1, y))//可以向上 
    {
        if (matrix[x][y] == matrix[x - 1][y] && !visit[x - 1][y])
        {
            visit[x - 1][y] = 1;
            dfs(x - 1, y, step + 1);
            visit[x - 1][y] = 0;
        }
    }
    if (flag == 1)return;//已经找到了最终答案,直接返回
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)//输入方格矩阵 
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    for (int i = 1; i <= n; i++)//枚举每个点(i,j)作为起点 
    {
        for (int j = 1; j <= m; j++)
        {
            start_x = i, start_y = j;//初始化起点 
            flag = 0;//清空标志位 
            memset(visit, 0, sizeof(visit));//清空visit数组 
            dfs(i, j, 1);//从(i,j)出发开始dfs,初始时走了一步 
            if (flag == 1)//找到答案 
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;//未找到答案 
    return 0;
}