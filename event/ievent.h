//
// Created by tntrol on 01.05.2022.
//

#ifndef ENGINE_IEVENT_H
#define ENGINE_IEVENT_H

#include "../type/ecs_typedef.h"

namespace ECS
{
    namespace Event
    {
        class IEvent
        {
        private:
            EventTypeID m_event_type;
        public:
            IEvent(EventTypeID event_type_id): m_event_type(event_type_id)
            {}

            inline EntityTypeID getTypeID()
            {
                return m_event_type;
            }
        };
    }
}

#endif //ENGINE_IEVENT_H
