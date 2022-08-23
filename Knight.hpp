#ifndef Knight_hpp
#define Knight_hpp

#include "Character.hpp"

class Knight : public Character {
  
public:
    Knight();
    Knight(string);
    Knight(string, Player);
    ~Knight() override;
    void intializeActions() override;
    
    void calculateStatus(string choice, Character &defender) override;
    void specialAbility(Character&, int) override;
    
};

#endif /* Knight_hpp */
