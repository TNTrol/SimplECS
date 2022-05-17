//
// Created by tntrol on 14.05.2022.
//

#include "engine.h"
#include "entity_manager.h"
#include "component_manager.h"
#include "system_manager.h"


ECS::Engine::Engine()
{
    m_event_handler = new Event::EventHandler();
    m_global_memory = new Memory::GlobalAllocator(BUFFER_SIZE, BUFFER_SIZE);
    m_component_manager = new ComponentManager(COMPONENT_SIZE_STACK, COMPONENT_GROW_SACK, m_global_memory);
    m_entity_manager = new EntityManager(m_component_manager, ENTITY_MAX, ENTITY_GROW_STACK, m_global_memory);
    m_system_manager = new SystemManager();
    m_timer = new Util::Timer();
}

ECS::Engine::~Engine()
{
    delete m_event_handler;
    delete m_system_manager;
    delete m_timer;
    delete m_entity_manager;
    delete m_component_manager;
    delete m_global_memory;
}

void ECS::Engine::update(float ms)
{
    m_timer->tick(ms);
    m_system_manager->update(ms);
    m_event_handler->dispatch();
    m_entity_manager->removeDestroyedEntity();
    m_event_handler->dispatch();
}

void ECS::Engine::unsubscribeEvent(Event::IDelegate &eventDelegate)
{
    m_event_handler->unsubscribe(eventDelegate);
}
