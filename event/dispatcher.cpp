//
// Created by tntrol on 07.05.2022.
//

#include "dispatcher.h"

void ECS::Event::Dispatcher::invoke(ECS::Event::IEvent *event)
{
    auto end = std::remove_if(m_delegates.begin(), m_delegates.end(),
                              [](container &c) {
                                  return !c.m_active;
                              });
    m_delegates.erase(end, m_delegates.end());
    for (auto delegate: m_delegates)
    {
        delegate.m_delegate->invoke(event);
    }
}

void ECS::Event::Dispatcher::remove(ECS::Event::IDelegate *delegate)
{
    auto result = std::find_if(this->m_delegates.begin(), this->m_delegates.end(),
                               [&](const container &other) {
                                   return other.m_delegate->operator==(delegate);
                               });
    if (result != m_delegates.end())
    {
        result->m_active = false;
    }
}

void ECS::Event::Dispatcher::add(ECS::Event::IDelegate *delegate)
{
    auto result = std::find_if(this->m_delegates.begin(), this->m_delegates.end(),
                               [&](const container &other) {
                                   return other.m_delegate->operator==(delegate);
                               });
    if (result == m_delegates.end())
    {
        m_delegates.emplace_back(delegate->clone());
    }
    else
    {
        result->m_active = true;
    }
}

