//
// Created by tntrol on 09.09.2021.
//

#ifndef ENGINE_COMPONENT_H
#define ENGINE_COMPONENT_H

#include "icomponent.h"

#define ECS_COMPONENT(Tag) class Tag: public ECS::Component<Tag>

namespace ECS
{
    template<class T>
    class Component : public IComponent
    {
    public:
        void operator delete(void *) = delete;

        void operator delete[](void *) = delete;

    public:
        static const ComponentTypeID STATIC_TYPE;
    public:
        Component() : IComponent(STATIC_TYPE)
        {}
    };

    template<class T>
    const ComponentTypeID Component<T>::STATIC_TYPE = Util::get<IComponent>();
}
#endif //ENGINE_COMPONENT_H
