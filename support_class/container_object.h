//
// Created by tntrol on 17.09.2021.
//

#ifndef ENGINE_CONTAINER_OBJECT_H
#define ENGINE_CONTAINER_OBJECT_H

#include "vector"
#include "helper_typedef.h"

#define DICT_FLAG 0xFFFFFFFF

namespace ECS
{

    struct node_list
    {
        uint32_t next = 0;
        uint32_t flag = DICT_FLAG;
    };

    template<class T>

    union node_u
    {
        node_list node;
        T *value;
        node_u(){}
    };

    template<class T>
    class ContainerObject
    {
    private:
        std::vector<node_u<T>> m_pool;
        const uint32_t m_grow;
        uint32_t m_max_size;
        uint32_t m_size;
        uint32_t m_start_free;
        uint32_t m_current;
    private:
        void resize()
        {
            m_current = m_max_size + 1;
            m_max_size += m_grow;
            m_pool.resize(m_max_size);
        }

    public:
        ContainerObject(uint32_t size, uint32_t grow) : m_grow(grow), m_max_size(size - 1)
        {
            m_pool.resize(size);
            m_size = 0;
            m_current = 0;
            m_start_free = m_max_size;
            m_pool[m_start_free].node = {m_start_free, DICT_FLAG};
        }

        ~ContainerObject()
        {

        }

        T *get(Index id)
        {
            if (m_pool[id].node.flag == DICT_FLAG && m_pool[id].node.next < m_max_size)
            {
                return nullptr;
            }
            return m_pool[id].value;
        }

        Index add(T *object)
        {
            Index id;
            if (m_size >= m_max_size)
            {
                resize();
            }
            if (m_current < m_max_size)
            {
                id = m_current++;
            }
            else
            {
                id = m_start_free;
                m_start_free = m_pool[id].node.next;
            }
            m_pool[id].value = object;
            m_size++;
            return id;
        }

        T* remove(Index id)
        {
            if (m_pool[id].node.flag == DICT_FLAG)
            {
                return nullptr;
            }
            T* value = m_pool[id].value;
            m_pool[id].node = {m_start_free, DICT_FLAG};
            m_start_free = id;
            m_size--;
            return value;
        }

        void clear()
        {
            m_start_free = m_max_size - 1;
            m_size = 0;
            m_current = 0;
        }

        uint32_t size()
        {
            return m_size;
        }
    };
}
#endif //ENGINE_CONTAINER_OBJECT_H
