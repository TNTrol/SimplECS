//
// Created by tntrol on 09.09.2021.
//

#ifndef ENGINE_ISYSTEM_H
#define ENGINE_ISYSTEM_H

#include "ecs_typedef.h"
#include "../utils/util_counter.h"

namespace ECS
{
    class SystemManager;

    class ISystem
    {
        friend SystemManager;
    private:

        float m_update_interval = 0.0f;
        float m_last_update = 0.0f;
        SystemTypeID m_type;
        Priority m_priority;
        bool m_is_enable;

    public:
        ISystem(SystemTypeID type_id): m_type(type_id){}
        virtual ~ISystem() = 0;

        inline SystemTypeID getType()
        {
            return m_type;
        }

        virtual void preUpdate() = 0;

        virtual void update() = 0;

        virtual void postUpdate() = 0;
    };
}
#endif //ENGINE_ISYSTEM_H
