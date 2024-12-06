//���ڱ���Ľ�㲻����2500��,��ֱ�ӱ���dfsö����֤�Ƿ���ڻ����� 
#include <bits/stdc++.h>

using namespace std;

const int N = 100;

char matrix[N][N];//���� 
bool flag = 0;//flag=1,�Ѿ��ҵ��˻� 
bool visit[N][N];//visit[i][j]=1,��ʾ(i,j)�ѷ��� 
int start_x, start_y;//��� 
int n, m;

bool in_map(int x, int y)//(x,y)�Ƿ��ڵ�ͼ�� 
{
    if (x > n || y > m || x <= 0 || y <= 0)return false;//���ܳ���Χ 
    return true;
}

void dfs(int x, int y, int step)
{
    //cout<<"x = "<<x<<", y = "<<y<<", step = "<<step<<endl;
    if (x == start_x && y == start_y && step >= 4)//�ص����,��������4 
    {
        flag = 1;//�ҵ��� 
        return;
    }
    if (in_map(x, y + 1))//��������,��ͬ 
    {
        if (matrix[x][y] == matrix[x][y + 1] && !visit[x][y + 1])//�����֮ǰδ���� 
        {
            visit[x][y + 1] = 1;//����֮ 
            dfs(x, y + 1, step + 1);//���ҵݹ� 
            visit[x][y + 1] = 0;//�˳��ݹ�ʱ��ձ�־λ 
        }
    }
    if (in_map(x + 1, y))//�������� 
    {
        if (matrix[x][y] == matrix[x + 1][y] && !visit[x + 1][y])
        {
            visit[x + 1][y] = 1;
            dfs(x + 1, y, step + 1);
            visit[x + 1][y] = 0;
        }
    }
    if (in_map(x, y - 1))//�������� 
    {
        if (matrix[x][y] == matrix[x][y - 1] && !visit[x][y - 1])
        {
            visit[x][y - 1] = 1;
            dfs(x, y - 1, step + 1);
            visit[x][y - 1] = 0;
        }
    }
    if (in_map(x - 1, y))//�������� 
    {
        if (matrix[x][y] == matrix[x - 1][y] && !visit[x - 1][y])
        {
            visit[x - 1][y] = 1;
            dfs(x - 1, y, step + 1);
            visit[x - 1][y] = 0;
        }
    }
    if (flag == 1)return;//�Ѿ��ҵ������մ�,ֱ�ӷ���
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)//���뷽����� 
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    for (int i = 1; i <= n; i++)//ö��ÿ����(i,j)��Ϊ��� 
    {
        for (int j = 1; j <= m; j++)
        {
            start_x = i, start_y = j;//��ʼ����� 
            flag = 0;//��ձ�־λ 
            memset(visit, 0, sizeof(visit));//���visit���� 
            dfs(i, j, 1);//��(i,j)������ʼdfs,��ʼʱ����һ�� 
            if (flag == 1)//�ҵ��� 
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;//δ�ҵ��� 
    return 0;
}