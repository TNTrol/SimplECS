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
    return nullptr;
}

void ECS::Memory::LinearAllocator::clear()
{

}
