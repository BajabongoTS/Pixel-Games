#pragma once

#include <string>
#include <stack>



// Game
void startGame(std::string& n);

void gameLoop(std::string& n);

void exitMessage();

void goback(std::string& n);


// Invoentory
void gotoInventory(std::string& n);

void choseOption(std::string& n);

void WeponChange(int id);

void PasiweItemChange(int id);

void choseOptionPlay(std::string& n);

