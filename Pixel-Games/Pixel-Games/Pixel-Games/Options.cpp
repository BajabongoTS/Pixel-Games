#include "Options.h"
#include "text.h"
#include <iostream>
#include <cstdlib>

using namespace std;



// Game

void startGame(string& n) {
    if (n == "Play") {
        system("cls");

        LevelView();
        system("cls");

        View_of_fight();

        View_fight_options();

        gameLoop(n);
        if (n == "Quit") {
            exitMessage();
        }
    }
}

// Inventory

void gotoInventory(string& n) {
    if (n == "Inventory") {
        system("cls");

        // Wiew inventory
        viewArmor();


        Options_of_Wepons_or_PasiweItem();


        choseOption(n);


        goback(n);


        gameLoop(n);
        if (n == "Quit") {
            exitMessage();
        }
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
            options();
            return;
        }

        else {
            cout << "Option not found. Try again." << endl;
        }
    }
}

// Dla obu 

void goback(string& n) {
    string c = "    ";
    while (n != "back") {
        cout << "######################" << endl;
        cout << "Do you want do come back: ";
        cin >> n;

        if (n == "back") {
            system("cls");

            viewArmor();

            Options_of_Wepons_or_PasiweItem();

            choseOption(n);
        }

        else if (n == "no") {
            break;
        }

    }
}

void gameLoop(string& n) {
    while (n != "Quit") {
        cout << "###########################" << endl;
        cout << "Enter if you want to Quit: " << ends;
        cin >> n;
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

    if (id == 1) {
        items = item1;
    }
    else if (id == 2) {
        items = item2;
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