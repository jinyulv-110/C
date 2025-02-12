#include <iostream>
#include <vector>

// ģ���㷨ʵ��
int findPositionSimulation(int N) {
    int position = 0;
    int rowIndex = 1;

    while (true) {
        std::vector<int> row(rowIndex, 1);
        // ���ɵ�ǰ�е��������Ԫ��
        for (int i = 1; i < rowIndex - 1; ++i) {
            row[i] = row[i - 1] + row[i];
        }

        // ��鵱ǰ���Ƿ����Ŀ����
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
    std::cout << "ʹ��ģ���㷨�ҵ� " << N << " ��λ����: " << findPositionSimulation(N) << std::endl;
    return 0;
}
