//
// Created by tntrol on 09.09.2021.
//

#ifndef ENGINE_SYSTEM_H
#define ENGINE_SYSTEM_H

#include "isystem.h"

namespace ECS
{
    template<class T>
    class System : public ISystem
    {
    public:
        static const SystemTypeID STATIC_TYPE;
    public:
        SystemTypeID getType() override
        {
            return STATIC_TYPE;
        }
    };

    template<class T>
    const SystemTypeID System<T>::STATIC_TYPE = util::get<ISystem>();
}
#endif //ENGINE_SYSTEM_H
