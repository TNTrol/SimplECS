//
// Created by tntrol on 16.02.2022.
//
#include "pool_allocator.h"

ECS::Memory::PoolAllocator::PoolAllocator(ECS::Memory::IAllocator *allocator, size_t size, size_t count_object) :
        Memory::IAllocator(size * count_object + count_object * sizeof(node_chunk),
                           allocator->allocate(size * count_object + (count_object) * sizeof(node_chunk))),
        m_size_object(size),
        m_max_count(count_object)
{
    m_offsets = new((char *) m_first + m_size_object * m_max_count) node_chunk[m_max_count];
    setup();
}

void *ECS::Memory::PoolAllocator::allocate(size_t)
{
    void *t;
    if (m_curr < m_max_count)
    {
        if (m_count_object)
        {
            m_offsets[m_tail].next = m_curr;
        }
        t = (char *) m_first + m_curr * m_size_object;
        m_offsets[m_curr] = {m_tail, m_curr};
        m_tail = m_curr;
        if( m_stack == m_curr && m_offsets[m_stack].next == m_stack)
        {
            m_stack = UINT32_MAX;
        }
        m_curr++;
    }
    else if(m_use_size + m_size_object >= m_max_size)
    {
        return nullptr;
    }
    else
    {
        t = (char *) m_first + m_stack * m_size_object;
        m_offsets[m_stack] = {m_tail, m_stack};
        m_tail = m_stack;
        m_stack = m_offsets[m_stack].next;
    }
    m_count_object++;
    m_use_size += m_size_object;
    return t;
}

void ECS::Memory::PoolAllocator::free(const void *ptr)
{
    if (ptr == nullptr)
    {
        return;
    }
    uint32_t ind = (((char *) ptr) - ((char *) m_first)) / m_size_object;
    if (ptr < m_first || ind >= m_max_count || m_offsets[ind].prev == 0xFFFFFFFF)
    {
        return;
    }
    uint32_t next = m_offsets[ind].next;
    uint32_t prev = m_offsets[ind].prev;
    if (m_count_object == 1)
    {
        setup();
        return;
    }
    if (ind == m_head)
    {
        m_head = next;
        m_offsets[next].prev = next;
    }
    else
    {
        m_offsets[next].prev = prev;
    }
    if (ind == m_tail)
    {
        m_tail = prev;
        m_offsets[prev].next = prev;
    }
    else
    {
        m_offsets[prev].next = next;
    }
    if(m_count_object == m_max_count)
    {
        m_stack = ind;
    }
    m_count_object--;
    m_offsets[ind] = {0xFFFFFFFF, m_stack};
    m_stack = ind;
    m_use_size -= m_size_object;
}

ECS::Memory::PoolAllocator::~PoolAllocator()
{
}

void ECS::Memory::PoolAllocator::setup()
{
    m_stack = m_max_count - 1;
    m_curr = 0;
    m_tail = 0;
    m_head = 0;
    m_count_object = 0;
    m_use_size = m_max_count * sizeof (node_chunk);
    m_offsets[m_stack] = {0xFFFFFFFF, m_stack};
}

void ECS::Memory::PoolAllocator::clear()
{
    setup();
}

ECS::Memory::PoolAllocator::Iterator ECS::Memory::PoolAllocator::begin()
{
    return ECS::Memory::PoolAllocator::Iterator(m_offsets, m_first, (uint32_t) m_count_object, m_head, m_size_object,
                                                m_stack);
}

ECS::Memory::PoolAllocator::Iterator ECS::Memory::PoolAllocator::end()
{
    return ECS::Memory::PoolAllocator::Iterator(m_offsets, m_first, m_count_object, m_stack, m_size_object, m_stack);;
}

ECS::Memory::PoolAllocator::Iterator::Iterator(ECS::Memory::node_chunk *offsets, const void *objs, uint32_t size,
                                               uint32_t start, uint32_t size_obj, uint32_t stack) :
        m_offsets(offsets),
        m_objects(objs),
        m_size(size),
        m_current(start),
        m_size_obj(size_obj),
        m_end(stack)
{}

void *ECS::Memory::PoolAllocator::Iterator::operator*() const
{
    return (char *) m_objects + m_size_obj * m_current;
}

ECS::Memory::PoolAllocator::Iterator::~Iterator()
{

}

void *ECS::Memory::PoolAllocator::Iterator::operator->()
{
    return (char *) m_objects + m_size_obj * m_current;
}

ECS::Memory::PoolAllocator::Iterator &ECS::Memory::PoolAllocator::Iterator::operator++()
{

    {
//        node_chunk n = m_offsets[m_current];
        if(m_current == m_end)
        {
            return *this;
        }
        if (m_offsets[m_current].next == m_current)
        {
            m_current = this->m_end;
        }
        else
        {
            m_current = m_offsets[m_current].next;
            m_size--;
        }
        return *this;
    }
}

ECS::Memory::PoolAllocator::Iterator ECS::Memory::PoolAllocator::Iterator::operator++(int)
{
    Iterator tmp = *this;
    ++(*this);
    return tmp;
}