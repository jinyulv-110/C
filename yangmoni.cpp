#include <iostream>
#include <vector>

// 模拟算法实现
int findPositionSimulation(int N) {
    int position = 0;
    int rowIndex = 1;

    while (true) {
        std::vector<int> row(rowIndex, 1);
        // 生成当前行的杨辉三角元素
        for (int i = 1; i < rowIndex - 1; ++i) {
            row[i] = row[i - 1] + row[i];
        }

        // 检查当前行是否包含目标数
        for (int colIndex = 0; colIndex < rowIndex; ++colIndex) {
            ++position;
            if (row[colIndex] == N) {
                return position;
            }
        }

        ++rowIndex;
    }
}

int main() {
    int N = 6;
    std::cout << "使用模拟算法找到 " << N << " 的位置是: " << findPositionSimulation(N) << std::endl;
    return 0;
}
