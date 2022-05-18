//
// Created by tntrol on 07.05.2022.
//

#ifndef ENGINE_IEVENT_LISTENER_H
#define ENGINE_IEVENT_LISTENER_H

#include "../ecs/API.h"
#include "ievent.h"
#include "delegate.h"
#include "../ecs/engine.h"

#include <list>

namespace ECS
{
    namespace Event
    {
        class IEventListener
        {
        private:
            std::list<Event::IDelegate *> m_delegate;
        public:

            template<class Even, class Class>
            void subscribe(void(Class::*Callback)(const Even *const))
            {
                Event::EventDelegate<Class, Even> delegate = {.m_receiver = this, .m_callback=Callback};
                SEngine->subscribeEvent<Even>(delegate);
            }

            template<class Even, class Class>
            void unsubscribe(void(Class::*Callback)(const Even *const))
            {
                Event::EventDelegate<Class, Even> delegate = {.m_receiver = this, .m_callback=Callback};
                SEngine->unsubscribeEvent(delegate);
            }

//            void fun();
        };
    }
}

#endif //ENGINE_IEVENT_LISTENER_H
