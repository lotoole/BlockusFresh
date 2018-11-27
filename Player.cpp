//
// Created by moniq on 11/16/2018.
//

#include "Player.h"
Player::Player() {
    name = "Human";
    score = 0;
    human = true;

    //TODO ADD HANDS
}

string Player::getName() const {
    return name;
}

int Player::getScore() const {
    return score;
}

bool Player::getHuman() const {
    return human;
}

void Player::setName(string n) {
    name = n;
}

void Player::setScore(int s) {
    score = s;
}

//TODO Add player hand
void Player::seeHand(vector<Piece> color) {
}

void Player::addToScore(int s) {
    score = Player::getScore() + s;
}

Computer::Computer() : Player() {
    name = "Computer";
    score = 0;
    human = false;

}