#include "Wizard.hpp"

Wizard::Wizard() : Character() {
    classType = "Wizard";
    intializeActions();
}

Wizard::Wizard(string name) : Character(name) {
    hp = 5;
    attack = 15;
    defense = 3;
    speed = 7;
    evasion = 10;
    classType = "Wizard";
    intializeActions();
}

Wizard::Wizard(string name, Player player) : Character(name, player) {
    classType = "Wizard";
    intializeActions();
}

Wizard::~Wizard() {
}

void Wizard::intializeActions() {
    
    action1.name = "Fire Blaze";
    action1.pow = 8 + (4 * action1.actLvl - 4 * 1);
    action1.minPow = 1 + (action1.actLvl - 1);
    action1.numUses = 14 + action1.actLvl;
    action1.usesRemain = 14 + action1.actLvl;
    action1.description1 = "33% chance to cause Burn.";
    action1.description2 = "";
    
    action2.name = "Ice Shards";
    action2.pow = 8 + (4 * action2.actLvl - 4 * 1);
    action2.minPow = 1 + (action2.actLvl - 1);
    action2.numUses = 14 + action2.actLvl;
    action1.usesRemain = 14 + action2.actLvl;
    action2.description1 = "33% chance to cause Freeze.";
    action2.description2 = "";
    
    action3.name = "Thunder Strike";
    action3.pow = 8 + (4 * action3.actLvl - 4 * 1);
    action3.minPow = 1 + (action3.actLvl - 1);
    action3.numUses = 14 + action3.actLvl;
    action1.usesRemain = 14 + action3.actLvl;
    action3.description1 = "33% chance to cause Shock.";
    action3.description2 = "";
    
    action4.name = "Focus";
    action4.pow = 0;
    action4.minPow = 0;
    action4.numUses = 1 + action4.actLvl;
    action4.usesRemain = 1 + action4.actLvl;
    action4.description1 = "Boost attack for 5 turns.";
    action4.description2 = "";
    
}

void Wizard::calculateStatus(string choice, Character &defender) {
    
    if(defender.getDefenseBoost() <= defender.getDefense()) {
    
        if(rand() % 3 == 0) {
            if(choice == "3" && defender.getNegStatus() != "Shock") {
                defender.setNegStatus("Shock");
                textBox("", defender.getName() + " is Shocked!", "", "press enter to continue");
                cin.get();
            }
            else if (choice == "2" && defender.getNegStatus() != "Freeze") {
                defender.setNegStatus("Freeze");
                textBox("", defender.getName() + " is Frozen!", "", "press enter to continue");
                cin.get();
            }
            else if(choice == "1" && defender.getNegStatus() != "Burn") {
                defender.setNegStatus("Burn");
                textBox("", defender.getName() + " is Burned!", "", "press enter to continue");
                cin.get();
            }
        }
        
    }
    else {
        defender.resetDefenseBoost();
    }
    
    if(attackCharge > 1) {
        --attackCharge;
        textBox("", "Attack is boosted for " + to_string(attackCharge) + " more turns.", "", "press enter to continue");
        cin.get();
    }
    else if(attackCharge == 1) {
        textBox("", "Attack boost has worn off.", "", "press enter to continue.");
        cin.get();
        attackCharge = 0;
        attackBoost = 0;
        statBoost = "none";
    }
    
}

void Wizard::specialAbility(Character &defender, int attackDamage) {
    
    attackCharge = 3 + action4.actLvl;
    attackBoost = (attack / 2) + action4.actLvl;
    textBox("", name + " boosted their attack for " + to_string(attackCharge) + " turns.", "", "press enter to continue");
    statBoost = "Attack + " + to_string(attackBoost);
    cin.get();
    
}
