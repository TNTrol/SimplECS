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
    ECS::Memory::IAllocator *allocator = new ECS::Memory::StackAllocator(70);
    int*g = nullptr;
    int *c_arr[5];
    for(int i = 0; i < 5; ++i)
    {
        void *a = allocator->allocate(sizeof(int));
        c_arr[i] = new (a) int(i);
    }
    for(int i = 0; i < 5; ++i)
    {
        allocator->free(c_arr[i]);
    }
    for(int i = 0; i < 5; ++i)
    {
        void *a = allocator->allocate(sizeof(int));
        c_arr[i] = new (a) int(i);
    }
    return 0;
}
