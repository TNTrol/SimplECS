//
// Created by tntrol on 12.09.2021.
//

#include "component_manager.h"
#include "../support_class/impl/componets_of_entity.h"

ECS::ComponentManager::ComponentManager(const unsigned int max_entity, const unsigned int grow):
    m_grow(grow),
    m_max_entity(max_entity)
{
    m_count_type = util::get<ComponentTypeIdS>() - 1;
    m_components.resize(max_entity);
    m_pool.resize(m_count_type);
    for(int i = 0; i < m_count_type; ++i)
    {
        //todo create container
    }
}

ECS::ComponentManager::~ComponentManager()
{
    for (int i = 0; i < m_count_type; ++i)
    {
        delete m_pool[i];
    }

    for(int i = 0; i < m_components.size(); ++i)
    {
        delete m_components[i];
    }
}

void ECS::ComponentManager::removeAllComponents(const EntityID entity_id)
{
    IComponentOfEntity *components = m_components[entity_id];
    IComponent *component = nullptr;
    int size;
    if(components)
    {
        size = components->size();
        for(int typeId = 0; typeId < size; ++typeId)
        {
            component = components->getComponent(typeId);
            if(component)
            {
                m_pool[typeId]->remove(entity_id);
                delete component;
                component = nullptr;
            }
        }
        delete components;
        m_components[entity_id] = nullptr;
    }
}

void ECS::ComponentManager::addComponent(EntityID entityId, ECS::IComponent *component)
{
    IComponentOfEntity *components = m_components[entityId];
    if(!components)
    {
        components = new ComponentsOfEntity(m_count_type);
        m_components[entityId] = components;
    }
    components->addComponent(component);
}
