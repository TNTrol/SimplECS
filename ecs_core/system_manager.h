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
        Memory::IAllocator *m_allocator;
    private:
        void update(float delta_time);

    public:
        SystemManager(Memory::IAllocator *allocator);

        ~SystemManager();

        template<class T, class... ARGS>
        T *createSystem(ARGS &&... systemArgs)
        {
            //todo
        }

        void UpdateSystemWorkOrder();

        template<class T>
        T *getSystem()
        {
            //todo
        }

        template<class T>
        void enableSystem()
        {}

        template<class T>
        void disableSystem()
        {}

        template<class T>
        void SetSystemUpdateInterval(float interval_ms)
        {}


    };
}

#endif //ENGINE_SYSTEM_MANAGER_H
