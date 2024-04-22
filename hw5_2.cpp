#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>

const int ARRAY_SIZE = 10;
const int NUM_THREADS = 4;

std::vector<int> data = {5, 2, 7, 1, 9, 3, 6, 4, 8, 0};

void sortArray(int start, int end) {
    std::sort(data.begin() + start, data.begin() + end);
}

int main() {
    std::vector<std::thread> threads;

    for (int i = 0; i < NUM_THREADS; i++) {
        threads.push_back(std::thread(sortArray, i * (ARRAY_SIZE / NUM_THREADS), (i + 1) * (ARRAY_SIZE / NUM_THREADS)));
    }

    for (auto& thread : threads) {
        thread.join();
    }

    // Merge the sorted subarrays
    std::sort(data.begin(), data.end());

    std::cout << "Sorted Array: ";
    for (int num : data) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
