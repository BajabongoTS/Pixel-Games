//#include "text.h"
//#include "Options.h"
//#include <iostream>
//#include <string>
//#include <locale.h>
//
//
//using namespace std;
//
//int main() {
//    setlocale(LC_CTYPE, "");
//    string n;
//
//    IntroView();
//    system("cls");
//
//    while (true) {
//        system("cls");
//        // Title screen
//        title();
//        // Options
//        options();
//        // Input
//        input();
//        cin >> n;
//        if (n == "Quit") {
//            exitMessage();
//            break;
//        }
//        startGame(n);
//        if (n == "Quit") {
//            exitMessage();
//            break;
//        }
//        gotoInventory(n);
//        if (n == "Quit") {
//            exitMessage();
//            break;
//        }
//        Enemies(n);
//        if (n == "Quit") {
//            exitMessage();
//            break;
//        }
//    }
//    return 0;
//}
//
//
//
//
//



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

    bool gameRunning = true;
    bool inGame = false;

    while (gameRunning) {
        if (!inGame) {
            system("cls");
            // Title screen
            title();
            // Options
            options();
            // Input
            input();
            cin >> n;
        }

        if (n == "Quit") {
            exitMessage();
            break;
        }
        else if (n == "Play") {
            inGame = true;
            startGame(n);
            // If startGame returns and n is not "Quit", we reset inGame to return to main menu
            if (n != "Quit" && n != "Play") {
                inGame = false;
            }
        }
        else if (n == "Inventory") {
            gotoInventory(n);
            inGame = false;
        }
        else if (n == "Enemies") {
            Enemies(n);
            inGame = false;
        }
        else {
            // If input doesn't match any option, go back to menu
            inGame = false;
        }
    }

    return 0;
}