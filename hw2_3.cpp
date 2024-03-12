#include <iostream>
#include <string>
#include <map>

int main() {
    std::string text = "Alpha Beta Alpha Beta Beta";
    
    std::map<std::string, int> wordCount;
    std::string word;
    std::string maxWord;
    int maxCount = 0;

    for (size_t i = 0; i < text.length(); ++i) {
        if (isalpha(text[i])) {
            word += tolower(text[i]);
        } else if (!word.empty()) {
            wordCount[word]++;
            if (wordCount[word] > maxCount || (wordCount[word] == maxCount && word < maxWord)) {
                maxWord = word;
                maxCount = wordCount[word];
            }
            word.clear();
        }
    }

    if (!word.empty()) {
        wordCount[word]++;
        if (wordCount[word] > maxCount || (wordCount[word] == maxCount && word < maxWord)) {
            maxWord = word;
            maxCount = wordCount[word];
        }
    }

    std::cout << maxWord << std::endl;

    return 0;
}
