#include <iostream>
#include <string>

#include "Queue.hpp"
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

// Prints each word of a sentence in the order it was typed (FIFO order),
// one per line, using a queue.
void printWordsInOrder(const std::string& text) {
    ds::Queue<std::string> queue;
    std::string word;
    for (char c : text) {
        if (c == ' ') {
            if (!word.empty()) {
                queue.enqueue(word);
                word.clear();
            }
        } else {
            word += c;
        }
    }
    if (!word.empty()) {
        queue.enqueue(word);
    }

    int position = 1;
    while (!queue.empty()) {
        std::cout << "  " << position << ". " << queue.front() << "\n";
        queue.dequeue();
        ++position;
    }
}

int main() {
    std::cout << "ds-toolkit-cpp: Stack demo\n";
    std::cout << "Enter a word or sentence: ";

    std::string input;
    std::getline(std::cin, input);

    std::cout << "Reversed (Stack, LIFO): " << reverseString(input) << "\n";
    std::cout << "Words in order (Queue, FIFO):\n";
    printWordsInOrder(input);
    return 0;
}