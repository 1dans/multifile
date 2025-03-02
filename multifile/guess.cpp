#include "function.h"
#include "main.h"
#include "guess.h"
#include <iostream>
#include <algorithm>
#include <windows.h>
using namespace std;

#define r "\033[31m"
#define o "\033[0m"

void guessWord() {
    srand(time(0));
    cout << "ÏÎËÅ ×ÓÄÅÑ\n";
    // int choice;
    // cin>>choice;
    // if(choice==1) main();
    char card[3][4];
    char sim[] = "++##@@--%%&&";
    random_shuffle(sim, sim + sizeof(sim) - 1);
    cout << "  1 2 3 4" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            card[i][j] = sim[i * 4 + j];
        }
    }

    for (int i = 0; i < 3; ++i) {
        cout << char('A' + i) << ' ';
        for (int j = 0; j < 4; ++j) {
            cout << card[i][j] << ' ';
        }
        cout << endl;
    }

    Sleep(5000);
    
    cout << "\033[2J\033[1;1H";
    cout << "Ðîçãàäàé ïàðè:\n";
    cout << "  1 2 3 4" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << char('A' + i) << ' ';
        for (int j = 0; j < 4; ++j) {
            cout << r << 'X' << o << ' ';
        }
        cout << endl;
    }
}