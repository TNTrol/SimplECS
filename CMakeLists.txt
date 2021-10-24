cmake_minimum_required(VERSION 3.19)
project(Engine)

set(CMAKE_CXX_STANDARD 14)

add_executable(Engine main.cpp utils/util_counter.h support_class/helper_typedef.h ecs_engine_data/entity.h ecs_engine_data/ientity.h ecs_engine_data/icomponent.h ecs_engine_data/component.h ecs_engine_data/isystem.h ecs_engine_data/system.h ecs_core/entity_manager.cpp ecs_core/entity_manager.h support_class/icontainer.h ecs_core/component_manager.cpp ecs_core/component_manager.h support_class/impl/componets_of_entity.h ex.h ecs_core/API.h support_class/icomponent_of_entity.h support_class/impl/component_container.cpp support_class/impl/component_container.h support_class/impl/entity_container.cpp support_class/impl/entity_container.h support_class/iterator.cpp support_class/iterator.h memory_manager/iallocator.h memory_manager/stack_allocator.cpp memory_manager/stack_allocator.h memory_manager/linear_allocator.cpp memory_manager/linear_allocator.h)