#include "function.h"
#include "main.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <chrono> 
#include <windows.h>
#include <stdlib.h>

using namespace std;

void startGame() {
    srand(time(0));
    cout << setw(50) << right << "����ʲ��� ����� \n";
    cout << setw(35) << "����\n" << setw(48) << "���: 0 |  �������: 0\n";
    string ar[3] = { "banana", "lemon", "apple" };
    cout << "�������� ENTER ��� ������� ���";
    int choice, randI = rand() % 2;
    cin >> choice;
    auto startPlayer = chrono::steady_clock::now();
    cout << ar[randI];
    string user;
    while (user != ar[randI]) {
        cout << "\n�����: ";
        cin >> user;
    }
    auto endPlayer = chrono::steady_clock::now();
    chrono::duration<double> elapsedPlayer = endPlayer - startPlayer;
    double timePlayer = elapsedPlayer.count();
    cout << timePlayer << endl;
    cout << "���� ��";
    auto startPC = chrono::steady_clock::now();
    for (int i = 1; i < 4; ++i) {
        cout << '.';
        cout.flush();
        Sleep(1000);
    }
    auto endPC = chrono::steady_clock::now();
    chrono::duration<double> elapsedPC = endPC - startPC;
    int rndPC = 5 + rand() % 10;
    double timePC = elapsedPC.count() + rndPC;
    cout << timePC << endl;
}