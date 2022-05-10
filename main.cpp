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
#include <functional>

#include "memory_manager/stack_allocator.h"
#include "utils/hash_container.h"
#include "container/pool.h"
#include "memory_manager/pool_allocator.h"
#include "list"

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

struct Test
{
    std::vector<int> arr;
    uint64_t t;
};

typedef void (*handler)(int);

struct TestHandler
{
    //typedef void (*Callback)(int);
    int x;
    TestHandler(int x){ this->x = x;}
    void print(int y){ std::cout << x + y << std::endl;}
};

class IEventDelegate
{
public:

    virtual inline void invoke(int) = 0;
}; // class IEventDelegate

template<class Class>
class EventDelegate : public IEventDelegate
{
    typedef void(Class::*Callback)(int);

    Class* m_Receiver;
    Callback m_Callback;

public:

    EventDelegate(Class* receiver, Callback& callbackFunction) :
            m_Receiver(receiver),
            m_Callback(callbackFunction)
    {}

    void invoke(int a) override
    {
        (m_Receiver->*m_Callback)(a);
    }

}; // class EventDelegate

template<class C, class E>
inline IEventDelegate* RegisterEventCallback(C* obj, void(C::*Callback)(E))
{

    IEventDelegate* eventDelegate = new EventDelegate<C>(static_cast<C*>(obj), Callback);
    return eventDelegate;
}

using namespace ECS;
int main()
{
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
    for(auto it = componentManager.beginAllComponentsOfEntity(e->getId()); it != componentManager.endAllComponentsOfEntity(e->getId()); ++it)
    {
        IComponent *component = *(it);
        std::cout << "La " << sizeof(Test);
    }

    std::cout << "\nTest Handler\n" << sizeof(std::list<void *>);

    TestHandler testHandler1(10), testHandler2(30);
//    EventDelegate<TestHandler> eventDelegate1(&testHandler1, testHandler1.print);
//    handler *func1 = testHandler1.print;
    //TestHandler::Callback h =  []( int b ){std::cout << b;};
//    IEventDelegate *w =  RegisterEventCallback(&testHandler1, &TestHandler::print);
//    w->invoke(10);

    return 0;
}
