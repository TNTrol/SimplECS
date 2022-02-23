#include <iostream>
#include "./ecs_engine_data/entity.h"
#include "./ecs_engine_data/component.h"
#include "./utils/util_counter.h"
#include "ecs_engine_data/ecs_typedef.h"
#include "./ecs_core/entity_manager.h"
#include "./ecs_core/component_manager.h"

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


class Base
{
private:
  int a;
public:
  int get_a()
  {
    return a;
  }
};

class C1: public Base
{
private:
  char s;
public:
  int get_s()
  {
    return s;
  }
};

using namespace ECS;
int main()
{
    char *b = new char[30];
    Example<10> arr;

    ECS::Memory::IAllocator *allocator = new ECS::Memory::StackAllocator(1000, new char[1000]);
    ComponentManager componentManager(8, 8, allocator);
    ECS::EntityManager entityManager(&componentManager, 8, 8, allocator);
    auto *e = entityManager.createEntity<ECS::Entity<int>>();
    auto *e2 = entityManager.createEntity<ECS::Entity<int>>();
    auto *ef = entityManager.createEntity<ECS::Entity<float>>();
    for(auto  it = entityManager.begin<Entity<float>>(); it != entityManager.end<Entity<float>>(); ++it)
    {
        (*it)->setActive(true);
        std::cout << "H\n";
        std::cout << sizeof(it) << "\t" << sizeof(entityManager) << "\t" << sizeof(Util::HashContainer<int>) << "\t" << sizeof(C1);
    }
    std::vector<int> vec(10, 1);

    std::cout << "\n" << sizeof(ComponentManager) << "\t" << sizeof(Util::HashContainer<IComponent> ) << "\t" << sizeof(ComponentManager::Iterator);

    auto *c = componentManager.createComponent<Component<float>>(ef->getId());
    auto *c2 = componentManager.createComponent<Component<int>>(e->getId());
    auto *c3 = componentManager.createComponent<Component<float>>(e->getId());
    for(auto it = componentManager.begin<Component<int>>(); it != componentManager.end<Component<int>>(); ++it)
    {
        IComponent *component = *(it);
        std::cout << "HA";
    }
    std::cout << std::endl;

    auto end = componentManager.endAllComponentsOfEntity(e->getId());
    for(auto it = componentManager.beginAllComponentsOfEntity(e2->getId()); it != componentManager.endAllComponentsOfEntity(e2->getId()); ++it)
    {
        IComponent *component = *(it);
        std::cout << "La";
    }
    /**
     *
     * int arr[3];
     * int arr3[3][10];
     * memcpy(arr3, arr_src, sizeof(arr3));
     *
     * int **arr_temp = new int*[N];
     * for(....)
     * {
     *  arr_temp[i] = new int[N];
     * }
     * ...
     * for(int i = 0; i < N; ++i)
     * {
     *      memcpy(arr_temp[i], arr_src[i], sizeof(int) * N);
     * }
     */
    return 0;
}
