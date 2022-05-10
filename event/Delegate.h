//
// Created by tntrol on 06.05.2022.
//

#ifndef ENGINE_DELEGATE_H
#define ENGINE_DELEGATE_H

#include "ievent.h"
#include <typeinfo>

namespace ECS
{
    namespace Event
    {
        class IDelegate
        {
        public:
            virtual void invoke(const IEvent *const e) = 0;

            virtual bool operator==(const IDelegate *other) const = 0;

            virtual uint32_t GetStaticEventTypeId() const = 0;
        };

        template<class C, class E>
        class EventDelegate : public IDelegate
        {
            typedef void(C::*Callback)(int);

            C *m_Receiver;
            Callback m_Callback;

        public:

            EventDelegate(C *receiver, Callback &callbackFunction) :
                    m_Receiver(receiver),
                    m_Callback(callbackFunction)
            {}

            void invoke(const IEvent *const e) override
            {
                (m_Receiver->*m_Callback)(reinterpret_cast<const E *const>(e));
            }

            uint32_t GetStaticEventTypeId() const override
            {
                static const uint32_t DELEGATE_ID{typeid(C).hash_code() ^ typeid(Callback).hash_code()};
                return DELEGATE_ID;
            }

            bool operator==(const IDelegate *other) const override
            {
                if (other == nullptr || other->GetStaticEventTypeId() != GetStaticEventTypeId())
                    return false;
                auto e = (EventDelegate<C, Callback> *) other;
                return e->m_Callback == this->m_Callback && e->m_Receiver == this->m_Receiver;
            }
        };
    }
}
#endif //ENGINE_DELEGATE_H
