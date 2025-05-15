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
extern std::string enemydef;

typedef int Hp;
typedef int Mana;
typedef int Damage;


extern Hp hp;
extern Mana mana;
extern Damage PlayerDamage;
extern Damage EnemyDamage;
extern Hp EnemyHp;

void title();

void options();

void input();

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

void viewLevel();

void LevelFunction(std::atomic<bool>& running);

void LevelView();

void View_of_fight();

void View_fight_options();

