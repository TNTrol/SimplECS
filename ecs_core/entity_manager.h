//
// Created by tntrol on 09.09.2021.
//

#ifndef ENGINE_ENTITY_MANAGER_H
#define ENGINE_ENTITY_MANAGER_H
#include "../support_class/helper_typedef.h"
#include "../ecs_engine_data/ientity.h"
#include "../support_class/icontainer.h"
#include "component_manager.h"
#include "API.h"

#include <vector>
namespace ECS
{
    class Entity_manager
    {
    protected:
        std::vector<IEntity*> m_entity;
        std::vector<IContainer*> m_pool;
        std::vector<EntityID> m_destroy_entity;
        ComponentManager *m_component_manager;
        unsigned int m_count_type;
        unsigned int m_count_entity;
        unsigned int m_max_count_entity;
        unsigned int m_grow;
        unsigned int m_count_destroy;
    public:
        Entity_manager(ComponentManager*component_manager, unsigned int max_count_entity = ENTITY_SIZE_STACK, unsigned int grow = ENTITY_GROW_STACK);
        ~Entity_manager();
        void destroyEntity(EntityID entityId);
        void removeDestroyedEntity();

        inline IEntity* getEntity(EntityID entityId)
        {
            return m_entity[entityId];
        }

        template<class T>
        inline IContainer* getContainer()
        {
            return m_pool[T::STATIC_TYPE];
        }

        template<class T, class... ARGS>
        T* createEntity(ARGS&&... args)
        {
            T* entity = new T(std::forward<ARGS>(args)...);
            EntityTypeID id_type = T::STATIC_TYPE;
            EntityID  id = entity->getId();
            m_pool[id_type]->add(id);
            m_entity[id] = entity;//todo make resize vector
            m_count_entity++;
            return entity;
        }
    };

}
#endif //ENGINE_ENTITY_MANAGER_H
