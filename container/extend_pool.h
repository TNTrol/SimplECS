//
// Created by tntrol on 17.05.2022.
//

#ifndef ENGINE_EXTEND_POOL_H
#define ENGINE_EXTEND_POOL_H

#include "vector"

#include "../memory/pool_allocator.h"

namespace ECS
{
    namespace Container
    {
        template<class E>
        class Iterator
        {
        private:
            Memory::PoolAllocator::Iterator m_poolIterator;
            std::vector<Memory::PoolAllocator *> *m_pools;
            uint32_t m_index;
        public:
            Iterator(std::vector<Memory::PoolAllocator *> *pools, bool end = false) :
                    m_pools(pools),
                    m_poolIterator(nullptr, nullptr, 0, 0, 0, 0)
            {
                if (end)
                {
                    for (m_index = m_pools->size() - 1; m_index >= 0; --m_index)
                    {
                        if ((*pools)[m_index]->get_count() > 0)
                        {
                            m_poolIterator = (*pools)[m_index]->end();
                            m_index = m_pools->size();
                            break;
                        }
                    }
                }
                else
                {
                    for (m_index = 0; m_index < pools->size(); ++m_index)
                    {
                        if ((*pools)[m_index]->get_count() > 0)
                        {
                            m_poolIterator = (*pools)[m_index]->begin();
                            break;
                        }
                    }
                }
            }

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
                if (m_index >= m_pools->size())
                {
                    return *this;
                }
                ++m_poolIterator;
                bool check = false;
                if (m_poolIterator == (*m_pools)[m_index]->end())
                {
                    check = true;
                    for (++m_index; m_index < m_pools->size(); ++m_index)
                    {
                        if ((*m_pools)[m_index]->get_count() > 0)
                        {
                            m_poolIterator = (*m_pools)[m_index]->begin();
                            check = false;
                            break;
                        }
                    }
                }
                if (check)
                {
                    m_index = m_pools->size();
                }
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

        template<class E>
        class PoolContainer
        {
        private:
            std::vector<Memory::PoolAllocator *> *m_pools;
        public:
            PoolContainer(std::vector<Memory::PoolAllocator *> *pools) :
                    m_pools(pools)
            {}

            Iterator<E> begin()
            {
                return Iterator<E>(m_pools);
            }

            Iterator<E> end()
            {
                return Iterator<E>(m_pools, true);
            }
        };

        template<class T>
        class ExtendPool
        {
        private:
            std::vector<Memory::PoolAllocator *> m_pools;
            Memory::IAllocator *m_allocator;
            size_t m_size_object;
            size_t m_count_object;
        public:
            ExtendPool(Memory::IAllocator *allocator, size_t size_object, size_t count_object) :
                    m_allocator(allocator),
                    m_size_object(size_object),
                    m_count_object(count_object)
            {
                m_pools.push_back(new Memory::PoolAllocator(m_allocator, size_object, count_object));
            }

            ~ExtendPool()
            {
                for (auto pool: m_pools)
                {
                    m_allocator->free(pool->get_source_ptr());
                }
            }

            inline T *create()
            {
                T *ptr = nullptr;
                for (auto pool: m_pools)
                {
                    ptr = (T *) pool->allocate(0);
                    if (ptr)
                    {
                        return ptr;
                    }
                }
                auto pool = new Memory::PoolAllocator(m_allocator, m_size_object, m_count_object);
                if (pool)
                {
                    m_pools.push_back(pool);
                    ptr = (T *) pool->allocate(0);
                }
                return ptr;
            }

            inline void remove(T *ptr)
            {
                for (auto pool: m_pools)
                {
                    pool->free(ptr);
                }
            }

            template<class D>
            inline PoolContainer<D> iterable()
            {
                return PoolContainer<D>(&m_pools);
            }
        };
    }
}

#endif //ENGINE_POOL_MODERN_H
