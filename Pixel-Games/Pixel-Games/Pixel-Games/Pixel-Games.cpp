#include "text.h"
#include "Options.h"
#include <iostream>
#include <string>
#include <locale.h>


using namespace std;

int main() {
    setlocale(LC_CTYPE, "");
    string n;

    IntroView();
    system("cls");

    while (true) {
        system("cls");
        // Title screen
        title();
        // Options
        options();
        // Input
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





