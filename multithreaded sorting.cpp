#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

// ����������������
void generateRandomNumbers(std::vector<int>& arr, int size) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000);

    for (int i = 0; i < size; ++i) {
        arr[i] = dis(gen);
    }
}

// �������������
void sortArray(std::vector<int>& arr) {
    std::sort(arr.begin(), arr.end());
}

int main() {
    const int size = 1000000;
    std::vector<int> arr(size);

    // ���������
    auto start = std::chrono::high_resolution_clock::now();
    generateRandomNumbers(arr, size);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "�����������ʱ: " << elapsed.count() << " ��\n";

    // ���������߳�
    start = std::chrono::high_resolution_clock::now();
    std::thread sortThread(sortArray, std::ref(arr));
    sortThread.join();
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "�����ʱ: " << elapsed.count() << " ��\n";

    // ���������ǰ10��Ԫ��
    std::cout << "������ǰ10��Ԫ��: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
