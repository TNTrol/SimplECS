////
//// Created by tntrol on 17.05.2022.
////
//#include "tests.h"
//
//class FirstTestEvent : public ECS::Event::Event<FirstTestEvent>
//{
//public:
//    FirstTestEvent()
//    {}
//};
//
//class SecondTestEvent : public ECS::Event::Event<SecondTestEvent>
//{
//public:
//    SecondTestEvent()
//    {}
//};
//
//class ThirdTestEvent : public ECS::Event::Event<ThirdTestEvent>
//{
//public:
//    ThirdTestEvent()
//    {}
//};
//
//class TestListener : public ECS::Event::IEventListener
//{
//    int b;
//public:
//    TestListener()
//    {
//        static int a = 0;
//        b = a++;
//        subscribe(&TestListener::func1);
//        subscribe(&TestListener::func2);
//        subscribe(&TestListener::func3);
//    }
//
//    void func1(const FirstTestEvent *const event)
//    {
//        std::cout << "First event handle " << b << std::endl;
//    }
//
//    void func2(const SecondTestEvent *const event)
//    {
//        std::cout << "Second event handle" << b << std::endl;;
//    }
//
//    void func3(const ThirdTestEvent *const event)
//    {
//        std::cout << "Third event handle" << b << std::endl;;
//    }
//
//};
//
//
//void test_event()
//{
//    std::cout << "\nTest Handler\n";
//    Event::EventHandler eventHandler;
//    TestListener testListener1, testListener2;
//    auto  event =  Event::EventDelegate<TestListener, FirstTestEvent>(&testListener1, &TestListener::func1);
//    auto  event2 =  Event::EventDelegate<TestListener, SecondTestEvent>(&testListener1, &TestListener::func2);
//    auto  event3 =  Event::EventDelegate<TestListener, ThirdTestEvent>(&testListener1, &TestListener::func3);
//    auto  event22 =  Event::EventDelegate<TestListener, SecondTestEvent>(&testListener2, &TestListener::func2);
//    auto  event23 =  Event::EventDelegate<TestListener, ThirdTestEvent>(&testListener2, &TestListener::func3);
//
//
//
//    eventHandler.subscribe<FirstTestEvent>(event);
//    eventHandler.subscribe<SecondTestEvent>(event2);
//    eventHandler.subscribe<ThirdTestEvent>(event3);
//
//    eventHandler.subscribe<SecondTestEvent>(event22);
//    eventHandler.subscribe<ThirdTestEvent>(event23);
//    eventHandler.subscribe<ThirdTestEvent>(event23);
//
//
//    eventHandler.sendEvent<FirstTestEvent>();
//    eventHandler.sendEvent<SecondTestEvent>();
//    eventHandler.sendEvent<ThirdTestEvent>();
//
//    eventHandler.unsubscribe(event23);
//
//    eventHandler.dispatch();
//
//}
