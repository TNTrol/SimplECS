//
// Created by tntrol on 15.05.2022.
//

#ifndef ENGINE_GLOBAL_ALLOCATOR_H
#define ENGINE_GLOBAL_ALLOCATOR_H

#include <cstddef>
#include <stdint.h>
#include "list"

#include "iallocator.h"

namespace ECS
{
    namespace Memory
    {
        class GlobalAllocator: public IAllocator
        {
        private:
            struct memory_block
            {
                const size_t m_size;
                size_t m_use;
                size_t m_free;
                uint8_t * const m_ptr;
            };
        private:
            std::list<memory_block> m_parts;
            const size_t m_size;
            const size_t m_grow;
        public:
            GlobalAllocator(size_t size, size_t grow);
            ~GlobalAllocator();
            void *allocate(size_t size) override;
            void free(const void *ptr) override;
            void clear() override;
        };

    }
}
#endif //ENGINE_GLOBAL_ALLOCATOR_H
