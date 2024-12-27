/*
С��Ϊ��Ѱ��������һ���Թ�������Թ���һ�� 
n
��
m
n��m �ľ��󣬾���Ԫ���� 
0
0 �� 
1
1 ���ɣ�С��������Ҫ������ߵ��յ㣬��ֻ�� ���������ƶ�����ֵΪ 
1
1 ** �ĸ��ӡ������ߵ��յ�ʱ�������� **��þ�����ֵΪ 
0
0 �ĸ��ӵ������Ľ�ҡ�����С������ʹ��һ��ħ������ħ��ֻ��ʹ�� һ�Σ�ħ���Ĺ���Ϊ���� ��ʼ����ǰ ���Խ� **�����ֵΪ 
1
1 �ĸ��ӱ�� 
0
0**����������С�����ߵ��յ���ܻ�õ������Ϊ���٣�

���ݱ�֤��һ��ʼʱ����һ�����ͨ���յ��·�ߣ����޷���������յ��� 
0
0��
*/

#include <iostream>
#include <queue>
using namespace std;
int n, m; // �����С
int startX, startY, endX, endY, total; // �����յ�����
int arr[310][310];
int al[310][310]; // �Ƿ��Ѿ����뵽������
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
        node aa = q.front(); // ȡ����һ��
        q.pop();

        for (int i = 0; i < 4; i++) {
            int xx = aa.x + dx[i];  // �µĵ������
            int yy = aa.y + dy[i];

            if (xx <= 0 || xx > n || yy <= 0 || yy > m) continue; //Խ����
            if (!al[xx][yy] && arr[xx][yy] == 1) { // ���xx yy ���껹û�б����뵽������
                if (xx == endX && yy == endY) { // ����µ��������Ŀ������Ļ�ֱ�ӷ���
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
    cout << n * m - total << endl; // �����ݼ�ȥ���·��
    return 0;
}
