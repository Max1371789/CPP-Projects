#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>

const int ARRAY_SIZE = 100;
const int NUM_THREADS = 4;

std::vector<int> data(ARRAY_SIZE);

void fillArrayWithRandomNumbers() {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        data[i] = rand() % 1000; // Генерируем случайное число от 0 до 999
    }
}

void findSumOfThreeLargestElements(int start, int end, int& sum) {
    std::sort(data.begin() + start, data.begin() + end, std::greater<int>());
    for (int i = start; i < start + 3; i++) {
        sum += data[i];
    }
}

int main() {
    fillArrayWithRandomNumbers();

    int sum = 0;
    std::vector<std::thread> threads;

    for (int i = 0; i < NUM_THREADS; i++) {
        threads.push_back(std::thread(findSumOfThreeLargestElements, i * (ARRAY_SIZE / NUM_THREADS), (i + 1) * (ARRAY_SIZE / NUM_THREADS), std::ref(sum)));
    }

    for (auto& thread : threads) {
        thread.join();
    }

    std::cout << "Sum of the 3 largest elements: " << sum << std::endl;

    return 0;
}
