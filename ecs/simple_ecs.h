//
// Created by tntrol on 18.05.2022.
//

#ifndef ENGINE_SIMPLE_ECS_H
#define ENGINE_SIMPLE_ECS_H



#include "../utils/timer.h"
#include "../utils/util_counter.h"
#include "../utils/hash_container.h"

#include "../memory/extend_allocator.h"
#include "../memory/linear_allocator.h"
#include "../memory/global_allocator.h"
#include "../memory/stack_allocator.h"
#include "../memory/pool_allocator.h"
#include "../container/extend_pool.h"

#include "../ecs/engine.h"

#include "../type/ecs_typedef.h"
#include "../type/entity.h"
#include "../type/component.h"
#include "../type/system.h"

#include "../ecs/component_manager.h"
//#include "../ecs/entity_manager.h"
#include "../ecs/system_manager.h"

#include "../event/event.h"
#include "../event/ievent_listener.h"
#include "../event/delegate.h"
#include "../event/event_handler.h"





#endif //ENGINE_SIMPLE_ECS_H
