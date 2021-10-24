//
// Created by tntrol on 09.09.2021.
//

#ifndef ENGINE_ICOMPONENT_H
#define ENGINE_ICOMPONENT_H

#include "../support_class/helper_typedef.h"
#include "../utils/util_counter.h"

//#include "../ecs_core/component_manager.h"
namespace ECS
{
    class IComponent
    {
        friend class ComponentManager;
    protected:
        ComponentID m_id = util::get<IComponent>();
        EntityID m_owner;
    public:
        inline ComponentID getId() const
        {
            return m_id;
        }
        virtual ComponentTypeID getType()=0;
        inline EntityID getOwner()
        {
            return m_owner;
        }
    };
}
#endif //ENGINE_ICOMPONENT_H
