//
// Created by tntrol on 08.09.2021.
//

#ifndef ENGINE_UTIL_COUNTER_H
#define ENGINE_UTIL_COUNTER_H

namespace ECS
{
    namespace Util
    {
        template<class T>
        static uint32_t get()
        {
            static uint32_t index = 0;
            return index++;
        }
    }
}

#endif //ENGINE_UTIL_COUNTER_H
