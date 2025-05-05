#include "text.h"
#include "Options.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    string n;

    while (true) {
        // Title screen
        system("cls");
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
    }

    return 0;
}



