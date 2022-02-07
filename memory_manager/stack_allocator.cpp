        //
// Created by tntrol on 12.10.2021.
//

#include <stdexcept>
#include "stack_allocator.h"
#define TYPE char

ECS::Memory::StackAllocator::StackAllocator(const size_t size):
            Memory::IAllocator(size, (void*)new char[size]),
            m_curr(0)
{
    if(!m_first)
    {
        throw "Dont allocate memory";
    }
}

ECS::Memory::StackAllocator::~StackAllocator()
{
    delete[] (TYPE *)m_first;
}

void ECS::Memory::StackAllocator::free(void *ptr)
{
    if(!ptr)
    {
        return;
    }
    TYPE* s_ptr = (TYPE*) ptr - sizeof(size_o);
    --m_count_object;
    m_use_size -= (static_cast<size_t>(*s_ptr) + sizeof(size_o));
    m_free_parts.push({static_cast<size_t>(*s_ptr), s_ptr });
}

void *ECS::Memory::StackAllocator::allocate(size_t size)
{
    if ( m_use_size + size + sizeof(size_o) >= m_size)
    {
        throw;// std::invalid_argument("Dont allocate memory\n");
    }
    char *new_obj = NULL;
    if(m_curr + size + sizeof(size_o) < m_size)
    {
        new_obj = (TYPE*)m_first + m_curr;
        m_curr += size + sizeof(size_o);
        m_use_size += size + sizeof(size_o);
    }
    else if(!m_free_parts.empty())
    {
        while (m_free_parts.front().m_size < size)
        {
            m_free_parts.push(m_free_parts.front());
            m_free_parts.pop();
        }
        new_obj = (TYPE*)m_free_parts.front().m_ptr;
        m_use_size += m_free_parts.front().m_size;
        m_free_parts.pop();
    }
    if(new_obj)
    {
        new(new_obj) size_o(size);
        ++m_count_object;
        //m_use_size += size + sizeof(size_o);
        new_obj += sizeof(size_o);
    }
    return new_obj;
}

void ECS::Memory::StackAllocator::clear()
{
    m_free_parts = {};
    m_curr = 0;
    m_use_size = 0;
    m_count_object = 0;
}
