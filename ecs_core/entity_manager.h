//
// Created by tntrol on 09.09.2021.
//

#ifndef ENGINE_ENTITY_MANAGER_H
#define ENGINE_ENTITY_MANAGER_H
#include "../support_class/helper_typedef.h"
#include "../support_class/container_object.h"
#include "../ecs_engine_data/ientity.h"
#include "../container/icontainer.h"
#include "../container/chunk_container.h"
#include "../memory_manager/stack_allocator.h"
#include "component_manager.h"
#include "API.h"

#include <vector>

namespace ECS
{
    class EntityManager
    {
    protected:
        ECS::ContainerObject<IEntity> m_entity;
        std::vector<IContainer<IEntity>*> m_pool;
        std::vector<EntityID> m_destroy_entity;
        ComponentManager *m_component_manager;
        const unsigned int m_count_type;
        const unsigned int m_max_count_entity;
        unsigned int m_count_destroy;
    public:
        EntityManager(ComponentManager*component_manager, unsigned int max_count_entity = ENTITY_SIZE_STACK, unsigned int grow = ENTITY_GROW_STACK);
        ~EntityManager();
        void destroyEntity(EntityID entityId);
        void removeDestroyedEntity();

        inline IEntity* getEntity(EntityID entityId)
        {
            return m_entity.get(entityId);
        }

        template<class T>
        inline IContainer<IEntity>* getContainer()
        {
            if(!m_pool[T::STATIC_TYPE])
            {
                m_pool[T::STATIC_TYPE] = new ChunkContainer<IEntity>(new Memory::StackAllocator(ENTITY_SIZE_STACK * sizeof(T)), sizeof(T)); //todo
            }
            return m_pool[T::STATIC_TYPE];
        }

        template<class T, class... ARGS>
        T* createEntity(ARGS&&... args)
        {
            IEntity* ptr_entity = getContainer<T>()->create();
            T* entity = new (ptr_entity) T(std::forward<ARGS>(args)...);
            entity->m_id = m_entity.add(entity);
            return entity;
        }
    };

}
#endif //ENGINE_ENTITY_MANAGER_H
