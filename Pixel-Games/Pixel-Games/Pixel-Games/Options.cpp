#include "Options.h"
#include "text.h"
#include <iostream>
#include <cstdlib>
#include <stack>


using namespace std;

int AbilityCount = 0;

int gamecount = 0;


Hp hp2;;
Mana mana2;
Shield shield2;

// Game

void startGame(string& n) {
    if (n == "Play") {
        system("cls");

        Layer1View();
        system("cls");

        View_of_fight();
        View_fight_options();

        choseOptionPlay(n);

        gameLoop(n);

        if (n == "Quit") exitMessage();
    }
}



vector<Enemy> enemies = {
    {
R"(                                                                                 _____ __ ________  ____   _____  ____  _____  _____ 
                                                                                /  ___>  |  /   __\/  _/  /   __\/    \/  _  \/  _  \
                                                                                |___  |  _ <|   __||  |---|   __|\-  -/|  |  ||  |  |
                                                                                <_____/__|__\_____/\_____/\_____/ |__| \_____/\__|__/
                                                     )",
        R"(                                                                                |                                                   |
                                                                                |                         .-.                       |
                                                                                |                        (o.o)                      |
                                                                                |                        _|=|_                      |
                                                                                |                      //.=|=.\\                    |
                                                                                |                     // .=|=. \\                   |
                                                                                |                     \\ (_=_) //                   |
                                                                                |                       (:| |:)                     |
                                                                                |                        || ||                      |
                                                                                |                        () ()                      |
                                                                                |                        || ||                      |
                                                                                |                       ==' '==                     |
                                                                                |                                                   |
                                                                                |                  Enemy damage: 20                 |
                                                                                |                   Enemy hp: 100                   |)",
        "easy"
    },
    {
    R"(                                        .-')    ('-. .-.   ('-.     _ .-') _                 (`\ .-') /`            .-. .-')       .-') _                     ('-. .-. .-') _         
                                       ( OO ). ( OO )  /  ( OO ).-.( (  OO) )                 `.( OO ),'          \  ( OO )     ( OO ) )                   ( OO )  /(  OO) )  
                                      (_)---\_),--. ,--.  / . --. / \     .'_  .-'),-----. ,--./  .--.            ,--. ,--. ,--./ ,--,' ,-.-')   ,----.    ,--. ,--./     '._  
                                      /    _ | |  | |  |  | \-.  \  ,`'--..._)( OO'  .-.  '|      |  |            |  .'   / |   \ |  |\ |  |OO) '  .-./-') |  | |  ||'--...__)
                                      \  :` `. |   .|  |.-'-'  |  | |  |  \  '/   |  | |  ||  |   |  |,           |      /, |    \|  | )|  |  \ |  |_( O- )|   .|  |'--.  .--' 
                                       '..`''.)|       | \| |_.'  | |  |   ' |\_) |  |\|  ||  |.'.|  |_)          |     ' _)|  .     |/ |  |(_/ |  | .--, \|       |   |  |        
                                      .-._)   \|  .-.  |  |  .-.  | |  |   / :  \ |  | |  ||         |            |  .   \  |  |\    | ,|  |_.'(|  | '. (_/|  .-.  |   |  | 
                                      \       /|  | |  |  |  | |  | |  '--'  /   `'  '-'  '|   ,'.   |            |  |\   \ |  | \   |(_|  |    |  '--'  | |  | |  |   |  | 
                                       `-----' `--' `--'  `--' `--' `-------'      `-----' '--'   '--'            `--' '--' `--'  `--'  `--'     `------'  `--' `--'   `--')",
        R"(                                                                                |                                                   |
                                                                                |                         !                         |
                                                                                |                        .-.                        |
                                                                                |                      __|=|__                      |
                                                                                |                     (_/`-`\_)                     |
                                                                                |                     //\___/\\                     |
                                                                                |                     <>/   \<>                     |
                                                                                |                      \|_._|/                      |
                                                                                |                       <_I_>                       |
                                                                                |                        |||                        |
                                                                                |                       /_|_\                       |
                                                                                |                                                   |
                                                                                |                  Enemy damage: 30                 |
                                                                                |                   Enemy hp: 150                   |)",
        "medium"
    },
    {
    R"(                                                                                           _____                                                   
                                                                    ____________     _____\    \_______    ______  ____________ _____             
                                                                    \           \   /    / |    \      |  |      |/            \\    \            
                                                                     \           \ /    /  /___/||     /  /     /|\___/\  \\___/\\    \           
                                                                      |    /\     |    |__ |___|/|\    \  \    |/ \|____\  \___|/\\    \          
                                                                      |   |  |    |       \      \ \    \ |    |        |  |      \|    | ______  
                                                                      |    \/     |     __/ __    \|     \|    |   __  /   / __    |    |/      \ 
                                                                      /           /|\    \  /  \    |\         /|  /  \/   /_/  |   /            | 
                                                                     /___________/ | \____\/    |   | \_______/ | |____________/|  /_____/\_____/| 
                                                                    |           | /| |    |____/|    \ |     | /  |           | / |      | |    || 
                                                                    |___________|/  \|____|   | |     \|_____|/   |___________|/  |______|/|____|/ 
                                                                                          |___|/                                                   )",
        R"(                                                                                |                                                   |
                                                                                |                              v                    |
                                                                                |                        (__)v | v                  |
                                                                                |                        /\/\\_|_/                  |
                                                                                |                       _\__/  |                    |
                                                                                |                      /  \/`\<`)                   |
                                                                                |                      \ (  |\_/                    |
                                                                                |                      /)))-(  |                    |
                                                                                |                     / /^ ^ \ |                    |
                                                                                |                    /  )^/\^( |                    |
                                                                                |                    )_//`__>>                      |
                                                                                |                                                   |
                                                                                |                  Enemy damage: 40                 |
                                                                                |                   Enemy hp: 200                   |)",
        "hard"
    }
};

