#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <set>

using TwoValueReturn = std::pair<int, bool>;

TwoValueReturn two_value_return()
{
    return TwoValueReturn(1, true);
}

// Not yet supported.
void set_insert()
{
    /*
    std::set<std::string> strset;
    if (auto [iter, success] = strset.insert("Hello"); success)
        std::cout << "insert success. value:" << std::quoted(*iter) << std::endl;
    else
        std::cout << "insert success. value:" << std::quoted(*iter) << std::endl;
    */
}

// Not yet supported.
void test1()
{
    /*
    const auto[x, y] = two_value_return();
    x = 1;
    y = true;
    */
}

int main()
{
    set_insert();
    test1();
    return 0;
}

