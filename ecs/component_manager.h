//
// Created by tntrol on 12.09.2021.
//

#ifndef ENGINE_COMPONENT_MANAGER_H
#define ENGINE_COMPONENT_MANAGER_H

#include "../ecs_engine_data/ecs_typedef.h"
#include "../ecs_engine_data/icomponent.h"
#include "../container/pool.h"
#include "../utils/hash_container.h"
#include "../memory/pool_allocator.h"
#include "../memory/stack_allocator.h"
#include "API.h"

#include "vector"

namespace ECS
{
    class ComponentManager
    {
    public:
        template<class T>
        using ComponentIterator = Pool<IComponent>::Iterator<T>;

        class Iterator
        {
        private:
            ComponentManager *manager;
            ComponentTypeID m_current;
            EntityID m_id;
        public:
            Iterator(ComponentManager *componentManager, EntityID id, ComponentTypeID current = 0) :
                    manager(componentManager),
                    m_id(id),
                    m_current(current)
            {}

            IComponent *operator*() const;

            IComponent *operator->();

            Iterator &operator++();

            Iterator operator++(int);

            friend bool operator==(const Iterator &a, const Iterator &b)
            {
                return a.m_current == b.m_current;
            }

            friend bool operator!=(const Iterator &a, const Iterator &b)
            {
                return a.m_current != b.m_current;
            }
        };

    protected:
        Util::HashContainer<IComponent> m_components;
        std::vector<Pool<IComponent> *> m_pool;
        std::vector<std::vector<ComponentID>> m_components_of_entity;
        Memory::IAllocator *m_allocator;
        const uint32_t m_max_entity;
        const uint32_t m_grow;
    private:
        void addComponent(EntityID entityId, IComponent *component);

        template<class T>
        Pool<IComponent> *getContainer()
        {
            if (T::STATIC_TYPE >= m_pool.size())
            {
                m_pool.resize(T::STATIC_TYPE + 1);
            }
            if (!m_pool[T::STATIC_TYPE])
            {
                m_pool[T::STATIC_TYPE] = new Pool<IComponent>(m_allocator, sizeof(T), COUNT_ENTITY_TAG);
            }
            return m_pool[T::STATIC_TYPE];
        }

    public:
        ComponentManager(uint32_t max_entity = ENTITY_SIZE_STACK, uint32_t grow = ENTITY_GROW_STACK,
                         Memory::IAllocator *allocator = nullptr);

        ~ComponentManager();

        void removeAllComponentsOfEntity(EntityID entity_id);

        template<class T>
        T *getComponentOfEntity(const EntityID entity_id)
        {
            if (T::STATIC_TYPE >= m_components_of_entity[entity_id].size() ||
                m_components_of_entity[entity_id][T::STATIC_TYPE] != UINT32_MAX)
            {
                return nullptr;
            }
            return m_components.get(m_components_of_entity[entity_id][T::STATIC_TYPE]);
        }

        template<class T, class... ARGS>
        T *createComponent(const EntityID entity_id, ARGS &&... args)
        {
            IComponent *component_ptr = getContainer<T>()->create();
            if (!component_ptr)
            {
                return nullptr;
            }
            T *component = new(component_ptr) T(std::forward<ARGS>(args)...);
            addComponent(entity_id, component);
            return component;
        }

        template<class T>
        void destroyComponent(const EntityID entityId)
        {
            ComponentTypeID type_id = T::STATIC_TYPE;
            if (m_components_of_entity.size() <= entityId ||
                m_components_of_entity[entityId].size() <= type_id ||
                m_components_of_entity[entityId][type_id] == UINT32_MAX)
            {
                return;
            }
            IComponent *component = m_components.get(m_components_of_entity[entityId][type_id]);
            if (!component)
            {
                return;
            }
            m_pool[entityId]->remove(component);
            m_components.remove(m_components_of_entity[entityId][type_id]);
            m_components_of_entity[entityId][type_id] = 0;
        }

        Iterator beginAllComponentsOfEntity(EntityID entity_id);

        Iterator endAllComponentsOfEntity(EntityID entity_id);

        template<class T>
        ComponentIterator<T> begin()
        {
            return getContainer<T>()->template begin<T>();
        }

        template<class T>
        ComponentIterator<T> end()
        {
            return getContainer<T>()->template end<T>();
        }
    };

}
#endif //ENGINE_COMPONENT_MANAGER_H
