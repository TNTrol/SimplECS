//
// Created by tntrol on 16.02.2022.
//

#ifndef ENGINE_POOL_H
#define ENGINE_POOL_H

#include "../memory_manager/pool_allocator.h"

namespace ECS
{
    template<class T>
    class Pool
    {
    public:
        template<class E>
        class Iterator
        {
        private:
            Memory::PoolAllocator::Iterator m_poolIterator;
        public:
            Iterator(Memory::PoolAllocator::Iterator poolIterator) :
                    m_poolIterator(poolIterator)
            {}

            E *operator*() const
            {
                return (E *) m_poolIterator.operator*();
            }

            E *operator->()
            {
                return (E *) m_poolIterator.operator->();
            }

            Iterator<E> &operator++()
            {
                m_poolIterator++;
                return *this;
            }

            Iterator<E> operator++(int)
            {
                Iterator<E> tmp = *this;
                ++(*this);
                return tmp;
            }

            friend bool operator==(const Iterator<E> &a, const Iterator<E> &b)
            {
                return a.m_poolIterator == b.m_poolIterator;
            };

            friend bool operator!=(const Iterator<E> &a, const Iterator<E> &b)
            {
                return a.m_poolIterator != b.m_poolIterator;
            };

        };

    private:
        Memory::PoolAllocator *m_pool;
        Memory::IAllocator *m_allocator;
    public:
        Pool(Memory::IAllocator *allocator, size_t size_object, size_t count_object)
        {
            m_pool = new Memory::PoolAllocator(allocator, size_object, count_object);
            m_allocator = allocator;
        }

        ~Pool()
        {
            m_allocator->free(m_pool->get_source_ptr());
        }

        inline T *create()
        {
            return (T *) m_pool->allocate(0);
        }

        inline void remove(T *ptr)
        {
            m_pool->free(ptr);
        }

        inline size_t size()
        {
            return m_pool->get_count();
        }

        template<class D>
        inline Iterator<D> begin()
        {
            return Iterator<D>(m_pool->begin());
        }

        template<class D>
        inline Iterator<D> end()
        {
            return Iterator<D>(m_pool->end());
        }
    };
}
#endif //ENGINE_POOL_H