void displayEnemies(const string& difficultyFilter) {

    string spaces = " ";


    for (const auto& e : enemies) {



        if (difficultyFilter.empty() || e.difficulty == difficultyFilter) {

            if (e.difficulty.length() == 6) {
                spaces = "                ";
            }
            else {
                spaces = "                  ";
            }

            cout << endl << endl << endl << endl << endl << e.name << endl << endl << endl << endl << endl << endl << endl << endl;
            cout << R"(                                                                                +---------------------------------------------------+
                                                                                |                                                   |
                                                                                |                                                   |)" << endl;
            cout << "                                                                                |                 Difficulty: " << e.difficulty << spaces << "|" << endl;
            cout << e.ascii << endl;
            cout << R"(                                                                                |                                                   |
                                                                                |                                                   |
                                                                                +---------------------------------------------------+)";
        }
    }
}



// 18





void Enemies(string& n) {
    if (n == "Enemies") {
        while (true) {
            system("cls");

cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << R"(                                                                    ______  __   __  ______  __    __  __  __       __      __  ______  ______  
                                                                   /\  ___\/\ "-.\ \/\  ___\/\ "-./  \/\ \_\ \     /\ \    /\ \/\  ___\/\__  _\ 
                                                                   \ \  __\\ \ \-.  \ \  __\\ \ \-./\ \ \____ \    \ \ \___\ \ \ \___  \/_/\ \/ 
                                                                    \ \_____\ \_\\"\_\ \_____\ \_\ \ \_\/\_____\    \ \_____\ \_\/\_____\ \ \_\ 
                                                                     \/_____/\/_/ \/_/\/_____/\/_/  \/_/\/_____/     \/_____/\/_/\/_____/  \/_/ 
                                                                             )" << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
            cout << "Enter difficulty to filter (easy / medium / hard), or type 'all' to show all:" << endl;
            cout << "Type 'back' to return or 'Quit' to exit: ";


            cin >> n;

            if (n == "back") {
                system("cls");
                title();
                options();
                input();
                break;
            }

            system("cls");
            if (n == "easy" || n == "medium" || n == "hard") {
                displayEnemies(n);
            }
            else if (n == "all") {
                displayEnemies();
            }
            else {
                cout << "Invalid option. Try again." << endl;
            }

            cout << "\nPress Enter to continue:";
            cin.ignore();
            cin.get();
        }
    }
}









