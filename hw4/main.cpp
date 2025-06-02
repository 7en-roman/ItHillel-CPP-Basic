// ДЗ 4. Динамічні масиви

#include <iostream>

using namespace std;

// Перша функція
void CreateArray(float*& arr, int& size) {
    if (arr != nullptr) {
        delete[] arr;
        arr = nullptr;
    }

    size = 20;
    arr = new float[size];

    for (int i = 0; i < size; ++i) {
        arr[i] = i * 1.1f;
    }
}

// Друга функція
void PrintArray(float* arr, int size) {
    if (arr == nullptr) {
        cout << "Масив порожній." << endl;
        return;
    }

    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    float* myArray = nullptr;
    int arraySize = 0;

    CreateArray(myArray, arraySize);
    PrintArray(myArray, arraySize);

    delete[] myArray;
    myArray = nullptr;
    return 0;
}
