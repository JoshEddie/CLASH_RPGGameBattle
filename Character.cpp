
#include "Character.hpp"

Character::Character() {
    name = "unknown";
    classType = "";
    hp = 1;
    attack = 1;
    defense = 1;
    speed = 1;
    evasion = 1;
    level = 1;
    exp = 0;
    action1.actLvl = 1;
    action2.actLvl = 1;
    action3.actLvl = 1;
    action4.actLvl = 1;
}
Character::Character(string name) : Character() {
    this->name = name;
    hp = 1;
    attack = 1;
    defense = 1;
    speed = 1;
    evasion = 1;
    level = 1;
    exp = 0;
    action1.actLvl = 1;
    action2.actLvl = 1;
    action3.actLvl = 1;
    action4.actLvl = 1;
}
Character::Character(string name, Player player) {
    this->name = name;
    this->hp = player.hp;
    this->attack = player.attack;
    this->defense = player.defense;
    this->speed = player.speed;
    this->evasion = player.evasion;
    this->level = player.level;
    this->exp = player.exp;
    action1.actLvl = player.act1Lvl;
    action2.actLvl = player.act2Lvl;
    action3.actLvl = player.act3Lvl;
    action4.actLvl = player.act4Lvl;
}
Character::~Character() {
}

void Character::setName(string name){
    this->name = name;
}
string Character::getName(){
    return name;
}
string Character::getClassType(){
    return classType;
}
int Character::getLevel(){
    return level;
}

int Character::getDefense() {
    return defense;
}
int Character::getDefenseBoost() {
    return defenseBoost;
}
void Character::resetDefenseBoost() {
    defenseBoost = 0;
}

