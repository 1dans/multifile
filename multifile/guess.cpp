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
    cout << "ПОЛЕ ЧУДЕС\n";
    fstream file("riddle.txt", ios::in);
    if (!file) {
        cout << "Файл не знайдено";
        return;
    }
    string words[5], tip[5], line;
    int index = 0, i = 0, allattempts = 0;
    
    while (getline(file, line)) {
        index = line.find("|");
        words[i] = line.substr(0, index);
        tip[i] = line.substr(index+1);
        i++;
    }

    file.close();
    index = rand() % 5;
    string rndword = words[index], guess = "";
    random_shuffle(rndword.begin(), rndword.end());
    cout << rndword << endl;
    cout << "Спробуйте вгадати слово (введіть 'q', якщо хочете завершити спроби):\n";
    bool gaveup = false, tipshowed = false; 
    
    while (guess != words[index]) {
        if (allattempts == 3 && !tipshowed) cout << "Хочете підказку? т/н\n"; 
        cin >> guess;
        if (guess == "q") { gaveup = true;  break; }
        if (guess == "н") { tipshowed = true; continue; } 
        else if (guess == "т" && !tipshowed) { cout << tip[index] << endl; tipshowed=true; continue; }
        if (guess.length() > words[index].length()) cout << "Слово має бути коротшим.\n";
        if (guess.length() < words[index].length()) cout << "Слово має бути довшим.\n";
        allattempts++;
    }
    
    if (!gaveup) cout << "Вітаю вас! Ви вгадали слово, скориставшись " << allattempts << " спробами";
    else cout << "Дуже прикро, що ви здалися. Ви зробили " << allattempts << " спроб. Правильне слово було: " << words[index];

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
    //cout << "Розгадай пари:\n";
    //cout << "  1 2 3 4" << endl;
    //for (int i = 0; i < 3; ++i) {
    //    cout << char('A' + i) << ' ';
    //    for (int j = 0; j < 4; ++j) {
    //        cout << r << 'X' << o << ' ';
    //    }
    //    cout << endl;
    //}

}