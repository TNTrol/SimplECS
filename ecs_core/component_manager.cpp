//
// Created by tntrol on 12.09.2021.
//

#include "component_manager.h"

ECS::ComponentManager::ComponentManager(const uint32_t max_entity,
                                        const uint32_t grow,
                                        Memory::IAllocator *allocator) :
        m_grow(grow),
        m_max_entity(max_entity),
        m_allocator(allocator),
        m_components(max_entity, grow)
{
    m_components_of_entity.resize(max_entity);
}

ECS::ComponentManager::~ComponentManager()
{
    for(auto pool: m_pool)
    {
        delete pool;
    }
}

void ECS::ComponentManager::removeAllComponentsOfEntity(EntityID entity_id) // todo
{
    if(m_components_of_entity.capacity() <= entity_id || m_components_of_entity[entity_id].capacity() == 0)
    {
        return;
    }
    for(ComponentTypeID component_id: m_components_of_entity[entity_id])
    {
        if(component_id == UINT32_MAX)
        {
            continue;
        }

    }

}

void ECS::ComponentManager::addComponent(EntityID entityId, ECS::IComponent *component)
{
//    HashContainer *components = m_components_of_entity[entityId];  // todo
//    if(!components)
//    {
//        components = new ComponentsOfEntity(m_count_type);
//        m_components_of_entity[entityId] = components;
//    }
//    components->addComponent(component);
}
