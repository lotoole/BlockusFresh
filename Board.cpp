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
    int xsize = 0, ysize = 15;
    for (int j = 0; j < 20; j++) {
        xsize = 25;
        for (int i = 0; i < 20; i++) {
            glBegin(GL_POLYGON);
            glVertex3f(-50.0 + xsize, -50.0 + ysize, 0.0);
            glVertex3f(-40.0 + xsize, -50.0 + ysize, 0.0);
            glVertex3f(-40.0 + xsize, -40.0 + ysize, 0.0);
            glVertex3f(-50.0 + xsize, -40.0 + ysize, 0.0);
            glEnd();


            coords.push_back(Coordinate(-50.0 + xsize, -50.0 + ysize));
            xsize += 2.0;

        }
        ysize += 2.0;
    }

    return coords;

}


