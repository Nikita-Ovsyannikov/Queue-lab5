#pragma once
#include <iostream>
#include <stdexcept>
#include <deque>

template <typename T>
class Queue 
{
    std::deque<T> data;
    size_t capacity;
    size_t sz = 0;
public:
    Queue(size_t capacity = 0) : capacity(capacity) {}

    void push(const T& val) {
        if (sz == capacity) {
            throw "Queue is full";
        }
        data.push_back(val);
        sz++;
    }

    void pop() {
        if (empty()) {
            throw "Queue is empty";
        }
        data.pop_front();
        sz--;
    }

    const T& front() const {
        if (empty()) {
            throw "Queue is empty";
        }
        return data.front();
    }

    bool empty() const {
        return sz == 0;
    }

    bool full() const {
        return sz == capacity;
    }

    size_t size() const {
        return sz;
    }

    size_t get_capacity() const {
        return capacity;
    }

    void clear() {
        data.clear();
        sz = 0;
    }
};