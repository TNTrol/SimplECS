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
        Priority m_priority = 0;
        float m_update_interval = 0.0f;
        float m_last_update = 0.0f;
        bool m_enable = true;
    public:

        virtual SystemTypeID getType() = 0;

        virtual void preUpdate() = 0;

        virtual void update() = 0;

        virtual void postUpdate() = 0;
    };
}
#endif //ENGINE_ISYSTEM_H
