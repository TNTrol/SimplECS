//
// Created by tntrol on 12.09.2021.
//

#include "component_manager.h"

ECS::ComponentManager::ComponentManager(const uint32_t max_entity,
                                        const uint32_t grow,
                                        Memory::IAllocator *allocator) :
        m_grow(grow),
        m_max_entity(max_entity),
        m_count_type(Util::get<IComponent>() - 1),
        m_allocator(allocator)
{
    m_components.resize(max_entity);
    m_pool.resize(m_count_type);
    for (int i = 0; i < m_count_type; ++i)
    {
        m_pool[i] = nullptr;
    }
}

ECS::ComponentManager::~ComponentManager()
{
    for (int i = 0; i < m_count_type; ++i)
    {
        delete m_pool[i];
    }
    for (int i = 0; i < m_components.size(); ++i)
    {
        // delete m_components[i]; //todo
    }
}

void ECS::ComponentManager::removeAllComponents(const EntityID entity_id) // todo
{
//    HashContainer *components = m_components[entity_id];
//    int size;
//    if(components)
//    {
//        size = components->size();
//        for(ComponentTypeID typeId = 0; typeId < size; ++typeId)
//        {
//            m_pool[typeId]->remove(components->removeComponent(typeId));
//        }
//        delete components;
//        m_components[entity_id] = nullptr;
//    }
}

void ECS::ComponentManager::addComponent(EntityID entityId, ECS::IComponent *component)
{
//    HashContainer *components = m_components[entityId];
//    if(!components)
//    {
//        components = new ComponentsOfEntity(m_count_type);
//        m_components[entityId] = components;
//    }
//    components->addComponent(component);
}
