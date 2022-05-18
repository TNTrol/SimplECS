//
// Created by tntrol on 09.09.2021.
//

#ifndef ENGINE_ENTITY_MANAGER_H
#define ENGINE_ENTITY_MANAGER_H

#include "simple_ecs.h"
#include "API.h"
#include <vector>

namespace ECS
{
    class EntityManager
    {
    public:
        template<class T>
        using EntityIterator = Container::PoolContainer<T>;
    protected:
        Util::HashContainer<IEntity> m_entity;
        std::vector<Container::ExtendPool<IEntity> *> m_pool;
        std::vector<EntityID> m_destroy_entity;
        ComponentManager *m_component_manager;
        Memory::IAllocator *m_allocator;
        const uint32_t m_max_count_entity;
        uint32_t m_count_destroy;
    private:
        template<class T>
        inline Container::ExtendPool<IEntity> *getContainer()
        {
            if (T::STATIC_TYPE >= m_pool.size())
            {
                m_pool.resize(m_pool.size() + (T::STATIC_TYPE + 1 - m_pool.size()) * 2);
            }
            if (!m_pool[T::STATIC_TYPE])
            {
                m_pool[T::STATIC_TYPE] = new Container::ExtendPool<IEntity>(m_allocator, sizeof(T), COUNT_ENTITY_TAG);
            }
            return m_pool[T::STATIC_TYPE];
        }

    public:
        EntityManager(ComponentManager *component_manager,
                      uint32_t max_count_entity = ENTITY_SIZE_STACK,
                      uint32_t grow = ENTITY_GROW_STACK,
                      Memory::IAllocator *allocator = nullptr);

        ~EntityManager();

        void destroyEntity(EntityID entityId);

        void removeDestroyedEntity();

        inline IEntity *getEntity(EntityID entityId)
        {
            return m_entity.get(entityId);
        }

        template<class T, class... ARGS>
        T *createEntity(ARGS &&... args)
        {
            IEntity *ptr_entity = getContainer<T>()->create();
            T *entity = new(ptr_entity) T(std::forward<ARGS>(args)...);
            entity->m_id = m_entity.add(entity);
            return entity;
        }

        template<class T>
        EntityIterator<T> getAllOfType()
        {
            return getContainer<T>()->template iterable<T>();
        }
    };
}
#endif //ENGINE_ENTITY_MANAGER_H
