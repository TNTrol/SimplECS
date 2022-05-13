//
// Created by tntrol on 02.05.2022.
//

#include "event_handler.h"
#include "../memory_manager/linear_allocator.h"

void ECS::Event::EventHandler::dispatch()
{
    for (IEvent *event: m_queue)
    {
        m_pool[event->getTypeID()].invoke(event);
    }
    m_queue.clear();
    m_allocator_event->clear();
}

ECS::Event::EventHandler::EventHandler(uint32_t max_size_queue) :
        m_max_size_queue(max_size_queue)
{
    size_t size = sizeof(EventDelegate<IEvent, IEventListener>);
    size_t size_allocate_part = size * max_size_queue;
    m_allocator_event = new Memory::LinearAllocator(size_allocate_part, new char[size_allocate_part]);
    m_queue.resize(m_max_size_queue);
    m_queue.clear();
}

void ECS::Event::EventHandler::unsubscribe(ECS::Event::IDelegate &i_delegate)
{
    EventTypeID typeId = i_delegate.get_type_id();
    if (m_pool.capacity() <= typeId)
    {
        m_pool.resize(typeId + 1);
        return;
    }
    m_pool[typeId].remove(&i_delegate);
}

