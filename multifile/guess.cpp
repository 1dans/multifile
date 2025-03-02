#include <iostream>
#include <algorithm>
#include <windows.h>
#include <fstream>
#include <string>
#include "function.h"
#include "main.h"
#include "guess.h"


using namespace std;

#define r "\033[31m"
#define o "\033[0m"

void guessWord() {
    srand(time(0));
    cout << "���� �����\n";
    fstream file("riddle.txt", ios::in);
    if (!file) {
        cout << "���� �� ��������";
        return;
    }
    string words[5], tip[5], line;
    int index = 0, i = 0;
    
    while (getline(file, line)) {
        index = line.find("|");
        words[i] = line.substr(0, index);
        tip[i] = line.substr(index+1);
        i++;
    }

    file.close();
    index = rand() % 5;
    string rndword = words[index];
    random_shuffle(rndword.begin(), rndword.end());
    cout << rndword << endl;
    string guess = "";
    int attempts = 0, allattempts = 0;
    cout << "��������� ������� ����� (������ 'q', ���� ������ ��������� ������):\n";
    bool gaveup = false; //����� ������� �����, ��� ���������, �� ���� ��� ����������� �������
    while (guess != words[index]) {
        if (attempts == 3) cout << "������ �������? �/�\n"; // ��� ����������, �� �� ����� � false
        cin >> guess;
        if (guess == "q") { gaveup = true;  break; }
        if (guess == "�") { attempts = 100; continue; } //��� ��� �� ����� ��������� �� true
        else if (guess == "�") { cout << tip[index] << endl; attempts = 100; continue; }
        if (guess.length() > words[index].length()) cout << "����� �� ���� ��������.\n";
        if (guess.length() < words[index].length()) cout << "����� �� ���� ������.\n";
        allattempts++;
        attempts++;
    }
    
    if (!gaveup) cout << "³��� ���! �� ������� �����, ������������� " << allattempts << " ��������";
    else cout << "���� ������, �� �� �������. �� ������� " << allattempts << " �����. ��������� ����� ����: " << words[index];

    //char word[] { words[index] };


    // int choice;
    // cin>>choice;
    // if(choice==1) main();
    //char card[3][4];
    //char sim[] = "++##@@--%%&&";
    //random_shuffle(sim, sim + sizeof(sim) - 1);
    //cout << "  1 2 3 4" << endl;
    //for (int i = 0; i < 3; ++i) {
    //    for (int j = 0; j < 4; ++j) {
    //        card[i][j] = sim[i * 4 + j];
    //    }
    //}

    //for (int i = 0; i < 3; ++i) {
    //    cout << char('A' + i) << ' ';
    //    for (int j = 0; j < 4; ++j) {
    //        cout << card[i][j] << ' ';
    //    }
    //    cout << endl;
    //}

    //Sleep(5000);
    //
    //cout << "\033[2J\033[1;1H";
    //cout << "�������� ����:\n";
    //cout << "  1 2 3 4" << endl;
    //for (int i = 0; i < 3; ++i) {
    //    cout << char('A' + i) << ' ';
    //    for (int j = 0; j < 4; ++j) {
    //        cout << r << 'X' << o << ' ';
    //    }
    //    cout << endl;
    //}

}