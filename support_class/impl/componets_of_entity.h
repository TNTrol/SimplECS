//
// Created by tntrol on 12.09.2021.
//

#ifndef ENGINE_COMPONETS_OF_ENTITY_H
#define ENGINE_COMPONETS_OF_ENTITY_H
#include "../../ecs_engine_data/icomponent.h"
#include "../icomponent_of_entity.h"

namespace ECS
{
    class ComponentsOfEntity: public IComponentOfEntity
    {
    private:
        int m_count;
        IComponent **components;
    public:
        ComponentsOfEntity(int count)
        {
            m_count = count;
            components = new IComponent*[count];
            for(int i = 0; i < m_count; ++i)
            {
                components[i] = nullptr;
            }
        }
        ~ComponentsOfEntity()
        {
            clear();
        }

        inline IComponent* getComponent(ComponentID type_id) override
        {
            return components[type_id];
        }

        inline void addComponent(IComponent *component) override
        {
            components[component->getType()] = component;
        }

        inline void removeComponent(ComponentTypeID type_id) override
        {
            delete components[type_id];
            components[type_id] = nullptr;
        }

        void clear() override
        {
            for (int i = 0; i < m_count; ++i)
            {
                delete components[i];
                components[i] = nullptr;
            }
        }

        inline int size() override
        {
            return m_count;
        }
    };
}

#endif //ENGINE_COMPONETS_OF_ENTITY_H
