// ДЗ 10. ПІДСУМКОВЕ ЗАВДАННЯ КУРСУ

#include "MyVector.h"

int main() {
    MyVector<int> vec;

    vec.push_back(7);
    vec.push_back(14);
    vec.push_back(21);

    std::cout << "Size: " << vec.size() << std::endl;
    std::cout << "Elements: " << vec << std::endl;

    vec.remove_at(1);
    std::cout << "After removal -> " << vec << std::endl;

    std::cout << "Iterating manually -> ";
    for (MyVector<int>::Iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }

    std::cout << "\nClearing vector..." << std::endl;
    vec.clear();
    std::cout << "Size after clear -> " << vec.size() << std::endl;

    return 0;
}
