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

            virtual uint32_t get_hash() const = 0;

            virtual EventTypeID get_type_id() = 0;

            virtual IDelegate* clone(void * = nullptr) = 0;
        };

        template<class C, class E>
        class EventDelegate : public IDelegate
        {
            typedef void(C::*Callback)(const E * const);

            C *m_receiver;
            Callback m_callback;

        public:

            EventDelegate(C *receiver, const Callback &callbackFunction) :
                    m_receiver(receiver),
                    m_callback(callbackFunction)
            {}

            void invoke(const IEvent *const e) override
            {
                (m_receiver->*m_callback)(reinterpret_cast<const E *const>(e));
            }

            uint32_t get_hash() const override
            {
                static const uint32_t DELEGATE_ID{typeid(C).hash_code() ^ typeid(Callback).hash_code()};
                return DELEGATE_ID;
            }

            bool operator==(const IDelegate *other) const override
            {
                if (other == nullptr || other->get_hash() != get_hash())
                    return false;
                auto e = (EventDelegate *) other;
                return e->m_callback == this->m_callback && e->m_receiver == this->m_receiver;
            }

            EventTypeID get_type_id() override
            {
                return E::STATIC_EVENT_TYPE_ID;
            }

            IDelegate* clone(void* ptr) override
            {
                return ptr ? new (ptr) EventDelegate<C, E>(m_receiver, m_callback) : new EventDelegate<C, E>(m_receiver, m_callback);
            }
        };
    }
}
#endif //ENGINE_DELEGATE_H
