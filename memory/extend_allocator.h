//
// Created by tntrol on 15.05.2022.
//

#ifndef ENGINE_EXTEND_ALLOCATOR_H
#define ENGINE_EXTEND_ALLOCATOR_H

#include "iallocator.h"

#include "vector"

namespace ECS
{
    namespace Memory
    {
        class ExtendMemory : public IAllocator
        {
        public:
            class IFactoryAllocator
            {
            public:
                virtual IAllocator *create() = 0;

                virtual void delete_allocator(IAllocator *) = 0;
            };

        private:
            std::vector<IAllocator *> m_allocators;
            IFactoryAllocator *const m_create;
        public:
            ExtendMemory(IFactoryAllocator *create_allocator) :
                    IAllocator(UINT32_MAX, nullptr),
                    m_create(create_allocator)
            {
                m_allocators.push_back(m_create->create());
            }

            ~ExtendMemory()
            {
                for (IAllocator *allocator: m_allocators)
                {
                    m_create->delete_allocator(allocator);
                }
            }

            void *allocate(size_t size) override
            {
                void *ptr = nullptr;
                for (IAllocator *allocator: m_allocators)
                {
                    ptr = allocator->allocate(size);
                    if (ptr)
                    {
                        break;
                    }
                }
                if (!ptr)
                {
                    m_allocators.push_back(m_create->create());
                    ptr = m_allocators.back()->allocate(size);
                }
                if (ptr)
                {
                    m_use_size += size;
                    m_count_object++;
                }
                return ptr;
            }

            void free(const void *ptr) override
            {
                size_t size;
                for (IAllocator *allocator: m_allocators)
                {
                    size = allocator->get_use_size();
                    allocator->free(ptr);
                    if (size != allocator->get_use_size())
                    {
                        m_count_object--;
                        m_use_size -= size - allocator->get_use_size();
                        break;
                    }
                }
            }

            void clear() override
            {
                for (IAllocator *allocator: m_allocators)
                {
                    allocator->clear();
                }
                m_use_size = 0;
                m_count_object = 0;
            }

            typename std::vector<IAllocator *>::iterator begin()
            {
                return m_allocators.begin();
            }

            typename std::vector<IAllocator *>::iterator end()
            {
                return m_allocators.end();
            }
        };
    }
}

#endif //ENGINE_EXTEND_ALLOCATOR_H
