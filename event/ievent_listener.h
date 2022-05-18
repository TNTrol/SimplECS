//
// Created by tntrol on 07.05.2022.
//

#ifndef ENGINE_IEVENT_LISTENER_H
#define ENGINE_IEVENT_LISTENER_H


#include "../ecs/API.h"
#include "ievent.h"
#include "delegate.h"
#include <list>

namespace ECS
{
    namespace Event
    {
        class IEventListener
        {
        private:
            std::list<IDelegate*> m_delegate;
        public:

            template<class Event, class Class>
            void subscribe(void(Class::*Callback)(const Event* const))
            {
                //todo
//                SEngine->subscribeEvent();

            }

            template<class Event, class Class>
            void unsubscribe(void(Class::*Callback)(const Event* const))
            {
                //todo
            }

            void fun();
        };
    }
}

#endif //ENGINE_IEVENT_LISTENER_H
