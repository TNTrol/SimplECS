//
// Created by tntrol on 19.09.2021.
//

#ifndef ENGINE_ENTITY_CONTAINER_H
#define ENGINE_ENTITY_CONTAINER_H
#include "../icontainer.h"
namespace ECS
{
    class EntityContainer //: public ECS::IContainer
    {
    private:
        std::vector<EntityID> entities;
    public:
        EntityContainer();

        ~EntityContainer(); //override;

        void add(EntityID entity_id);// override;

        void remove(EntityID entity_id);// override;

        int size() ;//override;

        EntityID get(int index);// override;
    };

}
#endif //ENGINE_ENTITY_CONTAINER_H
