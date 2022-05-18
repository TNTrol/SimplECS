//
// Created by tntrol on 12.10.2021.
//

#include "stack_allocator.h"

#define TYPE char

ECS::Memory::StackAllocator::StackAllocator(const size_t size, void *ptr) :
        Memory::IAllocator(size, ptr),
        m_curr(0)
{
    if (!m_first)
    {
        throw "Dont allocate memory";
    }
}

ECS::Memory::StackAllocator::~StackAllocator()
{
}

void ECS::Memory::StackAllocator::free(const void *ptr)
{
    if (!ptr)
    {
        return;
    }
    TYPE *s_ptr = (TYPE *) ptr - sizeof(uint32_t);
    --m_count_object;
    m_use_size -= (static_cast<size_t>(*s_ptr) + sizeof(uint32_t));
    m_free_parts.push({static_cast<size_t>(*s_ptr), s_ptr});
}

void *ECS::Memory::StackAllocator::allocate(size_t size)
{
    if (m_use_size + size + sizeof(uint32_t) >= m_max_size)
    {
        throw;// std::invalid_argument("Dont allocate memory\n");
    }
    char *new_obj = NULL;
    if (m_curr + size + sizeof(uint32_t) < m_max_size)
    {
        new_obj = (TYPE *) m_first + m_curr;
        m_curr += size + sizeof(uint32_t);
        m_use_size += size + sizeof(uint32_t);
    }
    else if (!m_free_parts.empty())
    {
        while (m_free_parts.front().m_size < size)
        {
            m_free_parts.push(m_free_parts.front());
            m_free_parts.pop();
        }
        new_obj = (TYPE *) m_free_parts.front().m_ptr;
        m_use_size += m_free_parts.front().m_size;
        m_free_parts.pop();
    }
    if (new_obj)
    {
        new(new_obj) uint32_t (size);
        ++m_count_object;
        //m_use_size += size + sizeof(size_o);
        new_obj += sizeof(uint32_t);
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
