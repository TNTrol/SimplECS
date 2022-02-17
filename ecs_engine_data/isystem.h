//
// Created by tntrol on 09.09.2021.
//

#ifndef ENGINE_ISYSTEM_H
#define ENGINE_ISYSTEM_H

#include "ecs_typedef.h"
#include "../utils/util_counter.h"

namespace ECS
{
    class ISystem
    {
    protected:
        SystemID m_id = util::get<ISystem>();
    public:
        inline SystemID getId()
        {
            return m_id;
        }

        virtual SystemTypeID getType() = 0;
    };
}
#endif //ENGINE_ISYSTEM_H
