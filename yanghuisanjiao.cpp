#include <iostream>
#include <vector>

// 枚举算法实现
int findPositionEnumeration(int N) {
    int row = 1;
    int position = 0;
    std::vector<int> previousRow;

    while (true) {
        std::vector<int> currentRow(row, 1);
        // 生成当前行的杨辉三角元素
        for (int i = 1; i < row - 1; ++i) {
            currentRow[i] = previousRow[i - 1] + previousRow[i];
        }

        // 检查当前行是否包含目标数
        for (int col = 0; col < row; ++col) {
            ++position;
            if (currentRow[col] == N) {
                return position;
            }
        }

        previousRow = currentRow;
        ++row;
    }
}

int main() {
    int N = 6;
    std::cout << "使用枚举算法找到 " << N << " 的位置是: " << findPositionEnumeration(N) << std::endl;
    return 0;
}
