//
// Created by tntrol on 14.05.2022.
//

#include "timer.h"

ECS::Util::Timer::Timer() :
        m_elapsed(0)
{}

ECS::Util::Timer::~Timer()
{}

void ECS::Util::Timer::tick(float_t ms)
{
    m_elapsed += std::chrono::duration<float, std::ratio<1, 1000>>(ms);;
}

void ECS::Util::Timer::reset()
{
    m_elapsed = std::chrono::duration<float_t, std::milli>::zero();
}

float_t ECS::Util::Timer::get_time()
{
    return m_elapsed.count();
}
