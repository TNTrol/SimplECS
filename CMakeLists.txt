cmake_minimum_required(VERSION 3.19)
project(Engine)

set(CMAKE_CXX_STANDARD 14)

add_executable(Engine main.cpp utils/util_counter.h ecs_engine_data/ecs_typedef.h ecs_engine_data/entity.h ecs_engine_data/ientity.h ecs_engine_data/icomponent.h ecs_engine_data/component.h ecs_engine_data/isystem.h ecs_engine_data/system.h ecs/entity_manager.cpp ecs/entity_manager.h ecs/component_manager.cpp ecs/component_manager.h ex.h ecs/API.h utils/hash_container.h memory/iallocator.h memory/stack_allocator.cpp memory/stack_allocator.h memory/linear_allocator.cpp memory/linear_allocator.h memory/pool_allocator.h container/pool.h memory/pool_allocator.cpp ecs/system_manager.cpp ecs/system_manager.h event/ievent.h event/event.h event/event_handler.cpp event/event_handler.h event/delegate.h event/ievent_listener.h event/dispatcher.cpp event/dispatcher.h ecs/engine.cpp ecs/engine.h utils/timer.cpp utils/timer.h memory/extend_memory.h)