void Character::levelUp(int opponentLevel, bool bot) {
    
    exp = exp + opponentLevel * 10;
    
    while(exp >= (10 * level)) {
        string choice = "0";
        int remainingExp = exp - (10 * level);
        
        if(!bot) {
            
            textBox("", name + " has leveled up! ", "", "press enter to continue");
            cin.get();
            
            cout << right << " " << setfill('-') << setw(80) << " " << endl;
            cout << left << setfill(' ') << setw(3) << "|";
            cout << left << setfill(' ') << setw(77) << "Pick a stat to increase." << "|" << endl;
            
            do {
                
                cout << left << setfill(' ') << setw(3) << "|";
                cout << left << setfill(' ') << setw(77) << "[1] -- HP: " + to_string(hp) + "->" + to_string(hp + 1) << "|" << endl;
                cout << left << setfill(' ') << setw(3) << "|";
                cout << left << setfill(' ') << setw(77) << "[2] -- Attack: " + to_string(attack) + "->" + to_string(attack + 1) << "|" << endl;
                cout << left << setfill(' ') << setw(3) << "|";
                cout << left << setfill(' ') << setw(77) << "[3] -- Defense: " + to_string(defense) + "->" + to_string(defense + 1) << "|" << endl;
                cout << left << setfill(' ') << setw(3) << "|";
                cout << left << setfill(' ') << setw(77) << "[4] -- Speed: " + to_string(speed) + "->" + to_string(speed + 1) << "|" << endl;
                cout << left << setfill(' ') << setw(3) << "|";
                cout << left << setfill(' ') << setw(77) << "[5] -- Evasion: " + to_string(evasion) + "->" + to_string(evasion + 1) << "|" << endl;
                cout << right << " " << setfill('-') << setw(80) << " " << endl;
                cin >> choice;
                cin.ignore();
                cout << endl;
                
            } while (choice > "5" || choice < "1");
            
        }
        else {
            choice = to_string((rand() % 5) + 1);
        }
        
        if(choice == "1") { hp++; }
        else if(choice == "2") { attack++; }
        else if(choice == "3") { defense++; }
        else if(choice == "4") { speed++; }
        else if(choice == "5") { evasion++; }
        
        level++;
        exp = remainingExp;
        
        if(!bot) {
            printCharacter();
        }
        
        if(level % 5 == 0) {
            
            if(!bot) {
                textBox("", "You are strong enough to level up one of your actions", "", "press enter to continue");
                cin.get();
            
                do {
                    
                    printActions();
                    textBox("", "Which action would you like to level up?", "", "press number key");
                    cin >> choice;
                    cin.ignore();
                    cout << endl;

                } while(choice != "1" && choice != "2" && choice != "3" && choice != "4");
                
            }
            else {
                //Randomize choice for bot
                choice = to_string((rand() % 7) + 1);
                
                if(choice == "1" || choice == "2") {
                    choice = "1";
                }
                else if(choice == "3" || choice == "4") {
                    choice = "2";
                }
                else if(choice == "5" || choice == "6") {
                    choice = "3";
                }
                else {
                    choice = "4";
                }
                //End randomize choice for bot
            }
                
            if(choice == "1") { action1.actLvl++; }
            else if(choice == "2") { action2.actLvl++; }
            else if (choice == "3") { action3.actLvl++; }
            else if (choice == "4") { action4.actLvl++; }
            
        }
        
    }
    
}
void Character::training(string title, Character &trainer) {
    
    string choice;
    string actionsTutotial = "Not Completed";
    string statsTutorial = "Not Complete";
    string statusTutorial = "Not Completed";
    resetStats();
    
    textBox(title, "Welcome!", "These are dangerous games and I'm in charge in getting you up to speed.", "press enter to continue");
    cin.get();
    
    do {
        
        textBox(title, "What would you like to learn about?", "", "");
        
        cout << right << " " << setfill('-') << setw(80) << " " << endl;
        cout << left << setfill(' ') << setw(3) << "|";
        cout << left << setfill(' ') << setw(77) << "[1] -- Actions" << "|" << endl;
        cout << left << setfill(' ') << setw(3) << "|";
        cout << left << setfill(' ') << setw(77) << "[2] -- Stats" << "|" << endl;
        cout << left << setfill(' ') << setw(3) << "|";
        cout << left << setfill(' ') << setw(77) << "[3] -- Status Effects/Boosts" << "|" << endl;
        cout << left << setfill(' ') << setw(3) << "|";
        cout << left << setfill(' ') << setw(77) << "[4] -- Exit" << "|" << endl;
        cout << right << " " << setfill('-') << setw(80) << " " << endl;
        cin >> choice;
        cin.ignore();
        cout << endl;
        
        if(choice == "1") {
            
            textBox(title, "Actions are the core of how you fight. You will be presented with 4 actions", "to choose from. Let's break down each part of an action.", "press enter to continue", "");
            cin.get();
            
            //Action 1
            cout << right << " " << setfill('-') << setw(40) << " " << endl;
            cout << left << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(37) << left << "1 " << "|" << endl;
            cout << endl;
            
            textBox(title, "First is the the action number, you will use this select the action.", "", "press enter to continue", "");
            cin.get();
            
            //Action 1
            cout << right << " " << setfill('-') << setw(40) << " " << endl;
            cout << left << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(37) << left << "1 " + action1.name << "|" << endl;
            cout << endl;
            
            textBox(title, "Next, you have the name of the action.", "", "press enter to continue", "");
            cin.get();
            
            //Action 1
            cout << right << " " << setfill('-') << setw(40) << " " << endl;
            cout << left << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(37) << left << "1 " + action1.name + ", level " + to_string(action1.actLvl) << "|" << endl;
            cout << endl;
            
            textBox(title, "Next, you have the level of the action.", "Every 5 levels you can level up an action.", "press enter to continue", "");
            cin.get();
            
            cout << right << " " << setfill('-') << setw(40) << " " << endl;
            cout << left << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(37) << left << "1 " + action1.name << "|" << endl;
            cout << left << setfill(' ') << setw(5) << "|" << left << setfill(' ') << setw(35) << "Uses: " + to_string(action1.usesRemain) + "/" + to_string(action1.numUses) << endl;
            cout << endl;
            textBox(title, "Each action can be used a limited number of times in a battle.", "The first number is the number of uses you have remaining.",  "press enter to continue", "The second number is the total times the action can be used each battle.");
            cin.get();
            
            cout << right << " " << setfill('-') << setw(40) << " " << endl;
            cout << left << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(37) << left << "1 " + action1.name << "|" << endl;
            cout << left << setfill(' ') << setw(5) << "|" << left << setfill(' ') << setw(35) << "Uses: " + to_string(action1.usesRemain) + "/" + to_string(action1.numUses)+ " | Damage: " + to_string(action1.minPow) + "-" + to_string(action1.pow) << "|" << endl;
            cout << endl;
            textBox(title, "Damage is calculated via a random range (like rolling a die in D&D)", "The first number is the minumum value of the attack.", "press enter to continue", "The second number is the maximum value of an attack.");
            cin.get();
            
            cout << right << " " << setfill('-') << setw(40) << " " << endl;
            cout << left << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(37) << left << "1 " + action1.name << "|" << endl;
            cout << left << setfill(' ') << setw(5) << "|" << left << setfill(' ') << setw(35) << "Uses: " + to_string(action1.usesRemain) + "/" + to_string(action1.numUses)+ " | Damage: " + to_string(action1.minPow) + "-" + to_string(action1.pow) << "|" << endl;
            cout << right << "|" << setfill(' ') << setw(40) << "|" << endl;
            cout << left << setfill(' ') << setw(5) << "|" << left << setfill(' ') << setw(35) << action1.description1 << "|" << endl;
            cout << right << " " << setfill('-') << setw(40) << " " << endl;
            cout << endl;
            
            textBox(title, "The last piece of information is a description of the action.", "This will tell you what the action does and any special status effects", "press enter to continue", "the action might add. You can ask me about those in a minute.", "");
            cin.get();
            
            
            textBox(title, "Let's practice each of your 4 actions.", "", "press enter to continue");
            cin.get();
            
            //Action 1
            cout << endl;
            cout << right << " " << setfill('-') << setw(40) << " " << endl;
            cout << left << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(37) << left << "1 " + action1.name << "|" << endl;
            cout << left << setfill(' ') << setw(5) << "|" << left << setfill(' ') << setw(35) << "Uses: " + to_string(action1.usesRemain) + "/" + to_string(action1.numUses)+ " | Damage: " + to_string(action1.minPow) + "-" + to_string(action1.pow) << "|" << endl;
            cout << right << "|" << setfill(' ') << setw(40) << "|" << endl;
            cout << left << setfill(' ') << setw(5) << "|" << left << setfill(' ') << setw(35) << action1.description1 << "|" << endl;
            cout << right << " " << setfill('-') << setw(40) << " " << endl;
            //End Action 1
            
            do {
                textBox(title, "First up action 1", "", "press 1 to use this action");
                cin >> choice;
                cin.ignore();
                cout << endl;
            } while(choice != "1");
            resolveAction(trainer, action1, choice);
            
            //Action 2
            cout << endl;
            cout << right << " " << setfill('-') << setw(40) << " " << endl;
            cout << left << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(37) << left << "2 " + action2.name << "|" << endl;
            cout << left << setfill(' ') << setw(5) << "|" << left << setfill(' ') << setw(35) << "Uses: " + to_string(action2.usesRemain) + "/" + to_string(action2.numUses)+ " | Damage: " + to_string(action2.minPow) + "-" + to_string(action2.pow) << "|" << endl;
            cout << right << " " << setfill(' ') << setw(40) << " " << endl;
            cout << left << setfill(' ') << setw(5) << "|" << left << setfill(' ') << setw(35) << action2.description1 << "|" << endl;
            cout << right << " " << setfill('-') << setw(40) << " " << endl;
            //End Action 2
            
            do {
                textBox(title, "Next is action 2", "", "press 2 to use this action");
                cin >> choice;
                cin.ignore();
                cout << endl;
            } while(choice != "2");
            resolveAction(trainer, action2, choice);
            
            //Action 3
            cout << endl;
            cout << right << " " << setfill('-') << setw(40) << " " << endl;
            cout << left << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(37) << left << "3 " + action3.name << "|" << endl;
            cout << left << setfill(' ') << setw(5) << "|" << left << setfill(' ') << setw(35) << "Uses: " + to_string(action3.usesRemain) + "/" + to_string(action3.numUses)+ " | Damage: " + to_string(action3.minPow) + "-" + to_string(action3.pow) << "|" << endl;
            cout << right << "|" << setfill(' ') << setw(40) << "|" << endl;
            cout << left << setfill(' ') << setw(5) << "|" << left << setfill(' ') << setw(35) << action3.description1 << "|" << endl;
            cout << right << " " << setfill('-') << setw(40) << " " << endl;
            //End Action 3
            
            do {
                textBox(title, "Now action 3", "", "press 3 to use this action");
                cin >> choice;
                cin.ignore();
                cout << endl;
            } while(choice != "3");
            resolveAction(trainer, action3, choice);
            
            //Action 4
            cout << endl;
            cout << right << " " << setfill('-') << setw(40) << " " << endl;
            cout << left << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(37) << left << "4 " + action4.name << "|" << endl;
            cout << left << setfill(' ') << setw(5) << "|" << left << setfill(' ') << setw(35) << "Uses: " + to_string(action4.usesRemain) + "/" + to_string(action4.numUses)+ " | Damage: " + to_string(action4.minPow) + "-" + to_string(action4.pow) << "|" << endl;
            cout << right << "|" << setfill(' ') << setw(40) << "|" << endl;
            cout << left << setfill(' ') << setw(5) << "|" << left << setfill(' ') << setw(35) << action4.description1 << "|" << endl;
            cout << right << " " << setfill('-') << setw(40) << " " << endl;
            //End Action 4
            
            do {
                textBox(title, "Finally action 4.", "This is the special ability of your class.", "press 4 to use this action");
                cin >> choice;
                cin.ignore();
                cout << endl;
            } while(choice != "4");
            resolveAction(trainer, action4, choice);
            
            choice = "0";
            
        }
        else if (choice == "2") {
            
            textBox(title, "Stats are the base of how your character functions", "Each time you level up, you will choose one stat to increase.", "press enter to continue", "");
            cin.get();
            
            textBox(title, "HP (health points) determines your health.", "", "press enter to continue");
            cin.get();
            
            textBox(title, "Atack is how much damage you can do.", "", "press enter to continue", "");
            cin.get();
            
            textBox(title, "Defense helps you prevent damage taken.", "", "press enter to continue", "");
            cin.get();
            
            textBox(title, "Speed is how fast you are. This determines who moves first in Battle.", "", "press enter to continue");
            cin.get();
            
            textBox(title, "Finally, Evasion is the percentage chance to evade an enemy action.", "", "press enter to continue");
            cin.get();
            
            if(level == 1) {
                
                textBox(title, "Let's have you choose one of those stats to increase now.", "", "press enter to continue");
                cin.get();
                
                levelUp(1, false);
                
            }
            
        }
        else if (choice == "3") {
            
            textBox(title, "Status effects will determine various negative effects in Battle.", "", "press enter to continue", "");
            cin.get();
            
            textBox(title, "Some negative status effects will deal damage to you.", "Others prevent you from acting for a turn.", "press enter to continue", "");
            cin.get();
            
            textBox(title, "Each class also has a Stat Boost they can use as part of their", "special ability.", "press enter to continue");
            cin.get();
            
            textBox(title, "The Ranger can boost their evasion.", "The Knight can boost their defense.", "press enter to continue", "The Wizard can boost their attack.");
            cin.get();
            
        }
        
    } while (choice != "4");
    
}

