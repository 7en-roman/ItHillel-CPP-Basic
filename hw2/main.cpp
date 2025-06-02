// ДЗ 2. Створити свійт тип даних та попрацювати з масивом таких даних

#include <iostream>
#include <string>

struct Fruit {
    std::string fruitName[3];   // Назва фруктів
    float fruitWeight;  // Вага
    std::string expirationDate; // Кінець придатності
    
    unsigned short int fruitCount;  // Кількість фруктів
};

int main() {
    // Варіант #1
    
    Fruit food;
    std::string fruits[3];
    
    food.fruitCount = 1;
    fruits[0] = "Apple";
    
    food.fruitWeight = 0.53f;
    food.expirationDate = "23.05.2025";
    std::cout << "\nFruit #" << food.fruitCount << "\n" << fruits[0] << "\n" << food.fruitWeight << "Kg\n" << food.expirationDate << std::endl;
    
    food.fruitCount = 2;
    fruits[1] = "Banana";
    
    food.fruitWeight = 0.36f;
    food.expirationDate = "13.05.2025";
    std::cout << "\nFruit #" << food.fruitCount << "\n" << fruits[1] << "\n" << food.fruitWeight << "Kg\n" << food.expirationDate << std::endl;

    food.fruitCount = 3;
    fruits[2] = "Peach";
    
    food.fruitWeight = 0.41f;
    food.expirationDate = "16.05.2025";
    std::cout << "\nFruit #" << food.fruitCount << "\n" << fruits[2] << "\n" << food.fruitWeight << "Kg\n" << food.expirationDate << std::endl;
    
    // Варіант #2 + Завдання з зірочкою
 
    std::cout << "\nEnter name: ";
    std::cin >> food.fruitName[0];
    
    std::cout << "Enter weight: ";
    std::cin >> food.fruitWeight;
    
    std::cout << "Enter expiration date: ";
    std::cin >> food.expirationDate;
    
    std::cout << "\n Fruit: " << food.fruitName[0] << "\n Weight: " << food.fruitWeight << " Kg" << "\n Expiration date: " << food.expirationDate << std::endl;
    
    std::cout << "\nEnter name: ";
    std::cin >> food.fruitName[1];
    
    std::cout << "Enter weight: ";
    std::cin >> food.fruitWeight;
    
    std::cout << "Enter expiration date: ";
    std::cin >> food.expirationDate;
    
    std::cout << "\n Fruit: " << food.fruitName[1] << "\n Weight: " << food.fruitWeight << " Kg" << "\n Expiration date: " << food.expirationDate << std::endl;
    
    std::cout << "\nEnter name: ";
    std::cin >> food.fruitName[2];
    
    std::cout << "Enter weight: ";
    std::cin >> food.fruitWeight;
    
    std::cout << "Enter expiration date: ";
    std::cin >> food.expirationDate;
    
    std::cout << "\n Fruit: " << food.fruitName[2] << "\n Weight: " << food.fruitWeight << " Kg" << "\n Expiration date: " << food.expirationDate << std::endl;
    
    return 0;
}
