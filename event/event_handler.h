//
// Created by tntrol on 02.05.2022.
//

#ifndef ENGINE_EVENT_HANDLER_H
#define ENGINE_EVENT_HANDLER_H

#include "vector"
#include "ievent.h"
#include "dispatcher.h"
#include "ievent_listener.h"
#include "../memory/iallocator.h"
#include "../ecs/API.h"

namespace ECS
{
    namespace Event
    {
        class EventHandler
        {
        private:
            std::vector<Dispatcher> m_pool;
            std::vector<IEvent *> m_queue;
            Memory::IAllocator *m_allocator_event;
            const uint32_t m_max_size_queue;
        public:
            EventHandler(uint32_t max_size_queue = EVENT_SIZE_STACK);
            ~EventHandler();

            void dispatch();

            void unsubscribe(IDelegate &i_delegate);

            template<class E, class... ARGS>
            void sendEvent(ARGS &&... args)
            {
                void *event = m_allocator_event->allocate(sizeof(E));
                if (event)
                {
                    m_queue.push_back(new(event) E(std::forward<ARGS>(args)...));
                }
            }

            template<class E>
            void subscribe(IDelegate &i_delegate)
            {
                EventTypeID typeId = E::STATIC_EVENT_TYPE_ID;
                if (m_pool.capacity() <= typeId)
                {
                    m_pool.resize(typeId + 1);
                }
                m_pool[typeId].add(&i_delegate);
            }

        };
    }
}

#endif //ENGINE_EVENT_HANDLER_H
