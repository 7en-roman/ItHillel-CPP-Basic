#ifndef _CLEAR_PTR_HPP_
#define _CLEAR_PTR_HPP_

#include <map>

// Основна шаблонна функція
template <typename T>
void ClearPtr(T*& ptr)
{
    if (ptr != nullptr)
    {
        delete ptr;
        ptr = nullptr;
    }
}

// Спеціалізація для std::map<int, T>
template <typename T>
int ClearPtr(std::map<int, T>*& ptr)
{
    if (ptr == nullptr)
        return -1;

    int size = static_cast<int>(ptr->size());
    delete ptr;
    ptr = nullptr;
    return size;
}

#endif // _CLEAR_PTR_HPP_
