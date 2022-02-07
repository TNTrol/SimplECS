//
// Created by tntrol on 04.11.2021.
//

#ifndef ENGINE_CHUNK_CONTAINER_H
#define ENGINE_CHUNK_CONTAINER_H

#include "icontainer.h"
#include "../memory_manager/iallocator.h"
namespace ECS
{

    template<class T>
    class ChunkContainer: public IContainer<T>
    {
    private:
        ECS::Memory::IAllocator *m_allocator;
        const size_t m_size;
    protected:
        void* create_obj() override;
        void destruct(void *ptr) override;
    public:
        ChunkContainer(ECS::Memory::IAllocator *allocator, size_t size);
        ~ChunkContainer();
    };

    template<class T>
    void *ChunkContainer<T>::create_obj()
    {
        if(m_allocator->get_use_size() + m_size > m_allocator->get_size())
        {
            return nullptr;
        }
        return m_allocator->allocate(m_size);
    }

    template<class T>
    void ChunkContainer<T>::destruct(void *ptr)
    {
        m_allocator->free(ptr);
    }

    template<class T>
    ChunkContainer<T>::ChunkContainer(ECS::Memory::IAllocator *allocator, size_t size):
            m_allocator(allocator),
            m_size(size)
    {}

    template<class T>
    ChunkContainer<T>::~ChunkContainer()
    {
        delete m_allocator;
    }

}
#endif //ENGINE_CHUNK_CONTAINER_H
