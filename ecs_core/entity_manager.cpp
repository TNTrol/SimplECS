//
// Created by tntrol on 09.09.2021.
//

#include "entity_manager.h"

ECS::Entity_manager::Entity_manager(ComponentManager*component_manager, const unsigned int max_count_entity, const unsigned int grow):
    m_grow(grow),
    m_max_count_entity(max_count_entity),
    m_component_manager(component_manager),
    m_count_destroy(0),
    m_count_entity(0)
{
    m_count_type = util::get<EntityTypeIdS>() - 1;
    m_pool.resize(m_count_type);
    m_entity.resize(max_count_entity);
    m_destroy_entity.resize(DESTROY_SIZE_STACK);
    for(int i = 0; i < m_count_type; ++i)
    {
        //m_pool[i] =
    }
}

ECS::Entity_manager::~Entity_manager()
{
    IEntity *entity = nullptr;
    for(int i = 0; i < m_count_type; ++i)
    {
        delete m_pool[i];
    }
    for(int i = 0; i < m_count_entity; ++i)
    {
        entity = m_entity[i];
        if(entity)
        {
            m_component_manager->removeAllComponents(entity->getId());
        }
    }
}

void ECS::Entity_manager::removeDestroyedEntity()
{
    EntityID entityId = 0;
    EntityTypeID id = 0;
    for(int i = 0; i < m_count_destroy; ++i)
    {
        entityId = m_destroy_entity[i];
        id = m_entity[entityId]->getType();
        m_pool[id]->remove(entityId);
        m_component_manager->removeAllComponents(entityId);
        delete m_entity[entityId];
    }
    m_count_destroy = 0;
}

void ECS::Entity_manager::destroyEntity(const EntityID entityId)
{
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
