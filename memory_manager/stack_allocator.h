//
// Created by tntrol on 12.10.2021.
//

#ifndef ENGINE_STACK_ALLOCATOR_H
#define ENGINE_STACK_ALLOCATOR_H

#include <cstddef>
#include "iallocator.h"

#include <queue>

namespace ECS
{
    namespace Memory
    {
        struct Block
        {
            size_t m_size;
            void *m_ptr;
        };

        class StackAllocator : public Memory::IAllocator
        {
        private:
            std::queue<Block> m_free_parts;
            size_t m_curr;
        public:
            StackAllocator(const size_t, void *ptr);

            ~StackAllocator();

            void free(const void *ptr) override;

            void *allocate(size_t size) override;

            void clear() override;
        };
    }
}
#endif //ENGINE_STACK_ALLOCATOR_H
