#pragma once
#include <type_traits>

template<typename T>
auto absoluteValue(T lhs, T rhs) {
    using ReturnType = std::conditional_t<std::is_same<T, char>::value, int, T>;

    ReturnType result;
    result = (lhs - rhs >= 0) ? lhs - rhs : rhs - lhs;

    return result;
}