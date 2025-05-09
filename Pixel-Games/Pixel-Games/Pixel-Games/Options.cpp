#include "Options.h"
#include "text.h"
#include <iostream>
#include <cstdlib>
#include <stack>


using namespace std;



// Game

void startGame(string& n) {
    if (n == "Play") {
        system("cls");

        LevelView();
        system("cls");

        View_of_fight();
        View_fight_options();

        choseOptionPlay(n);

        gameLoop(n);

        if (n == "Quit") exitMessage();
    }
}


void choseOptionPlay(string& n) {
    for (int i = 0; i < 3; ++i) cout << endl;

    bool validOption = false;
    while (!validOption) {
        cout << "Choose an option (Normal Attack / Super Attack / back): ";
        cin >> n;

        if (n == "NormalAttak") {
            cout << "Normal" << endl;
        }
        else if (n == "SpecialAttak") {
            cout << "Special!!" << endl;
        }
        else if (n == "back") {
            break;
            system("cls");
            title();
            options();
            input();
        }
        else {
            cout << "Option not found. Try again." << endl;
        }
    }
}

// Inventory

//void gotoInventory(string& n) {
//    if (n == "Inventory") {
//        system("cls");
//
//        viewArmor();
//        Options_of_Wepons_or_PasiweItem();
//        choseOption(n);
//
//        goback(n);
//
//        gameLoop(n);
//        if (n == "Quit") exitMessage();
//    }
//}


//void choseOption(string& n) {
//    for (int i = 0; i < 3; ++i) cout << endl;
//
//    bool validOption = false;
//    while (!validOption) {
//        cout << "Choose an option (Wepons / PasiweItems / ChangeWepon / ChangePasiwe / back): ";
//        cin >> n;
//
//        if (n == "Wepons") {
//            system("cls");
//            AsciiWeapons::viewWeapon(AsciiWeapons::sword);
//            validOption = true;
//        }
//        else if (n == "PasiweItems") {
//            system("cls");
//            AsciiWeapons::viewPasiweItem(AsciiWeapons::shields);
//            validOption = true;
//        }
//        else if (n == "ChangeWepon") {
//            int id;
//            cin >> id;
//            WeponChange(id);
//            system("cls");
//            viewArmor();
//            Options_of_Wepons_or_PasiweItem();
//        }
//        else if (n == "ChangePasiwe") {
//            int id;
//            cin >> id;
//            PasiweItemChange(id);
//            system("cls");
//            viewArmor();
//            Options_of_Wepons_or_PasiweItem();
//        }
//        else if (n == "back") {
//            return;
//        }
//        else {
//            cout << "Option not found. Try again." << endl;
//        }
//    }
//}

void gotoInventory(string& n) {
    if (n == "Inventory") {
        while (true) {
            system("cls");
            viewArmor();
            Options_of_Wepons_or_PasiweItem();
            choseOption(n);

            if (n == "Quit") {
                exitMessage();
                break;
            }
            else if (n == "back") {
                break; // wróæ do menu g³ównego
            }
        }
    }
}


void choseOption(string& n) {
    bool inInventory = true;
    while (inInventory) {
        cout << endl;
        cout << "Choose an option (Wepons / PasiweItems / ChangeWepon / ChangePasiwe / back): ";
        cin >> n;

        if (n == "Wepons") {
            while (true) {
                system("cls");
                AsciiWeapons::viewWeapon(AsciiWeapons::sword);
                cout << "\nType 'back' to return to inventory: ";
                cin >> n;
                if (n == "back") {
                    system("cls");
                    viewArmor();
                    Options_of_Wepons_or_PasiweItem();
                    break;
                }
            }
        }
        else if (n == "PasiweItems") {
            while (true) {
                system("cls");
                AsciiWeapons::viewPasiweItem(AsciiWeapons::shields);
                cout << "\nType 'back' to return to inventory: ";
                cin >> n;
                if (n == "back") {
                    system("cls");
                    viewArmor();
                    Options_of_Wepons_or_PasiweItem();
                    break;
                }
            }
        }
        else if (n == "ChangeWepon") {
            int id;
            cin >> id;
            WeponChange(id);
            system("cls");
            viewArmor();
            Options_of_Wepons_or_PasiweItem();
            cout << endl;
        }
        else if (n == "ChangePasiwe") {
            int id;
            cin >> id;
            PasiweItemChange(id);
            system("cls");
            viewArmor();
            Options_of_Wepons_or_PasiweItem();
            cout << endl;
        }
        else if (n == "back") {
            n = "back"; // wa¿ne ¿eby dalej wyjœæ z gotoInventory
            inInventory = false;
        }
        else {
            cout << "Option not found. Try again." << endl;
        }
    }
}


// Dla obu 

void goback(string& n) {
    
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
               |                                                                                                                                              |       ///     \ \______/########]      |.
               |                                                                                                                                              |        ///     \--------/              |.
)";


    string item5 = R"(               |                                                                                                                                              |                 _____                  |.
               |                                                                                                                                              |                /     \                 |.
               |                                                                                                                                              |               | () () |                |.
               |                                                                                                                                              |                \  ^  /                 |.
               |                                                                                                                                              |                 |||||                  |.
               |                                                                                                                                              |                 |||||                  |.
)";


    string item6 = R"(               |                                                                                                                                              |           [---\\/---]                  |.
               |                                                                                                                                              |            \###\\###/                  |.
               |                                                                                                                                              |             ----\\--                   |.
               |                                                                                                                                              |                  \\                    |.
)";

    if (id == 1) {
        items = item1;
        ability = item4;
    }
    else if (id == 2) {
        items = item2;
        ability = item5;
    }
    else if (id == 3) {
        items = item3;
        ability = item6;

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
