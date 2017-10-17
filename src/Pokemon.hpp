//
//  Pokemon.hpp
//  Pokemon Game Final
//
//  Created by Stejara Dinulescu on 12/3/16.
//
//

#ifndef Pokemon_hpp
#define Pokemon_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Moves.hpp"

class Pokemon
{
protected:
    ofImage pokemon;
    ofTrueTypeFont font;
    ofSoundPlayer pokemonSound;
    
    string pokemonName;
    string imageName;
    string soundName;
    int HP{100};
    int level{5};
    int speed{5};
public:
    
    Moves* moves = new Moves[4];
    Pokemon();
    Pokemon(string, string);
    Pokemon(const Pokemon& pokemon); //copy constructor
    Pokemon(Pokemon &&pokemon); //move copy constructor
    Pokemon& operator = (const Pokemon& pokemon); //overloaded assignment operator
    Pokemon& operator = (Pokemon&& pokemon); //move overloaded assignment operator
    void battle(Pokemon*, Pokemon*, char);
    ~Pokemon();
//Getters and setters
    void setName(string);
    string getImageName();
    void setHP(int);
    int getHP();
    void setLevel(int);
    int getLevel();
    void setSpeed(int);
    int getSpeed();
    void setPokemonName(string);
    string getPokemonName();
    void setMoves(Moves*);
    void setSoundName(string);
    string getSoundName();
    Moves* getMoves();
};

class Bulbasaur : public Pokemon
{
private:
public: 
    Bulbasaur();
    Bulbasaur(string, string);
    void display(int, int);
    void opponentDisplay(int, int);
};

class Charmander : public Pokemon
{
private:
public:
    Charmander();
    Charmander(string, string);
    void display(int, int);
    void opponentDisplay(int, int);
};

class Squirtle : public Pokemon
{
private:
public:
    Squirtle();
    Squirtle(string, string);
    void display(int, int);
    void opponentDisplay(int, int);
};

#endif /* Pokemon_hpp */
