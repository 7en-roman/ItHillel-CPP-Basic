// ДЗ 5. Класи

#include <iostream>
#include <string>

using namespace std;

class Numbers {
private:
    int number1;
    int number2;

public:
    void set(int a, int b) {
        number1 = a;
        number2 = b;
    }
    void print() {
        cout << "\n Number 1 -> " << number1 << "\n Number 2 -> " << number2 << endl;
    }
};

class Ball {
    string m_color;
    double m_radius;

public:
    Ball() {
        m_color = "Red";
        m_radius = 20.0;
    }
    Ball(string color) {
        m_color = color;
        m_radius = 20.0;
    }
    Ball(double radius) {
        m_color = "Red";
        m_radius = radius;
    }
    Ball(string color, double radius) {
        m_color = color;
        m_radius = radius;
    }

    void print() {
        cout << "Ball: Color -> " << m_color << ", Radius -> " << m_radius << endl;
    }
};

int main() {
    Numbers nums;
    nums.set(5, 10);
    nums.print();

    Ball b1;
    Ball b2("Green");
    Ball b3(30.5);
    Ball b4("Blue", 25.0);

    b1.print();
    b2.print();
    b3.print();
    b4.print();

    return 0;
}
