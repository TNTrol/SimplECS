//
// Created by tntrol on 14.05.2022.
//

#ifndef ENGINE_ENGINE_H
#define ENGINE_ENGINE_H

#include "API.h"
//#include "../event/ievent_listener.h"
#include "../event/event_handler.h"
#include "../memory/global_allocator.h"
#include "../utils/timer.h"

namespace ECS
{
    class EntityManager;

    class SystemManager;

    class ComponentManager;

    namespace Event
    {
        class IEventListener;
    }

    class Engine
    {
        friend class IEntity;

        friend class IComponent;

        friend class ISystem;

        friend class Event::IEvent;

        friend class  Event::IEventListener;

        friend class EntityManager;


    private:
        EntityManager *m_entity_manager;
        ComponentManager *m_component_manager;
        SystemManager *m_system_manager;
        Event::EventHandler *m_event_handler;
        Memory::GlobalAllocator *m_global_memory;
        Util::Timer *m_timer;
    private:
        template<class E>
        inline void subscribeEvent(Event::IDelegate &eventDelegate)
        {
            m_event_handler->subscribe<E>(eventDelegate);
        }

        inline void unsubscribeEvent(Event::IDelegate &eventDelegate);

    public:
        Engine();

        ~Engine();

        void update(float ms);

        inline EntityManager *getEntityManager()
        { return m_entity_manager; }

        inline ComponentManager *getComponentManager()
        { return m_component_manager; }

        inline SystemManager *getSystemManager()
        { return m_system_manager; }

        template<class E, class... ARGS>
        void sendEvent(ARGS &&... eventArgs)
        {
            m_event_handler->sendEvent<E>(std::forward<ARGS>(eventArgs)...);
        }
    };
}

#endif //ENGINE_ENGINE_H
