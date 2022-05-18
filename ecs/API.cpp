//
// Created by tntrol on 18.05.2022.
//

#include "API.h"
#include "engine.h"

namespace ECS
{
    Engine *SEngine = nullptr;

    void initialize()
    {
        if(!SEngine)
        {
            SEngine = new Engine();
        }

    }

    void termite()
    {
        delete SEngine;
    }
}
