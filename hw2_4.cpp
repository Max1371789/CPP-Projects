#include <iostream>
#include <string>
#include <stack>

bool isValidBracketSequence(const std::string& sequence) {
    std::stack<char> s;
    
    for (char bracket : sequence) {
        if (bracket == '(' || bracket == '[' || bracket == '{') {
            s.push(bracket);
        } else if (bracket == ')' && !s.empty() && s.top() == '(') {
            s.pop();
        } else if (bracket == ']' && !s.empty() && s.top() == '[') {
            s.pop();
        } else if (bracket == '}' && !s.empty() && s.top() == '{') {
            s.pop();
        } else {
            return false;
        }
    }
    
    return s.empty();
}

int main() {
    std::string bracketSequence;
    std::cout << "Enter a bracket sequence: ";
    std::cin >> bracketSequence;
    
    if (isValidBracketSequence(bracketSequence)) {
        std::cout << "The bracket sequence is correct." << std::endl;
    } else {
        std::cout << "The bracket sequence is incorrect." << std::endl;
    }

    return 0;
}
