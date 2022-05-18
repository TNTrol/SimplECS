//
// Created by tntrol on 16.09.2021.
//

#ifndef ENGINE_API_H
#define ENGINE_API_H

#define DESTROY_SIZE_STACK 100
#define DESTROY_GROW_STACK 12
#define ENTITY_SIZE_STACK 1024
#define ENTITY_GROW_STACK 100
#define COMPONENT_SIZE_STACK 5120
#define COMPONENT_GROW_SACK 512
#define COMPONENT_CHUNK_STACK 100
#define COUNT_ENTITY_TAG 10
#define EVENT_SIZE_STACK 100
#define EVENT_GROW_STACK 50
#define EVENT_DELEGATE_SIZE 100
#define EVENT_MEMORY_BUFFER_SIZE        4194304
#define SYSTEM_MEMORY_BUFFER_SIZE        8388608
#define BUFFER_SIZE        (8388608 * 16)
#define ENTITY_MAX 1000
#define DESTROY_MAX 1000
#define EVENT_MAX 1000

//#include "engine.h"

namespace ECS
{
    class Engine;

    extern Engine *SEngine;

    void initialize();

    void termite();
}

#endif //ENGINE_API_H
