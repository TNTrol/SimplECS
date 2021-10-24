//
// Created by tntrol on 12.09.2021.
//

#ifndef ENGINE_COMPONENT_MANAGER_H
#define ENGINE_COMPONENT_MANAGER_H
#include "../support_class/helper_typedef.h"
#include "../ecs_engine_data/icomponent.h"
#include "../support_class/icontainer.h"
#include "../support_class/icomponent_of_entity.h"
#include "API.h"

#include "vector"

namespace ECS
{
    class ComponentManager
    {
    protected:
        std::vector<IContainer*> m_pool;
        std::vector<IComponentOfEntity*> m_components;
        unsigned int m_count_type;
        unsigned int m_max_entity;
        unsigned int m_grow;
    protected:
        void addComponent(EntityID entityId,IComponent *component);
    public:
        ComponentManager(unsigned int max_entity = ENTITY_SIZE_STACK, unsigned int grow = ENTITY_GROW_STACK);
        ~ComponentManager();
        void removeAllComponents(EntityID entity_id);

        template<class T>
        T* getComponentOfEntity(const EntityID entity_id)
        {
            ComponentID id = T::STATIC_TYPE;
            return m_components[entity_id]->getComponent(id);
        }

        template<class T, class... ARGS>
        T* createComponent(const EntityID entity_id, ARGS&&... args)
        {
            IComponent* component = new T(std::forward<ARGS>(args)...);
            ComponentTypeID id_type = T::STATIC_TYPE;
            component->m_owner = entity_id;
            addComponent(entity_id, component);
            m_pool[id_type]->add(entity_id);
            return component;
        }

        template<class T>
        void destroyComponent(const EntityID entityId)
        {
            ComponentTypeID type_id = T::STATIC_TYPE;
            m_pool[type_id]->remove(entityId);
            m_components[entityId]->removeComponent(type_id);
        }
    };

}
#endif //ENGINE_COMPONENT_MANAGER_H
