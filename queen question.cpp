//���⣺����һ���Թ����ҵ�����ڵ����ڵ����п���·����������������̵�·��

#include <iostream>
#include <vector>
using namespace std;
struct Point {
int x, y;
Point(int x_, int y_) : x(x_), y(y_) {}
};
const int N = 4; // �Թ���С
const int ENTER_X = 0, ENTER_Y = 0; // �������
const int EXIT_X = 3, EXIT_Y = 3; // ��������
vector<Point> Path; // ��ǰ·��
vector<Point> BestPath; // ���·��
int Maze[N][N] = { // �Թ�ʾ����0��ʾ���ߣ�1��ʾ������
{0, 1, 0, 0}, {0, 0, 0, 1}, {0, 1, 0, 0}, {0, 0, 0, 0}
};

void FindPaths(int x, int y) {
// ����ǰ�����·�������Ϊ�ѷ���
Path.push_back(Point(x, y));
Maze[x][y] = 1;
// ����Ƿ��ǳ���
if (x == EXIT_X && y == EXIT_Y) {
// �������·��
if (BestPath.empty() || Path.size() < BestPath.size()) {
BestPath = Path;
}
} else {
// ̽���ĸ�����
// ��
if (x - 1 >= 0 && Maze[x-1][y] == 0) {
FindPaths(x-1, y);
}
// ��
if (x + 1 < N && Maze[x+1][y] == 0) {
FindPaths(x+1, y);
}
// ��
if (y - 1 >= 0 && Maze[x][y-1] == 0) {
FindPaths(x, y-1);
}
// ��
if (y + 1 < N && Maze[x][y+1] == 0) {
FindPaths(x, y+1);
}
}
// ���ݣ��ָ���ǰ��״̬
Path.pop_back();
if (!(x == ENTER_X && y == ENTER_Y)) {
Maze[x][y] = 0;
}
}
int main() {
FindPaths(ENTER_X, ENTER_Y);
// ������·��
cout << "Shortest path:" << endl;
for (const auto& p : BestPath) {
cout << "(" << p.x << ", " << p.y << ") ";
}
cout << endl;
return 0;
}

