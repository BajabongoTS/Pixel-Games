#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>


extern std::string items;
extern std::string pasiws;
extern std::string ability;

extern std::vector<std::string> enemydefshield;
extern std::vector<std::string> wepdef;

extern std::string enemy1;
extern std::string enemy2;
extern std::string enemy3;


extern int gamecount;
extern int AbilityCount;

typedef int Shield;
typedef int Hp;
typedef int Mana;
typedef int Damage;


extern Shield shield;
extern Hp hp;
extern Mana mana;
extern Damage PlayerDamage;


extern Damage EndmyDamage1;
extern Hp EnemyHp1;

extern Damage EndmyDamage2;
extern Hp EnemyHp2;

extern Damage EndmyDamage3;
extern Hp EnemyHp3;


extern Damage PlayerSpecialDamage;
extern Mana ManaCost;


void title();

void options();

void input();

void studio(std::atomic<bool>& running);

void IntroView();

void Victory();

void GameOver();


// Inventory

void viewArmor();

void Options_of_Wepons_or_PasiweItem();

void showItemsAndPasiws();

namespace AsciiWeapons {
    extern std::vector<std::string> sword;
    extern std::vector<std::string> shields;

    void viewWeapon(const std::vector<std::string>& weapon);
    void viewPasiweItem(const std::vector<std::string>& pasiws);
}


// Play
void Layer1Function(std::atomic<bool>& running);

void Layer1View();

void Layer2Function(std::atomic<bool>& running);

void Layer2View();

void Layer3Function(std::atomic<bool>& running);

void Layer3View();

void View_of_fight();

void View_fight_options();

