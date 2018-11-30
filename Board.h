//------------------------------------------------**
//Created by Nick on 11/17/18
//modified by Liam OToole on 11/29/18
//------------------------------------------------**

#include <vector>

using namespace std;

#ifndef GRAPHICS_STARTER_BOARD_H
#define GRAPHICS_STARTER_BOARD_H

struct Coordinate
{
    double x, y;

    Coordinate(double x, double y) : x(x), y(y) {}
};

class Board {

public:
    Board();
    ~Board();

    //Creates Board
    vector<Coordinate> drawBoard();
    //create score variables and methods
    void updateUserScore();
    void updateComputerScore();
    void drawScore();
    void gameOverScore();
    void drawEndGameButton();

private:
    int userScore = 0;
    int computerScore = 0;



};

#endif //GRAPHICS_STARTER_BOARD_H
