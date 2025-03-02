#include "function.h"
#include "main.h"
#include "guess.h"
#include <iostream>
using namespace std;


int main()
{
    srand(time(0));
    system("chcp 1251>null");
    cout << "Колекція ігор:\n1) Швидкість друку\n2) Гра \"поле чудес\"\nВаш вибір: ";
    int choice;
    cin >> choice;
    switch (choice) {
    case 1: startGame(); break;
    case 2: guessWord(); break;
    default: break;
    }

    return 0;
}