#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    std::vector<int> values(10000);
    
    // Генерируем случайные значения
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 10000);
    for (int i = 0; i < 10000; i++) {
        values[i] = dis(gen);
    }

    // Копируем вектор для каждого алгоритма сортировки
    std::vector<int> values_bubble = values;
    std::vector<int> values_quick = values;

    // Сортировка пузырьком
    auto start_bubble = std::chrono::steady_clock::now();
    bubbleSort(values_bubble);
    auto end_bubble = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_bubble = end_bubble - start_bubble;

    // Быстрая сортировка
    auto start_quick = std::chrono::steady_clock::now();
    quickSort(values_quick, 0, values_quick.size() - 1);
    auto end_quick = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_quick = end_quick - start_quick;

    // Вывод
    if (elapsed_bubble < elapsed_quick) {
        std::cout << "Bubble sort is faster. Time taken: " << elapsed_bubble.count() << " seconds" << std::endl;
    } else {
        std::cout << "Quick sort is faster. Time taken: " << elapsed_quick.count() << " seconds" << std::endl;
    }

    return 0;
}