//Used to reset stats before battle to full health, normal status, etc.
void Character::resetStats(){
    hpValue = 500 + hp * 50;
    attackBoost = 0;
    attackCharge = 0;
    defenseBoost = 0;
    evasionBoost = 0;
    statBoost = "none";
    negStatus = "normal";
    intializeActions();
    action1.usesRemain = action1.numUses;
    action2.usesRemain = action2.numUses;
    action3.usesRemain = action3.numUses;
    action4.usesRemain = action4.numUses;
}
int Character::lowerHP(int damage) {
    
    damage = damage - defense * 5;
    
    if(defenseBoost > defense) {
        damage = 0;
        //defenseBoost = 0;
        statBoost = "none";
    }
    else if (damage < 1) { //Ensures 1 damage is always done and there isn't negative damage.
        damage = 1;
    }
    
    hpValue = hpValue - damage;
    
    return damage;
    
}
void Character::setNegStatus(string status) {
    negStatus = status;
}
string Character::getNegStatus() {
    return negStatus;
}
bool Character::checkStatus(Character &defender) {
    
    int recoverChance =  rand() % 10;
    int maxHP = 500 + hp * 50;
    
    if(recoverChance == 0 && (negStatus != "normal")) {
        printStats(defender);
        textBox("", name + " recovered from " + negStatus, "", "press enter to continue");
        setNegStatus("normal");
        cin.get();
    }
    
    if(negStatus == "normal") {
        return false;
    }
    
    if(negStatus == "Poison" || negStatus == "Burn") {
        printStats(defender);
        hpValue = hpValue - (maxHP * 0.05);
        textBox("", name + " lost " + to_string(static_cast<int>(maxHP * 0.05)) + " HP due to " + negStatus + ".", "", "press enter to continue");
        cin.get();
    }
    else if(negStatus == "Bleed") {
        printStats(defender);
        hpValue = hpValue - (maxHP * 0.05);
        textBox("", name + " is Bleeding and lost " + to_string(static_cast<int>(maxHP * 0.05)) + " HP.", "", "press enter to continue");
        cin.get();
    }
    
    if(hpValue <= 0) {
        return true;
    }
    
    int twentyFivePercent = rand() % 4;
    
    if(twentyFivePercent == 0) {
        
        if(negStatus == "Freeze") {
            printStats(defender);
            textBox("", name + " is Frozen and cannot move.", "", "press enter to continue");
            cin.get();
            return true;
        }
        else if(negStatus == "Shock") {
            printStats(defender);
            textBox("", name + " is Shocked and cannot move.", "", "press enter to continue");
            cin.get();
            return true;
        }
        
    }
    
    return false;
    
}

