//
// Created by tntrol on 04.11.2021.
//

#ifndef ENGINE_POOL_ALLOCATOR_H
#define ENGINE_POOL_ALLOCATOR_H

#include <iostream>
#include "iallocator.h"

namespace ECS
{
    namespace Memory
    {
        struct node_chunk
        {
            uint32_t prev = 0xFFFFFFFF;
            uint32_t next = 0;
        };

        class PoolAllocator : public Memory::IAllocator
        {
        public:
            class Iterator
            {
            private:
                const void *m_objects;
                node_chunk *m_offsets;
                uint32_t m_size;
                uint32_t m_current;
                uint32_t m_size_obj;
                uint32_t m_end;
            public:
                Iterator(node_chunk *offsets, const void *objs, uint32_t size, uint32_t start, uint32_t size_obj,
                         uint32_t stack);

                ~Iterator();

                void *operator*() const;

                void *operator->();

                Iterator &operator++();

                Iterator operator++(int);

                friend bool operator==(const Iterator &a, const Iterator &b)
                {
                    return a.m_current == b.m_current;
                }

                friend bool operator!=(const Iterator &a, const Iterator &b)
                {
                    return a.m_current != b.m_current;
                }
            };

        private:
            node_chunk *m_offsets;
            const size_t m_size_object;
            const uint32_t m_max_count;
            uint32_t m_head;
            uint32_t m_tail;
            uint32_t m_stack;
            uint32_t m_curr;
        private:
            void setup();

        public:
            PoolAllocator(Memory::IAllocator *allocator, size_t size_object, size_t count_object);

            ~PoolAllocator();

            void *allocate(size_t size) override;

            void free(const void *ptr) override;

            void clear() override;

            Iterator begin();

            Iterator end();
        };
    }
}
#endif //ENGINE_POOL_ALLOCATOR_H
