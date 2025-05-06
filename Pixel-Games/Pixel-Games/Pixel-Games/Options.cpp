#include "Options.h"
#include "text.h"
#include <iostream>
#include <cstdlib>
#include <stack>


using namespace std;

string previousActivity = "";



// Game

void startGame(string& n) {
    if (n == "Play") {
        previousActivity = "startGame";

        system("cls");
        LevelView();
        system("cls");
        View_of_fight();
        View_fight_options();

        cin >> n;
        gameLoop(n);
        if (n == "Quit") exitMessage();
    }
}


void choseOptionPlay(string& n) {
    for (int i = 0; i < 3; ++i) cout << endl;

    bool validOption = false;
    while (!validOption) {
        cout << "Chose Option to fight ";
        cin >> n;

        if (n == "NormalAttak") {
            cout << "Normal";
        }
        else if (n == "SpecialAttak") {
            cout << "Special!!";
        }
        else if (n == "back") {
            goback(n);
        }
        else {
            cout << "Option not found. Try again." << endl;
        }
    }
}

// Inventory

void gotoInventory(string& n) {
    if (n == "Inventory") {
        previousActivity = "gotoInventory";

        system("cls");
        viewArmor();
        Options_of_Wepons_or_PasiweItem();
        choseOption(n);
        goback(n);
        gameLoop(n);
        if (n == "Quit") exitMessage();
    }
}



void choseOption(string& n) {
    for (int i = 0; i < 3; ++i) cout << endl;

    bool validOption = false;
    while (!validOption) {
        cout << "Choose an option (Wepons / PasiweItems): ";
        cin >> n;

        if (n == "Wepons") {
            system("cls");
            AsciiWeapons::viewWeapon(AsciiWeapons::sword);
            validOption = true;
        }
        else if (n == "PasiweItems") {
            system("cls");
            AsciiWeapons::viewPasiweItem(AsciiWeapons::shields);
            validOption = true;
        }
        else if (n == "ChangeWepon") {
            int id;
            cin >> id;
            WeponChange(id);
            system("cls");
            viewArmor();
            Options_of_Wepons_or_PasiweItem();
        }
        else if (n == "ChangePasiwe") {
            int id;
            cin >> id;
            PasiweItemChange(id);
            system("cls");
            viewArmor();
            Options_of_Wepons_or_PasiweItem();
        }
        else if (n == "back") {
            system("cls");
            title();

            // Options
            options();

            // Input
            input();
            return;
        }

        else {
            cout << "Option not found. Try again." << endl;
        }
    }
}

// Dla obu 

void goback(string& n) {
    while (n != "back") {
        cout << "######################" << endl;
        cout << "Do you want to go back? (back/no): ";
        cin >> n;

        if (n == "back") {
            system("cls");

            if (previousActivity == "gotoInventory") {
                gotoInventory(n);
                return;
            }
            else if (previousActivity == "startGame") {
                startGame(n);
                return;
            }
            else {
                cout << "No previous activity recorded." << endl;
                title();
                options();
                input();
                return;
            }
        }
        else if (n == "no") {
            break;
        }
    }
}


void gameLoop(string& n) {
    if (n == "Quit") {
    while (n != "Quit") {
            cout << "###########################" << endl;
            cout << "Enter if you want to Quit: " << ends;
            cin >> n;
        }
    }
    
}

void exitMessage() {
    cout << "##################" << endl;
    cout << "Bye!!!!" << endl;
    cout << "##################" << endl;
}



void WeponChange(int id) {

    string item1 = R"(                                                                          |                           
                                                                          |       /                   
                                                                          |   O===[==================-
                                                                          |       \                   
                                                                          |                           )";

    string item2 = R"(                                                                          |                           
                                                                          |      /\                   
                                                                          |   |####==================-
                                                                          |      \/                   
                                                                          |                           )";

    string item3 = R"(                                                                          |                           
                                                                          |                  \---/    
                                                                          |      o================>   
                                                                          |                  /___\    
                                                                          |                           )";

    string item4 = R"(               |                                                                                                                                              |         ///  /\                        |.
               |                                                                                                                                              |        ///   \ \                       |.
               |                                                                                                                                              |       ///     \ \_______^^^^^^|        |.
               |                                                                                                                                              |        ///     \--------VVVVVV|        |.
)";

    if (id == 1) {
        items = item1;
    }
    else if (id == 2) {
        items = item2;
        ability = item4;
    }
    else if (id == 3) {
        items = item3;
    }
}

void PasiweItemChange(int id) {

    string item3 = R"(|          |\_.--._/|          |.
|          /###/\###\          |.   
|          \##(())##/          |.   
|         (`\##\/##/`)         |.   
|            -\__/-            |.)";

    string item2 = R"(|          |--------|          |.
|          |   ||   |          |.   
|          \===[]===/          |.   
|           \  ||  /           |.   
|            ------            |.)";

    string item1 = R"(|          /---------\         |.
|          \####|(_*)/         |.   
|           \###|(_'/          |.   
|            \()|##/           |.   
|             -----            |.)";

    if (id == 1) {
        pasiws = item1;
        hp = 100;
        mana = 100;
        hp = hp + 30;
    }
    else if (id == 2) {
        pasiws = item2;
        hp = 100;
        mana = 100;
        hp = hp + 15;
        mana = mana + 15;
    }
    else if (id == 3) {
        pasiws = item3;
        hp = 100;
        mana = 100;
        mana = mana + 30;
    }
}