void Character::printCharacter() {
    
    cout << right << " " << setfill('-') << setw(80) << " " << endl;
    
    cout << left << setfill(' ') << setw(3) << "|";
    if(name.length() > 0) {
        cout << left << setfill(' ') << setw(77) << name + " | Level " + to_string(level) + " " + classType + " | Exp: " + to_string(exp) + "/" + to_string(10 * level) << "|" << endl;
    }
    else {
        cout << left << setfill(' ') << setw(77) << "Level " + to_string(level) + " " + classType + " | Exp: " + to_string(exp) + "/" + to_string(10 * level) << "|" << endl;
    }
    
    cout << left << setfill(' ') << setw(3) << "|";
    cout << left << setfill('-') << setw(67) << "";
    cout << right << setfill(' ') << setw(11) << "|" << endl;
    
    cout << left << setfill(' ') << setw(3) << "|";
    cout << left << setfill(' ') << setw(77) << "HP: " + to_string(hp)<< "|" << endl;
    cout << left << setfill(' ') << setw(3) << "|";
    cout << left << setfill(' ') << setw(77) << "Attack: " + to_string(attack)<< "|" << endl;
    cout << left << setfill(' ') << setw(3) << "|";
    cout << left << setfill(' ') << setw(77) << "Defense: " + to_string(defense)<< "|" << endl;
    cout << left << setfill(' ') << setw(3) << "|";
    cout << left << setfill(' ') << setw(77) << "Speed: " + to_string(speed)<< "|" << endl;
    cout << left << setfill(' ') << setw(3) << "|";
    cout << left << setfill(' ') << setw(77) << "Evasion: " + to_string(evasion)<< "|" << endl;
    cout << right << " " << setfill('-') << setw(80) << " " << endl;
    cout << endl;
    
}
void Character::printActions() {
    
    string action1MinPow = to_string(action1.minPow);
    string action2MinPow = to_string(action2.minPow);
    string action3MinPow = to_string(action3.minPow);
    string action4MinPow = to_string(action4.minPow);
    
    if(action1.minPow < 0) { action1MinPow = "0"; }
    if(action2.minPow < 0) { action2MinPow = "0"; }
    if(action3.minPow < 0) { action3MinPow = "0"; }
    if(action4.minPow < 0) { action4MinPow = "0"; }
    
    cout << right;
    cout << " " << setfill('-') << setw(40) << " ";
    cout << setfill('-') << setw(40) << " " << endl;
    
    cout << left << setfill(' ') << setw(3) << "|";
    cout << setfill(' ') << setw(37) << left << "1 " + action1.name + ", level " + to_string(action1.actLvl);
    cout << left << setfill(' ') << setw(3) << "|";
    cout << setfill(' ') << setw(37) << left << "2 " + action2.name + ", level " + to_string(action2.actLvl);
    cout << "|" << endl;
    
    cout << left << setfill(' ') << setw(5) << "|";
    cout << left << setfill(' ') << setw(35) << "Uses: " + to_string(action1.usesRemain) + "/" + to_string(action1.numUses)+ " | Damage: " + action1MinPow + "-" + to_string(action1.pow);
    cout << left << setfill(' ') << setw(5) << "|";
    cout << left << setfill(' ') << setw(35) << "Uses: " + to_string(action2.usesRemain) + "/" + to_string(action2.numUses)+ " | Damage: " + action2MinPow + "-" + to_string(action2.pow);
    cout << "|" << endl;
    
    cout << right << "|" << setfill(' ') << setw(40) << "|" << setfill(' ') << setw(40) << "|" << endl;
    
    cout << left << setfill(' ') << setw(5) << "|";
    cout << left << setfill(' ') << setw(35) << action1.description1;
    cout << left << setfill(' ') << setw(5) << "|";
    cout << left << setfill(' ') << setw(35) << action2.description1;
    cout << "|" << endl;
    
    cout << right;
    cout << " " << setfill('-') << setw(40) << " ";
    cout << setfill('-') << setw(40) << " " << endl;
    
    cout << left << setfill(' ') << setw(3) << "|";
    cout << setfill(' ') << setw(37) << left << "3 " + action3.name + ", level " + to_string(action3.actLvl);
    cout << left << setfill(' ') << setw(3) << "|";
    cout << setfill(' ') << setw(37) << left << "4 " + action4.name + ", level " + to_string(action4.actLvl);
    cout << "|" << endl;
    
    cout << left << setfill(' ') << setw(5) << "|";
    cout << left << setfill(' ') << setw(35) << "Uses: " + to_string(action3.usesRemain) + "/" + to_string(action3.numUses) + " | Damage: " + action3MinPow + "-" + to_string(action3.pow);
    cout << left << setfill(' ') << setw(5) << "|";
    cout << left << setfill(' ') << setw(35) << "Uses: " + to_string(action4.usesRemain) + "/" + to_string(action4.numUses);
    cout << "|" << endl;
    
    cout << right << "|" << setfill(' ') << setw(40) << "|" << setfill(' ') << setw(40) << "|" << endl;
    
    cout << left << setfill(' ') << setw(5) << "|";
    cout << left << setfill(' ') << setw(35) << action3.description1;
    cout << left << setfill(' ') << setw(5) << "|";
    cout << left << setfill(' ') << setw(35) << action4.description1;
    cout << "|" << endl;
    
    cout << right;
    cout << " " << setfill('-') << setw(40) << " ";
    cout << setfill('-') << setw(40) << " " << endl;
    cout << endl;
    
}
void Character::printStats(Character &player2) {
    
    cout << right << " " << setfill('-') << setw(80) << " " << endl;
    
    cout << left << setfill(' ') << setw(3) << "|";
    cout << left << setfill(' ') << setw(37) << name << "|";
    cout << right << setfill(' ') << setw(37) << player2.name;
    cout << right << setfill(' ') << setw(3) << "|" << endl;
    
    cout << left << setfill(' ') << setw(3) << "|";
    cout << left << setfill(' ') << setw(37) << "HP: " + to_string(hpValue) << "|";
    cout << right << setfill(' ') << setw(37) << "HP: " + to_string(player2.hpValue);
    cout << right << setfill(' ') << setw(3) << "|" << endl;
    
    cout << left << setfill(' ') << setw(3) << "|";
    cout << left << setfill(' ') << setw(37) << "Status: " + getNegStatus() << "|";
    cout << right << setfill(' ') << setw(37) << "Status: " + player2.getNegStatus();
    cout << right << setfill(' ') << setw(3) << "|" << endl;
    
    cout << left << setfill(' ') << setw(3) << "|";
    cout << left << setfill(' ') << setw(37) << "Boost: " + statBoost << "|";
    cout << right << setfill(' ') << setw(37) << "Boost: " + player2.statBoost;
    cout << right << setfill(' ') << setw(3) << "|" << endl;
    
    cout << right << " " << setfill('-') << setw(80) << " " << endl;
    
}

