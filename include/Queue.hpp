#ifndef DS_TOOLKIT_QUEUE_HPP
#define DS_TOOLKIT_QUEUE_HPP

#include <cstddef>
#include <stdexcept>

namespace ds {

// A FIFO (first in, first out) queue backed by a singly linked list.
// head_ is the front (dequeue side), tail_ is the back (enqueue side).
template <typename T>
class Queue {
public:
    Queue() : head_(nullptr), tail_(nullptr), size_(0) {}

    ~Queue() {
        while (head_ != nullptr) {
            Node* next = head_->next;
            delete head_;
            head_ = next;
        }
    }

    // Copying is disabled for now to avoid double-deleting nodes.
    Queue(const Queue&) = delete;
    Queue& operator=(const Queue&) = delete;

    // Adds a value to the back of the queue.
    void enqueue(const T& value) {
        Node* node = new Node{value, nullptr};
        if (tail_ == nullptr) {
            head_ = node;
        } else {
            tail_->next = node;
        }
        tail_ = node;
        ++size_;
    }

    // Removes the front value. Throws if the queue is empty.
    void dequeue() {
        if (head_ == nullptr) {
            throw std::runtime_error("Queue::dequeue() called on empty queue");
        }
        Node* old = head_;
        head_ = head_->next;
        if (head_ == nullptr) {
            tail_ = nullptr;
        }
        delete old;
        --size_;
    }

    // Returns the front value. Throws if the queue is empty.
    T& front() {
        if (head_ == nullptr) {
            throw std::runtime_error("Queue::front() called on empty queue");
        }
        return head_->value;
    }

    const T& front() const {
        if (head_ == nullptr) {
            throw std::runtime_error("Queue::front() called on empty queue");
        }
        return head_->value;
    }

    bool empty() const { return size_ == 0; }
    std::size_t size() const { return size_; }

private:
    struct Node {
        T value;
        Node* next;
    };

    Node* head_;
    Node* tail_;
    std::size_t size_;
};

}  // namespace ds

#endif  // DS_TOOLKIT_QUEUE_HPP