//
// Created by tntrol on 09.09.2021.
//

#ifndef ENGINE_ICOMPONENT_H
#define ENGINE_ICOMPONENT_H

#include "ecs_typedef.h"
#include "../utils/util_counter.h"

namespace ECS
{
    class ComponentManager;

    class IComponent
    {
        friend class ComponentManager;

    private:
        ComponentID m_id;
        EntityID m_owner;
        const ComponentTypeID m_type;
        bool m_is_active;
    public:
        IComponent(ComponentTypeID componentTypeId) : m_type(componentTypeId)
        {}

        inline ComponentID getId() const
        {
            return m_id;
        }

        inline ComponentTypeID getType()
        {
            return m_type;
        }

        inline EntityID getOwner()
        {
            return m_owner;
        }

        inline bool isActive()
        {
            return m_is_active;
        }

        inline void setActive(bool active)
        {
            m_is_active = active;
        }
    };
}
#endif //ENGINE_ICOMPONENT_H
