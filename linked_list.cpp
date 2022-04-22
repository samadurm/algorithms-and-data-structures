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

    std::weak_ptr<Node> weak_cur = m_head;
    while (const auto cur = weak_cur.lock())
    {
        std::cout << cur->data << " ";
        weak_cur = cur->next;
    }
    std::cout << "\n";
}

// Time: O(1)
// Space: O(1)
void Linked_list::push_back(int value)
{
    if (!m_size)
    {   // first insert
        m_head = std::make_shared<Node>(value);
        m_tail = m_head;
    }
    else 
    {   // regular insert
        m_tail->next = std::make_shared<Node>(value);
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
        m_head = nullptr;
        m_size--;
        return;
    }

    // find the new tail, 1 node before previous tail
    std::weak_ptr<Node> weak_cur = m_head;
    while (const auto strong_cur = weak_cur.lock())
    {
        if (!strong_cur->next)
        {
            m_tail = strong_cur;
            break;
        }
        weak_cur = strong_cur->next;
    }
    m_size--;
}