#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <list>

template<typename T>
typename T::iterator easyfind(T &container, int test){
    typename T::iterator it = std::find(container.begin(), container.end(), test);
    if (container.begin() == container.end())
        throw std::runtime_error("Container is empty");
    if (it == container.end())
        throw std::runtime_error("Element not found in container");
    return it;
}

template<typename T>
typename T::const_iterator easyfind(const T &container, int test) {
    typename T::const_iterator it = std::find(container.begin(), container.end(), test);
    if (container.begin() == container.end())
        throw std::runtime_error("Container is empty");
    if (it == container.end())
        throw std::runtime_error("Element not found in container");
    return it;
}

#endif