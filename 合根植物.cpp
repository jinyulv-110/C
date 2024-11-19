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

#include<iostream>
#include<vector>
int parent[1010], cnt[1010];
using namespace std;

// 寻找根节点
int findRoot(int x) {
    if (x != parent[x]) {
        parent[x] = findRoot(parent[x]); // 路径压缩，将x到根节点的路径上的所有节点的父节点都指向根节点
    }
    return parent[x];
}

int main() {
    int m, n, k, t = 1;
    cin >> m >> n;
    // 初始化并查集
    for (int i = 1; i <= m * n; i++) {
        parent[i] = i; // 初始化每个节点的父节点为自身
        cnt[i] = 1; // 每个集合中节点数量初始化为1
    }
    cin >> k;
    // 处理合并根的情况
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        int rootA = findRoot(a); // 查找a的根节点
        int rootB = findRoot(b); // 查找b的根节点
        if (rootA != rootB) { // 如果a和b的根节点不同，说明需要合并
            parent[rootB] = rootA; // 将b的根节点设置为a的根节点的子节点
            cnt[rootA] += cnt[rootB]; // 更新a所在集合的节点数量
        }
    }
    // 统计合根植物数量
    int ans = 0;
    for (int i = 1; i <= m * n; i++) {
        if (parent[i] == i) { // 如果节点的父节点是自身，说明它是一个集合的根节点
            ans++; // 统计合根植物的数量
        }
    }
    cout << ans;
    return 0;
}
