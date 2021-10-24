//
// Created by tntrol on 11.09.2021.
//

#ifndef ENGINE_ICONTAINER_H
#define ENGINE_ICONTAINER_H
#include "vector"
//#include "../ecs_engine_data/ientity.h"
#include "helper_typedef.h"
//#include "i"

namespace ECS
{

    class IContainer
    {
    public:
        virtual ~IContainer() = 0;
        virtual void add(Index id) = 0;
        virtual void remove(Index id) = 0;
        virtual int size() = 0;
        virtual Index get(int index) = 0;
    };

}
#endif //ENGINE_ICONTAINER_H
