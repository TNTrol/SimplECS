//
// Created by tntrol on 08.09.2021.
//

#ifndef ENGINE_IENTITY_H
#define ENGINE_IENTITY_H
#include "../support_class/helper_typedef.h"
#include "../utils/util_counter.h"
namespace ECS
{
    class IEntity
    {
    protected:
        EntityID m_id = util::get<IEntity>();
        bool m_active;
    public:
        //virtual ~IEntity();
        virtual EntityTypeID getType() = 0;
//        virtual void Start() = 0;
//        virtual void Delete() = 0;
        inline EntityID getId()
        {
            return m_id;
        }
        bool isActive()
        {
            return m_active;
        }
        void setActive(bool active)
        {
            m_active = active;
        }
    };
}
#endif //ENGINE_IENTITY_H
