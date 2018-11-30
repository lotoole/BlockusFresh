//------------------------------------------------**
//Created by Nick on 11/17/18
//------------------------------------------------**

#include "Board.h"
#include "graphics.h"
#include <vector>

using namespace std;

Board::Board(){

}

Board::~Board(){

}

vector<Coordinate> Board::drawBoard() {


    vector<Coordinate> coords;



    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(1.0, 0.0, 0.0);
    int xsize = 0, ysize = 35;
    for (int j = 0; j < 20; j++) {
        xsize = 45;
        for (int i = 0; i < 20; i++) {
            glBegin(GL_POLYGON);
            glRasterPos2i(xsize + 100, 100 + ysize);
            glRasterPos2i(xsize + 100, 100 + ysize);
            glRasterPos2i(xsize + 100, 100 + ysize);
            glRasterPos2i(xsize + 100, 100 + ysize);

//            glRasterPos2i(xsize + 50, 50 + ysize);
//            glRasterPos2i(xsize + 50, 50 + ysize);
//            glRasterPos2i(xsize + 40, ysize + 40);
//            glRasterPos2i(xsize + 40, ysize + 40);
//            glVertex3f(xsize + 40, 40 + ysize, 0.0);
//            glVertex3f(xsize + 50, 50 + ysize, 0.0);
//            glVertex3f(xsize + 50, 50 + ysize, 0.0);
//            glVertex3f(xsize + 40, ysize + 40, 0.0);
            glEnd();



            coords.push_back(Coordinate(-50.0 + xsize, -50.0 + ysize));
            xsize += 2.0;

        }
        ysize += 2.0;
    }

    return coords;

}
//------------------------------------------------**
//Created by Liam OToole on 11/7/18
// Simply draw the score of the player and computer on the right side of the screen
//------------------------------------------------**
void Board::drawScore() {
    //Draw Player label
    string playerLabel = "Your Score:";
    glColor3f(1, 1, 1);
    glRasterPos2i(700, 400);
    for (int i = 0; i < playerLabel.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, playerLabel[i]);
    }
    //Draw Player Score
    string playerScore = to_string(userScore);
    glColor3f(1, 1, 1);
    glRasterPos2i(700, 450);
    for (int i = 0; i < playerScore.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, playerScore[i]);
    }


    //Draw Computer label
    string computerLabel = "Computer Score: ";
    glColor3f(1, 1, 1);
    glRasterPos2i(700, 500);
    for (int i = 0; i < computerLabel.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, computerLabel[i]);
    }
    //Draw Computer Score
    string compScore = to_string(computerScore);
    glColor3f(1, 1, 1);
    glRasterPos2i(700, 550);
    for (int i = 0; i < compScore.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, compScore[i]);
    }
}
//------------------------------------------------**
//Created by Liam OToole on 11/29/18
// Display a button for the user to end the game
//------------------------------------------------**
void Board::drawEndGameButton() {

    glBegin(GL_QUADS);
    int x = 1;
    int y = 1;
    glColor3f(1,1,1);

    //Draw outline
   glVertex2f(27,-22);
   glVertex2f(45,-22);
   glVertex2f(45,-27);
   glVertex2f(27,-27);

    glEnd();

    glColor3f(1, 1, 1);
    //Draw Computer Score
    string endGameText = "End Game";
    glColor3f(1, 1, 1);
    glRasterPos2i(30, -25);
    for (int i = 0; i < endGameText.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, endGameText[i]);
    }
}
//------------------------------------------------**
//Created by Liam OToole on 11/29/18
// Update score when user places piece
//------------------------------------------------**
void Board::updateUserScore() {

}
//------------------------------------------------**
//Created by Liam OToole on 11/29/18
// Update score when computer places piece
//------------------------------------------------**
void Board::updateComputerScore() {

}
//------------------------------------------------**
//Created by Liam OToole on 11/29/18
// Update score when computer places piece
//------------------------------------------------**
void Board::gameOverScore() {
    //Draw Player label
    string playerLabel = "Your Score:";
    glColor3f(1, 1, 1);
    glRasterPos2i(400, 300);
    for (int i = 0; i < playerLabel.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, playerLabel[i]);
    }
    //Draw Player Score
    string playerScore = to_string(userScore);
    glColor3f(1, 1, 1);
    glRasterPos2i(400, 350);
    for (int i = 0; i < playerScore.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, playerScore[i]);
    }


    //Draw Computer label
    string computerLabel = "Computer Score: ";
    glColor3f(1, 1, 1);
    glRasterPos2i(400, 400);
    for (int i = 0; i < computerLabel.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, computerLabel[i]);
    }
    //Draw Computer Score
    string compScore = to_string(computerScore);
    glColor3f(1, 1, 1);
    glRasterPos2i(400, 450);
    for (int i = 0; i < compScore.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, compScore[i]);
    }
}



