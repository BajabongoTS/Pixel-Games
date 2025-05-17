#include "Options.h"
#include "text.h"
#include <iostream>
#include <cstdlib>
#include <stack>


using namespace std;

int gamecount = 0;

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

void Enemies(string& n) {
    if (n == "Enemies") {
        while (true) {
            system("cls");
            cout << enemy1 << endl << endl;
            cout << "Chose option to Sort of dificulty or go back: ";
            cin >> n;

            if (n == "back") {
                system("cls");
                title();
                options();
                input();
                break;
            }

            if (n == "Quit") {
                exitMessage();
                break;
            }
        }
    }
}


void choseOptionPlay(string& n) {
    cout << endl;
    bool validOption = false;

    while (hp > 0 && EnemyHp > 0) {
        cout << "Choose an option (NormalAttack / SpecialAttack / EndRound / back): ";
        cin >> n;

        if (n == "NormalAttack") {
               EnemyHp = EnemyHp - PlayerDamage;
               system("cls");
               View_of_fight();
               View_fight_options();
               while (n != "EndRound") {
                   cout << "EndRound:  ";
                   cin >> n;
                   if (n == "EndRound") {
                       gamecount = gamecount - 1;
                       GameSystem();
                       system("cls");
                       View_of_fight();
                       View_fight_options();
                   }
               }
        }
        else if (n == "SpecialAttack") {
            if (gamecount == 0) {
                if (mana >= 20) {
                    EnemyHp -= PlayerSpecialDamage;
                    mana -= ManaCost;
                    gamecount = 3;
                    system("cls");
                    View_of_fight();
                    View_fight_options();
                    while (n != "EndRound") {
                        cout << "EndRound:  ";
                        cin >> n;
                        if (n == "EndRound") {
                            gamecount = gamecount - 1;
                            GameSystem();
                            system("cls");
                            View_of_fight();
                            View_fight_options();
                        }
                    }
                }
                else {
                    cout << "Not enough mana for Special Attack!" << endl;
                }
            }
            else {
                cout << "Rounds left to use Special Attack: " << gamecount << endl;
            }
                
        }
        else if (n == "EndRound") {
            gamecount = gamecount - 1;
            GameSystem();
            system("cls");
            View_of_fight();
            View_fight_options();
        }
        else if (n == "back") {
            hp = 100;
            mana = 100;
            EnemyHp = 200;
            gamecount = 0;
            system("cls");
            title();
            options();
            input();
            break;
        }
        else {
            cout << "Option not found. Try again." << endl;
        }

        if (hp <= 0 || EnemyHp <= 0) break;
    }
}



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
                break;
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
            n = "back";
            inInventory = false;
        }
        else {
            cout << "Option not found. Try again." << endl;
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
               |                                                                                                                                              |       ///     \ \______/########]      |.
               |                                                                                                                                              |        ///     \--------/              |.
)";


    string item5 = R"(                     |                                                                                                                                                |                 _____                  |.
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


vector<string> wepdef1 = { R"(                                         __                                              |.)",
R"(                                        /  \                                             |.)",
R"(                                       / \  \                                            |.)",
R"(                                      /   \  \                                           |.)",
R"(                                     /     \  \                                          |.)",
R"(                                     \  \\  \  \                                         |.)",
R"(                                      \  \\  \  \                                        |.)",
R"(                                       \  \\  \  \                                       |.)",
R"(                                        \  \\  \  \                                      |.)",
R"(                                         \  \\  \  \                                     |.)",
R"(                                          \  \\  \  \                                    |.)",
R"(                                           \  \\  \  \                                   |.)",
R"(                                            \  \\  \  \                                  |.)",
R"(                                             \  \\  \  \                                 |.)" };
    

vector<string> wepdef2 = { R"(                                                                                         |.)",
R"(                                        /\                                               |.)",
R"(                                       / \\                                              |.)",
R"(                                      / \ \\                                             |.)",
R"(                                     /\  \ \\                                            |.)",
R"(                                     \/\  \ \\                                           |.)",
R"(                                      \/\  \ \\                                          |.)",
R"(                                       \/\  \ \\                                         |.)",
R"(                                        \/\  \ \\                                        |.)",
R"(                                         \/\  \ \\                                       |.)",
R"(                                          \/\  \ \\                                      |.)",
R"(                                           \/\  \ \\                                     |.)",
R"(                                            \/\  \ \\                                    |.)",
R"(                                             \/   \ \\                                   |.)" };


