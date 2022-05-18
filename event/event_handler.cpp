//
// Created by tntrol on 02.05.2022.
//

#include "event_handler.h"


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
    m_allocator_event = new Memory::LinearAllocator(EVENT_MEMORY_BUFFER_SIZE, new uint8_t[EVENT_MEMORY_BUFFER_SIZE]);
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

ECS::Event::EventHandler::~EventHandler()
{
    delete[] (uint8_t*) m_allocator_event->get_source_ptr();
    delete m_allocator_event;
}

