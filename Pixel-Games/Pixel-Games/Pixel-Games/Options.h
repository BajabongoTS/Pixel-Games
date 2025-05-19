#pragma once

#include <string>
#include <stack>
#include <vector>


// Game
void startGame(std::string& n);

void gameLoop(std::string& n);

void exitMessage();

void GameSystem();

// Invoentory
void gotoInventory(std::string& n);

void choseOption(std::string& n);

void WeponChange(int id);

void PasiweItemChange(int id);

void choseOptionPlay(std::string& n);

// Enemies

struct Enemy {
    std::string name;
    std::string ascii;
    std::string difficulty;
};

extern std::vector<Enemy> enemies;

void displayEnemies(const std::string& difficultyFilter = "");

void Enemies(std::string& n);
