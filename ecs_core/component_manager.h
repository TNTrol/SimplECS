//
// Created by tntrol on 12.09.2021.
//

#ifndef ENGINE_COMPONENT_MANAGER_H
#define ENGINE_COMPONENT_MANAGER_H

#include "../support_class/ecs_typedef.h"
#include "../ecs_engine_data/icomponent.h"
#include "../container/ipool_object.h"
#include "../utils/hash_container.h"
#include "../container/pool_object.h"
#include "../memory_manager/stack_allocator.h"
#include "API.h"

#include "vector"

namespace ECS
{
    class ComponentManager
    {
    protected:
        std::vector<IPoolObject<IComponent> *> m_pool;
        std::vector<std::vector<ComponentID>> m_components;
        //Util::HashContainer<IComponent> m_comp; //todo
        Memory::IAllocator *m_allocator;
        const uint32_t m_count_type;
        const uint32_t m_max_entity;
        const uint32_t m_grow;
    private:
        void addComponent(EntityID entityId, IComponent *component);

        template<class T>
        IPoolObject<IComponent> *getContainer()
        {
            if (!m_pool[T::STATIC_TYPE])
            {
                size_t size = ENTITY_SIZE_STACK * sizeof(T);
                Memory::IAllocator *allocator = m_allocator ?
                                                m_allocator :
                                                new Memory::StackAllocator(ENTITY_SIZE_STACK * sizeof(T),
                                                                           new char[size]);
                m_pool[T::STATIC_TYPE] = new PoolObject<IComponent>(allocator, sizeof(T), COUNT_ENTITY_TAG);
            }
            return m_pool[T::STATIC_TYPE];
        }

    public:
        ComponentManager(uint32_t max_entity = ENTITY_SIZE_STACK, uint32_t grow = ENTITY_GROW_STACK,
                         Memory::IAllocator *allocator = nullptr);

        ~ComponentManager();

        void removeAllComponents(EntityID entity_id);

        template<class T>
        T *getComponentOfEntity(const EntityID entity_id)
        {
            return m_components[entity_id][T::STATIC_TYPE];
        }

        template<class T, class... ARGS>
        T *createComponent(const EntityID entity_id, ARGS &&... args)
        {
            IComponent *component_ptr = getContainer(T::STATIC_TYPE)->create();
            if (!component_ptr)
            {
                return nullptr;
            }
            IComponent *component = new(component_ptr) T(std::forward<ARGS>(args)...);
            component->m_owner = entity_id;
            addComponent(entity_id, component);
            return component;
        }

        template<class T>
        void destroyComponent(const EntityID entityId)
        {
            ComponentTypeID type_id = T::STATIC_TYPE;
            // m_pool[type_id]->remove(m_components[entityId]->removeComponent(type_id)); todo
        }
    };

}
#endif //ENGINE_COMPONENT_MANAGER_H
