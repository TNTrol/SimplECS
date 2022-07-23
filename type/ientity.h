//
// Created by tntrol on 08.09.2021.
//
//#include "../ecs/entity_manager.h"
#ifndef ENGINE_IENTITY_H
#define ENGINE_IENTITY_H

#include "ecs_typedef.h"
#include "../utils/util_counter.h"

class EntityManager;

namespace ECS
{
    class IEntity
    {
        friend class EntityManager;

    private:
        EntityID m_id;
        const EntityTypeID m_type_id;
        bool m_is_enable;

    public:
        IEntity(EntityTypeID type_id) : m_type_id(type_id)
        {}

        EntityTypeID getType()
        {
            return m_type_id;
        }

        inline EntityID getId()
        {
            return m_id;
        }

        bool isActive()
        {
            return m_is_enable;
        }

        void setActive(bool active)
        {
            m_is_enable = active;
        }

        inline bool operator==(const IEntity &rhs) const
        { return this->m_id == rhs.m_id; }

        inline bool operator!=(const IEntity &rhs) const
        { return this->m_id != rhs.m_id; }

        inline bool operator==(const IEntity *rhs) const
        { return this->m_id == rhs->m_id; }

        inline bool operator!=(const IEntity *rhs) const
        { return this->m_id != rhs->m_id; }
    };
}
#endif //ENGINE_IENTITY_H
