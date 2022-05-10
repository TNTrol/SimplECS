//
// Created by tntrol on 23.02.2022.
//

#ifndef ENGINE_SYSTEM_MANAGER_H
#define ENGINE_SYSTEM_MANAGER_H

#include "vector"
#include "../ecs_engine_data/isystem.h"
#include "../memory_manager/iallocator.h"

namespace ECS
{

    class SystemManager
    {
    private:
        std::vector<ISystem *> m_systems;
        std::vector<ISystem *> m_order;
        std::vector<std::vector<bool>> m_order_matrix;
        Memory::IAllocator *m_allocator;
    private:
        void update(float delta_time);

        void setState(const SystemTypeID id, bool state)
        {
            if (id >= m_systems.size())
            {
                return;
            }
            ISystem *system = m_systems[id];
            if (system)
            {
                system->m_enable = state;
            }
        }

    public:
        SystemManager(Memory::IAllocator *allocator);

        ~SystemManager();

        template<class T, class... ARGS>
        T *createSystem(ARGS &&... args) // todo resize
        {
            T *ptr = m_allocator->allocate(sizeof(T));
            T *value = new(ptr) T(std::forward<ARGS>(args)...);
            if (T::STATIC_TYPE >= m_systems.size())
            {
                m_systems.resize(T::STATIC_TYPE + 1);
                m_order_matrix.resize(T::STATIC_TYPE + 1);
                for (uint32_t i = 0; i < T::STATIC_TYPE + 1; ++i)
                {
                    m_order_matrix[i].resize(T::STATIC_TYPE + 1);
                }
            }
            m_systems[T::STATIC_TYPE] = value;
            return value;
        }

        void UpdateSystemWorkOrder();

        template<class Target_, class Dependency_, class... Dependencies>
        void addSystemDependency(Target_ target, Dependency_ dependency, Dependencies &&... dependencies)
        {
            SystemTypeID target_id = target->getType();
            SystemTypeID dep_id = dependency->getType();
            m_order_matrix[target_id][dep_id] = true;
            addSystemDependency(target, std::forward<Dependencies>(dependency)...);
        }

        template<class T>
        T *getSystem()
        {
            if (T::STATIC_TYPE >= m_systems.size())
            {
                return nullptr;
            }
            return m_systems[T::STATIC_TYPE];
        }

        template<class T>
        void enableSystem()
        {
            setState(T::STATIC_TYPE, true);
        }

        template<class T>
        void disableSystem()
        {
            setState(T::STATIC_TYPE, false);
        }

        template<class T>
        void SetSystemUpdateInterval(float interval_ms)
        {
            if (m_systems.size() >= T::STATIC_TYPE || m_systems[T::STATIC_TYPE] == nullptr)
            {
                return;
            }
            m_systems[T::STATIC_TYPE]->m_update_interval = interval_ms;
        }

        template<class T>
        void setPriority(Priority priority)
        {
            if (m_systems.size() >= T::STATIC_TYPE || m_systems[T::STATIC_TYPE] == nullptr)
            {
                return;
            }
            m_systems[T::STATIC_TYPE]->m_priority = priority;
        }

    };
}

#endif //ENGINE_SYSTEM_MANAGER_H
