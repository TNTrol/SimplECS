//
// Created by tntrol on 08.09.2021.
//

#ifndef ENGINE_UTIL_COUNTER_H
#define ENGINE_UTIL_COUNTER_H

#include "../support_class/ecs_typedef.h"

namespace ECS
{
    namespace Util
    {
        template<class T>
        static Index get()
        {
            static Index index = 0;
            return ++index;
        }

        template<class T>
        class Counter //todo
        {
            static Index index;
        public:
            static Index getAndIncrement()
            {
                return index++;
            }

            static Index get()
            {
                return index;
            }
        };
    }
}

#endif //ENGINE_UTIL_COUNTER_H