void choseOptionPlay(string& n) {
    cout << endl;
    bool validOption = false;

    while (hp > 0 && EnemyHp1 > 0) {
        cout << "Choose an option (NormalAttack / SpecialAttack / EndRound / back): ";
        cin >> n;

        if (n == "NormalAttack") {
               EnemyHp1 = EnemyHp1 - PlayerDamage;
               system("cls");
               View_of_fight();
               View_fight_options();
               cout << "\nPress Enter to EndRound:";
               cin.ignore();
               cin.get();
                       AbilityCount = AbilityCount - 1;

                       if (AbilityCount < 0) {
                           AbilityCount = 0;
                       }

                       GameSystem();
                       system("cls");
                       View_of_fight();
                       View_fight_options();
        }
        else if (n == "HpPotion") {
            if (HpPotion > 0) {
                HpPotion = HpPotion - 20;
                hp = hp + 20;
            }
            else {
                HpPotion = 0;
            }
            
            system("cls");
            View_of_fight();
            View_fight_options();
        }
        else if (n == "ManaPotion") {
            if (ManaPotion > 0) {
               ManaPotion = ManaPotion - 20;
                mana = mana + 20; 
            }
            else {
                ManaPotion = 0;
            }

            system("cls");
            View_of_fight();
            View_fight_options();
        }
        else if (n == "SpecialAttack") {
            if (AbilityCount == 0) {
                if (mana >= 20) {
                    EnemyHp1 -= PlayerSpecialDamage;
                    mana -= ManaCost;
                    AbilityCount = 3;
                    system("cls");
                    View_of_fight();
                    View_fight_options();
                    cout << "\nPress Enter to EndRound:";
                    cin.ignore();
                    cin.get();
                    AbilityCount = AbilityCount - 1;

                    if (AbilityCount < 0) {
                        AbilityCount = 0;
                    }

                    GameSystem();
                    system("cls");
                    View_of_fight();
                    View_fight_options();
                }
                else {
                    cout << "Not enough mana for Special Attack!" << endl;
                }
            }
            else {
                cout << "Rounds left to use Special Attack: " << AbilityCount << endl;
            }
                
        }
        else if (n == "EndRound") {
            AbilityCount = AbilityCount - 1;

            if (AbilityCount < 0) {
                AbilityCount = 0;
            }

            GameSystem();
            system("cls");
            View_of_fight();
            View_fight_options();
        }
        else if (n == "back") {
            hp = hp2;
            mana = mana2;
            shield = shield2;
            EnemyHp1 = 100;
            enemy1 = enemydef;
            AbilityCount = 0;
            system("cls");
            title();
            options();
            input();
            break;
        }
        else {
            cout << "Option not found. Try again." << endl;
        }

        if (hp <= 0 || EnemyHp1 <= 0) break;
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
        hp = 130;
        mana = 100;
        enemydefshield = enemydef1;
        shield = 50;

        hp2 = hp;
        mana2 = mana;
        shield2 = shield;

    }
    else if (id == 2) {
        pasiws = item2;
        hp = 115;
        mana = 115;
        enemydefshield = enemydef2;
        shield = 65;

        hp2 = hp;
        mana2 = mana;
        shield2 = shield;
    }
    else if (id == 3) {
        pasiws = item3;
        hp = 100;
        mana = 130;
        enemydefshield = enemydef3;
        shield = 50;

        hp2 = hp;
        mana2 = mana;
        shield2 = shield;
    }
}


//void GameSystem() {
//    if (EnemyHp1 > 0) {
//        if (shield > 0) {
//            shield = shield - 20;
//            hp = hp - EndmyDamage1 + 20;
//        }
//        else {
//            shield = 0;
//            hp = hp - EndmyDamage1;
//        }
//    }
//
//    if (hp <= 0) {
//        system("cls");
//        for (int i = 0; i <= 22; ++i) cout << endl;
//        GameOver();
//        for (int i = 0; i <= 10; ++i) cout << endl;
//        string choice;
//        while (true) {
//            cout << "   Choose: quit / back / play again: ";
//            cin >> choice;
//
//            if (choice == "quit") {
//                exitMessage();
//                exit(0);  // To ensure program actually exits
//            }
//            else if (choice == "back") {
//                hp = hp2;
//                mana = mana2;
//                shield = shield2;
//                EnemyHp1 = 100;
//                enemy1 = enemydef;
//                AbilityCount = 0;
//                system("cls");
//                title();
//                options();
//                input();
//                break;
//            }
//            else if (choice == "play" || choice == "play again") {
//                hp = hp2;
//                mana = mana2;
//                shield = shield2;
//                EnemyHp1 = 100;
//                EnemyHp2 = 150;
//                EnemyHp3 = 200;
//                AbilityCount = 0;
//                enemy1 = enemydef;
//                system("cls");
//                Layer1View();
//                system("cls");
//                View_of_fight();
//                View_fight_options();
//                break;
//            }
//            else {
//                cout << "Invalid choice. Try again." << endl;
//            }
//        }
//        return;
//    }
//
//    if (EnemyHp1 <= 0) {
//        if (EnemyHp2 > 0) {
//            system("cls");
//            EnemyHp1 = EnemyHp2;
//            EnemyHp2 = 0;
//            EndmyDamage1 = EndmyDamage2;
//            enemy1 = enemy2;
//            Layer2View();
//            system("cls");
//            View_of_fight();
//            View_fight_options();
//        }
//        else if (EnemyHp3 > 0) {
//            system("cls");
//            EnemyHp1 = EnemyHp3;
//            EnemyHp3 = 0;
//            EndmyDamage1 = EndmyDamage3;
//            enemy1 = enemy3;
//            Layer3View();
//            system("cls");
//            View_of_fight();
//            View_fight_options();
//        }
//        else {
//            system("cls");
//            for (int i = 0; i <= 22; ++i) cout << endl;
//            Victory();
//            for (int i = 0; i <= 10; ++i) cout << endl;
//            string choice;
//            while (true) {
//                cout << "   Choose: quit / back / play again: ";
//                cin >> choice;
//
//                if (choice == "quit") {
//                    exitMessage();
//                    exit(0);  // To ensure program actually exits
//                }
//                else if (choice == "back") {
//                    hp = hp2;
//                    mana = mana2;
//                    shield = shield2;
//                    EnemyHp1 = 100;
//                    EnemyHp2 = 150;
//                    EnemyHp3 = 200;
//                    enemy1 = enemydef;
//                    AbilityCount = 0;
//                    system("cls");
//                    title();
//                    options();
//                    input();
//                    break;
//                }
//                else if (choice == "play" || choice == "play again") {
//                    hp = hp2;
//                    mana = mana2;
//                    shield = shield2;
//                    EnemyHp1 = 100;
//                    EnemyHp2 = 150;
//                    EnemyHp3 = 200;
//                    AbilityCount = 0;
//                    enemy1 = enemydef;
//                    system("cls");
//                    Layer1View();
//                    system("cls");
//                    View_of_fight();
//                    View_fight_options();
//                    break;
//                }
//                else {
//                    cout << "Invalid choice. Try again." << endl;
//                }
//            }
//        }
//    }
//}


