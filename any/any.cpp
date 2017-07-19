#include "stdafx.h"
#include <any>
#include <iostream>

void any()
{
    std::any a;
    a = 1;

    std::cout << "a:" << std::any_cast<int>(a) << std::endl;
}

void any_cast()
{
    try
    {
        std::any a;
        a = 1;

        std::cout << "a:" << std::any_cast<float>(a) << std::endl;

    }
    catch (const std::bad_any_cast& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}

void any_cast2()
{
    try
    {
        std::any a = 1;
        int* p = std::any_cast<int>(&a);
        std::cout << "p:" << *p << std::endl;
    }
    catch (const std::bad_any_cast& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}

void any_reset()
{
    std::any a(1);
    std::cout << "a:" << std::any_cast<int>(a) << std::endl;

    a.reset();
    if (!a.has_value())
        std::cout << "a has_value() false" << std::endl;

    a = 2;
    std::cout << "a:" << std::any_cast<int>(a) << std::endl;
}

void any_swap()
{
    std::any a(1);
    std::any b(false);

    a.swap(b);

    std::cout << "swap a:" << std::any_cast<bool>(a) << std::endl;
    std::cout << "swap b:" << std::any_cast<int>(b) << std::endl;

    std::any c(1);
    std::any d(false);

    std::swap(c, d);

    std::cout << "swap c:" << std::any_cast<bool>(c) << std::endl;
    std::cout << "swap d:" << std::any_cast<int>(d) << std::endl;
}

void any_type()
{
    std::any a(1);
    std::cout << "a type:" << a.type().name() << std::endl;

    std::any b(false);
    std::cout << "b type:" << b.type().name() << std::endl;

    std::any c(1.1f);
    std::cout << "c type:" << c.type().name() << std::endl;

    std::any d("string type");
    std::cout << "d type:" << d.type().name() << std::endl;

    std::any e(std::string("string type"));
    std::cout << "e type:" << e.type().name() << std::endl;

    std::any f(std::wstring(L"string type"));
    std::cout << "f type:" << f.type().name() << std::endl;
}

void make_any()
{
    auto a = std::make_any<int>(1);
    std::cout << "make_any a:" << std::any_cast<int>(a) << std::endl;

    auto b(std::make_any<int>(2));
    std::cout << "make_any b:" << std::any_cast<int>(b) << std::endl;
}

int main()
{
    any();
    any_cast();
    any_cast2();
    any_reset();
    any_swap();
    any_type();
    make_any();
    return 0;
}