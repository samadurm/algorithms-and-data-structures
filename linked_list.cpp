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

// O(N) time
// O(1) space
void Linked_list::pop_back()
{
    if (!m_size)
    {
        return;
    }
    else if (m_size == 1)
    {
        delete m_head;
        m_head = nullptr;
        m_size--;
        return;
    }

    Node* prev = m_head;
    Node* cur = m_head->next;

    while (cur->next)
    {
        cur = cur->next;
        prev = prev->next;
    }

    delete cur;
    prev->next = nullptr;
    m_size--;
    m_tail = prev;
}