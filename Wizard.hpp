#ifndef Wizard_hpp
#define Wizard_hpp

#include "Knight.hpp"

class Wizard : public Character {
  
public:
    Wizard();
    Wizard(string);
    Wizard(string, Player);
    ~Wizard() override;
    void intializeActions() override;
    
    void calculateStatus(string choice, Character &defender) override;
    void specialAbility(Character&, int) override;
  
};

#endif /* Wizard_hpp */
