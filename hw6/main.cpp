// ДЗ 6. Контейнери vector та set

#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

void printVector(const vector<string>& vec) {
    cout << "*** Vector CONTENT ***" << endl;
    for (const string& str : vec)
        cout << str << endl;
}

void printSet(const set<string>& st) {
    cout << "*** SET CONTENT ***" << endl;
    for (const string& str : st)
        cout << str << endl;
}

int main() {
    vector<string> names = {"Tom", "Roman", "Ivan", "Emma"};
    printVector(names);

    cout << "\n";

    set<string> uniqueNames = {"Tom", "Ivan", "Roman", "Emma", "Tom"};
    printSet(uniqueNames);

    return 0;
}
