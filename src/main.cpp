#include <iostream>
#include <string>

#include "Stack.hpp"

// Reverses a string using a stack (LIFO order).
std::string reverseString(const std::string& text) {
    ds::Stack<char> stack;
    for (char c : text) {
        stack.push(c);
    }

    std::string result;
    while (!stack.empty()) {
        result += stack.top();
        stack.pop();
    }
    return result;
}

int main() {
    std::cout << "ds-toolkit-cpp: Stack demo\n";
    std::cout << "Enter a word or sentence: ";

    std::string input;
    std::getline(std::cin, input);

    std::cout << "Reversed: " << reverseString(input) << "\n";
    return 0;
}