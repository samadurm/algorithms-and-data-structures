#pragma once

#include <cstdlib>
#include <memory>

struct Node
{
    Node(int value);
    ~Node();
    std::shared_ptr<Node> next;
    int data{-1};
};

class Linked_list
{
public:
    Linked_list();
    void print_all() const;

    void push_back(int value);
    void pop_back();

    size_t size() const;
    int at(size_t index) const;
    int back() const;
    int front() const;

    void erase();

private:
    std::shared_ptr<Node> m_head;
    std::shared_ptr<Node> m_tail;

    size_t m_size{0};
};