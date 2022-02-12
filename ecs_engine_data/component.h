//
// Created by tntrol on 09.09.2021.
//

#ifndef ENGINE_COMPONENT_H
#define ENGINE_COMPONENT_H

#include "icomponent.h"

namespace ECS
{
    template<class T>
    class Component : public IComponent
    {
    public:
        static const ComponentTypeID STATIC_TYPE;
    public:
        inline ComponentTypeID getType() override
        {
            return STATIC_TYPE;
        }
    };

    template<class T>
    const ComponentTypeID Component<T>::STATIC_TYPE = Util::get<IComponent>();
}
#endif //ENGINE_COMPONENT_H
