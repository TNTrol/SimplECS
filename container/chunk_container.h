//
// Created by tntrol on 04.11.2021.
//

#ifndef ENGINE_CHUNK_CONTAINER_H
#define ENGINE_CHUNK_CONTAINER_H

#include "icontainer.h"
#include "../memory_manager/iallocator.h"

namespace ECS
{
    struct node_chunk
    {
        uint32_t prev = 0xFFFFFFFF;
        uint32_t next = 0;
    };

    template<class T>
    class ChunkContainer : public IContainer<T>
    {
    private:
        ECS::Memory::IAllocator *m_allocator;
        T *const m_objects;
        node_chunk *m_offsets;
        const size_t m_size_object;
        const uint32_t m_max_count;
        uint32_t m_head;
        uint32_t m_tail;
        uint32_t m_stack;
        uint32_t m_size;
        uint32_t m_curr;
    protected:
        void *create_obj() override;

        void destruct(void *ptr) override;

    private:
        void setup();

    public:
        ChunkContainer(ECS::Memory::IAllocator *allocator, size_t size_object, size_t count_object = 0);

        ~ChunkContainer();
    };

    template<class T>
    void *ChunkContainer<T>::create_obj()
    {
        void *t;
        if (m_curr < m_max_count)
        {
            t = m_objects + m_curr * m_size_object;
            m_offsets[m_curr] = {m_tail, m_curr};
            m_tail = m_curr;
            m_curr++;
        }
        else
        {
            t = m_objects + m_stack * m_size_object;
            m_offsets[m_stack] = {m_tail, m_stack};
            m_tail = m_stack;
            m_stack = m_offsets[m_stack].next;
        }
        m_size++;
        return t;
    }

    template<class T>
    void ChunkContainer<T>::destruct(void *ptr)
    {
        uint32_t ind = (ptr - m_objects) / m_size_object;
        if (ptr < m_offsets || ind >= m_max_count || m_offsets[ind].prev == 0xFFFFFFFF)
        {
            return;
        }
        uint32_t next = m_offsets[ind].next;
        uint32_t prev = m_offsets[ind].prev;
        if (m_size == 1)
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
        m_size--;
        m_offsets[ind] = {0xFFFFFFFF, m_stack};
        m_stack = ind;
    }

    template<class T>
    ChunkContainer<T>::ChunkContainer(ECS::Memory::IAllocator *allocator, size_t size, size_t count_object):
            m_allocator(allocator),
            m_size_object(size),
            m_max_count(count_object)
    {
        m_objects = allocator->allocate(m_size_object * m_max_count);
        m_offsets = new(allocator->allocate(m_max_count * sizeof(node_chunk))) node_chunk[m_max_count];
        setup();
    }

    template<class T>
    ChunkContainer<T>::~ChunkContainer()
    {
        m_allocator->free(m_objects);
        m_allocator->free(m_offsets);
    }

    template<class T>
    void ChunkContainer<T>::setup()
    {
        m_stack = m_max_count - 1;
        m_curr = 0;
        m_tail = 0;
        m_head = 0;
        m_size = 0;
        m_offsets[m_stack] = {0xFFFFFFFF, m_stack};
    }

}
#endif //ENGINE_CHUNK_CONTAINER_H
