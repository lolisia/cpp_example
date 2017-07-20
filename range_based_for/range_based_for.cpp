#include "stdafx.h"
#include <vector>
#include <map>
#include <iostream>

void copy_for()
{
    std::vector<int> v{ 1, 2, 3, 4, 5 };

    for (auto i : v)
        std::cout << i << " ";
    std::cout << std::endl;
}

void no_copy_for()
{
    std::vector<int> v{ 1, 2, 3, 4, 5 };

    for (auto& i : v)
        std::cout << i << " ";
    std::cout << std::endl;
}

void no_copy_cosnt_for()
{
    std::vector<int> v{ 1, 2, 3, 4, 5 };

    for (const auto& i : v)
        std::cout << i << " ";
    std::cout << std::endl;
}

void init_for()
{
    for (int i : {0, 1, 2, 3, 4, 5})
        std::cout << i << " ";
    std::cout << std::endl;
}

void array_for()
{
    int a[]{ 6, 7, 8, 9, 10, 11 };
    for (int i : a)
        std::cout << i << " ";
    std::cout << std::endl;
}

void map_for()
{
    std::map<int, int> a{ {1, 10}, {2, 9}, {3, 8}, {4, 7} };
    for (const auto& v : a)
        std::cout << "(" << v.first << ":" << v.second << ") ";
    std::cout << std::endl;

    // structured binding. Not yet supported.
    /*
    for (const auto& [k, v] : a)
        std::cout << "(" << k << ":" << v << ") ";
    std::cout << std::endl;\
    */
}

int main()
{
    copy_for();
    no_copy_for();
    no_copy_cosnt_for();
    init_for();
    array_for();
    map_for();
    return 0;
}
