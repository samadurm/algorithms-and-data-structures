#pragma once

#include <memory>
#include <cstdlib>

class Dynamic_array
{
public:
    Dynamic_array();

    void print_all() const;

    void push_back(int value);
    void pop_back();

    size_t size() const;
    int at(size_t index) const;
    int back() const;
    int front() const;

    void erase();
    void reserve(size_t capacity);

    void remove(size_t index);
    void insert(size_t index, int value);

private:
    void reallocate_(size_t capacity);

    int* m_data;
    size_t m_capacity{10}, m_size{0};
};