bool Character::battle(Character &player2, bool bot, int &numDefeated) {
    
    string p1Choice, p2Choice;
    bool p1Faster = true;
    bool p2Faster = false;
    int random;
    bool defeated = false;
    
    resetStats();
    player2.resetStats();
    
    textBox("Battle", name + " vs " + player2.name, "", "press enter to continue");
    cin.get();
    
    do {
        
        //printStats(player2);
        
        p1Choice = chooseAction(false, player2);
        p2Choice = player2.chooseAction(bot, *this);
        
        if(p1Choice == "Fled") {
            textBox("", name + " fled!", "", "press enter to continue");
            cin.get();
            break;
        }
        else if(p2Choice == "Fled") {
            textBox("", player2.name + " fled!", "", "press enter to continue");
            cin.get();
            break;
        }
        
        p1Faster = speed > player2.speed;
        p2Faster = player2.speed > speed;
        
        if(!p1Faster && !p2Faster) {
            random = rand() % 2;
            if(random == 0) {
                p1Faster = true;
            }
            else {
                p2Faster = true;
            }
        }
        
        if(p1Faster) {
            defeated = battleResults(player2, p1Choice, p2Choice);
            if(!defeated) {
                defeated = player2.battleResults(*this, p2Choice, p1Choice);
            }
        }
        else if(p2Faster) {
            defeated = player2.battleResults(*this, p2Choice, p1Choice);
            if(!defeated) {
                defeated = battleResults(player2, p1Choice, p2Choice);
            }
        }
        
        if(defeated) {
            if(player2.hpValue <= 0) {
                //cout << endl;
                textBox("", name + " defeated " + player2.name, "", "press enter to continue");
                cin.get();
                levelUp(player2.level, false);
                numDefeated++;
                return true;
            }
            
            if(hpValue <= 0) {
                //cout << endl;
                textBox("", player2.name + " defeated " + name, "", "press enter to continue");
                cin.get();
                player2.levelUp(level, bot);
                return false;
            }
        }
        
    } while(true);
    
    return false;
    
}
string Character::chooseAction(bool bot, Character &defender) {
    
    string choice = "1";
    int usesRemain;
    
    if(bot) {
        //Randomize choice for bot
        choice = to_string((rand() % 12) + 1);
        int randNum = (rand() % 12) + 1;
        
        if(randNum < 4) {
        //if(choice == "1" || choice == "2" || choice == "3") {
            return "1";
        }
        else if(randNum < 8) {
        //else if(choice == "4" || choice == "5" || choice == "6" || choice == "7") {
            return "2";
        }
        else if(randNum < 12) {
        //else if(choice == "8" || choice == "9" || choice == "10" || choice == "11") {
            return "3";
        }
        else {
            return "4";
        }
        //End randomize choice for bot
    }
    else {
        
        printStats(defender);
        
        cout << right << " " << setfill('-') << setw(80) << " " << endl;
        cout << left << setfill(' ') << setw(3) << "|";
        cout << left << setfill(' ') << setw(77) << name + " CHOOSE ACTION:" << "|" << endl;
        cout << left << setfill(' ') << setw(3) << "|";
        cout << left << setfill(' ') << setw(77) << "[1] -- Attack" << "|" << endl;
        cout << left << setfill(' ') << setw(3) << "|";
        cout << left << setfill(' ') << setw(77) << "[2] -- Flee" << "|" << endl;
        cout << right << " " << setfill('-') << setw(80) << " " << endl;
        
        cin >> choice;
        cin.ignore();
        cout << endl;
        
        if(choice == "2") {
            return "Fled";
        }
        else {
            
            do {
                
                printActions();
                textBox("", name + ": choose your action", "", "enter number");
                cin >> choice;
                cin.ignore();
                cout << endl;
                
                if(choice == "4") {
                    usesRemain = action4.usesRemain;
                }
                else if(choice == "3") {
                    usesRemain = action3.usesRemain;
                }
                else if(choice == "2") {
                        usesRemain = action2.usesRemain;
                }
                else {
                    usesRemain = action1.usesRemain;
                }
                
                if(usesRemain > 0) {
                    return choice;
                }
                else {
                    textBox("", "No uses remaining. Pick a different action." , "", "press enter to continue");
                    cin.get();
                    continue;
                }
                
            } while(true);
            
        }
        
    }
    
}
bool Character::battleResults(Character &defender, string p1Choice, string p2Choice) {
    
    bool statusPrevent = checkStatus(defender);
    
    if(!statusPrevent) {
        printStats(defender);
        
        if(p1Choice == "4") {
            resolveAction(defender, action4, p1Choice);
        }
        else if(p1Choice == "3") {
            resolveAction(defender, action3, p1Choice);
        }
        else if(p1Choice == "2") {
            resolveAction(defender, action2, p1Choice);
        }
        else if(p1Choice == "1") {
            resolveAction(defender, action1, p1Choice);
        }
    }
    
    if(defender.hpValue <= 0 || hpValue <= 0) {
        return true;
    }
    
    return false;
    
}
void Character::resolveAction(Character &defender, Action &action, string choice) {
   
    int attackDamage = (((rand() % action.pow) + action.minPow) + attack + attackBoost) * 10;
    
    textBox("", name + " used " + action.name + ".", "", "");
    
    if(choice == "4") {
        specialAbility(defender, attackDamage);
    }
    else if(defender.evasion + defender.evasionBoost > rand() % 150) {
        textBox("", defender.name + " evaded the attack.", "", "press enter to continue");
        cin.get();
    }
    else {
        textBox("", name + " did " + to_string(defender.lowerHP(attackDamage)) + " damage to " + defender.name, "", "press enter to continue");
        cin.get();
        calculateStatus(choice, defender);
        
    }
    action.usesRemain--;
    
}

ostream & operator<<(ostream &out, Character *player) {
    out << player->name << endl;
    out << player->classType << endl;
    out << player->hp << " ";
    out << player->attack << " ";
    out << player->defense << " ";
    out << player->speed << " ";
    out << player->evasion << endl;
    out << player->level << " ";
    out << player->exp << endl;
    out << player->action1.actLvl << " ";
    out << player->action2.actLvl << " ";
    out << player->action3.actLvl << " ";
    out << player->action4.actLvl << endl;
    out << endl;
    return out;
}
