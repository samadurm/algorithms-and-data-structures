#include "linked_list.h"
#include <iostream>

Node::Node(int value)
    : data(value)
{
}


Linked_list::Linked_list() = default;

void Linked_list::print_all() const
{
    std::cout << "\nSize: " << m_size << "\n";

    Node* current = m_head;
    while (current)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";
}

// Time: O(1)
// Space: O(1)
void Linked_list::push_back(int value)
{
    if (!m_size)
    {   // first insert
        m_head = new Node(value);
        m_tail = m_head;
    }
    else 
    {   // regular insert
        m_tail->next = new Node(value);
        m_tail = m_tail->next;
    }
    m_size++;
}