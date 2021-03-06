//
// Created by tntrol on 23.10.2021.
//

#include "linear_allocator.h"

#define TYPE char

ECS::Memory::LinearAllocator::LinearAllocator(size_t size, void *ptr) : IAllocator(size, ptr), m_curr(0)
{
    if (!m_first)
    {
        throw;
    }
}

ECS::Memory::LinearAllocator::~LinearAllocator()
{}

void ECS::Memory::LinearAllocator::free(const void *ptr)
{

}

void *ECS::Memory::LinearAllocator::allocate(size_t size)
{
    if (m_curr + size > m_max_size)
    {
        return nullptr;
    }
    void *ptr = ((TYPE *) m_first) + m_curr;
    m_curr += size;
    ++m_count_object;
    m_use_size += size;
    return ptr;
}

void ECS::Memory::LinearAllocator::clear()
{
    m_curr = 0;
    m_use_size = 0;
    m_count_object = 0;
}
