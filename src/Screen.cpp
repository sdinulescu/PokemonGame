//
//  Screen.cpp
//  Pokemon Game Final
//
//  Created by Stejara Dinulescu on 12/3/16.
//
//

#include "Screen.hpp"
#include "Moves.hpp"
#include <iostream>
#include "ofApp.h"

Screen::~Screen()
{
    cout<<"Screen destructor called"<<endl;
}

void Screen::setWins(int wins)
{
    this->wins = wins;
}

int Screen::getWins()
{
    return wins;
}

void Screen::setLosses(int losses)
{
    this->losses = losses;
}

int Screen::getLosses()
{
    return losses;
}

void StartScreen::display()
{
    ofSetColor(255);
    professorImage.load("professor.png");
    professorImage.resize(ofGetWidth(), ofGetHeight() - 100);
    professorImage.draw(0, 0);
    ofSetColor(0);
    font.load("font", 10);
    font.setLetterSpacing(0.9);
    font.drawString("Hello there! Welcome to the world of pokémon! My name is Oak! People call me\nthe pokémon Prof! This world is inhabited by creatures called pokémon! For\nsome people, pokémon are pets. Others use them for fights. Myself... I study \npokémon as a profession.\nPlease press any key to continue! Press 'p' to pause at any time.", 10, ofGetHeight()-75);
}

void ChoiceScreen::display()
{
    ofSetColor(255);
    //load fonts and images
    font.load("font", 10);
    logoImage.load("logo.jpg");
    bulbasaurImage.load("bulbasaur.png");
    charmanderImage.load("charmander.png");
    squirtleImage.load("squirtle.png");
    professorImage.load("professor.png");
    //draw
    logoImage.resize(600, 300);
    logoImage.draw(ofGetWidth()/2 - 100, 0);
    ofSetColor(255, 0, 0);
    font.drawString("WELCOME TO POKEMON: BATTLE EDITION", ofGetWidth() / 2, ofGetHeight() / 2 - 50);
    font.drawString("To start, pick your pokemon.", ofGetWidth() / 2 + 50, ofGetHeight() / 2);
    ofSetColor(255);
    bulbasaurImage.resize(300, 300);
    bulbasaurImage.draw(100, 0);
    charmanderImage.resize(300, 300);
    charmanderImage.draw(100, 225);
    squirtleImage.resize(300, 300);
    squirtleImage.draw(100, 450);
    professorImage.draw(ofGetWidth() / 2 - 20, ofGetHeight()/2 + 25);
}

void IntroScreenB::display()
{
    ofSetColor(255);
    professorImage.load("professor.png");
    professorImage.resize(ofGetWidth(), ofGetHeight());
    professorImage.draw(0, 0);
    ofSetColor(151, 201, 172);
    ofDrawEllipse(ofGetWidth()/2 - 300, ofGetHeight()/2, 325, 125);
    ofSetColor(195, 228, 210);
    ofDrawEllipse(ofGetWidth()/2 - 300, ofGetHeight()/2, 300, 100);
    ofSetColor(255);
    bulbasaurImage.load("bulbasaur.png");
    bulbasaurImage.resize(300, 300);
    bulbasaurImage.draw((ofGetWidth()/2 - 450), (ofGetHeight()/2) - 200);
    ofSetColor(0);
    font.load("font", 10);
    //font.setLetterSpacing(0.9);
    font.drawString("This is your Pokemon, BULBASAUR!\n\nBulbasaur is a seed pokemon, of grass and poison type.\n\nYour BULBASAUR has 2 moves: tackle and growl.\n\nTo start battling, press 'b'.", 50, 125);
}

void IntroScreenC::display()
{
    ofSetColor(255);
    professorImage.load("professor.png");
    professorImage.resize(ofGetWidth(), ofGetHeight());
    professorImage.draw(0, 0);
    ofSetColor(151, 201, 172);
    ofDrawEllipse(ofGetWidth()/2 - 300, ofGetHeight()/2 + 40, 325, 125);
    ofSetColor(195, 228, 210);
    ofDrawEllipse(ofGetWidth()/2 - 300, ofGetHeight()/2 + 40, 300, 100);
    ofSetColor(255);
    charmanderImage.load("charmander.png");
    charmanderImage.resize(300, 300);
    charmanderImage.draw((ofGetWidth()/2 - 450), (ofGetHeight()/2) - 200);
    ofSetColor(0);
    font.load("font", 10);
    font.setLetterSpacing(0.9);
    font.drawString("This is your Pokemon, CHARMANDER!\n\nCHARMANDER is a lizard pokemon, of fire type.\n\nYour CHARMANDER has 2 moves: scratch and growl.\n\nTo start battling, press 'b'.", 50, 125);
}

