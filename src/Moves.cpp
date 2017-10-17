//
//  Moves.cpp
//  Pokemon Game Final
//
//  Created by Stejara Dinulescu on 12/3/16.
//
//

#include "Moves.hpp"

Moves::Moves(){}

Moves::Moves(string name, int attack)
{
    this->name = name;
    this->attack = attack;
}

void Moves::attackMove()
{
    
}

void Moves::blockMove()
{
    
}

void Moves::setName(string name)
{
    this->name = name;
}

string Moves::getName()
{
    return name;
}

void Moves::setAttack(int attack)
{
    this->attack = attack;
}

int Moves::getAttack()
{
    return attack;
}

void Moves::setDefense(int defense)
{
    this->defense = defense;
}

int Moves::getDefense()
{
    return defense;
}