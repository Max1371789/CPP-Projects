#include <iostream>
#include <set>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <chrono>

class RBTree {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node* parent;
        bool isRed; // true if red, false if black
    };

    Node* root;

    //Вспомогательные функции для операций Red-Black Tree

public:
    RBTree() : root(nullptr) {}

    // Операции «Красно-черного дерева»

};

int main() {
    std::set<int> setContainer;
    RBTree rbTree;

    srand(static_cast<unsigned>(time(0)));

    // Заполняем контейнеры 500 случайными неповторяющимися числами.
    const int numElements = 500;
    for (int i = 0; i < numElements; ++i) {
        int num = rand() % 1000; // Генерируем случайное число от 0 до 999
        while (setContainer.find(num) != setContainer.end()) {
            num = rand() % 1000;
        }
        setContainer.insert(num);
    }

    // Сравниваем время поиска
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numElements; ++i) {
        int num = rand() % 1000;
        setContainer.find(num);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> searchTime = end - start;
    std::cout << "Search time for set container: " << searchTime.count() << " seconds" << std::endl;

    // Добавляем новый элемент
    start = std::chrono::high_resolution_clock::now();
    int newNum = rand() % 1000;
    setContainer.insert(newNum);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> insertTime = end - start;
    std::cout << "Time to add a new element to set container: " << insertTime.count() << " seconds" << std::endl;

    return 0;
}
