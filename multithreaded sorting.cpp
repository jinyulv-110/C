#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

// 生成随机数填充数组
void generateRandomNumbers(std::vector<int>& arr, int size) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000);

    for (int i = 0; i < size; ++i) {
        arr[i] = dis(gen);
    }
}

// 对数组进行排序
void sortArray(std::vector<int>& arr) {
    std::sort(arr.begin(), arr.end());
}

int main() {
    const int size = 1000000;
    std::vector<int> arr(size);

    // 生成随机数
    auto start = std::chrono::high_resolution_clock::now();
    generateRandomNumbers(arr, size);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "生成随机数耗时: " << elapsed.count() << " 秒\n";

    // 创建排序线程
    start = std::chrono::high_resolution_clock::now();
    std::thread sortThread(sortArray, std::ref(arr));
    sortThread.join();
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "排序耗时: " << elapsed.count() << " 秒\n";

    // 输出排序后的前10个元素
    std::cout << "排序后的前10个元素: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
