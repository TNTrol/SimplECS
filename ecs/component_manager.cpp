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
    for (auto pool: m_pool)
    {
        delete pool;
    }
}

void ECS::ComponentManager::removeAllComponentsOfEntity(EntityID entity_id)
{
    if (m_components_of_entity.size() <= entity_id || m_components_of_entity[entity_id].empty())
    {
        return;
    };
    IComponent *component;
    for (ComponentTypeID type_id = 0; type_id < m_components_of_entity[entity_id].size(); ++type_id)
    {
        if (m_components_of_entity[entity_id][type_id] == UINT32_MAX)
        {
            continue;
        }
        component = m_components.get(m_components_of_entity[entity_id][type_id]);
        m_components.remove(component->getId());
        m_pool[entity_id]->remove(component);
        m_components_of_entity[entity_id][type_id] = UINT32_MAX;
    }
}

void ECS::ComponentManager::addComponent(EntityID entityId, ECS::IComponent *component)
{
    component->m_owner = entityId;
    component->m_id = m_components.add(component);
    ComponentTypeID componentTypeId = component->getType();
    if (m_components_of_entity[entityId].size() <= componentTypeId)
    {
        m_components_of_entity[entityId].resize(componentTypeId + 1, UINT32_MAX);
    }
    m_components_of_entity[entityId][componentTypeId] = component->getId();
}

ECS::ComponentManager::ComponentContainer ECS::ComponentManager::getComponentsOfEntity(ECS::EntityID entity_id)
{
    return ECS::ComponentManager::ComponentContainer(this, entity_id);
}

ECS::IComponent *ECS::ComponentManager::Iterator::operator*() const
{
    ComponentID id = manager->m_components_of_entity[m_id][m_current];
    return manager->m_components.get(id);
}

ECS::IComponent *ECS::ComponentManager::Iterator::operator->()
{
    ComponentID id = manager->m_components_of_entity[m_id][m_current];
    return manager->m_components.get(id);
}

ECS::ComponentManager::Iterator &ECS::ComponentManager::Iterator::operator++()
{
    if (m_current < manager->m_components_of_entity[m_id].size())
    {
        for (++m_current; m_current < manager->m_components_of_entity[m_id].size(); ++m_current)
        {
            if (manager->m_components_of_entity[m_id][m_current] != UINT32_MAX)
            {
                return *this;
            }
        }
    }
    return *this;
}

ECS::ComponentManager::Iterator ECS::ComponentManager::Iterator::operator++(int)
{
    Iterator tmp = *this;
    ++(*this);
    return tmp;
}

ECS::ComponentManager::Iterator ECS::ComponentManager::ComponentContainer::begin()
{
    ComponentTypeID type = 0;
    for(; type < manager->m_components_of_entity[m_id].size(); ++type)
    {
        if(manager->m_components_of_entity[m_id][type] != UINT32_MAX)
        {
            break;
        }
    }
    return {manager, m_id, type};;
}

ECS::ComponentManager::Iterator ECS::ComponentManager::ComponentContainer::end()
{
    return Iterator(manager, m_id, manager->m_components_of_entity[m_id].size());;
}

ECS::ComponentManager::ComponentContainer::ComponentContainer(ECS::ComponentManager *componentManager, ECS::EntityID id):
    manager(componentManager),
    m_id(id)
{}
