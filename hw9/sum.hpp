#ifndef _SUM_HPP_
#define _SUM_HPP_

#include <string>

struct TestStruct
{
    int a = 0;
    double b = 0;
};

template <typename TypeA, typename TypeB>
TypeB Sum(TypeA a, TypeB b)
{
    return a + b;
}

unsigned int Sum(std::string a, std::string b)
{
    return a.size() + b.size();
}

template <>
TestStruct Sum(TestStruct a, TestStruct b)
{
    TestStruct res;
    res.a = a.a + b.a;
    res.b = a.b + b.b;
    return res;
}

template <typename TypeA>
double Sum(TypeA a, double b)
{
    return (a + b) * 2;
}

#endif // _SUM_HPP_
