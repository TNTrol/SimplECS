#include <iostream>
#include "./ecs_engine_data/entity.h"
#include "./ecs_engine_data/component.h"
#include "./utils/util_counter.h"
#include "ecs_engine_data/ecs_typedef.h"
#include "./ecs_core/entity_manager.h"
#include "./ecs_core/component_manager.h"

#include "ex.h"
#include "vector"
#include "memory_manager/stack_allocator.h"
#include "utils/hash_container.h"
#include "container/pool.h"
#include "memory_manager/pool_allocator.h"
#include "event/event.h"
#include "event/ievent_listener.h"
#include "event/delegate.h"
#include "event/event_handler.h"
#include "list"

struct TestHandler
{
    //typedef void (*Callback)(int);
    int x;

    TestHandler(int x)
    { this->x = x; }

    void print(int y)
    { std::cout << x + y << std::endl; }
};

class FirstTestEvent : public ECS::Event::Event<FirstTestEvent>
{
public:
    FirstTestEvent()
    {}
};

class SecondTestEvent : public ECS::Event::Event<SecondTestEvent>
{
public:
    SecondTestEvent()
    {}
};

class ThirdTestEvent : public ECS::Event::Event<ThirdTestEvent>
{
public:
    ThirdTestEvent()
    {}
};

class TestListener : public ECS::Event::IEventListener
{
    int b;
public:
    TestListener()
    {
        static int a = 0;
        b = a++;
        subscribe(&TestListener::func1);
        subscribe(&TestListener::func2);
        subscribe(&TestListener::func3);
    }

    void func1(const FirstTestEvent *const event)
    {
        std::cout << "First event handle " << b << std::endl;
    }

    void func2(const SecondTestEvent *const event)
    {
        std::cout << "Second event handle" << b << std::endl;;
    }

    void func3(const ThirdTestEvent *const event)
    {
        std::cout << "Third event handle" << b << std::endl;;
    }

};

using namespace ECS;

int main()
{
    ECS::Memory::IAllocator *allocator = new ECS::Memory::StackAllocator(1000, new char[1000]);
    ComponentManager componentManager(8, 8, allocator);
    ECS::EntityManager entityManager(&componentManager, 8, 8, allocator);
    auto *e = entityManager.createEntity<ECS::Entity<int>>();
    auto *e2 = entityManager.createEntity<ECS::Entity<int>>();
    auto *ef = entityManager.createEntity<ECS::Entity<float>>();
    for (auto it = entityManager.begin<Entity<float>>(); it != entityManager.end<Entity<float>>(); ++it)
    {
        (*it)->setActive(true);
        std::cout << "H\n";
        std::cout << sizeof(it) << "\t" << sizeof(entityManager) << "\t" << sizeof(Util::HashContainer<int>) << "\t";
    }
    std::vector<int> vec(10, 1);

    std::cout << "\n" << sizeof(ComponentManager) << "\t" << sizeof(Util::HashContainer<IComponent>) << "\t"
              << sizeof(ComponentManager::Iterator);

    auto *c = componentManager.createComponent<Component<float>>(ef->getId());
    auto *c2 = componentManager.createComponent<Component<int>>(e->getId());
    auto *c3 = componentManager.createComponent<Component<float>>(e->getId());
    for (auto it = componentManager.begin<Component<int>>(); it != componentManager.end<Component<int>>(); ++it)
    {
        IComponent *component = *(it);
        std::cout << "HA";
    }
    std::cout << std::endl;

    auto end = componentManager.endAllComponentsOfEntity(e->getId());
    for (auto it = componentManager.beginAllComponentsOfEntity(e->getId());
         it != componentManager.endAllComponentsOfEntity(e->getId()); ++it)
    {
        IComponent *component = *(it);
        std::cout << "La\n";
    }

    std::cout << "\nTest Handler\n";

    Event::EventHandler eventHandler;
    TestListener testListener1, testListener2;
    auto  event =  Event::EventDelegate<TestListener, FirstTestEvent>(&testListener1, &TestListener::func1);
    auto  event2 =  Event::EventDelegate<TestListener, SecondTestEvent>(&testListener1, &TestListener::func2);
    auto  event3 =  Event::EventDelegate<TestListener, ThirdTestEvent>(&testListener1, &TestListener::func3);
    auto  event22 =  Event::EventDelegate<TestListener, SecondTestEvent>(&testListener2, &TestListener::func2);
    auto  event23 =  Event::EventDelegate<TestListener, ThirdTestEvent>(&testListener2, &TestListener::func3);



    eventHandler.subscribe<FirstTestEvent>(event);
    eventHandler.subscribe<SecondTestEvent>(event2);
    eventHandler.subscribe<ThirdTestEvent>(event3);

    eventHandler.subscribe<SecondTestEvent>(event22);
    eventHandler.subscribe<ThirdTestEvent>(event23);
    eventHandler.subscribe<ThirdTestEvent>(event23);


    eventHandler.sendEvent<FirstTestEvent>();
    eventHandler.sendEvent<SecondTestEvent>();
    eventHandler.sendEvent<ThirdTestEvent>();

    eventHandler.unsubscribe(event23);

    eventHandler.dispatch();
    return 0;
}