void GameSystem() {
    if (EnemyHp1 > 0) {
        if (shield > 0) {
            shield = shield - 20;
            hp = hp - EndmyDamage1 + 20;
        }
        else {
            shield = 0;
            hp = hp - EndmyDamage1;
        }
    }

    if (hp <= 0) {
        system("cls");
        for (int i = 0; i <= 22; ++i) cout << endl;
        GameOver();
        for (int i = 0; i <= 10; ++i) cout << endl;
        string choice;
        while (true) {
            cout << "   Choose: quit / back / play again: ";
            cin >> choice;

            if (choice == "quit") {
                exitMessage();
                exit(0);  // To ensure program actually exits
            }
            else if (choice == "back") {
                hp = hp2;
                mana = mana2;
                shield = shield2;
                EnemyHp1 = 100;
                enemy1 = enemydef;
                AbilityCount = 0;
                system("cls");
                title();
                options();
                input();
                break;
            }
            else if (choice == "play" || choice == "play again") {
                hp = hp2;
                mana = mana2;
                shield = shield2;
                EnemyHp1 = 100;
                EnemyHp2 = 150;
                EnemyHp3 = 200;
                AbilityCount = 0;
                enemy1 = enemydef;
                system("cls");
                Layer1View();
                system("cls");
                View_of_fight();
                View_fight_options();

                // Get a new input string to start the game again
                string n = "Play";
                choseOptionPlay(n);
                return;  // Return directly to avoid going back to title screen
            }
            else {
                cout << "Invalid choice. Try again." << endl;
            }
        }
        return;
    }

    if (EnemyHp1 <= 0) {
        if (EnemyHp2 > 0) {
            system("cls");
            EnemyHp1 = EnemyHp2;
            EnemyHp2 = 0;
            EndmyDamage1 = EndmyDamage2;
            enemy1 = enemy2;
            Layer2View();
            system("cls");
            View_of_fight();
            View_fight_options();
        }
        else if (EnemyHp3 > 0) {
            system("cls");
            EnemyHp1 = EnemyHp3;
            EnemyHp3 = 0;
            EndmyDamage1 = EndmyDamage3;
            enemy1 = enemy3;
            Layer3View();
            system("cls");
            View_of_fight();
            View_fight_options();
        }
        else {
            system("cls");
            for (int i = 0; i <= 22; ++i) cout << endl;
            Victory();
            for (int i = 0; i <= 10; ++i) cout << endl;
            string choice;
            while (true) {
                cout << "   Choose: quit / back / play again: ";
                cin >> choice;

                if (choice == "quit") {
                    exitMessage();
                    exit(0);  // To ensure program actually exits
                }
                else if (choice == "back") {
                    hp = hp2;
                    mana = mana2;
                    shield = shield2;
                    EnemyHp1 = 100;
                    EnemyHp2 = 150;
                    EnemyHp3 = 200;
                    enemy1 = enemydef;
                    AbilityCount = 0;
                    system("cls");
                    title();
                    options();
                    input();
                    break;
                }
                else if (choice == "play" || choice == "play again") {
                    hp = hp2;
                    mana = mana2;
                    shield = shield2;
                    EnemyHp1 = 100;
                    EnemyHp2 = 150;
                    EnemyHp3 = 200;
                    AbilityCount = 0;
                    enemy1 = enemydef;
                    system("cls");
                    Layer1View();
                    system("cls");
                    View_of_fight();
                    View_fight_options();

                    // Get a new input string to start the game again
                    string n = "Play";
                    choseOptionPlay(n);
                    return;  // Return directly to avoid going back to title screen
                }
                else {
                    cout << "Invalid choice. Try again." << endl;
                }
            }
        }
    }
}