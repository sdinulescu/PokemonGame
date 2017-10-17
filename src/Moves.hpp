//
//  Moves.hpp
//  Pokemon Game Final
//
//  Created by Stejara Dinulescu on 12/3/16.
//
//

#ifndef Moves_hpp
#define Moves_hpp

#include <stdio.h>
#include <string>
using namespace std;

class Moves
{
private:
    int attack;
    int defense;
    string name;
public:
    Moves();
    Moves(string, int);
    void attackMove();
    void blockMove();
    
    void setName(string);
    string getName();
    void setAttack(int);
    int getAttack();
    void setDefense(int);
    int getDefense();
    
};

#endif /* Moves_hpp */
