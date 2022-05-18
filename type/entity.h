//
// Created by tntrol on 08.09.2021.
//

#ifndef ENGINE_ENTITY_H
#define ENGINE_ENTITY_H

#include "ecs_typedef.h"
#include "../utils/util_counter.h"
#include "ientity.h"

#define ECS_ENTITY(Tag) class Tag: public ECS::Entity<Tag>

namespace ECS
{
    template<class E>
    class Entity : public IEntity
    {
    public:
        void operator delete(void *) = delete;

        void operator delete[](void *) = delete;

    public:
        static const EntityTypeID STATIC_TYPE;
    public:
        inline EntityTypeID getType() override
        {
            return STATIC_TYPE;
        }
//        void Start() override
//        {
//
//        }
//        void Delete() override
//        {
//
//        }
    };

    template<class E>
    const EntityTypeID Entity<E>::STATIC_TYPE = Util::get<IEntity>();
}
#endif //ENGINE_ENTITY_H
