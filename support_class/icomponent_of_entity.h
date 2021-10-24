//
// Created by tntrol on 17.09.2021.
//

#ifndef ENGINE_ICOMPONENT_OF_ENTITY_H
#define ENGINE_ICOMPONENT_OF_ENTITY_H

namespace ECS
{
    class IComponentOfEntity
    {
    public:
        virtual IComponent *getComponent(ComponentTypeID type_id) = 0;

        virtual void addComponent(IComponent *component) = 0;

        virtual void removeComponent(ComponentTypeID type_id) = 0;

        virtual void clear() = 0;

        virtual int size() = 0;
    };
}
#endif //ENGINE_ICOMPONENT_OF_ENTITY_H
