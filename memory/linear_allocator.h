//
// Created by tntrol on 23.10.2021.
//

#ifndef ENGINE_LINEAR_ALLOCATOR_H
#define ENGINE_LINEAR_ALLOCATOR_H

#include "iallocator.h"

namespace ECS
{
    namespace Memory
    {
        class LinearAllocator : public IAllocator
        {
        private:
            size_t m_curr;
        public:
            LinearAllocator(const size_t size, void *ptr);

            ~LinearAllocator();

            void free(const void *ptr) override;

            void *allocate(size_t size) override;

            void clear() override;
        };
    }
}


#endif //ENGINE_LINEAR_ALLOCATOR_H
