#include <iostream>
#include "./ecs_engine_data/entity.h"
#include "./ecs_engine_data/component.h"
#include "./utils/util_counter.h"
#include "ecs_engine_data/ecs_typedef.h"
#include "./ecs_core/entity_manager.h"

#include "ex.h"

#include "stack"
#include "vector"
#include <queue>

#include "memory_manager/stack_allocator.h"
#include "utils/hash_container.h"
#include "container/pool.h"
#include "memory_manager/pool_allocator.h"

struct node_t
{
    uint32_t a;
    uint32_t b;
};

struct node2_t
{
    uint64_t t;
};

union node_u
{
    struct
    {
        uint32_t a;
        uint32_t b;
    } node;
    uint8_t arr[9];
};

using namespace ECS;
int main()
{
    char *b = new char[30];
//    auto *e4 = new(b) ECS::Entity<int>();
//    auto *e5 = new(b + sizeof(ECS::Entity<int>)) ECS::Entity<int>();
//    auto *l3 = new ECS::Entity<long>();
//    auto *e3 = new ECS::Entity<float>();
    Example<10> arr;

//    std::cout << "Hello, World!" << ECS::Component<int>::STATIC_TYPE <<" " <<  ECS::Component<float>::STATIC_TYPE<<std::endl;
//    ECS::Component<int> *a = new ECS::Component<int>();
//    ECS::Component<long> *b = new ECS::Component<long>();
//    std::stack<float> stack;
//    std::queue<int> q;
//    std::vector<int> vec;
//    std::cout << sizeof(unsigned int );
//    ECS::Util::HashContainer<ECS::IEntity> container(10, 10);
//    container.add(e);
//    container.add(e2);
    ECS::Memory::IAllocator *allocator = new ECS::Memory::StackAllocator(1000, new char[1000]);
//    ECS::Pool<ECS::IEntity> *pool = new ECS::Pool<ECS::IEntity>(allocator, sizeof(ECS::Entity<int>), 8);
//    ECS::Entity<int> *e = new(pool->create()) ECS::Entity<int>();
//    ECS::Entity<int> *e2 = new(pool->create()) ECS::Entity<int>();
//    std::cout << sizeof(e) << "\t" << sizeof(*pool) << "\t" << sizeof(ECS::Memory::PoolAllocator) <<"\t" << sizeof(ECS::Memory::IAllocator)<< "\t" << sizeof(pool) << std::endl;
//    e->setActive(true);
//    e2->setActive(true);
////    for (ECS::IEntity  *e1: (*pool))
////    {
////        std::cout << "H\n";
////        e1->isActive();
////    }
//    for(auto it = pool->begin<ECS::Entity<int>>(); it != pool->end<ECS::Entity<int>>(); ++it)
//    {
//        ECS::Entity<int> *e = *it;
//        std::cout << "H\n";
//    }

    ECS::EntityManager entityManager(nullptr, 8, 8, allocator);
    ECS::Entity<int> *e = entityManager.createEntity<ECS::Entity<int>>();
    ECS::Entity<int> *e2 = entityManager.createEntity<ECS::Entity<int>>();
    ECS::Entity<float> *ef = entityManager.createEntity<ECS::Entity<float>>();
//    for(auto it = entityManager.getContainer<Entity<int>>()->begin<ECS::Entity<int>>(); it != entityManager.getContainer<Entity<int>>()->end<ECS::Entity<int>>(); ++it)
//    {
//        ECS::Entity<int> *e = *it;
//        std::cout << "H\n";
//    }
    for(auto  it = entityManager.begin<Entity<float>>(); it != entityManager.end<Entity<float>>(); ++it)
    {
        std::cout << "H\n";
        std::cout << sizeof(it) << "\t" << sizeof(entityManager) << "\t" << sizeof(Util::HashContainer<int>);
    }

    return 0;
}
