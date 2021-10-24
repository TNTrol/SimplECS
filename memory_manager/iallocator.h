//
// Created by tntrol on 08.10.2021.
//

#ifndef ENGINE_IALLOCATOR_H
#define ENGINE_IALLOCATOR_H
#include <cstddef>

namespace ECS
{
    namespace Memory
    {
        typedef unsigned int size_o;

        class IAllocator
        {
        protected:
            const void* m_first;
            const size_t m_size;
            size_t m_use_size;
            size_t m_count_object;
        public:
            IAllocator(const size_t size, void* mem):
                m_size(size),
                m_first(mem),
                m_use_size(0),
                m_count_object(0)
            {}
            virtual ~IAllocator()
            {}
            virtual void* allocate(size_t size) = 0;
            virtual void free(void* ptr) = 0;
            virtual void clear() = 0;
            inline size_t get_size()
            {
                return m_size;
            }
            inline size_t get_use_size()
            {
                return m_use_size;
            }
            inline size_t get_count()
            {
                return m_count_object;
            }
            inline const void* get_source_ptr()
            {
                return m_first;
            }
        };
    }
}
#endif //ENGINE_IALLOCATOR_H
