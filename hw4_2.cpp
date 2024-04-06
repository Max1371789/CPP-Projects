#include <iostream>
#include <set>
#include <ctime>
#include <chrono>
#include <random>
#include <algorithm>
#include <map>

// Реализация красно-чёрного дерева
template<typename Key, typename Value>
class RedBlackTree {
private:
    std::map<Key, Value> rbTree;

public:
    void insert(Key key, Value value) {
        rbTree[key] = value;
    }

    Value search(Key key) {
        auto it = rbTree.find(key);
        if (it != rbTree.end()) {
            return it->second;
        }
        return Value();
    }
};

int main() {
    std::set<int> uniqueNumbers;
    std::default_random_engine generator(time(0));
    std::uniform_int_distribution<int> distribution(1, 1000);

    // Заполняем контейнеры 500 случайными неповторяющимися числами.
    while (uniqueNumbers.size() < 500) {
        uniqueNumbers.insert(distribution(generator));
    }

    RedBlackTree<int, int> rbTree;
    for (int num : uniqueNumbers) {
        rbTree.insert(num, num);
    }

    // Сравниваем время поиска
    auto start = std::chrono::high_resolution_clock::now();
    for (int num : uniqueNumbers) {
        rbTree.search(num);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> searchTime = end - start;
    std::cout << "Search time in Red-Black Tree: " << searchTime.count() << " seconds" << std::endl;

    // Сравниваем время добавления нового элемента
    start = std::chrono::high_resolution_clock::now();
    rbTree.insert(1001, 1001);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> addTime = end - start;
    std::cout << "Time to add a new element in Red-Black Tree: " << addTime.count() << " seconds" << std::endl;

    return 0;
}
