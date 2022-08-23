#include "Knight.hpp"

Knight::Knight() : Character() {
    classType = "Knight";
    intializeActions();
}

Knight::Knight(string name) : Character(name) {
    hp = 10;
    attack = 7;
    defense = 15;
    speed = 5;
    evasion = 3;
    classType = "Knight";
    intializeActions();
}

Knight::Knight(string name, Player player) : Character(name, player) {
    classType = "Knight";
    intializeActions();
}

Knight::~Knight() {
}

void Knight::intializeActions() {
    
    action1.name = "Light Attack";
    action1.pow = 6 + (4 * action1.actLvl - 4 * 1);
    action1.minPow = 1 + (action1.actLvl - 1);
    action1.numUses = 29 + action1.actLvl;
    action1.usesRemain = 29 + action1.actLvl;
    action1.description1 = "Basic attack action.";
    action1.description2 = "";
    
    action2.name = "Heavy Attack";
    action2.pow = 12 + (4 * action2.actLvl - 4 * 1);
    action2.minPow = 2 + (action2.actLvl - 1);
    action2.numUses = 2 + action2.actLvl;
    action2.usesRemain = 2 + action2.actLvl;
    action2.description1 = "Heavy attack action.";
    action2.description2 = "";
    
    action3.name = "Sharp Slice";
    action3.pow = 4 + (4 * action3.actLvl - 4 * 1);
    action3.minPow = 1 + (action3.actLvl - 1);
    action3.numUses = 4 + action3.actLvl;
    action3.usesRemain = 4 + action3.actLvl;
    action3.description1 = "50% Chance to cause bleed.";
    action3.description2 = "";
    
    action4.name = "Defend";
    action4.pow = 0;
    action4.minPow = 0;
    action4.numUses = 1 + action4.actLvl;
    action4.usesRemain = 1 + action4.actLvl;
    action4.description1 = "Block next attack & Recover HP";
    action4.description2 = "";
    
}

void Knight::calculateStatus(string choice, Character &defender) {
    
    if(defender.getDefenseBoost() <= defender.getDefense()) {
        
        if (choice == "3" && (rand() % 2 == 0) && defender.getNegStatus() != "Bleed") {
            defender.setNegStatus("Bleed");
            textBox("", defender.getName() + " is bleeding from " + name + "\'s attack.", "", "press enter to continue");
            cin.get();
        }
        
    }
    else {
        defender.resetDefenseBoost();
    }
    
}

void Knight::specialAbility(Character &defender, int attackDamage) {
    
    textBox("", name + " recovered " + to_string(100 + 50 * action4.actLvl) + " HP", "", "press enter to continue");
    hpValue = hpValue + 100 + 50 * action4.actLvl;
    defenseBoost = defense + 1000;
    statBoost = "Protected";
    cin.get();
    
}
