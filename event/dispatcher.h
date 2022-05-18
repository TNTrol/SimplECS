//
// Created by tntrol on 07.05.2022.
//

#ifndef ENGINE_DISPATCHER_H
#define ENGINE_DISPATCHER_H

#include <algorithm>
#include <vector>
#include <list>

#include "delegate.h"
#include "ievent.h"

namespace ECS
{
    namespace Event
    {
        class Dispatcher
        {
        private:
            struct container
            {
                IDelegate *m_delegate;
                bool m_active;

                container(IDelegate *delegate) :
                        m_delegate(delegate),
                        m_active(true)
                {}
            };

        private:
            std::list<container> m_delegates;
        public:
            Dispatcher()
            {}

            void invoke(IEvent *event);

            void remove(IDelegate *delegate);

            void add(IDelegate *delegate);

        };
    }
}

#endif //ENGINE_DISPATCHER_H
