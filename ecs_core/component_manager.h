//
// Created by tntrol on 12.09.2021.
//

#ifndef ENGINE_COMPONENT_MANAGER_H
#define ENGINE_COMPONENT_MANAGER_H
#include "../support_class/helper_typedef.h"
#include "../ecs_engine_data/icomponent.h"
#include "../container/icontainer.h"
#include "../support_class/container_object.h"
#include "../container/chunk_container.h"
#include "../memory_manager/stack_allocator.h"
#include "API.h"

#include "vector"

namespace ECS
{
    class ComponentManager
    {
    protected:
        std::vector<IContainer<IComponent>*> m_pool;
        std::vector<std::vector<ComponentID>> m_components;
        const unsigned int m_count_type;
        const unsigned int m_max_entity;
        const unsigned int m_grow;
    private:
        void addComponent(EntityID entityId,IComponent *component);
        template<class T>
        IContainer<IComponent>* getContainer()
        {
            if(!m_pool[T::STATIC_TYPE])
            {
                m_pool[T::STATIC_TYPE] = new ChunkContainer<IComponent>(new ECS::Memory::StackAllocator(ENTITY_SIZE_STACK * sizeof(T)), sizeof(T));
            }
            return m_pool[T::STATIC_TYPE];
        }
    public:
        ComponentManager(unsigned int max_entity = ENTITY_SIZE_STACK, unsigned int grow = ENTITY_GROW_STACK);
        ~ComponentManager();
        void removeAllComponents(EntityID entity_id);

        template<class T>
        T* getComponentOfEntity(const EntityID entity_id)
        {
            return m_components[entity_id][T::STATIC_TYPE];
        }

        template<class T, class... ARGS>
        T* createComponent(const EntityID entity_id, ARGS&&... args)
        {
            IComponent *component_ptr = getContainer(T::STATIC_TYPE)->create();
            if(!component_ptr)
            {
                return nullptr;
            }
            IComponent* component = new(component_ptr) T(std::forward<ARGS>(args)...);
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
