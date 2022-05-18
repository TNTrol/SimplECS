////
//// Created by tntrol on 17.05.2022.
////
//




#include "tests.h"
//
#include <iostream>
#include "../type/entity.h"
#include "../type/component.h"
#include "../ecs/entity_manager.h"
#include "../ecs/component_manager.h"
#include "../memory/linear_allocator.h"

using namespace ECS;

void test_manager()
{
//    ECS::Memory::IAllocator *allocator = new ECS::Memory::LinearAllocator(10000, new char[10000]);
//    ComponentManager componentManager(8, 8, allocator);
//    ECS::EntityManager entityManager(&componentManager, 8, 8, allocator);
//    auto *e = entityManager.createEntity<ECS::Entity<int>>();
//    auto *e2 = entityManager.createEntity<ECS::Entity<int>>();
//    auto *ef = entityManager.createEntity<ECS::Entity<float>>();
//    for (auto it: entityManager.getAllOfType<Entity<int>>())
//    {
//        (it)->setActive(true);
//        std::cout << "H\n";
//        //std::cout << sizeof(it) << "\t" << sizeof(entityManager) << "\t" << sizeof(Util::HashContainer<int>) << "\t";
//    }
//
//    std::cout << "\n" << sizeof(Container::Iterator<int>) << "\t" << sizeof(Util::HashContainer<IComponent>) << "\t"
//              << sizeof(ComponentManager::Iterator);
//
//    std::cout << "Test component manager\n";
//    auto *c = componentManager.createComponent<Component<float>>(ef->getId());
//    auto *c2 = componentManager.createComponent<Component<int>>(e->getId());
//    auto *c3 = componentManager.createComponent<Component<float>>(e->getId());
//    componentManager.destroyComponentOfEntity<Component<float>>(e->getId());
//    for (auto it: componentManager.getAllComponentsOfType<Component<int>>())
//    {
//        std::cout << "HA\n";
//    }
//    std::cout << std::endl;
//
//    for (auto it : componentManager.getComponentsOfEntity(e->getId()))
//    {
//        std::cout << "La\n";
//    }
//
//    delete ((uint8_t*)allocator->get_source_ptr());
}