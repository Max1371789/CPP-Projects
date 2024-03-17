#include <iostream>
#include <vector>

// Структура узла для связанного списка в отдельной цепочке
struct Node {
    int key;
    Node* next;
};

// Простая хэш-функция с использованием хеширования по модулю
int hashFunction(int key, int tableSize) {
    return key % tableSize;
}

// Функция поиска элемента в хеш-таблице
bool searchElement(const std::vector<Node*>& hashTable, int key, int tableSize) {
    int index = hashFunction(key, tableSize);
    Node* current = hashTable[index];
    while (current != nullptr) {
        if (current->key == key) {
            return true; // Элемент найден
        }
        current = current->next;
    }
    return false; // Элемент не найден
}

int main() {
   // Определяем размер хеш-таблицы
    const int tableSize = 10;
// Создаем вектор связанных списков для представления хеш-таблицы
    std::vector<Node*> hashTable(tableSize, nullptr);

    // Вставляем несколько элементов в хеш-таблицу
    int keys[] = {12, 23, 34, 45, 56, 67, 78, 89};
    for (int key : keys) {
        int index = hashFunction(key, tableSize);
        
        // Создаем новый узел для ключа
        Node* newNode = new Node{key, nullptr};

        // Вставляем новый узел в начало связанного списка.
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }

    // Поиск элементов в хеш-таблице
    int searchKeys[] = {34, 55};
    for (int key : searchKeys) {
        if (searchElement(hashTable, key, tableSize)) {
            std::cout << "Element " << key << " found in the hash table." << std::endl;
        } else {
            std::cout << "Element " << key << " not found in the hash table." << std::endl;
        }
    }

    //  Очистите память, удалив узлы
    for (int i = 0; i < tableSize; ++i) {
        Node* current = hashTable[i];
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    return 0;
}
