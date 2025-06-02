// ДЗ 3. Вказівники (Практичне)

#include <iostream>

using namespace std;

void managePointer(int*& ptr) {
    if (ptr == nullptr) {
        ptr = new int(455);
        cout << "New memory with the value: " << *ptr << endl;
    }

    else {
        delete ptr;
        ptr = new int(320);
        cout << "The old memory is freed and a new value is assigned: " << *ptr << endl;
    }
}

int main() {
    int* a = nullptr;
    managePointer(a);
    cout << "The value of \"A\" after the first call: " << *a << endl;

    managePointer(a);
    cout << "The value of \"A\" after the second call: " << *a << endl;

    delete a;
    a = nullptr;

    return 0;
}
