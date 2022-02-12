//
// Created by tntrol on 09.09.2021.
//

#ifndef ENGINE_ENTITY_MANAGER_H
#define ENGINE_ENTITY_MANAGER_H

#include "../support_class/ecs_typedef.h"
#include "../utils/hash_container.h"
#include "../ecs_engine_data/ientity.h"
#include "../container/ipool_object.h"
#include "../container/pool_object.h"
#include "../memory_manager/stack_allocator.h"
#include "component_manager.h"
#include "API.h"

#include <vector>

namespace ECS
{
    class EntityManager
    {
    protected:
        Util::HashContainer<IEntity> m_entity;
        std::vector<IPoolObject<IEntity> *> m_pool;
        std::vector<EntityID> m_destroy_entity;
        ComponentManager *m_component_manager;
        Memory::IAllocator *m_allocator;
        const uint32_t m_count_type;
        const uint32_t m_max_count_entity;
        uint32_t m_count_destroy;
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

        template<class T>
        inline IPoolObject<IEntity> *getContainer()
        {
            if (!m_pool[T::STATIC_TYPE])
            {
                size_t size = ENTITY_SIZE_STACK * sizeof(T);
                void *ptr = m_allocator ? m_allocator->allocate(size) : new char[size];
                m_pool[T::STATIC_TYPE] = new PoolObject<IEntity>(new Memory::StackAllocator(size, ptr), sizeof(T),
                                                                 COUNT_ENTITY_TAG);
            }
            return m_pool[T::STATIC_TYPE];
        }

        template<class T, class... ARGS>
        T *createEntity(ARGS &&... args)
        {
            IEntity *ptr_entity = getContainer<T>()->create();
            T *entity = new(ptr_entity) T(std::forward<ARGS>(args)...);
            entity->m_id = m_entity.add(entity);
            return entity;
        }
    };

}
#endif //ENGINE_ENTITY_MANAGER_H