void IntroScreenS::display()
{
    ofSetColor(255);
    professorImage.load("professor.png");
    professorImage.resize(ofGetWidth(), ofGetHeight());
    professorImage.draw(0, 0);
    ofSetColor(151, 201, 172);
    ofDrawEllipse(ofGetWidth()/2 - 300, ofGetHeight()/2 + 20, 325, 125);
    ofSetColor(195, 228, 210);
    ofDrawEllipse(ofGetWidth()/2 - 300, ofGetHeight()/2 + 20, 300, 100);
    ofSetColor(255);
    squirtleImage.load("squirtle.png");
    squirtleImage.resize(300, 300);
    squirtleImage.draw((ofGetWidth()/2 - 450), (ofGetHeight()/2) - 200);
    ofSetColor(0);
    font.load("font", 10);
    font.setLetterSpacing(0.9);
    font.drawString("This is your Pokemon, SQUIRTLE!\n\nSQUIRTLE is a tiny turtle pokemon, of water type.\n\nYour SQUIRTLE has 2 moves: tackle and tail whip.\n\nTo start battling, press 'b'.", 50, 125);
}

void BattleScreenB::display()
{
    sleep(1);
    ofSetColor(255);
    battleScreen.load("BattleScreenTemplate.png");
    battleScreen.resize(ofGetWidth(), ofGetHeight());
    battleScreen.draw(0, 0);
    ofSetColor(255);
    bulbasaur->display(100, 240);
    opponent->opponentDisplay(600, 50);
    ofSetColor(0);
    font.load("font", 15);
    font.drawString(bulbasaur->getPokemonName(), 620, 410);
    font.drawString(opponent->getPokemonName(), 100, 130);
    font.drawString(to_string(bulbasaur->getLevel()), 380, 130);
    font.drawString(bulbasaur->moves[0].getName(), 60, 620);
    font.drawString(bulbasaur->moves[1].getName(), 410, 620);
    font.drawString(to_string(opponent->getLevel()), 900, 410);
    if (opponent->getHP() > 0 && bulbasaur->getHP() > 0)
    {
        cout<<"What does " <<bulbasaur->getPokemonName()<< " want to do? Press '1' for "<<bulbasaur->moves[0].getName()<<" or '2' for "<<bulbasaur->moves[1].getName()<<"!"<<endl;
        sleep(5);
        cin >> test;
        bulbasaur->battle(bulbasaur, opponent, test);
        ofDrawRectangle(424, 160, (opponent->getHP() - 100) * 2 - 10, 10);
        sleep(2);
        cout<<"Now, it is the opponent's turn!"<<endl;
        int opponentChoice = ofRandom(0, 3);
        if (opponentChoice == 0)
        {
            charChoice='0';
        } else if (opponentChoice == 1)
        {
            charChoice='1';
        } else if (opponentChoice == 2)
        {
            charChoice='2';
        }
        opponent->battle(opponent, bulbasaur, charChoice);
        ofDrawRectangle(945, 438, (bulbasaur->getHP() - 100) * 2 - 10, 10);
    } else if (opponent->getHP() <= 0)
    {
        cout<<opponent->getPokemonName()<<" fainted! Press the 'w' key to continue."<<endl;
        ofSetColor(255);
        battleScreen.draw(0, 0);
        bulbasaur->display(100, 240);
        ofSetColor(0);
        font.load("font", 15);
        font.drawString(bulbasaur->getPokemonName(), 620, 410);
        font.drawString(opponent->getPokemonName(), 100, 130);
        font.drawString(to_string(bulbasaur->getLevel()), 380, 130);
        font.drawString(bulbasaur->moves[0].getName(), 60, 620);
        font.drawString(bulbasaur->moves[1].getName(), 410, 620);
        font.drawString(to_string(opponent->getLevel()), 900, 410);
        ofDrawRectangle(424, 160, -201, 10);
    } else if (bulbasaur->getHP() <= 0)
    {
        cout<<bulbasaur->getPokemonName()<<" fainted! Press the 'q' key to continue."<<endl;
        ofSetColor(255);
        battleScreen.draw(0, 0);
        opponent->opponentDisplay(600, 50);
        ofSetColor(0);
        font.load("font", 15);
        font.drawString(bulbasaur->getPokemonName(), 620, 410);
        font.drawString(opponent->getPokemonName(), 100, 130);
        font.drawString(to_string(bulbasaur->getLevel()), 380, 130);
        font.drawString(bulbasaur->moves[0].getName(), 60, 620);
        font.drawString(bulbasaur->moves[1].getName(), 410, 620);
        font.drawString(to_string(opponent->getLevel()), 900, 410);
        ofDrawRectangle(945, 438, -201, 10);
    }
}

