#include "wordguess.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

void censorWord(string word) {
    for (char i : word) cout << '*';
}

void guessword() {
    system("chcp 1251>null");
    fstream file("guess.txt", ios::in);
    if (!file) {
        cout << "Файл не знайдено";
        return;
    }
    string words[4], tip[4], line;
    int index = 0, i = 0, attempts = 0;

    while (getline(file, line)) {
        index = line.find("|");
        cout << index << endl;
        words[i] = line.substr(index + 1);
        tip[i] = line.substr(0, index);
        i++;
    }

    file.close();
    index = rand() % 4;
    string rndword = words[index], guess = "", description = tip[index];
    cout << description << ": ";
    censorWord(rndword);
    cout<<endl;
    cout << "Спробуйте вгадати слово (введіть 'q', якщо хочете завершити спроби):\n";
    bool gaveup = false;

    while (guess != words[index]) {
        cin >> guess;
        if (guess == "q") { gaveup = true;  break; }
        if (guess.length() > words[index].length()) cout << "Слово має бути коротшим.\n";
        if (guess.length() < words[index].length()) cout << "Слово має бути довшим.\n";
        attempts++;
    }

    if (!gaveup) cout << "Вітаю вас! Ви вгадали слово, скориставшись " << attempts << " спробами";
    else cout << "Дуже прикро, що ви здалися. Ви зробили " << attempts << " спроб. Правильне слово було: " << words[index];
}