#include <iostream>
#include "./ecs_engine_data/entity.h"
#include "./ecs_engine_data/component.h"
#include "./utils/util_counter.h"
#include "./support_class/helper_typedef.h"

#include "ex.h"
struct ABC
{
    int a;
};


#include "stack"
#include "vector"
#include <queue>

#include "memory_manager/stack_allocator.h"
#include "./support_class/container_object.h"

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

int main()
{
    auto *e = new ECS::Entity<int>();
    auto *e2 = new ECS::Entity<int>();
    auto *l3 = new ECS::Entity<long>();
    auto *e3 = new ECS::Entity<float>();
    Example<10> arr;

//    std::cout << "Hello, World!" << ECS::Component<int>::STATIC_TYPE <<" " <<  ECS::Component<float>::STATIC_TYPE<<std::endl;
//    ECS::Component<int> *a = new ECS::Component<int>();
//    ECS::Component<long> *b = new ECS::Component<long>();
//    std::stack<float> stack;
//    std::queue<int> q;
//    std::vector<int> vec;
//    std::cout << sizeof(unsigned int );
    ECS::ContainerObject<ECS::IEntity> container(10, 10);
    container.add(e);
    container.add(e2);
    node_u node;
    std::cout << sizeof(node);
    return 0;
}