vector<string> wepdef3 = { R"(                                                                                         |.)",
R"(                                        _____                                            |.)",
R"(                                   ____/  \  \                                           |.)",
R"(                                   \   \   \  \                                          |.)",
R"(                                   /\   \  /  /                                          |.)",
R"(                                  /  \   \/  /                                           |.)",
R"(                                 /   /\   \  \                                           |.)",
R"(                                \   /  \   \  \                                          |.)",
R"(                                 \_/___/\   \  \                                         |.)",
R"(                                         \   \  \                                        |.)",
R"(                                          \   \  \                                       |.)",
R"(                                           \   \  \                                      |.)",
R"(                                            \   \  \                                     |.)",
R"(                                             \   \  \                                    |.)" };

    if (id == 1) {
        items = item1;
        ability = item4;
        PlayerDamage = 30;
        wepdef = wepdef1;
        PlayerSpecialDamage = PlayerDamage + 10;
        ManaCost = 30;
    }
    else if (id == 2) {
        items = item2;
        ability = item5;
        PlayerDamage = 20;
        wepdef = wepdef2;
        PlayerSpecialDamage = 80;
        ManaCost = 50;
    }
    else if (id == 3) {
        items = item3;
        ability = item6;
        PlayerDamage = 20;
        wepdef = wepdef3;
        PlayerSpecialDamage = 40;
        hp = hp + 10;
        ManaCost = 60;
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


vector<string> enemydef1 = { "               |                                                                                              ",
"               |                                                                                              ",
"               |                                                                                              ",
"               |                                                                                              ",
"               |                                                                                              ",
"               |                                                                                              ",
"               |                                                                                              ",
"               |                                                                                              ",
"               |                                                                                              ",
"               |         _________________________________________________________                            ",
R"(               |        /(__6____#___3____####3)####||#############uy#############\                           )",
R"(               |       \(__6_12___#___3____####3)###||#############################/                         )",
R"(               |        \(__6_7___#___3____####3)()0||####de######################/                          )",
R"(               |         \7___# (0)3____####3)()0__)||###############aw##########/                           )"
};

vector<string> enemydef3 = { "               |                                                                                              ",
"               |                                                                                              ",
"               |                                                                                              ",
"               |                                                                                              ",
"               |                                                                                              ",
"               |                                                                                              ",
"               |                                                                                              ",
"               |                                                                                              ",
"               |                                                                                              ",
R"(               |          |\_______________.---------------------.______________/|                            )",
R"(               |         /########################################################\                           )",
R"(               |         \##########################/||\##########################/                           )",
R"(               |          \########################/d||b\########################/                            )",
R"(               |           \######################(0(())0)######################/                             )"
};


vector<string> enemydef2 = { "               |                                                                                              ",
"               |                                                                                              ",
"               |                                                                                              ",
"               |                                                                                              ",
"               |                                                                                              ",
"               |                                                                                              ",
"               |                                                                                              ",
"               |                                                                                              ",
"               |                                                                                              ",
"               |         _________________________________________________________                            ",
R"(               |        /                           ||                            \                           )",
"               |        |                           ||                            |                           ",
"               |        |                           ||                            |                           ",
"               |        |                           ||                            |                           "
};


    if (id == 1) {
        pasiws = item1;
        hp = 100;
        mana = 100;
        hp = hp + 30;
        enemydefshield = enemydef1;
        shield = 50;
    }
    else if (id == 2) {
        pasiws = item2;
        hp = 100;
        mana = 100;
        hp = hp + 15;
        mana = mana + 15;
        enemydefshield = enemydef2;
        shield = 65;
    }
    else if (id == 3) {
        pasiws = item3;
        hp = 100;
        mana = 100;
        mana = mana + 30;
        enemydefshield = enemydef3;
        shield = 50;
    }
}

void GameSystem() {
        if (shield > 0) {
           shield = shield - 10;
           hp = hp - EndmyDamage + 10;
        }
        else {
           hp = hp - EndmyDamage;
        }


    if (hp <= 0) {
        cout << "Game Over!" << endl;
        string choice;
        while (true) {
            cout << "Choose: quit / back: ";
            cin >> choice;
            if (choice == "quit") {
                exitMessage();
                break;
            }
            else if (choice == "back") {
                hp = 100;
                mana = 100;
                shield = shield;
                EnemyHp = 200;
                system("cls");
                title();
                options();
                input();
                break;
            }
            else {
                cout << "Invalid choice. Try again." << endl;
            }
        }
    }
    else if (EnemyHp <= 0) {
        Victory();
        string choice;
        while (true) {
            cout << "Choose: quit / back: ";
            cin >> choice;
            if (choice == "quit") {
                exitMessage();
                break;
            }
            else if (choice == "back") {
                hp = 100;
                mana = 100;
                EnemyHp = 200;
                system("cls");
                title();
                options();
                input();
                break;
            }
            else {
                cout << "Invalid choice. Try again." << endl;
            }
        }
    }
}
