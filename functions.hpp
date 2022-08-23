#ifndef functions_hpp
#define functions_hpp

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <ctime>

using namespace std;

struct Player {
    int hp, attack, defense, speed, evasion, level, exp, act1Lvl, act2Lvl, act3Lvl, act4Lvl;
};

struct Action {
    string name, description1, description2;
    int actLvl, pow, minPow, usesRemain, numUses, statusChance;
};

void pauseMilliseconds(int);
void textBox(string title, string line1, string line2 = "", string action = "", string line3 = "", string line4 ="");
string nameGenerator();
void printBattleMenu();
void printMenu();

#endif /* functions_hpp */
