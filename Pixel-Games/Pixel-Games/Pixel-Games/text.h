#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

extern std::string items;
extern std::string pasiws;

extern int hp;
extern int mana;

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

