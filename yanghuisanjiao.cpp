#include <iostream>
#include <vector>

// ö���㷨ʵ��
int findPositionEnumeration(int N) {
    int row = 1;
    int position = 0;
    std::vector<int> previousRow;

    while (true) {
        std::vector<int> currentRow(row, 1);
        // ���ɵ�ǰ�е��������Ԫ��
        for (int i = 1; i < row - 1; ++i) {
            currentRow[i] = previousRow[i - 1] + previousRow[i];
        }

        // ��鵱ǰ���Ƿ����Ŀ����
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
    std::cout << "ʹ��ö���㷨�ҵ� " << N << " ��λ����: " << findPositionEnumeration(N) << std::endl;
    return 0;
}
