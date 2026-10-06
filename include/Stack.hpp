#ifndef DS_TOOLKIT_STACK_HPP
#define DS_TOOLKIT_STACK_HPP

#include <cstddef>

namespace ds {

// A LIFO (last in, first out) stack backed by a singly linked list.
template <typename T>
class Stack {
public:
    Stack() : head_(nullptr), size_(0) {}

    ~Stack() {
        while (head_ != nullptr) {
            Node* next = head_->next;
            delete head_;
            head_ = next;
        }
    }

    // Copying is disabled for now to avoid double-deleting nodes.
    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;

    // Adds a value to the top of the stack.
    void push(const T& value) {
        head_ = new Node{value, head_};
        ++size_;
    }

    bool empty() const { return size_ == 0; }
    std::size_t size() const { return size_; }

private:
    struct Node {
        T value;
        Node* next;
    };

    Node* head_;
    std::size_t size_;
};

}  // namespace ds

#endif  // DS_TOOLKIT_STACK_HPP