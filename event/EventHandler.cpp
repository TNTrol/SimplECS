//
// Created by tntrol on 02.05.2022.
//

#include "EventHandler.h"

void ECS::Event::EventHandler::dispatch()
{
    for (IEvent *event: m_queue)
    {
        m_pool[event->getTypeID()].invoke(event);
    }
    m_allocator_event->clear();
}
