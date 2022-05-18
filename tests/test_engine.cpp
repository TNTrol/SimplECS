//
// Created by tntrol on 18.05.2022.
//
#include "tests.h"
#include "../ecs/API.h"
#include "../ecs/engine.h"
#include "../type/entity.h"
#include "../type/component.h"
#include "../ecs/entity_manager.h"
#include "../ecs/component_manager.h"

#include <iostream>

class Player: public ECS::Entity<Player>
{
public:
    Player()= default;
    void print()
    {
        std::cout << "Player#" << getId() << std::endl;
    }
};

ECS_ENTITY(Bomb)
{
public:
    Bomb() = default;
    void bomb()
    {
        std::cout << "Bomb[]" << getId() << std::endl;
    }
};

ECS_COMPONENT(Health)
{
public:
    Health() = default;
    void health()
    {
        std::cout << "Health[" << getId() << "," << getOwner() << "]\n";
    }
};

ECS_COMPONENT(Damage)
{
public:
    Damage() = default;
    void damage()
    {
        std::cout << "Damage[" << getId() << "," << getOwner() << "]\n";
    }
};


void test_engine()
{
    ECS::initialize();
    ECS::Engine *engine = ECS::SEngine;
    auto *entity_m = engine->getEntityManager();
    auto *component_m = engine->getComponentManager();

    auto *player1 = entity_m->createEntity<Player>();
    auto *player2 = entity_m->createEntity<Player>();
    auto *player3 = entity_m->createEntity<Player>();
    auto *bomb1 = entity_m->createEntity<Bomb>();
    auto *bomb2 = entity_m->createEntity<Bomb>();

    auto *health1 = component_m->createComponent<Health>(player1->getId());
    auto *health2 = component_m->createComponent<Health>(player2->getId());
    auto *health3 = component_m->createComponent<Health>(player3->getId());

    auto *damage1 = component_m->createComponent<Damage>(player1->getId());
    auto *damage2 = component_m->createComponent<Damage>(player2->getId());
    auto *damage3 = component_m->createComponent<Damage>(player3->getId());
    auto *damage4 = component_m->createComponent<Damage>(bomb1->getId());
    auto *damage5 = component_m->createComponent<Damage>(bomb2->getId());

    for (auto *e : entity_m->getAllOfType<Player>())
    {
        e->print();
    }

    for (auto *e : entity_m->getAllOfType<Bomb>())
    {
        e->bomb();
    }

    for (auto *e : component_m->getComponentsOfEntity(player1->getId()))
    {
        std::cout << e->getOwner() << std::endl;
    }

    for (auto *c : component_m->getAllComponentsOfType<Damage>())
    {
        c->damage();
    }

    ECS::termite();
}