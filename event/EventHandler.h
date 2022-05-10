//
// Created by tntrol on 02.05.2022.
//

#ifndef ENGINE_EVENTHANDLER_H
#define ENGINE_EVENTHANDLER_H

#include "vector"
#include "ievent.h"
#include "../memory_manager/iallocator.h"
#include "dispatcher.h"

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
            uint32_t m_size_queue;
            const uint32_t m_max_size_queue;
        public:
            EventHandler(uint32_t max_size_queue);

            template<class E, class... ARGS>
            void sendEvent(ARGS &&... args) //new(ptr_entity) T(std::forward<ARGS>(args)...);
            {
                void *event = m_allocator_event->allocate(sizeof(E));
                if (event)
                {
                    m_queue.push_back(new (event) E(std::forward<ARGS>(args)...));
                }
            }

            void dispatch();

            template<class E>
            void subscribe(Dispatcher *eventDispather) //new(ptr_entity) T(std::forward<ARGS>(args)...);
            {

            }

            void unsubscribe(Dispatcher *eventDispather) //new(ptr_entity) T(std::forward<ARGS>(args)...);
            {}

        };
    }
}

#endif //ENGINE_EVENTHANDLER_H
