// practice03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "mathyStuff.h"




int main()
{
    Rectangle r{ 3,4 };

    std::cout << add(2,3) << "\n";
    std::cout << doubleValue(99) << "\n";
    std::cout << r.area() << "\n";
}