//
// Created by tntrol on 23.10.2021.
//

#include "linear_allocator.h"
#define TYPE char

ECS::Memory::LinearAllocator::LinearAllocator(size_t size) : IAllocator(size, new TYPE [size]), m_curr(0)
{
    if(!m_first)
    {
        throw ;
    }
}

ECS::Memory::LinearAllocator::~LinearAllocator()
{
    delete[] (TYPE*)m_first;
}

void ECS::Memory::LinearAllocator::free(void *ptr)
{

}

void *ECS::Memory::LinearAllocator::allocate(size_t size)
{
    if(m_curr + size > m_size)
    {
        return nullptr;
    }
    void* ptr = ((TYPE*)m_first) + m_curr;
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
