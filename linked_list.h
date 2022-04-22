#pragma once

#include <cstdlib>
#include <memory>

struct Node
{
    Node(int value);
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

private:
    std::shared_ptr<Node> m_head;
    std::shared_ptr<Node> m_tail;

    size_t m_size{0};
};