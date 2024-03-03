#include <iostream>
#include <vector>

std::vector<int> factorialNumberSystem(int n) {
    std::vector<int> result;
    int base = 1;
    while (n > 0) {
        result.insert(result.begin(), n % base);
        n /= base;
        base++;
    }
    return result;
}

void printFactorialNumberSystem(int n) {
    std::vector<int> result = factorialNumberSystem(n);
    for (size_t i = 0; i < result.size(); i++) {
        std::cout << result[i];
        if (i < result.size() - 1) {
            std::cout << ".";
        }
    }
    std::cout << std::endl;
}

int main() {
    int number = 7;
    std::cout << "Factorial Number System representation of " << number << " is: ";
    printFactorialNumberSystem(number);
    return 0;
}
