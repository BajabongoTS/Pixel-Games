#include "text.h"
#include "Options.h"
#include <iostream>
#include <string>
#include <locale.h>

using namespace std;

int main(int argc, char* argv[]) {
    setlocale(LC_CTYPE, "");
    string n;

    if (argc > 1) {
        cout << "Uruchomiono program z argumentami:" << endl;
        for (int i = 1; i < argc; ++i) {
            cout << "Arg[" << i << "]: " << argv[i] << endl;
        }
        system("pause");
    }
    
    IntroView();
    system("cls");

    while (true) {
        system("cls");
        title();
        options();
        input();
        cin >> n;
        if (n == "Quit") {
            exitMessage();
            break;
        }
        startGame(n);
        if (n == "Quit") {
            exitMessage();
            break;
        }
        gotoInventory(n);
        if (n == "Quit") {
            exitMessage();
            break;
        }
        Enemies(n);
        if (n == "Quit") {
            exitMessage();
            break;
        }
    }
    return 0;
}

