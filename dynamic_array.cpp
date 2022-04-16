#include "dynamic_array.h"

#include <iostream>


Dynamic_array::Dynamic_array()
{
    m_data = new int[m_capacity];
}

void Dynamic_array::print_all() const
{
    std::cout << "\nSize: " << m_size << ", capacity: " << m_capacity << "\n";
    for (size_t i = 0; i < m_size; i++)
    {
        std::cout << m_data[i] << " ";
    }
    std::cout << "\n";
}

// Time Complexity: 
//  Best Case: O(1), Worst Case: O(n)
// Space Complexity
//  Best Case: O(1), Worst Case: O(2n)
// n = m_capacity
void Dynamic_array::push_back(int value)
{
    if (m_size >= m_capacity)
    {
        // reallocate and move memory
        reallocate_();
    }
    m_data[m_size++] = value;
}

// Time Complexity: O(n)
// Space Complexity: O(2n)
// n = m_capacity
void Dynamic_array::reallocate_()
{
    int* temp = new int[m_capacity * 2];

    for (size_t i = 0; i < m_capacity; ++i)
    {
        temp[i] = m_data[i];
    }

    delete m_data;
    m_data = temp;
    m_capacity *= 2;
}


void Dynamic_array::pop_back()
{
    if (!m_size)
    {
        return;
    }

    m_size--;
}

size_t Dynamic_array::size() const
{
    return m_size;
}

// Time: O(1)
// Space: O(1)
int Dynamic_array::at(size_t index) const
{
    if (index > m_size)
    {
        throw std::out_of_range("Out of bounds access on Dynamic_array::at()");
    }

    return m_data[index];
}

// Time: O(1)
int Dynamic_array::back() const
{
    if (!m_size)
    {
        throw std::out_of_range("Dynamic_array::back() called on empty array");
    }
    return m_data[m_size - 1];
}

int Dynamic_array::front() const
{
    if (!m_size)
    {
        throw std::out_of_range("Dynamic_array::front() called on empty array");
    }
    return m_data[0];
}


// Time: O(1)
// Space: O(1)
void Dynamic_array::erase()
{
    m_size = 0;
}

void Dynamic_array::reserve(size_t capacity)
{
    if (capacity > m_capacity)
    {
        m_capacity = capacity;
    }
}



