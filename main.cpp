#include "tests/tests.h"

#include "stdint.h"
#include <iostream>

class Test
{
    Test(){}
};

class Test2: public Test
{
    uint32_t test[3];
};

int main()
{
//    test_manager();
//    test_event();
//    test_memory();
    test_engine();
    std::cout << sizeof (Test2);
    return 0;
}
