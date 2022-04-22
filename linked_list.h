#pragma once

#include <cstdlib>

struct Node
{
    Node(int value);
    Node* next{nullptr};
    int data{-1};
};

class Linked_list
{
public:
    Linked_list();
    void print_all() const;

    void push_back(int value);

private:
    Node* m_head;
    Node* m_tail;

    size_t m_size{0};
};