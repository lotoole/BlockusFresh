//
// Created by moniq on 11/16/2018.
//

#ifndef GRAPHICS_STARTER_PLAYER_H
#define GRAPHICS_STARTER_PLAYER_H
#include <iostream>
#include <vector>
#include "Piece.h"
using namespace std;

class Player {
protected:
    string name;
    int score;
    bool human;
    vector<Piece> color1;
    vector<Piece> color2;

public:
    //default constructor
    Player();

    //getters
    string getName() const;
    int getScore() const;
    bool getHuman() const;

    //setters
    void setName(string n);
    void setScore(int s);

    //peek at hand
    void seeHand(vector<Piece> color);
    void addToScore(int s);

};

class Computer : public Player{
public:
    Computer();

    //TODO add AI functionality
};

#endif //GRAPHICS_STARTER_PLAYER_H
