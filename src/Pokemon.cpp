//
//  Pokemon.cpp
//  Pokemon Game Final
//
//  Created by Stejara Dinulescu on 12/3/16.
//
//

#include "Pokemon.hpp"
#include "ofApp.h"


Pokemon::Pokemon(){}
Pokemon::Pokemon(string pokemonName, string imageName)
{
    this->pokemonName = pokemonName;
    this->imageName = imageName;
    pokemon.load(imageName);
}

Pokemon::Pokemon(const Pokemon& pokemon)//copy constructor
{
    moves = new Moves[4];
    for (size_t i{}; i != 4; ++i)
        moves[i] = pokemon.moves[i];
}

Pokemon::Pokemon(Pokemon&& pokemon)//move copy constructor
{
    moves = pokemon.moves;
    pokemon.moves = nullptr;
}

Pokemon& Pokemon::operator=(const Pokemon& pokemon)//overloaded assignment operator
{
    if (this != &pokemon)
    {
        delete[] moves;
        moves = nullptr;
        moves = new Moves[4];
        for (size_t i{}; i != 4; ++i)
            moves[i] = pokemon.moves[i];
    }
    return *this;
}

Pokemon& Pokemon::operator=(Pokemon&& pokemon)//move overloaded assignment operator
{
    delete[] moves;
    moves = nullptr;
    moves = pokemon.moves;
    pokemon.moves = nullptr;
    return *this;
}


void Pokemon::battle(Pokemon* attacker, Pokemon* receiver, char choice)
{
    if (choice == '0')
    {
        cout<<"Opponent missed!"<<endl;
    } else if (choice == '1')
    {
        pokemonSound.load(receiver->getSoundName());
        pokemonSound.play();
        receiver->setHP(receiver->getHP() - attacker->moves[0].getAttack());
        cout<<attacker->getPokemonName()<<" used "<<attacker->moves[0].getName()<<"!"<<endl;
    } else if (choice == '2')
    {
        pokemonSound.load(receiver->getSoundName());
        pokemonSound.play();
        receiver->setHP(receiver->getHP() - attacker->moves[1].getAttack());
        cout<<attacker->getPokemonName()<<" used "<<attacker->moves[1].getName()<<"!"<<endl;
    }
}
Pokemon::~Pokemon()
{
    cout << "Pokemon destructor called" << endl;
    delete[] moves;
    moves = nullptr;
}


//Getters and setters

void Pokemon::setName(string imageName)
{
    this->imageName = imageName;
}

string Pokemon::getImageName()
{
    return imageName;
}

void Pokemon::setHP(int HP)
{
    this->HP = HP;
}

int Pokemon::getHP()
{
    return HP;
}

void Pokemon::setLevel(int level)
{
    this->level = level;
}

int Pokemon::getLevel()
{
    return level;
}

void Pokemon::setSpeed(int speed)
{
    this->speed = speed;
}

int Pokemon::getSpeed()
{
    return speed;
}

void Pokemon::setPokemonName(string pokemonName)
{
    this->pokemonName = pokemonName;
}

string Pokemon::getPokemonName()
{
    return pokemonName;
}

void Pokemon::setSoundName(string soundName)
{
    this->soundName = soundName;
}

string Pokemon::getSoundName()
{
    return soundName;
}

void Pokemon::setMoves(Moves* moves)
{
    this->moves = moves;
}

Moves* Pokemon::getMoves()
{
    for (int i = 0; i < 4; i++)
    {
        cout<<moves[i].getName()<<endl;
    }
    return moves;
}



Bulbasaur::Bulbasaur(string pokemonName, string imageName)
{
    this->pokemonName = pokemonName;
    this->imageName = imageName;
    soundName = "bulbasaur.mp3";
    speed = 5;
    moves[0]= *new Moves("TACKLE", 10);
    moves[1] = *new Moves("GROWL", 5);
}

void Bulbasaur::display(int xPos, int yPos)
{
    pokemon.load("battleBulbasaur.png");
    pokemon.resize(300, 300);
    pokemon.draw(xPos, yPos);
}

void Bulbasaur::opponentDisplay(int xPos, int yPos)
{
    pokemon.load("bulbasaur.png");
    pokemon.resize(300, 300);
    pokemon.draw(xPos, yPos);
}


Charmander::Charmander(string pokemonName, string imageName)
{
    this->pokemonName = pokemonName;
    this->imageName = imageName;
    soundName = "charmander.mp3";
    speed = 6;
    moves[0]= *new Moves("SCRATCH", 10);
    moves[1] = *new Moves("GROWL", 5);
}

void Charmander::display(int xPos, int yPos)
{
    pokemon.load("battleCharmander.png");
    pokemon.resize(300, 300);
    pokemon.draw(xPos, yPos);
}

void Charmander::opponentDisplay(int xPos, int yPos)
{
    pokemon.load("charmander.png");
    pokemon.resize(300, 300);
    pokemon.draw(xPos, yPos);
}

Squirtle::Squirtle(string pokemonName, string imageName)
{
    this->pokemonName = pokemonName;
    this->imageName = imageName;
    soundName = "squirtle.mp3";
    speed = 4;
    moves[0]= *new Moves("TACKLE", 10);
    moves[1] = *new Moves("TAIL WHIP", 5);
}

void Squirtle::display(int xPos, int yPos)
{
    pokemon.load("battleSquirtle.png");
    pokemon.resize(300, 300);
    pokemon.draw(xPos, yPos);
}

void Squirtle::opponentDisplay(int xPos, int yPos)
{
    pokemon.load("squirtle.png");
    pokemon.resize(300, 300);
    pokemon.draw(xPos, yPos);
}
