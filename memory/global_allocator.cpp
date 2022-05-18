//
// Created by tntrol on 15.05.2022.
//

#include "global_allocator.h"

ECS::Memory::GlobalAllocator::GlobalAllocator(size_t size, size_t grow) :
        IAllocator(size, new uint8_t[size]),
        m_grow(grow),
        m_size(size)
{
    m_parts.push_back({.m_size= size, .m_use = 0, .m_ptr = (uint8_t*)m_first});
}

ECS::Memory::GlobalAllocator::~GlobalAllocator()
{
    for (auto part: m_parts)
    {
        delete[] part.m_ptr;
    }
}

void *ECS::Memory::GlobalAllocator::allocate(size_t size)
{
    uint8_t *ptr;
    for (auto &part: m_parts)
    {
        if (part.m_use + size <= part.m_size)
        {
            ptr = part.m_ptr + part.m_use;
            part.m_use += size;
            return ptr;
        }
    }
    m_parts.push_back({.m_size= size, .m_use = size, .m_ptr = new uint8_t[size]});
    return m_parts.back().m_ptr;
}

void ECS::Memory::GlobalAllocator::free(const void *ptr)
{

}

void ECS::Memory::GlobalAllocator::clear()
{

}
