//问题：给定一个迷宫，找到从入口到出口的所有可行路径，并给出其中最短的路径

#include <iostream>
#include <vector>
using namespace std;
struct Point {
int x, y;
Point(int x_, int y_) : x(x_), y(y_) {}
};
const int N = 4; // 迷宫大小
const int ENTER_X = 0, ENTER_Y = 0; // 入口坐标
const int EXIT_X = 3, EXIT_Y = 3; // 出口坐标
vector<Point> Path; // 当前路径
vector<Point> BestPath; // 最短路径
int Maze[N][N] = { // 迷宫示例，0表示可走，1表示不可走
{0, 1, 0, 0}, {0, 0, 0, 1}, {0, 1, 0, 0}, {0, 0, 0, 0}
};

void FindPaths(int x, int y) {
// 将当前点加入路径并标记为已访问
Path.push_back(Point(x, y));
Maze[x][y] = 1;
// 检查是否是出口
if (x == EXIT_X && y == EXIT_Y) {
// 更新最短路径
if (BestPath.empty() || Path.size() < BestPath.size()) {
BestPath = Path;
}
} else {
// 探索四个方向
// 上
if (x - 1 >= 0 && Maze[x-1][y] == 0) {
FindPaths(x-1, y);
}
// 下
if (x + 1 < N && Maze[x+1][y] == 0) {
FindPaths(x+1, y);
}
// 左
if (y - 1 >= 0 && Maze[x][y-1] == 0) {
FindPaths(x, y-1);
}
// 右
if (y + 1 < N && Maze[x][y+1] == 0) {
FindPaths(x, y+1);
}
}
// 回溯，恢复当前点状态
Path.pop_back();
if (!(x == ENTER_X && y == ENTER_Y)) {
Maze[x][y] = 0;
}
}
int main() {
FindPaths(ENTER_X, ENTER_Y);
// 输出最短路径
cout << "Shortest path:" << endl;
for (const auto& p : BestPath) {
cout << "(" << p.x << ", " << p.y << ") ";
}
cout << endl;
return 0;
}

