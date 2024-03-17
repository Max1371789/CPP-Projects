#include <iostream>
#include <string>
#include <map>
#include <vector>

struct Node {
    std::string name;
    int height;
};

int main() {
    int N;
    std::cin >> N;

    std::map<std::string, std::string> parentMap;
    std::map<std::string, Node> familyTree;

    for (int i = 0; i < N - 1; ++i) {
        std::string child, parent;
        std::cin >> child >> parent;
        parentMap[child] = parent;
    }

    // Поиск предка
    std::string ancestor;
    for (const auto& entry : parentMap) {
        if (parentMap.find(entry.second) == parentMap.end()) {
            ancestor = entry.second;
            break;
        }
    }

    // Проходим по генеалогическому древу, чтобы вычислить рост.
    std::vector<std::string> names;
    names.push_back(ancestor);

    while (!names.empty()) {
        std::string currentName = names.back();
        names.pop_back();

        if (familyTree.find(currentName) == familyTree.end()) {
            familyTree[currentName] = {currentName, 0};
        }

        for (const auto& entry : parentMap) {
            if (entry.second == currentName) {
                familyTree[entry.first] = {entry.first, familyTree[currentName].height + 1};
                names.push_back(entry.first);
            }
        }
    }

    // Выводим элементы дерева в лексикографическом порядке с указанием их высот.
    for (const auto& entry : familyTree) {
        std::cout << entry.second.name << " " << entry.second.height << std::endl;
    }

    return 0;
}
