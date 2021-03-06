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
    public:
        inline ComponentID getId() const
        {
            return m_id;
        }

        virtual ComponentTypeID getType() = 0;

        inline EntityID getOwner()
        {
            return m_owner;
        }
    };
}
#endif //ENGINE_ICOMPONENT_H
