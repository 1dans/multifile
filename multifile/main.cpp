#include <iostream>
#include "function.h"
#include "main.h"
#include "guess.h"
#include "wordguess.h"
using namespace std;


int main()
{
    srand(time(0));
    system("chcp 1251>null");
    cout << "�������� ����:\n1) �������� �����\n2) ��� \"���� �����\"\n3 - ������ �����\n��� ����: ";
    int choice;
    cin >> choice;
    switch (choice) {
    case 1: startGame(); break;
    case 2: guessWord(); break;
    case 3: guessword(); break;
    default: break;
    }

    return 0;
}