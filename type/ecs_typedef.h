//
// Created by tntrol on 08.09.2021.
//

#ifndef ENGINE_ECS_TYPEDEF_H
#define ENGINE_ECS_TYPEDEF_H

#include <cinttypes>
#include <cstddef>

namespace ECS
{
    typedef std::uint32_t Number;
    typedef Number EntityID;
    typedef Number Index;
    typedef Number ComponentID;
    typedef Number SystemID;
    typedef Number EntityTypeID;
    typedef Number ComponentTypeID;
    typedef Number SystemTypeID;
    typedef Number Priority;
    typedef Number EventTypeID;
}

#endif //ENGINE_ECS_TYPEDEF_H
