//
//  Screen.hpp
//  Pokemon Game Final
//
//  Created by Stejara Dinulescu on 12/3/16.
//
//

#ifndef Screen_hpp
#define Screen_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Pokemon.hpp"

class Screen
{
protected:
    ofImage professorImage;
    ofImage logoImage;
    ofImage bulbasaurImage;
    ofImage charmanderImage;
    ofImage squirtleImage;
    ofImage battleScreen;
    ofTrueTypeFont font;
    char test = 0;
    char charChoice = 0;
    int wins = 0;
    int losses = 0;
    int opponentChoice{(int)ofRandom(0, 3)};
public:
    virtual void display() = 0;
    void setWins(int);
    int getWins();
    void setLosses(int);
    int getLosses();
    virtual ~Screen();
};

class StartScreen : public Screen
{
public:
    void display();
};

class ChoiceScreen : public Screen
{
public:
    void display();
};

class IntroScreenB : public Screen
{
public:
    void display();
};

class IntroScreenC : public Screen
{
public:
    void display();
};

class IntroScreenS : public Screen
{
public:
    void display();
};

class BattleScreenB : public Screen
{

Bulbasaur* bulbasaur = new Bulbasaur("BULBASAUR", "bulbasaur.png");
    
Squirtle* opponent = new Squirtle("SQUIRTLE", "squirtle.png");
    
public:
    void display();
};

class BattleScreenC : public Screen
{

Charmander* charmander = new Charmander ("CHARMANDER", "charmander.png");
    
Bulbasaur* opponent = new Bulbasaur("BULBASAUR", "bulbasaur.png");


public:
    void display();
};

class BattleScreenS : public Screen
{

Squirtle* squirtle = new Squirtle("SQUIRTLE", "squirtle.png");

Charmander* opponent = new Charmander ("CHARMANDER", "charmander.png");
    
public:
    void display();
};

class PauseScreen : public Screen
{
public:
    void display();
};

class WinScreen : public Screen
{
private:
public:

    void display();
};

class OverScreen : public Screen
{
public:
    void display();
};

#endif /* Screen_hpp */