void BattleScreenC::display()
{
    sleep(1);
    ofSetColor(255);
    battleScreen.load("BattleScreenTemplate.png");
    battleScreen.resize(ofGetWidth(), ofGetHeight());
    battleScreen.draw(0, 0);
    ofSetColor(255);
    charmander->display(100, 240);
    opponent->opponentDisplay(600, 50);
    ofSetColor(0);
    font.load("font", 15);
    font.drawString(charmander->getPokemonName(), 620, 410);
    font.drawString(opponent->getPokemonName(), 100, 130);
    font.drawString(to_string(charmander->getLevel()), 380, 130);
    font.drawString(charmander->moves[0].getName(), 60, 620);
    font.drawString(charmander->moves[1].getName(), 410, 620);
    font.drawString(to_string(opponent->getLevel()), 900, 410);
    if (opponent->getHP() > 0 && charmander->getHP() > 0)
    {
        cout<<"What does " <<charmander->getPokemonName()<< " want to do? Press '1' for "<<charmander->moves[0].getName()<<" or '2' for "<<charmander->moves[1].getName()<<"!"<<endl;
        sleep(5);
        cin >> test;
        charmander->battle(charmander, opponent, test);
        ofDrawRectangle(424, 160, (opponent->getHP() - 100) * 2 - 10, 10);
        sleep(2);
        cout<<"Now, it is the opponent's turn!"<<endl;
        int opponentChoice = ofRandom(0, 3);
        if (opponentChoice == 0)
        {
            charChoice='0';
        } else if (opponentChoice == 1)
        {
            charChoice='1';
        } else if (opponentChoice == 2)
        {
            charChoice='2';
        }
        opponent->battle(opponent, charmander, charChoice);
        ofDrawRectangle(945, 438, (charmander->getHP() - 100) * 2 - 10, 10);
    } else if (opponent->getHP() <= 0)
    {
        cout<<opponent->getPokemonName()<<" fainted! Press the 'w' key to continue."<<endl;
        ofSetColor(255);
        battleScreen.draw(0, 0);
        charmander->display(100, 240);
        ofSetColor(0);
        font.load("font", 15);
        font.drawString(charmander->getPokemonName(), 620, 410);
        font.drawString(opponent->getPokemonName(), 100, 130);
        font.drawString(to_string(charmander->getLevel()), 380, 130);
        font.drawString(charmander->moves[0].getName(), 60, 620);
        font.drawString(charmander->moves[1].getName(), 410, 620);
        font.drawString(to_string(opponent->getLevel()), 900, 410);
        ofDrawRectangle(424, 160, -201, 10);
    } else if (charmander->getHP() <= 0)
    {
        cout<<charmander->getPokemonName()<<" fainted! Press the 'q' key to continue."<<endl;
        ofSetColor(255);
        battleScreen.draw(0, 0);
        opponent->opponentDisplay(600, 50);
        ofSetColor(0);
        font.load("font", 15);
        font.drawString(charmander->getPokemonName(), 620, 410);
        font.drawString(opponent->getPokemonName(), 100, 130);
        font.drawString(to_string(charmander->getLevel()), 380, 130);
        font.drawString(charmander->moves[0].getName(), 60, 620);
        font.drawString(charmander->moves[1].getName(), 410, 620);
        font.drawString(to_string(opponent->getLevel()), 900, 410);
        ofDrawRectangle(945, 438, -201, 10);
    }
}

