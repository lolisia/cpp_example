#include "stdafx.h"

// need additional compile option "/std:c++latest" for static_assert
// https://docs.microsoft.com/en-us/cpp/error-messages/compiler-errors-1/compiler-error-c2429

struct no_default_constructor
{
    no_default_constructor() = delete;
};

template<typename T> struct check_default_constructor
{
    static_assert(std::is_default_constructible<T>::value, "no default constructor");   // C++11 static_assert with message
    static_assert(std::is_default_constructible<T>::value);                             // C++17 static_assert without message
};

int main()
{
    // check_default_constructor<no_default_constructor> error; // compile error!

    return 0;
}
