// ДЗ 9. Шаблонні функції

#include <iostream>
#include <string>
#include <map>

#include "sum.hpp"
#include "clear_ptr.hpp"

using namespace std;

int main()
{
    cout << "*** Sum Функції ***" << endl;
    cout << "Sum(double, double): " << Sum(55.5555, 12.5555) << "\n";
    cout << "Sum(string, string): " << Sum(string("first"), string("_second")) << "\n";
    cout << "Sum(int, float): " << Sum(3, 6.555f) << "\n";

    cout << "\n*** ClearPtr Функції ***" << endl;

    int* myInt = new int(42);
    ClearPtr(myInt);
    cout << "myInt: " << (myInt == nullptr ? "очищено" : "не очищено") << endl;

    map<int, string>* myMap = new map<int, string>();
    (*myMap)[1] = "ONE";
    (*myMap)[2] = "TWO";

    int removedCount = ClearPtr(myMap);
    cout << "Кількість елементів до очищення: " << removedCount << "\n";
    cout << "myMap: " << (myMap == nullptr ? "очищено" : "не очищено") << endl;

    map<int, string>* nullMap = nullptr;
    cout << "Null map: " << ClearPtr(nullMap) << "\n";

    return 0;
}
