#include <iostream>
#include <stdexcept>
#include <string>

#include "Stack.hpp"

static int failures = 0;

#define CHECK(condition)                                              \
    do {                                                              \
        if (!(condition)) {                                           \
            std::cerr << "FAILED: " #condition " (line " << __LINE__  \
                      << ")\n";                                       \
            ++failures;                                               \
        }                                                             \
    } while (0)

void testNewStackIsEmpty() {
    ds::Stack<int> s;
    CHECK(s.empty());
    CHECK(s.size() == 0);
}

void testPushIncreasesSize() {
    ds::Stack<int> s;
    s.push(10);
    s.push(20);
    CHECK(!s.empty());
    CHECK(s.size() == 2);
}

void testLifoOrder() {
    ds::Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    CHECK(s.top() == 3);
    s.pop();
    CHECK(s.top() == 2);
    s.pop();
    CHECK(s.top() == 1);
    s.pop();
    CHECK(s.empty());
}

void testPopOnEmptyThrows() {
    ds::Stack<int> s;
    bool threw = false;
    try {
        s.pop();
    } catch (const std::runtime_error&) {
        threw = true;
    }
    CHECK(threw);
}

void testTopOnEmptyThrows() {
    ds::Stack<int> s;
    bool threw = false;
    try {
        s.top();
    } catch (const std::runtime_error&) {
        threw = true;
    }
    CHECK(threw);
}

void testWorksWithStrings() {
    ds::Stack<std::string> s;
    s.push("hello");
    s.push("world");
    CHECK(s.top() == "world");
    s.pop();
    CHECK(s.top() == "hello");
}

int main() {
    testNewStackIsEmpty();
    testPushIncreasesSize();
    testLifoOrder();
    testPopOnEmptyThrows();
    testTopOnEmptyThrows();
    testWorksWithStrings();

    if (failures == 0) {
        std::cout << "All Stack tests passed.\n";
        return 0;
    }
    std::cerr << failures << " check(s) failed.\n";
    return 1;
}