void BattleScreenS::display()
{
    sleep(1);
    ofSetColor(255);
    battleScreen.load("BattleScreenTemplate.png");
    battleScreen.resize(ofGetWidth(), ofGetHeight());
    battleScreen.draw(0, 0);
    ofSetColor(255);
    squirtle->display(100, 240);
    opponent->opponentDisplay(600, 50);
    ofSetColor(0);
    font.load("font", 15);
    font.drawString(squirtle->getPokemonName(), 620, 410);
    font.drawString(opponent->getPokemonName(), 100, 130);
    font.drawString(to_string(squirtle->getLevel()), 380, 130);
    font.drawString(squirtle->moves[0].getName(), 60, 620);
    font.drawString(squirtle->moves[1].getName(), 410, 620);
    font.drawString(to_string(opponent->getLevel()), 900, 410);
    if (opponent->getHP() > 0 && squirtle->getHP() > 0)
    {
        cout<<"What does " <<squirtle->getPokemonName()<< " want to do? Press '1' for "<<squirtle->moves[0].getName()<<" or '2' for "<<squirtle->moves[1].getName()<<"!"<<endl;
        sleep(5);
        cin >> test;
        squirtle->battle(squirtle, opponent, test);
        ofDrawRectangle(424, 160, (opponent->getHP() - 100) * 2 - 10, 10);
        sleep(2);
        cout<<"Now, it is the opponent's turn!"<<endl;
        int opponentChoice = ofRandom(0, 3);
        if (opponentChoice == 0)
        {
            charChoice='0';
        } else if (opponentChoice == 1)
        {
            charChoice='1';
        } else if (opponentChoice == 2)
        {
            charChoice='2';
        }
        opponent->battle(opponent, squirtle, charChoice);
        ofDrawRectangle(945, 438, (squirtle->getHP() - 100) * 2 - 10, 10);
    } else if (opponent->getHP() <= 0)
    {
        cout<<opponent->getPokemonName()<<" fainted! Press the 'w' key to continue."<<endl;
        ofSetColor(255);
        battleScreen.draw(0, 0);
        squirtle->display(100, 240);
        ofSetColor(0);
        font.load("font", 15);
        font.drawString(squirtle->getPokemonName(), 620, 410);
        font.drawString(opponent->getPokemonName(), 100, 130);
        font.drawString(to_string(squirtle->getLevel()), 380, 130);
        font.drawString(squirtle->moves[0].getName(), 60, 620);
        font.drawString(squirtle->moves[1].getName(), 410, 620);
        font.drawString(to_string(opponent->getLevel()), 900, 410);
        ofDrawRectangle(424, 160, -201, 10);
    } else if (squirtle->getHP() <= 0)
    {
        cout<<squirtle->getPokemonName()<<" fainted! Press the 'q' key to continue."<<endl;
        ofSetColor(255);
        battleScreen.draw(0, 0);
        opponent->opponentDisplay(600, 50);
        ofSetColor(0);
        font.load("font", 15);
        font.drawString(squirtle->getPokemonName(), 620, 410);
        font.drawString(opponent->getPokemonName(), 100, 130);
        font.drawString(to_string(squirtle->getLevel()), 380, 130);
        font.drawString(squirtle->moves[0].getName(), 60, 620);
        font.drawString(squirtle->moves[1].getName(), 410, 620);
        font.drawString(to_string(opponent->getLevel()), 900, 410);
        ofDrawRectangle(945, 438, -201, 10);
    }
}

void PauseScreen::display()
{
    ofSetColor(255);
    professorImage.load("professor.png");
    professorImage.resize(ofGetWidth(), ofGetHeight() - 100);
    professorImage.draw(0, 0);
    ofSetColor(0);
    font.load("font", 10);
    font.setLetterSpacing(0.9);
    font.drawString("Game is paused. Please press 'r' to resume!", 10, ofGetHeight()-75);
}

void WinScreen::display()
{
    ofSetColor(255);
    professorImage.load("professor.png");
    professorImage.resize(ofGetWidth(), ofGetHeight());
    professorImage.draw(0, 0);
    ofSetColor(0);
    font.load("font", 10);
    font.drawString("Congratulations! You won! Press the spacebar to play again!\nPress 'e' to end game.", 100, 100);
    font.load("font", 10);
    font.drawString("WINS: ", 20, ofGetHeight()/2);
    font.drawString(to_string(getWins()), 120, ofGetHeight()/2);
    font.drawString("LOSSES: ", 20, ofGetHeight()/2 + 50);
    font.drawString(to_string(getLosses()), 120, ofGetHeight()/2 + 50);
}

void OverScreen::display()
{
    ofSetColor(255);
    professorImage.load("professor.png");
    professorImage.resize(ofGetWidth(), ofGetHeight());
    professorImage.draw(0, 0);
    ofSetColor(0);
    font.load("font", 10);
    font.drawString("You lost! Press the spacebar to play again!\nPress 'e' to end game.", 100, 100);
    font.load("font", 10);
    font.drawString("WINS: ", 20, ofGetHeight()/2);
    font.drawString(to_string(getWins()), 120, ofGetHeight()/2) ;
    font.drawString("LOSSES: ", 20, ofGetHeight()/2 + 50);
    font.drawString(to_string(getLosses()), 120, ofGetHeight()/2 + 50);
}