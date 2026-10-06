#include <iostream>
#include <stdexcept>
#include <string>

#include "Queue.hpp"

static int failures = 0;

#define CHECK(condition)                                              \
    do {                                                              \
        if (!(condition)) {                                           \
            std::cerr << "FAILED: " #condition " (line " << __LINE__  \
                      << ")\n";                                       \
            ++failures;                                               \
        }                                                             \
    } while (0)

void testNewQueueIsEmpty() {
    ds::Queue<int> q;
    CHECK(q.empty());
    CHECK(q.size() == 0);
}

void testEnqueueIncreasesSize() {
    ds::Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    CHECK(!q.empty());
    CHECK(q.size() == 2);
}

void testFifoOrder() {
    ds::Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    CHECK(q.front() == 1);
    q.dequeue();
    CHECK(q.front() == 2);
    q.dequeue();
    CHECK(q.front() == 3);
    q.dequeue();
    CHECK(q.empty());
}

void testReuseAfterEmptying() {
    // Catches the classic bug of forgetting to reset tail_ when the queue empties.
    ds::Queue<int> q;
    q.enqueue(1);
    q.dequeue();
    q.enqueue(2);
    CHECK(q.size() == 1);
    CHECK(q.front() == 2);
}

void testDequeueOnEmptyThrows() {
    ds::Queue<int> q;
    bool threw = false;
    try {
        q.dequeue();
    } catch (const std::runtime_error&) {
        threw = true;
    }
    CHECK(threw);
}

void testFrontOnEmptyThrows() {
    ds::Queue<int> q;
    bool threw = false;
    try {
        q.front();
    } catch (const std::runtime_error&) {
        threw = true;
    }
    CHECK(threw);
}

void testWorksWithStrings() {
    ds::Queue<std::string> q;
    q.enqueue("hello");
    q.enqueue("world");
    CHECK(q.front() == "hello");
    q.dequeue();
    CHECK(q.front() == "world");
}

int main() {
    testNewQueueIsEmpty();
    testEnqueueIncreasesSize();
    testFifoOrder();
    testReuseAfterEmptying();
    testDequeueOnEmptyThrows();
    testFrontOnEmptyThrows();
    testWorksWithStrings();

    if (failures == 0) {
        std::cout << "All Queue tests passed.\n";
        return 0;
    }
    std::cerr << failures << " check(s) failed.\n";
    return 1;
}