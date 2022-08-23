#ifndef Ranger_hpp
#define Ranger_hpp

#include "Wizard.hpp"

class Ranger : public Character {
  
public:
    Ranger();
    Ranger(string);
    Ranger(string, Player);
    ~Ranger() override;
    void intializeActions() override;
    
    void calculateStatus(string choice, Character &defender) override;
    void specialAbility(Character&, int) override;
    
};

#endif /* Ranger_hpp */
