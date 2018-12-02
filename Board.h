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
    double x1, y1, x2, y2, x3, y3, x4, y4;

    Coordinate(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3), x4(x4), y4(y4) {}
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
