//
// Created by tntrol on 07.05.2022.
//

#ifndef ENGINE_DISPATCHER_H
#define ENGINE_DISPATCHER_H

#include <algorithm>
#include "vector"
#include "list"
#include "Delegate.h"
#include "ievent.h"

namespace ECS
{
    namespace Event
    {
        class Dispatcher
        {
        private:
            std::list<IDelegate *> m_delegates;
            std::list<IDelegate *> m_remove_delegates;
        public:
            Dispatcher(uint32_t max)
            {}

            void invoke(IEvent *event)
            {
                for (auto delegate: m_delegates)
                {
                    delegate->invoke(event);
                }
            }

            IDelegate* remove(IDelegate* delegate)
            {
                auto result = std::find_if(this->m_delegates.begin(), this->m_delegates.end(),
                                           [&](const IDelegate* other)
                                           {
                                               return other->operator==(delegate);
                                           });
                if (result != m_delegates.end())
                {

                }
            }

            void add(IDelegate *delegate)
            {
                m_delegates.push_back(delegate);
            }

        };
    }
}

#endif //ENGINE_DISPATCHER_H
