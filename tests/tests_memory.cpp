//
// Created by tntrol on 17.05.2022.
//
#include "tests.h"

class TestMemory : public Memory::IFactoryAllocator
{
    Memory::LinearAllocator linearAllocator;
public:
    TestMemory() :
            linearAllocator(1000, new char[1000])
    {}

    Memory::IAllocator *create() override
    {
        return new Memory::PoolAllocator(&linearAllocator, 4 * 4, 3);
    }

    void delete_allocator(Memory::IAllocator *allocator) override
    {
        delete ((Memory::PoolAllocator *) allocator);
    }
};

void test_memory()
{
    std::cout << "\nTest memory\n";

    TestMemory testMemory;

    Memory::ExtendMemory<Memory::PoolAllocator> extendMemory(&testMemory);
    uint32_t *t = nullptr;
    for (int i = 0; i < 5; ++i)
    {

        uint32_t *t1 = (uint32_t *) extendMemory.allocate(4 * 4);
        t1[0] = 255 + i;
        t1[1] = i;
        t1[2] = 2550 + i;
        t1[3] = 50 + i;
        if (i == 1)
            t = t1;
    }

    for (auto all: extendMemory)
    {
        for (auto a: *all)
        {
            uint32_t *b = ((uint32_t *) a);
            for (int i = 0; i < 4; ++i)
            {
                uint32_t c = b[i];
                std::cout << c << std::endl;
            }
        }
    }

    extendMemory.free(t);

    std::cout << "\nOutput\n";
    for (auto all: extendMemory)
    {
        for (auto a: *all)
        {
            uint32_t *b = ((uint32_t *) a);
            for (int i = 0; i < 4; ++i)
            {
                uint32_t c = b[i];
                std::cout << c << std::endl;
            }
        }
    }
    uint32_t *t1 = (uint32_t *) extendMemory.allocate(4 * 4);
    t1[0] = 666;
    t1[1] = 66;
    t1[2] = 2566;
    t1[3] = 56;
    std::cout << "\nOutput\n";
    for (auto all: extendMemory)
    {
        for (auto a: *all)
        {
            uint32_t *b = ((uint32_t *) a);
            for (int i = 0; i < 4; ++i)
            {
                uint32_t c = b[i];
                std::cout << c << std::endl;
            }
        }
    }
}