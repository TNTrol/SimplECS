//
// Created by tntrol on 17.05.2022.
//

#ifndef ENGINE_TESTS_H
#define ENGINE_TESTS_H

#include <iostream>
#include "../ecs_engine_data/entity.h"
#include "../ecs_engine_data/component.h"
#include "../utils/util_counter.h"
#include "../ecs_engine_data/ecs_typedef.h"
#include "../ecs/entity_manager.h"
#include "../ecs/component_manager.h"

#include "vector"
#include "../memory/stack_allocator.h"
#include "../utils/hash_container.h"
#include "../container/pool.h"
#include "../memory/pool_allocator.h"
#include "../event/event.h"
#include "../event/ievent_listener.h"
#include "../event/delegate.h"
#include "../event/event_handler.h"
#include "list"
#include "../memory/extend_allocator.h"
#include "../memory/linear_allocator.h"

using namespace ECS;

void test_memory();

void test_event();

void test_manager();

#endif //ENGINE_TESTS_H
