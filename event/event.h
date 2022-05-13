//
// Created by tntrol on 02.05.2022.
//

#ifndef ENGINE_EVENT_H
#define ENGINE_EVENT_H

#include "ievent.h"
#include "../utils/util_counter.h"

namespace ECS
{
    namespace Event
    {
        template<class T>
        class Event: public IEvent
        {
        public:
            void operator delete(void *) = delete;

            void operator delete[](void *) = delete;

            static const EventTypeID STATIC_EVENT_TYPE_ID;

            Event() : IEvent(STATIC_EVENT_TYPE_ID)
            {}
        };
        template<class T>
        const EventTypeID Event<T>::STATIC_EVENT_TYPE_ID = Util::get<IEvent>();
    }
}
#endif //ENGINE_EVENT_H
