//
// Created by tntrol on 08.09.2021.
//

#ifndef ENGINE_UTIL_COUNTER_H
#define ENGINE_UTIL_COUNTER_H

#include "../ecs_engine_data/ecs_typedef.h"

namespace ECS
{
    namespace Util
    {
        template<class T>
        static Index get()
        {
            static Index index = 0;
            return index++;
        }
    }
}

#endif //ENGINE_UTIL_COUNTER_H
