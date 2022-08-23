
#ifndef Character_hpp
#define Character_hpp

#include "functions.hpp"

class Character {

public:
    Character();
    Character(string);
    Character(string, Player);
    virtual ~Character();
    
    void setName(string);
    
    string getName();
    string getClassType();
    int getLevel();
    
    int getDefense();
    int getDefenseBoost();
    void resetDefenseBoost();
    
    void resetStats();
    int lowerHP(int);
    
    void setNegStatus(string);
    string getNegStatus();
    virtual void calculateStatus(string choice, Character &defender) = 0;
    bool checkStatus(Character&);
    
    void levelUp(int, bool);
    void training(string, Character &trainer);
    
    void printCharacter();
    void printActions();
    void printStats(Character &player2);
    
    bool battle(Character &player2, bool bot, int &numDefeated);
    bool battleResults(Character &defender, string, string);
    string chooseAction(bool, Character&);
    void resolveAction(Character&, Action&, string);
    
    virtual void specialAbility(Character&, int) = 0;
    virtual void intializeActions() = 0;
    
    friend ostream & operator<<(ostream &out, Character *player);
    
protected:
    string name, classType;
    string statBoost;
    string negStatus;
    int hp, attack, defense, speed, evasion;
    int hpValue, attackBoost, attackCharge, defenseBoost, evasionBoost;
    int level, exp;
    
    Action action1;
    Action action2;
    Action action3;
    Action action4;

};

#endif /* Character_hpp */
