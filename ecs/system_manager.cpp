//
// Created by tntrol on 23.02.2022.
//

#include "system_manager.h"

void ECS::SystemManager::update(float delta_time)
{
    for(auto *system: m_order)
    {
        system->update(); //todo
    }
}

ECS::SystemManager::SystemManager(ECS::Memory::IAllocator *allocator)
{
    uint8_t *p = (uint8_t*) allocator->allocate(SYSTEM_MEMORY_BUFFER_SIZE);
    m_allocator = new Memory::LinearAllocator(SYSTEM_MEMORY_BUFFER_SIZE, p); //todo
}

ECS::SystemManager::~SystemManager()
{
    for (auto *system: m_systems)
    {
        system->~ISystem();
    }
}

void ECS::SystemManager::UpdateSystemWorkOrder()
{
    uint32_t size = 0;
    uint32_t i = 0;
    ISystem *temp;
    ISystem *temp2;
    for (ISystem *system: m_systems)
    {
        if (system)
        {
            if (!size)
            {
                m_order[0] = system;
                size++;
                continue;
            }
            for (i = 0; i < size; ++i)
            {
                if (system->m_priority < m_order[i]->m_priority ||
                    system->m_priority == m_order[i]->m_priority &&
                    (m_order_matrix[m_order[i]->getType()][system->getType()] ||
                     !m_order_matrix[system->getType()][m_order[i]->getType()]))
                {
                    temp = m_order[i];
                    m_order[i] = system;
                    break;
                }
            }
            if(i <= size)
            {
                m_order[size++] = system;
                continue;
            }
            size++;
            for (++i; i < size; ++i)
            {
                temp2 = m_order[i];
                m_order[i] = temp;
                temp = temp2;
            }
        }
    }
    for (; size < m_order.size(); ++size)
    {
        m_order[size] = nullptr;
    }
}
