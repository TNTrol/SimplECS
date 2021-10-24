//
// Created by tntrol on 12.09.2021.
//

#ifndef ENGINE_EX_H
#define ENGINE_EX_H
#include "iostream"
template<int COUNT>
class Example
{
protected:
    int arr[COUNT];
public:
    Example()
    {
        std::cout<< COUNT << "Hi!\n" ;
    }
};
#endif //ENGINE_EX_H
