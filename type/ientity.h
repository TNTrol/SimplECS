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
        EntityID m_id; //= Util::get<IEntity>();
        bool m_active = false;
    public:
        //virtual ~IEntity();
        virtual EntityTypeID getType() = 0;

//        virtual void Start() = 0;
//        virtual void Delete() = 0;
        inline EntityID getId()
        {
            return m_id;
        }

        bool isActive()
        {
            return m_active;
        }

        void setActive(bool active)
        {
            m_active = active;
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
