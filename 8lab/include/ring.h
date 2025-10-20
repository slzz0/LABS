#pragma once

#include <iostream>
#include <vector>

#include "../include/node.h"
#include "../include/exceptions.h"

template <typename T>
class Ring {
    Node<T>* head = nullptr;
    size_t size = 0;

    bool containsNode(Node<T>* node) const {
        if (!node || empty()) return false;

        Node<T>* current = head;
        for (size_t i = 0; i < size; i++) {
            if (current == node) return true;
            current = current->next;
        }
        return false;
    }

    Node<T>* getTail() const {
        if (empty()) return nullptr;

        Node<T>* current = head;
        for (size_t i = 1; i < size; i++) {
            current = current->next;
        }
        return current;
    }

    void bubbleSortOptimized() {
        if (size <= 1) return;

        bool swapped;
        for (size_t i = 0; i < size - 1; i++) {
            swapped = false;
            Node<T>* current = head;

            for (size_t j = 0; j < size - i - 1; j++) {
                if (Node<T>* nextNode = current->next; current->data > nextNode->data) {
                    std::swap(current->data, nextNode->data);
                    swapped = true;
                }
                current = current->next;
            }

            if (!swapped) break;
        }
    }

   public:
    class Iterator {
        Node<T>* ptr;
        Node<T>* start;
        size_t iterations = 0;
        size_t maxIterations;

       public:
        Iterator() : ptr(nullptr), start(nullptr), maxIterations(0) {}
        Iterator(Node<T>* node, size_t ringSize)
            : ptr(node), start(node), maxIterations(ringSize) {}

        T& operator*() {
            if (!ptr) throw IteratorException("Dereferencing null iterator");
            return ptr->data;
        }

        const T& operator*() const {
            if (!ptr) throw IteratorException("Dereferencing null iterator");
            return ptr->data;
        }

        Iterator& operator++() {
            if (!ptr) throw IteratorException("Incrementing null iterator");
            if (iterations >= maxIterations && maxIterations > 0) {
                throw InfiniteLoopException();
            }
            ptr = ptr->next;
            iterations++;
            return *this;
        }

        Iterator operator++(int) {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        bool operator==(const Iterator& other) const { return ptr == other.ptr; }

        [[nodiscard]] bool completedCycle() const { return ptr == start && iterations > 0; }

        Node<T>* getNode() const { return ptr; }
    };

    Ring() = default;

    Ring(const Ring& other) : size(other.size) {
        if (other.empty()) return;

        head = new Node<T>(other.head->data);
        Node<T>* current = head;
        Node<T>* otherCurrent = other.head->next;

        for (size_t i = 1; i < size; i++) {
            current->next = new Node<T>(otherCurrent->data);
            current = current->next;
            otherCurrent = otherCurrent->next;
        }
        current->next = head;
    }

    Ring(Ring&& move) noexcept : head(move.head), size(move.size) {
        move.head = nullptr;
        move.size = 0;
    }

    ~Ring() { clear(); }

    Ring& operator=(const Ring& other) {
        if (this == &other) return *this;

        Ring temp(other);
        swap(temp);
        return *this;
    }

    Ring& operator=(Ring&& move) noexcept {
        if (this == &move) return *this;

        clear();
        head = move.head;
        size = move.size;

        move.head = nullptr;
        move.size = 0;

        return *this;
    }

    bool operator==(const Ring& other) const {
        if (size != other.size) return false;

        auto it1 = begin();
        auto it2 = other.begin();

        for (size_t i = 0; i < size; i++) {
            if (*it1 != *it2) return false;
            ++it1;
            ++it2;
        }
        return true;
    }

    bool empty() const { return size == 0; }
    size_t getSize() const { return size; }

    void swap(Ring& other) noexcept {
        std::swap(head, other.head);
        std::swap(size, other.size);
    }

    Iterator begin() const { return Iterator(head, size); }
    Iterator end() const { return Iterator(nullptr, size); }

    void clear() noexcept {
        while (head != nullptr) {
            Node<T>* temp = head;

            if (size == 1) {
                head = nullptr;
            } else {
                Node<T>* tail = head;
                for (size_t i = 1; i < size; i++) {
                    tail = tail->next;
                }
                head = head->next;
                tail->next = head;

                if (head->next == head) {
                    delete temp;
                    head = nullptr;
                    size = 0;
                    return;
                }
            }

            delete temp;
            size--;
        }
    }

    T& front() {
        if (empty()) throw EmptyRingException();
        return head->data;
    }

    const T& front() const {
        if (empty()) throw EmptyRingException();
        return head->data;
    }

    T& back() {
        if (empty()) throw EmptyRingException();
        return getTail()->data;
    }

    const T& back() const {
        if (empty()) throw EmptyRingException();
        return getTail()->data;
    }

    void pushBack(const T& value) {
        auto* newNode = new Node<T>(value);

        if (empty()) {
            head = newNode;
            head->next = head;
        } else {
            Node<T>* tail = getTail();
            tail->next = newNode;
            newNode->next = head;
        }
        size++;
    }

    void pushFront(const T& value) {
        auto* newNode = new Node<T>(value);

        if (empty()) {
            head = newNode;
            head->next = head;
        } else {
            Node<T>* tail = getTail();
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
        size++;
    }

    void popBack() {
        if (empty()) throw EmptyRingException();

        if (size == 1) {
            popFront();
            return;
        }

        Node<T>* current = head;
        Node<T>* prev = nullptr;

        for (size_t i = 1; i < size; i++) {
            prev = current;
            current = current->next;
        }

        prev->next = head;
        delete current;
        size--;
    }

    void popFront() {
        if (empty()) throw EmptyRingException();

        if (size == 1) {
            delete head;
            head = nullptr;
        } else {
            Node<T>* tail = getTail();
            Node<T>* temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
        }
        size--;
    }

    void print() const {
        if (empty()) {
            std::cout << "Ring is empty" << "\n";
            return;
        }

        Iterator it = begin();
        for (size_t i = 0; i < size; i++) {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << "\n";
    }

    void sort() { bubbleSortOptimized(); }
};