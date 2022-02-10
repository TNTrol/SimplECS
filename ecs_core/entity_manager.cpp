//
// Created by tntrol on 09.09.2021.
//

#include "entity_manager.h"

ECS::EntityManager::EntityManager(ComponentManager*component_manager,
                                  const uint32_t max_count_entity,
                                  const uint32_t grow,
                                  Memory::IAllocator *allocator):
    m_max_count_entity(max_count_entity),
    m_component_manager(component_manager),
    m_count_destroy(0),
    m_entity(max_count_entity, grow),
    m_count_type(util::get<IEntity>() - 1),
    m_allocator(allocator)
{
    m_pool.resize(m_count_type);
    m_destroy_entity.resize(DESTROY_SIZE_STACK);
    for(int i = 0; i < m_count_type; ++i)
    {
        m_pool[i] = nullptr;
    }
}

ECS::EntityManager::~EntityManager()
{
    for(int i = 0; i < m_count_type; ++i)
    {
        delete m_pool[i];
    }
}

void ECS::EntityManager::removeDestroyedEntity()
{
    IEntity *entity = nullptr;
    for(int i = 0; i < m_count_destroy; ++i)
    {
        entity = m_entity.remove(m_destroy_entity[i]);
        if(entity)
        {
            m_component_manager->removeAllComponents(entity->getId());
            m_pool[entity->getType()]->remove(entity);
        }
    }
    m_count_destroy = 0;
}

void ECS::EntityManager::destroyEntity(const EntityID entityId)
{
    if(entityId >= m_max_count_entity || !m_entity.get(entityId))
    {
        return;
    }
    if(m_count_destroy < m_destroy_entity.size())
    {
        m_destroy_entity.push_back(entityId);
    }
    else
    {
        m_destroy_entity[m_count_destroy] = entityId;
    }
    m_count_destroy++;
}
