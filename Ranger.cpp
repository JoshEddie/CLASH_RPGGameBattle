#include "Ranger.hpp"

Ranger::Ranger() : Character() {
    classType = "Ranger";
    intializeActions();
}

Ranger::Ranger(string name) : Character(name) {
    hp = 5;
    attack = 3;
    defense = 7;
    speed = 15;
    evasion = 10;
    classType = "Ranger";
    intializeActions();
}

Ranger::Ranger(string name, Player player) : Character(name, player) {
    classType = "Ranger";
    intializeActions();
}

Ranger::~Ranger() {
}

void Ranger::intializeActions() {
    
    action1.name = "Quick Shot";
    action1.pow = speed;
    action1.minPow = 1 + (action1.actLvl - 1);
    action1.numUses = 29 + action1.actLvl;
    action1.usesRemain = 29 + action1.actLvl;
    action1.description1 = "Maximum power equal to speed.";
    
    action2.name = "Spike Trap";
    action2.pow = 100;
    action2.minPow = -51 + action2.actLvl;
    action2.numUses = 4 + action2.actLvl;
    action2.usesRemain = 4 + action2.actLvl;
    action2.description1 = "Chance of MASSIVE Damage";
    
    
    action3.name = "Poison Arrow";
    action3.pow = 8 + (4 * action3.actLvl - 4 * 1);
    action3.minPow = 1 + (action3.actLvl - 1);
    action3.numUses = 2 + action3.actLvl;
    action3.usesRemain = 2 + action3.actLvl;
    action3.description1 = "Poisons opponent.";
    
    action4.name = "Rations";
    action4.pow = 0;
    action4.minPow = 0;
    action4.numUses = 1 + action4.actLvl;
    action4.usesRemain = 1 + action4.actLvl;
    action4.description1 = "Boost evasion + Recover some HP";

}

void Ranger::calculateStatus(string choice, Character &defender) {
    
    if(defender.getDefenseBoost() <= defender.getDefense()) {
    
        if(choice == "3" && defender.getNegStatus() != "Poison") {
            defender.setNegStatus("Poison");
            textBox("", defender.getName() + " is Poisoned!", "", "press enter to continue");
            cin.get();
        }
        
    }
    else {
        defender.resetDefenseBoost();
    }
    
}

void Ranger::specialAbility(Character &defender, int attackDamage) {
    
    textBox("", name + " recovered " + to_string(speed * (9 + action4.actLvl)) + " HP", "", "press enter to continue");
    
    hpValue = hpValue + (speed * (9 + action4.actLvl));
    evasionBoost = evasionBoost + 5;
    statBoost = "Evasion + " + to_string(evasionBoost);
    cin.get();
    
}
