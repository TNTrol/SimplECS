//
// Created by tntrol on 14.05.2022.
//

#ifndef ENGINE_TIMER_H
#define ENGINE_TIMER_H

#include <chrono>
#include <cmath>

namespace ECS
{
    namespace Util
    {
        class Timer
        {
        private:
            std::chrono::duration<float_t, std::milli> m_elapsed;
        public:
            Timer();
            ~Timer();
            void tick(float_t ms);
            void reset();
            float_t get_time();
        };
    }
}



#endif //ENGINE_TIMER_H
