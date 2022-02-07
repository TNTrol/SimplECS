//
// Created by tntrol on 11.09.2021.
//

#ifndef ENGINE_ICONTAINER_H
#define ENGINE_ICONTAINER_H

#include <cstddef>
#include "../support_class/helper_typedef.h"

namespace ECS
{
    template<class T>
    class IContainer
    {
    protected:
        virtual void* create_obj() = 0;
        virtual void destruct(void *ptr) = 0;
    public:
        virtual ~IContainer()
        {}

        inline T* create()
        {
            T *t = (T*) create_obj();
            return t;
        }

        inline void remove(T *ptr)
        {
            destruct(ptr);
        }
    };

}
#endif //ENGINE_ICONTAINER_H
