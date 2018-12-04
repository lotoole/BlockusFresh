//------------------------------------------------**
//Created by Will on 11/13/18
//------------------------------------------------**

#include "graphics.h"
#include "Piece.h"

Piece::Piece(){
}

Piece::~Piece(){

}

Piece::Piece(float r, float g, float b){
    color.push_back(r);
    color.push_back(g);
    color.push_back(b);
}

void Piece::setColor(float r, float g, float b) {
    color[0] = r;
    color[1] = g;
    color[2] = b;
}

void Piece::setCordinates(double x1, double y1, double x2, double y2, double x3, double y3,double x4,double y4) {
    cordinates.push_back(PieceCoordinate(x1,y1, x2, y2, x3, y3, x4, y4));
}

void Piece::setIsClicked(int test) {
    isClicked = test;
}

int Piece::getIsClicked() {
    return isClicked;
}

vector<PieceCoordinate> Piece::getCordinates() {

    return cordinates;
}

void Piece::create_O(float x, float y, int orientation){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x,y,0);
    glRotatef(orientation, 0, 0, 1);
    glTranslatef(-x,-y,0);

    glBegin(GL_QUADS);
    glColor3f(color[0], color[1], color[2]);

    //top left
    glVertex2f(-tileSize + x, y);
    glVertex2f(-tileSize + x, tileSize + y);
    glVertex2f(x, tileSize + y);
    glVertex2f(x, y);

    //top right
    glVertex2f(x, y);
    glVertex2f(tileSize + x, y);
    glVertex2f(tileSize + x, tileSize + y);
    glVertex2f(x, tileSize + y);

    //bottom right
    glVertex2f(x, -tileSize + y);
    glVertex2f(tileSize + x, -tileSize + y);
    glVertex2f(tileSize + x, y);
    glVertex2f(x, y);

    //bottom left
    glVertex2f(-tileSize + x, -tileSize + y);
    glVertex2f(x, -tileSize + y);
    glVertex2f(x, y);
    glVertex2f(-tileSize + x, y);

    //clear cordinates
    cordinates.clear();
    //add the cordinates for each tile
    setCordinates(-tileSize + x, y, -tileSize + x, tileSize + y, x, tileSize + y, x, y);
    setCordinates(x, y, tileSize + x, y, tileSize + x, tileSize + y, x, tileSize + y );
    setCordinates(x, -tileSize + y,tileSize + x, -tileSize + y,tileSize + x, y,x, y );
    setCordinates(-tileSize + x, -tileSize + y, x, -tileSize + y, x, y, -tileSize + x, y);

    glEnd();

    //LINES (includes border and grid lines)

    glLineWidth(0.03);

    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);

    glVertex2f(-tileSize + x, -tileSize + y);
    glVertex2f(tileSize + x, -tileSize + y);

    glVertex2f(tileSize + x, -tileSize + y);
    glVertex2f(tileSize + x, tileSize + y);

    glVertex2f(tileSize + x, tileSize + y);
    glVertex2f(-tileSize + x, tileSize + y);

    glVertex2f(-tileSize + x, tileSize + y);
    glVertex2f(-tileSize + x, -tileSize + y);

    glVertex2f(x, tileSize + y);
    glVertex2f(x, -tileSize + y);

    glVertex2f(-tileSize + x, y);
    glVertex2f(tileSize + x, y);

    glEnd();

    glPopMatrix();

    isClicked = 0;

}

void Piece::create_1(float x, float y, int orientation){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x,y,0);
    glRotatef(orientation, 0, 0, 1);
    glTranslatef(-x,-y,0);

    glBegin(GL_QUADS);
    glColor3f(color[0], color[1], color[2]);

    glVertex2f(x, y);
    glVertex2f(tileSize + x, y);
    glVertex2f(tileSize + x, -tileSize + y);
    glVertex2f(x, -tileSize + y);

    //clear cordinates
    cordinates.clear();
    //add the cordinates for each tile
    setCordinates(x, y, tileSize + x, y, tileSize + x, -tileSize + y, x, -tileSize + y);

    glEnd();

    //LINES (includes border and grid lines)

    glLineWidth(0.03);

    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);

    glVertex2f(x, y);
    glVertex2f(tileSize + x, y);

    glVertex2f(tileSize + x, y);
    glVertex2f(tileSize + x, -tileSize + y);

    glVertex2f(tileSize + x, -tileSize + y);
    glVertex2f(x, -tileSize + y);

    glVertex2f(x, y);
    glVertex2f(x, -tileSize + y);

    glEnd();

    glPopMatrix();

    isClicked = 1;

}

void Piece::create_2(float x, float y, int orientation){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x,y,0);
    glRotatef(orientation, 0, 0, 1);
    glTranslatef(-x,-y,0);

    glBegin(GL_QUADS);
    glColor3f(color[0], color[1], color[2]);

    glVertex2f(x, y);
    glVertex2f(tileSize + x, y);
    glVertex2f(tileSize + x, -tileSize + y);
    glVertex2f(x, -tileSize + y);

    glVertex2f(tileSize + x, y);
    glVertex2f(2*tileSize + x, y);
    glVertex2f(2*tileSize + x, -tileSize + y);
    glVertex2f(tileSize + x, -tileSize + y);

    //clear cordinates
    cordinates.clear();
    //add the cordinates for each tile
    setCordinates(x, y, tileSize + x, y,tileSize + x, -tileSize + y, x, -tileSize + y);
    setCordinates(tileSize + x, y, 2*tileSize + x, y, 2*tileSize + x, -tileSize + y, tileSize + x, -tileSize + y);

    glEnd();

    //LINES (includes border and grid lines)

    glLineWidth(0.03);

    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);

    glVertex2f(x, y);
    glVertex2f(2*tileSize + x, y);

    glVertex2f(2*tileSize + x, y);
    glVertex2f(2*tileSize + x, -tileSize + y);

    glVertex2f(2*tileSize + x, -tileSize + y);
    glVertex2f(x, -tileSize + y);

    glVertex2f(x, y);
    glVertex2f(x, -tileSize + y);

    glVertex2f(tileSize + x, y);
    glVertex2f(tileSize + x, -tileSize + y);

    glEnd();

    glPopMatrix();

    isClicked = 2;

}

void Piece::create_l3(float x, float y, int orientation){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x,y,0);
    glRotatef(orientation, 0, 0, 1);
    glTranslatef(-x,-y,0);

    glBegin(GL_QUADS);
    glColor3f(color[0], color[1], color[2]);

    glVertex2f(x, y);
    glVertex2f(tileSize + x, y);
    glVertex2f(tileSize + x, -tileSize + y);
    glVertex2f(x, -tileSize + y);

    glVertex2f(tileSize + x, y);
    glVertex2f(2*tileSize + x, y);
    glVertex2f(2*tileSize + x, -tileSize + y);
    glVertex2f(tileSize + x, -tileSize + y);

    glVertex2f(2*tileSize + x, y);
    glVertex2f(3*tileSize + x, y);
    glVertex2f(3*tileSize + x, -tileSize + y);
    glVertex2f(2*tileSize + x, -tileSize + y);

    //clear cordinates
    cordinates.clear();
    //add the cordinates for each tile
    setCordinates(x,y, tileSize + x, y, tileSize + x, -tileSize + y, x, -tileSize + y);
    setCordinates(tileSize + x, y, 2*tileSize + x, y, 2*tileSize + x, -tileSize + y, tileSize + x, -tileSize + y);
    setCordinates(2*tileSize + x, y, 3*tileSize + x, y, 3*tileSize + x, -tileSize + y, 2*tileSize + x, -tileSize + y);

    glEnd();

    //LINES (includes border and grid lines)

    glLineWidth(0.03);

    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);

    glVertex2f(x, y);
    glVertex2f(3*tileSize + x, y);

    glVertex2f(3*tileSize + x, y);
    glVertex2f(3*tileSize + x, -tileSize + y);

    glVertex2f(3*tileSize + x, -tileSize + y);
    glVertex2f(x, -tileSize + y);

    glVertex2f(x, y);
    glVertex2f(x, -tileSize + y);

    glVertex2f(tileSize + x, y);
    glVertex2f(tileSize + x, -tileSize + y);

    glVertex2f(2*tileSize + x, y);
    glVertex2f(2*tileSize + x, -tileSize + y);

    glEnd();

    glPopMatrix();

    isClicked = 3;

}

void Piece::create_l4(float x, float y, int orientation){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x,y,0);
    glRotatef(orientation, 0, 0, 1);
    glTranslatef(-x,-y,0);

    glBegin(GL_QUADS);
    glColor3f(color[0], color[1], color[2]);

    glVertex2f(x, y);
    glVertex2f(tileSize + x, y);
    glVertex2f(tileSize + x, -tileSize + y);
    glVertex2f(x, -tileSize + y);

    glVertex2f(tileSize + x, y);
    glVertex2f(2*tileSize + x, y);
    glVertex2f(2*tileSize + x, -tileSize + y);
    glVertex2f(tileSize + x, -tileSize + y);

    glVertex2f(2*tileSize + x, y);
    glVertex2f(3*tileSize + x, y);
    glVertex2f(3*tileSize + x, -tileSize + y);
    glVertex2f(2*tileSize + x, -tileSize + y);

    glVertex2f(3*tileSize + x, y);
    glVertex2f(4*tileSize + x, y);
    glVertex2f(4*tileSize + x, -tileSize + y);
    glVertex2f(3*tileSize + x, -tileSize + y);

    //clear cordinates
    cordinates.clear();
    //add the cordinates for each tile
    setCordinates(x,y, tileSize + x, y, tileSize + x, -tileSize + y, x, -tileSize + y);
    setCordinates(tileSize + x, y, 2*tileSize + x, y, 2*tileSize + x, -tileSize + y, tileSize + x, -tileSize + y);
    setCordinates(2*tileSize + x, y, 3*tileSize + x, y, 3*tileSize + x, -tileSize + y, 2*tileSize + x, -tileSize + y);
    setCordinates(3*tileSize + x, y, 4*tileSize + x, y, 4*tileSize + x, -tileSize + y, 3*tileSize + x, -tileSize + y);

    glEnd();

    //LINES (includes border and grid lines)

    glLineWidth(0.03);

    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);

    glVertex2f(x, y);
    glVertex2f(4*tileSize + x, y);

    glVertex2f(4*tileSize + x, y);
    glVertex2f(4*tileSize + x, -tileSize + y);

    glVertex2f(4*tileSize + x, -tileSize + y);
    glVertex2f(x, -tileSize + y);

    glVertex2f(x, y);
    glVertex2f(x, -tileSize + y);

    glVertex2f(tileSize + x, y);
    glVertex2f(tileSize + x, -tileSize + y);

    glVertex2f(2*tileSize + x, y);
    glVertex2f(2*tileSize + x, -tileSize + y);

    glVertex2f(3*tileSize + x, y);
    glVertex2f(3*tileSize + x, -tileSize + y);

    glEnd();

    glPopMatrix();

    isClicked = 4;
}

void Piece::create_l5(float x, float y, int orientation){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x,y,0);
    glRotatef(orientation, 0, 0, 1);
    glTranslatef(-x,-y,0);

    glBegin(GL_QUADS);
    glColor3f(color[0], color[1], color[2]);

    glVertex2f(x, y);
    glVertex2f(tileSize + x, y);
    glVertex2f(tileSize + x, -tileSize + y);
    glVertex2f(x, -tileSize + y);

    glVertex2f(tileSize + x, y);
    glVertex2f(2*tileSize + x, y);
    glVertex2f(2*tileSize + x, -tileSize + y);
    glVertex2f(tileSize + x, -tileSize + y);

    glVertex2f(2*tileSize + x, y);
    glVertex2f(3*tileSize + x, y);
    glVertex2f(3*tileSize + x, -tileSize + y);
    glVertex2f(2*tileSize + x, -tileSize + y);

    glVertex2f(3*tileSize + x, y);
    glVertex2f(4*tileSize + x, y);
    glVertex2f(4*tileSize + x, -tileSize + y);
    glVertex2f(3*tileSize + x, -tileSize + y);

    glVertex2f(4*tileSize + x, y);
    glVertex2f(5*tileSize + x, y);
    glVertex2f(5*tileSize + x, -tileSize + y);
    glVertex2f(4*tileSize + x, -tileSize + y);

    //clear cordinates
    cordinates.clear();
    //add the cordinates for each tile
    setCordinates(x,y, tileSize + x, y, tileSize + x, -tileSize + y, x, -tileSize + y);
    setCordinates(tileSize + x, y, 2*tileSize + x, y, 2*tileSize + x, -tileSize + y, tileSize + x, -tileSize + y);
    setCordinates(2*tileSize + x, y, 3*tileSize + x, y, 3*tileSize + x, -tileSize + y, 2*tileSize + x, -tileSize + y);
    setCordinates(3*tileSize + x, y, 4*tileSize + x, y, 4*tileSize + x, -tileSize + y, 3*tileSize + x, -tileSize + y);
    setCordinates(4*tileSize + x, y, 5*tileSize + x, y, 5*tileSize + x, -tileSize + y, 4*tileSize + x, -tileSize + y);

    glEnd();

    //LINES (includes border and grid lines)

    glLineWidth(0.03);

    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);

    glVertex2f(x, y);
    glVertex2f(5*tileSize + x, y);

    glVertex2f(5*tileSize + x, y);
    glVertex2f(5*tileSize + x, -tileSize + y);

    glVertex2f(5*tileSize + x, -tileSize + y);
    glVertex2f(x, -tileSize + y);

    glVertex2f(x, y);
    glVertex2f(x, -tileSize + y);

    glVertex2f(tileSize + x, y);
    glVertex2f(tileSize + x, -tileSize + y);

    glVertex2f(2*tileSize + x, y);
    glVertex2f(2*tileSize + x, -tileSize + y);

    glVertex2f(3*tileSize + x, y);
    glVertex2f(3*tileSize + x, -tileSize + y);

    glVertex2f(4*tileSize + x, y);
    glVertex2f(4*tileSize + x, -tileSize + y);

    glEnd();

    glPopMatrix();

    isClicked = 5;

}

void Piece:: create_Y(float x, float y, int orientation){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x,y,0);
    glRotatef(orientation, 0, 0, 1);
    glTranslatef(-x,-y,0);

    glBegin(GL_QUADS);
    glColor3f(color[0], color[1], color[2]);

    glVertex2f(x, y);
    glVertex2f(tileSize + x, y);
    glVertex2f(tileSize + x, -tileSize + y);
    glVertex2f(x, -tileSize + y);

    glVertex2f(tileSize + x, y);
    glVertex2f(2*tileSize + x, y);
    glVertex2f(2*tileSize + x, -tileSize + y);
    glVertex2f(tileSize + x, -tileSize + y);

    glVertex2f(2*tileSize + x, y);
    glVertex2f(3*tileSize + x, y);
    glVertex2f(3*tileSize + x, -tileSize + y);
    glVertex2f(2*tileSize + x, -tileSize + y);

    glVertex2f(3*tileSize + x, y);
    glVertex2f(4*tileSize + x, y);
    glVertex2f(4*tileSize + x, -tileSize + y);
    glVertex2f(3*tileSize + x, -tileSize + y);

    glVertex2f(tileSize + x, -tileSize + y);
    glVertex2f(2*tileSize + x, -tileSize + y);
    glVertex2f(2*tileSize + x, -2*tileSize + y);
    glVertex2f(tileSize + x, -2*tileSize + y);

    //clear cordinates
    cordinates.clear();
    //add the cordinates for each tile
    setCordinates(x, y, tileSize + x, y, tileSize + x, -tileSize + y, x, -tileSize + y);
    setCordinates(tileSize + x, y, 2*tileSize + x, y, 2*tileSize + x, -tileSize + y, tileSize + x, -tileSize + y);
    setCordinates(2*tileSize + x, y, 3*tileSize + x, y, 3*tileSize + x, -tileSize + y, 2*tileSize + x, -tileSize + y);
    setCordinates(3*tileSize + x, y, 4*tileSize + x, y, 4*tileSize + x, -tileSize + y, 3*tileSize + x, -tileSize + y);
    setCordinates(tileSize + x, -tileSize + y, 2*tileSize + x, -tileSize + y, 2*tileSize + x, -2*tileSize + y, tileSize + x, -2*tileSize + y);

    glEnd();

    //LINES (includes border and grid lines)

    glLineWidth(0.03);

    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);

    glVertex2f(x, y);
    glVertex2f(4*tileSize + x, y);

    glVertex2f(4*tileSize + x, y);
    glVertex2f(4*tileSize + x, -tileSize + y);

    glVertex2f(4*tileSize + x, -tileSize + y);
    glVertex2f(x, -tileSize + y);

    glVertex2f(x, -tileSize + y);
    glVertex2f(x, y);

    glVertex2f(tileSize + x, y);
    glVertex2f(tileSize + x, -2*tileSize + y);

    glVertex2f(2*tileSize + x, y);
    glVertex2f(2*tileSize + x, -2*tileSize + y);

    glVertex2f(tileSize + x, -2*tileSize + y);
    glVertex2f(2*tileSize + x, -2*tileSize + y);

    glVertex2f(3*tileSize + x, y);
    glVertex2f(3*tileSize + x, -tileSize + y);

    glEnd();

    glPopMatrix();

    isClicked = 6;

}

void Piece:: create_N(float x, float y, int orientation){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x,y,0);
    glRotatef(orientation, 0, 0, 1);
    glTranslatef(-x,-y,0);

    glBegin(GL_QUADS);
    glColor3f(color[0], color[1], color[2]);

    glVertex2f(x, y);
    glVertex2f(tileSize + x, y);
    glVertex2f(tileSize + x, tileSize + y);
    glVertex2f(x, tileSize + y);

    glVertex2f(tileSize + x, y);
    glVertex2f(2*tileSize + x, y);
    glVertex2f(2*tileSize + x, tileSize + y);
    glVertex2f(tileSize + x, tileSize + y);

    glVertex2f(tileSize + x, tileSize + y);
    glVertex2f(2*tileSize + x, tileSize + y);
    glVertex2f(2*tileSize + x, 2*tileSize + y);
    glVertex2f(tileSize + x, 2*tileSize + y);

    glVertex2f(2*tileSize + x, tileSize + y);
    glVertex2f(3*tileSize + x, tileSize + y);
    glVertex2f(3*tileSize + x, 2*tileSize + y);
    glVertex2f(2*tileSize + x, 2*tileSize + y);

    glVertex2f(3*tileSize + x, tileSize + y);
    glVertex2f(4*tileSize + x, tileSize + y);
    glVertex2f(4*tileSize + x, 2*tileSize + y);
    glVertex2f(3*tileSize + x, 2*tileSize + y);
    //clear cordinates
    cordinates.clear();
    //add the cordinates for each tile
    setCordinates(x, y, tileSize + x, y, tileSize + x, tileSize + y, x, tileSize + y);
    setCordinates(tileSize + x, y, 2*tileSize + x, y, 2*tileSize + x, tileSize + y, tileSize + x, tileSize + y);
    setCordinates(tileSize + x, tileSize + y, 2*tileSize + x, tileSize + y, 2*tileSize + x, 2*tileSize + y, tileSize + x, 2*tileSize + y);
    setCordinates(2*tileSize + x, tileSize + y, 3*tileSize + x, tileSize + y, 3*tileSize + x, 2*tileSize + y, 2*tileSize + x, 2*tileSize + y);
    setCordinates(3*tileSize + x, tileSize + y, 4*tileSize + x, tileSize + y, 4*tileSize + x, 2*tileSize + y, 3*tileSize + x, 2*tileSize + y);

    glEnd();

    //LINES (includes border and grid lines)

    glLineWidth(0.03);

    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);

    glVertex2f(x, y);
    glVertex2f(2*tileSize + x, y);

    glVertex2f(x, tileSize + y);
    glVertex2f(4*tileSize + x, tileSize + y);

    glVertex2f(tileSize + x, 2*tileSize + y);
    glVertex2f(4*tileSize + x, 2*tileSize + y);

    glVertex2f(x, tileSize + y);
    glVertex2f(x, y);

    glVertex2f(tileSize + x, 2*tileSize + y);
    glVertex2f(tileSize + x, y);

    glVertex2f(2*tileSize + x, 2*tileSize + y);
    glVertex2f(2*tileSize + x, y);

    glVertex2f(3*tileSize + x, 2*tileSize + y);
    glVertex2f(3*tileSize + x, tileSize + y);

    glVertex2f(4*tileSize + x, tileSize + y);
    glVertex2f(4*tileSize + x, 2*tileSize + y);

    glEnd();

    glPopMatrix();

    isClicked = 7;
}

void Piece:: create_Z4(float x, float y, int orientation){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x,y,0);
    glRotatef(orientation, 0, 0, 1);
    glTranslatef(-x,-y,0);

    glBegin(GL_QUADS);
    glColor3f(color[0], color[1], color[2]);

    glVertex2f(x, -tileSize + y);
    glVertex2f(tileSize + x, -tileSize + y);
    glVertex2f(tileSize + x, -2*tileSize + y);
    glVertex2f(x, -2*tileSize + y);

    glVertex2f(tileSize + x, -tileSize + y);
    glVertex2f(2*tileSize + x, -tileSize + y);
    glVertex2f(2*tileSize + x, -2*tileSize + y);
    glVertex2f(tileSize + x, -2*tileSize + y);

    glVertex2f(x, y);
    glVertex2f(tileSize + x, y);
    glVertex2f(tileSize + x, -tileSize + y);
    glVertex2f(x, -tileSize + y);

    glVertex2f(tileSize + x, -2*tileSize + y);
    glVertex2f(2*tileSize + x, -2*tileSize + y);
    glVertex2f(2*tileSize + x, -3*tileSize + y);
    glVertex2f(tileSize + x, -3*tileSize + y);

    //clear cordinates
    cordinates.clear();
    //add the cordinates for each tile
    setCordinates(x, -tileSize + y, tileSize + x, -tileSize + y, tileSize + x, -2*tileSize + y, x, -2*tileSize + y);
    setCordinates(tileSize + x, -tileSize + y, 2*tileSize + x, -tileSize + y, 2*tileSize + x, -2*tileSize + y, tileSize + x, -2*tileSize + y);
    setCordinates(x, y, tileSize + x, y, tileSize + x, -tileSize + y, x, -tileSize + y);
    setCordinates(tileSize + x, -2*tileSize + y, 2*tileSize + x, -2*tileSize + y, 2*tileSize + x, -3*tileSize + y, tileSize + x, -3*tileSize + y);

    glEnd();

    //LINES (includes border and grid lines)

    glLineWidth(0.03);

    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);

    glVertex2f(x, y);
    glVertex2f(tileSize + x, y);

    glVertex2f(tileSize + x, -3*tileSize + y);
    glVertex2f(2*tileSize + x, -3*tileSize + y);

    glVertex2f(x, -tileSize + y);
    glVertex2f(2*tileSize + x, -tileSize + y);

    glVertex2f(2*tileSize + x, -tileSize + y);
    glVertex2f(2*tileSize + x, -3*tileSize + y);

    glVertex2f(2*tileSize + x, -2*tileSize + y);
    glVertex2f(x, -2*tileSize + y);

    glVertex2f(x, y);
    glVertex2f(x, -2*tileSize + y);

    glVertex2f(tileSize + x, y);
    glVertex2f(tileSize + x, -3*tileSize + y);

    glEnd();

    glPopMatrix();

    isClicked = 8;

}

void Piece:: create_Z5(float x, float y, int orientation){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x,y,0);
    glRotatef(orientation, 0, 0, 1);
    glTranslatef(-x,-y,0);

    glBegin(GL_QUADS);
    glColor3f(color[0], color[1], color[2]);

    glVertex2f(x, y);
    glVertex2f(tileSize + x, y);
    glVertex2f(tileSize + x, -tileSize + y);
    glVertex2f(x, -tileSize + y);

    glVertex2f(x, -tileSize + y);
    glVertex2f(tileSize + x, -tileSize + y);
    glVertex2f(tileSize + x, -2*tileSize + y);
    glVertex2f(x, -2*tileSize + y);

    glVertex2f(tileSize + x, -tileSize + y);
    glVertex2f(2*tileSize + x, -tileSize + y);
    glVertex2f(2*tileSize + x, -2*tileSize + y);
    glVertex2f(tileSize + x, -2*tileSize + y);

    glVertex2f(2*tileSize + x, -tileSize + y);
    glVertex2f(3*tileSize + x, -tileSize + y);
    glVertex2f(3*tileSize + x, -2*tileSize + y);
    glVertex2f(2*tileSize + x, -2*tileSize + y);

    glVertex2f(2*tileSize + x, -2*tileSize + y);
    glVertex2f(3*tileSize + x, -2*tileSize + y);
    glVertex2f(3*tileSize + x, -3*tileSize + y);
    glVertex2f(2*tileSize + x, -3*tileSize + y);

    //clear cordinates
    cordinates.clear();
    //add the cordinates for each tile
    setCordinates(x, y, tileSize + x, y, tileSize + x, -tileSize + y, x, -tileSize + y);
    setCordinates(x, -tileSize + y, tileSize + x, -tileSize + y, tileSize + x, -2*tileSize + y, x, -2*tileSize + y);
    setCordinates(tileSize + x, -tileSize + y, 2*tileSize + x, -tileSize + y, 2*tileSize + x, -2*tileSize + y, tileSize + x, -2*tileSize + y);
    setCordinates(2*tileSize + x, -tileSize + y, 3*tileSize + x, -tileSize + y, 3*tileSize + x, -2*tileSize + y, 2*tileSize + x, -2*tileSize + y);
    setCordinates(2*tileSize + x, -2*tileSize + y, 3*tileSize + x, -2*tileSize + y, 3*tileSize + x, -3*tileSize + y, 2*tileSize + x, -3*tileSize + y);

    glEnd();

    //LINES

    glLineWidth(0.03);

    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);

    glVertex2f(x, y);
    glVertex2f(x, -2*tileSize + y);

    glVertex2f(tileSize + x, y);
    glVertex2f(tileSize + x, -2*tileSize + y);

    glVertex2f(2*tileSize + x, -tileSize + y);
    glVertex2f(2*tileSize + x, -3*tileSize + y);

    glVertex2f(3*tileSize + x, -tileSize + y);
    glVertex2f(3*tileSize + x, -3*tileSize + y);

    glVertex2f(x, -tileSize + y);
    glVertex2f(3*tileSize + x, -tileSize + y);

    glVertex2f(x, y);
    glVertex2f(tileSize + x, y);

    glVertex2f(2*tileSize + x, -3*tileSize + y);
    glVertex2f(3*tileSize + x, -3*tileSize + y);

    glVertex2f(x, -2*tileSize + y);
    glVertex2f(3*tileSize + x, -2*tileSize + y);

    glEnd();

    glPopMatrix();

    isClicked = 9;
}

void Piece:: create_L4(float x, float y, int orientation){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x,y,0);
    glRotatef(orientation, 0, 0, 1);
    glTranslatef(-x,-y,0);

    glBegin(GL_QUADS);
    glColor3f(color[0], color[1], color[2]);

    glVertex2f(x, y);
    glVertex2f(tileSize + x, y);
    glVertex2f(tileSize + x, -tileSize + y);
    glVertex2f(x, -tileSize + y);

    glVertex2f(x, -tileSize + y);
    glVertex2f(tileSize + x, -tileSize + y);
    glVertex2f(tileSize + x, -2*tileSize + y);
    glVertex2f(x, -2*tileSize + y);

    glVertex2f(tileSize + x, -tileSize + y);
    glVertex2f(2*tileSize + x, -tileSize + y);
    glVertex2f(2*tileSize + x, -2*tileSize + y);
    glVertex2f(tileSize + x, -2*tileSize + y);

    glVertex2f(2*tileSize + x, -tileSize + y);
    glVertex2f(3*tileSize + x, -tileSize + y);
    glVertex2f(3*tileSize + x, -2*tileSize + y);
    glVertex2f(2*tileSize + x, -2*tileSize + y);

    //clear cordinates
    cordinates.clear();
    //add the cordinates for each tile
    setCordinates(x, y, tileSize + x, y, tileSize + x, -tileSize + y, x, -tileSize + y);
    setCordinates(x, -tileSize + y, tileSize + x, -tileSize + y, tileSize + x, -2*tileSize + y, x, -2*tileSize + y);
    setCordinates(tileSize + x, -tileSize + y, 2*tileSize + x, -tileSize + y, 2*tileSize + x, -2*tileSize + y, tileSize + x, -2*tileSize + y);
    setCordinates(2*tileSize + x, -tileSize + y, 3*tileSize + x, -tileSize + y, 3*tileSize + x, -2*tileSize + y, 2*tileSize + x, -2*tileSize + y);

    glEnd();

    //LINES

    glLineWidth(0.03);

    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);

    glVertex2f(x, y);
    glVertex2f(x, -2*tileSize + y);

    glVertex2f(tileSize + x, y);
    glVertex2f(tileSize + x, -2*tileSize + y);

    glVertex2f(2*tileSize + x, -tileSize + y);
    glVertex2f(2*tileSize + x, -2*tileSize + y);

    glVertex2f(3*tileSize + x, -tileSize + y);
    glVertex2f(3*tileSize + x, -2*tileSize + y);

    glVertex2f(x, y);
    glVertex2f(tileSize + x, y);

    glVertex2f(x, -tileSize + y);
    glVertex2f(3*tileSize + x, -tileSize + y);

    glVertex2f(x, -2*tileSize + y);
    glVertex2f(3*tileSize + x, -2*tileSize + y);

    glEnd();

    glPopMatrix();

    isClicked = 10;

}

void Piece:: create_L5(float x, float y, int orientation){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x,y,0);
    glRotatef(orientation, 0, 0, 1);
    glTranslatef(-x,-y,0);

    glBegin(GL_QUADS);
    glColor3f(color[0], color[1], color[2]);

    glVertex2f(x, y);
    glVertex2f(tileSize + x, y);
    glVertex2f(tileSize + x, -tileSize + y);
    glVertex2f(x, -tileSize + y);

    glVertex2f(x, -tileSize + y);
    glVertex2f(tileSize + x, -tileSize + y);
    glVertex2f(tileSize + x, -2*tileSize + y);
    glVertex2f(x, -2*tileSize + y);

    glVertex2f(tileSize + x, -tileSize + y);
    glVertex2f(2*tileSize + x, -tileSize + y);
    glVertex2f(2*tileSize + x, -2*tileSize + y);
    glVertex2f(tileSize + x, -2*tileSize + y);

    glVertex2f(2*tileSize + x, -tileSize + y);
    glVertex2f(3*tileSize + x, -tileSize + y);
    glVertex2f(3*tileSize + x, -2*tileSize + y);
    glVertex2f(2*tileSize + x, -2*tileSize + y);

    glVertex2f(3*tileSize + x, -tileSize + y);
    glVertex2f(4*tileSize + x, -tileSize + y);
    glVertex2f(4*tileSize + x, -2*tileSize + y);
    glVertex2f(3*tileSize + x, -2*tileSize + y);

    //clear cordinates
    cordinates.clear();
    //add the cordinates for each tile
    setCordinates(x, y, tileSize + x, y, tileSize + x, -tileSize + y, x, -tileSize + y);
    setCordinates(x, -tileSize + y, tileSize + x, -tileSize + y, tileSize + x, -2*tileSize + y, x, -2*tileSize + y);
    setCordinates(tileSize + x, -tileSize + y, 2*tileSize + x, -tileSize + y, 2*tileSize + x, -2*tileSize + y, tileSize + x, -2*tileSize + y);
    setCordinates(2*tileSize + x, -tileSize + y, 3*tileSize + x, -tileSize + y, 3*tileSize + x, -2*tileSize + y, 2*tileSize + x, -2*tileSize + y);
    setCordinates(3*tileSize + x, -tileSize + y, 4*tileSize + x, -tileSize + y, 4*tileSize + x, -2*tileSize + y, 3*tileSize + x, -2*tileSize + y);

    glEnd();

    //LINES

    glLineWidth(0.03);

    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);

    glVertex2f(x, y);
    glVertex2f(x, -2*tileSize + y);

    glVertex2f(tileSize + x, y);
    glVertex2f(tileSize + x, -2*tileSize + y);

    glVertex2f(2*tileSize + x, -tileSize + y);
    glVertex2f(2*tileSize + x, -2*tileSize + y);

    glVertex2f(3*tileSize + x, -tileSize + y);
    glVertex2f(3*tileSize + x, -2*tileSize + y);

    glVertex2f(x, y);
    glVertex2f(tileSize + x, y);

    glVertex2f(x, -tileSize + y);
    glVertex2f(4*tileSize + x, -tileSize + y);

    glVertex2f(x, -2*tileSize + y);
    glVertex2f(4*tileSize + x, -2*tileSize + y);

    glVertex2f(4*tileSize + x, -tileSize + y);
    glVertex2f(4*tileSize + x, -2*tileSize + y);

    glEnd();

    glPopMatrix();

    isClicked = 11;

}

void Piece:: create_V3(float x, float y, int orientation){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x,y,0);
    glRotatef(orientation, 0, 0, 1);
    glTranslatef(-x,-y,0);

    glBegin(GL_QUADS);
    glColor3f(color[0], color[1], color[2]);

    glVertex2f(x, y);
    glVertex2f(tileSize + x, y);
    glVertex2f(tileSize + x, -tileSize + y);
    glVertex2f(x, -tileSize + y);

    glVertex2f(x, -tileSize + y);
    glVertex2f(tileSize + x, -tileSize + y);
    glVertex2f(tileSize + x, -2*tileSize + y);
    glVertex2f(x, -2*tileSize + y);

    glVertex2f(tileSize + x, -tileSize + y);
    glVertex2f(2*tileSize + x, -tileSize + y);
    glVertex2f(2*tileSize + x, -2*tileSize + y);
    glVertex2f(tileSize + x, -2*tileSize + y);

    //clear cordinates
    cordinates.clear();
    //add the cordinates for each tile
    setCordinates(x, y, tileSize + x, y, tileSize + x, -tileSize + y, x, -tileSize + y);
    setCordinates(x, -tileSize + y, tileSize + x, -tileSize + y, tileSize + x, -2*tileSize + y, x, -2*tileSize + y);
    setCordinates(tileSize + x, -tileSize + y, 2*tileSize + x, -tileSize + y, 2*tileSize + x, -2*tileSize + y, tileSize + x, -2*tileSize + y);

    glEnd();

    //LINES

    glLineWidth(0.03);

    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);

    glVertex2f(x, y);
    glVertex2f(x, -2*tileSize + y);

    glVertex2f(tileSize + x, y);
    glVertex2f(tileSize + x, -2*tileSize + y);

    glVertex2f(2*tileSize + x, -tileSize + y);
    glVertex2f(2*tileSize + x, -2*tileSize + y);

    glVertex2f(x, y);
    glVertex2f(tileSize + x, y);

    glVertex2f(x, -tileSize + y);
    glVertex2f(2*tileSize + x, -tileSize + y);

    glVertex2f(x, -2*tileSize + y);
    glVertex2f(2*tileSize + x, -2*tileSize + y);

    glEnd();

    glPopMatrix();

    isClicked = 12;
}

void Piece:: create_V5(float x, float y, int orientation){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x,y,0);
    glRotatef(orientation, 0, 0, 1);
    glTranslatef(-x,-y,0);

    glBegin(GL_QUADS);
    glColor3f(color[0], color[1], color[2]);

    glVertex2f(x, y);
    glVertex2f(tileSize + x, y);
    glVertex2f(tileSize + x, -tileSize + y);
    glVertex2f(x, -tileSize + y);

    glVertex2f(x, -tileSize + y);
    glVertex2f(tileSize + x, -tileSize + y);
    glVertex2f(tileSize + x, -2*tileSize + y);
    glVertex2f(x, -2*tileSize + y);

    glVertex2f(x, -2*tileSize + y);
    glVertex2f(tileSize + x, -2*tileSize + y);
    glVertex2f(tileSize + x, -3*tileSize + y);
    glVertex2f(x, -3*tileSize + y);

    glVertex2f(tileSize + x, -2*tileSize + y);
    glVertex2f(2*tileSize + x, -2*tileSize + y);
    glVertex2f(2*tileSize + x, -3*tileSize + y);
    glVertex2f(tileSize + x, -3*tileSize + y);

    glVertex2f(2*tileSize + x, -2*tileSize + y);
    glVertex2f(3*tileSize + x, -2*tileSize + y);
    glVertex2f(3*tileSize + x, -3*tileSize + y);
    glVertex2f(2*tileSize + x, -3*tileSize + y);
    //clear cordinates
    cordinates.clear();
    //add the cordinates for each tile
    setCordinates(x, y, tileSize + x, y, tileSize + x, -tileSize + y, x, -tileSize + y);
    setCordinates(x, -tileSize + y, tileSize + x, -tileSize + y, tileSize + x, -2*tileSize + y, x, -2*tileSize + y);
    setCordinates(x, -2*tileSize + y, tileSize + x, -2*tileSize + y, tileSize + x, -3*tileSize + y, x, -3*tileSize + y);
    setCordinates(tileSize + x, -2*tileSize + y, 2*tileSize + x, -2*tileSize + y, 2*tileSize + x, -3*tileSize + y, tileSize + x, -3*tileSize + y);
    setCordinates(2*tileSize + x, -2*tileSize + y, 3*tileSize + x, -2*tileSize + y, 3*tileSize + x, -3*tileSize + y, 2*tileSize + x, -3*tileSize + y);

    glEnd();

    //LINES

    glLineWidth(0.03);

    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);

    glVertex2f(x, y);
    glVertex2f(x, -3*tileSize + y);

    glVertex2f(tileSize + x, y);
    glVertex2f(tileSize + x, -3*tileSize + y);

    glVertex2f(2*tileSize + x, -2*tileSize + y);
    glVertex2f(2*tileSize + x, -3*tileSize + y);

    glVertex2f(3*tileSize + x, -2*tileSize + y);
    glVertex2f(3*tileSize + x, -3*tileSize + y);

    glVertex2f(x, y);
    glVertex2f(tileSize + x, y);

    glVertex2f(x, -tileSize + y);
    glVertex2f(tileSize + x, -tileSize + y);

    glVertex2f(x, -2*tileSize + y);
    glVertex2f(3*tileSize + x, -2*tileSize + y);

    glVertex2f(x, -3*tileSize + y);
    glVertex2f(3*tileSize + x, -3*tileSize + y);

    glEnd();

    glPopMatrix();

    isClicked = 13;

}

void Piece:: create_W(float x, float y, int orientation){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x,y,0);
    glRotatef(orientation, 0, 0, 1);
    glTranslatef(-x,-y,0);

    glBegin(GL_QUADS);
    glColor3f(color[0], color[1], color[2]);

    glVertex2f(x, y);
    glVertex2f(tileSize + x, y);
    glVertex2f(tileSize + x, -tileSize + y);
    glVertex2f(x, -tileSize + y);

    glVertex2f(x, -tileSize + y);
    glVertex2f(tileSize + x, -tileSize + y);
    glVertex2f(tileSize + x, -2*tileSize + y);
    glVertex2f(x, -2*tileSize + y);

    glVertex2f(tileSize + x, -tileSize + y);
    glVertex2f(2*tileSize + x, -tileSize + y);
    glVertex2f(2*tileSize + x, -2*tileSize + y);
    glVertex2f(tileSize + x, -2*tileSize + y);

    glVertex2f(tileSize + x, -2*tileSize + y);
    glVertex2f(2*tileSize + x, -2*tileSize + y);
    glVertex2f(2*tileSize + x, -3*tileSize + y);
    glVertex2f(tileSize + x, -3*tileSize + y);

    glVertex2f(2*tileSize + x, -2*tileSize + y);
    glVertex2f(3*tileSize + x, -2*tileSize + y);
    glVertex2f(3*tileSize + x, -3*tileSize + y);
    glVertex2f(2*tileSize + x, -3*tileSize + y);
    //clear cordinates
    cordinates.clear();
    //add the cordinates for each tile
    setCordinates(x, y, tileSize + x, y, tileSize + x, -tileSize + y, x, -tileSize + y);
    setCordinates(x, -tileSize + y, tileSize + x, -tileSize + y, tileSize + x, -2*tileSize + y, x, -2*tileSize + y);
    setCordinates(tileSize + x, -tileSize + y, 2*tileSize + x, -tileSize + y, 2*tileSize + x, -2*tileSize + y, tileSize + x, -2*tileSize + y);
    setCordinates(tileSize + x, -2*tileSize + y, 2*tileSize + x, -2*tileSize + y, 2*tileSize + x, -3*tileSize + y, tileSize + x, -3*tileSize + y);
    setCordinates(2*tileSize + x, -2*tileSize + y, 3*tileSize + x, -2*tileSize + y, 3*tileSize + x, -3*tileSize + y, 2*tileSize + x, -3*tileSize + y);

    glEnd();

    //LINES

    glLineWidth(0.03);

    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);

    glVertex2f(x, y);
    glVertex2f(x, -2*tileSize + y);

    glVertex2f(tileSize + x, y);
    glVertex2f(tileSize + x, -3*tileSize + y);

    glVertex2f(2*tileSize + x, -tileSize + y);
    glVertex2f(2*tileSize + x, -3*tileSize + y);

    glVertex2f(3*tileSize + x, -2*tileSize + y);
    glVertex2f(3*tileSize + x, -3*tileSize + y);

    glVertex2f(x, y);
    glVertex2f(tileSize + x, y);

    glVertex2f(x, -tileSize + y);
    glVertex2f(2*tileSize + x, -tileSize + y);

    glVertex2f(x, -2*tileSize + y);
    glVertex2f(3*tileSize + x, -2*tileSize + y);

    glVertex2f(tileSize + x, -3*tileSize + y);
    glVertex2f(3*tileSize + x, -3*tileSize + y);

    glEnd();

    glPopMatrix();

    isClicked = 14;

}

void Piece:: create_T4(float x, float y, int orientation){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x,y,0);
    glRotatef(orientation, 0, 0, 1);
    glTranslatef(-x,-y,0);

    glBegin(GL_QUADS);
    glColor3f(color[0], color[1], color[2]);

    glVertex2f(x, y);
    glVertex2f(tileSize + x, y);
    glVertex2f(tileSize + x, tileSize + y);
    glVertex2f(x, tileSize + y);

    glVertex2f(tileSize + x, y);
    glVertex2f(2*tileSize + x, y);
    glVertex2f(2*tileSize + x, tileSize + y);
    glVertex2f(tileSize + x, tileSize + y);

    glVertex2f(2*tileSize + x, y);
    glVertex2f(3*tileSize + x, y);
    glVertex2f(3*tileSize + x, tileSize + y);
    glVertex2f(2*tileSize + x, tileSize + y);

    glVertex2f(tileSize + x, tileSize + y);
    glVertex2f(2*tileSize + x, tileSize + y);
    glVertex2f(2*tileSize + x, 2*tileSize + y);
    glVertex2f(tileSize + x, 2*tileSize + y);
    //clear cordinates
    cordinates.clear();
    //add the cordinates for each tile
    setCordinates(x, y, tileSize + x, y, tileSize + x, tileSize + y, x, tileSize + y);
    setCordinates(tileSize + x, y, 2*tileSize + x, y, 2*tileSize + x, tileSize + y, tileSize + x, tileSize + y);
    setCordinates(2*tileSize + x, y, 3*tileSize + x, y, 3*tileSize + x, tileSize + y, 2*tileSize + x, tileSize + y);
    setCordinates(tileSize + x, tileSize + y, 2*tileSize + x, tileSize + y, 2*tileSize + x, 2*tileSize + y, tileSize + x, 2*tileSize + y);

    glEnd();

    //LINES

    glLineWidth(0.03);

    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);

    glVertex2f(x, y);
    glVertex2f(x, tileSize + y);

    glVertex2f(3*tileSize + x, y);
    glVertex2f(3*tileSize + x, tileSize + y);

    glVertex2f(tileSize + x, y);
    glVertex2f(tileSize + x, 2*tileSize + y);

    glVertex2f(2*tileSize + x, y);
    glVertex2f(2*tileSize + x, 2*tileSize + y);

    glVertex2f(2*tileSize + x, y);
    glVertex2f(2*tileSize + x, tileSize + y);

    glVertex2f(x, y);
    glVertex2f(3*tileSize + x, y);

    glVertex2f(x, tileSize + y);
    glVertex2f(3*tileSize + x, tileSize + y);

    glVertex2f(tileSize + x, 2*tileSize + y);
    glVertex2f(2*tileSize + x, 2*tileSize + y);

    glEnd();

    glPopMatrix();

    isClicked = 15;

}

void Piece:: create_T5(float x, float y, int orientation){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x,y,0);
    glRotatef(orientation, 0, 0, 1);
    glTranslatef(-x,-y,0);

    glBegin(GL_QUADS);
    glColor3f(color[0], color[1], color[2]);

    glVertex2f(x, y);
    glVertex2f(tileSize + x, y);
    glVertex2f(tileSize + x, tileSize + y);
    glVertex2f(x, tileSize + y);

    glVertex2f(tileSize + x, y);
    glVertex2f(2*tileSize + x, y);
    glVertex2f(2*tileSize + x, tileSize + y);
    glVertex2f(tileSize + x, tileSize + y);

    glVertex2f(2*tileSize + x, y);
    glVertex2f(3*tileSize + x, y);
    glVertex2f(3*tileSize + x, tileSize + y);
    glVertex2f(2*tileSize + x, tileSize + y);

    glVertex2f(tileSize + x, tileSize + y);
    glVertex2f(2*tileSize + x, tileSize + y);
    glVertex2f(2*tileSize + x, 2*tileSize + y);
    glVertex2f(tileSize + x, 2*tileSize + y);

    glVertex2f(tileSize + x, 2*tileSize + y);
    glVertex2f(2*tileSize + x, 2*tileSize + y);
    glVertex2f(2*tileSize + x, 3*tileSize + y);
    glVertex2f(tileSize + x, 3*tileSize + y);
    //clear cordinates
    cordinates.clear();
    //add the cordinates for each tile
    setCordinates(x, y, tileSize + x, y, tileSize + x, tileSize + y, x, tileSize + y);
    setCordinates(tileSize + x, y, 2*tileSize + x, y, 2*tileSize + x, tileSize + y, tileSize + x, tileSize + y);
    setCordinates(2*tileSize + x, y, 3*tileSize + x, y, 3*tileSize + x, tileSize + y, 2*tileSize + x, tileSize + y);
    setCordinates(tileSize + x, tileSize + y, 2*tileSize + x, tileSize + y, 2*tileSize + x, 2*tileSize + y, tileSize + x, 2*tileSize + y);
    setCordinates(tileSize + x, 2*tileSize + y, 2*tileSize + x, 2*tileSize + y, 2*tileSize + x, 3*tileSize + y, tileSize + x, 3*tileSize + y);

    glEnd();

    //LINES

    glLineWidth(0.03);

    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);

    glVertex2f(x, y);
    glVertex2f(x, tileSize + y);

    glVertex2f(3*tileSize + x, y);
    glVertex2f(3*tileSize + x, tileSize + y);

    glVertex2f(tileSize + x, y);
    glVertex2f(tileSize + x, 3*tileSize + y);

    glVertex2f(2*tileSize + x, y);
    glVertex2f(2*tileSize + x, 3*tileSize + y);

    glVertex2f(2*tileSize + x, y);
    glVertex2f(2*tileSize + x, tileSize + y);

    glVertex2f(x, y);
    glVertex2f(3*tileSize + x, y);

    glVertex2f(x, tileSize + y);
    glVertex2f(3*tileSize + x, tileSize + y);

    glVertex2f(tileSize + x, 2*tileSize + y);
    glVertex2f(2*tileSize + x, 2*tileSize + y);

    glVertex2f(tileSize + x, 3*tileSize + y);
    glVertex2f(2*tileSize + x, 3*tileSize + y);

    glEnd();

    glPopMatrix();

    isClicked = 16;

}

void Piece:: create_P(float x, float y, int orientation){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x,y,0);
    glRotatef(orientation, 0, 0, 1);
    glTranslatef(-x,-y,0);

    glBegin(GL_QUADS);
    glColor3f(color[0], color[1], color[2]);

    glVertex2f(x, y);
    glVertex2f(tileSize + x, y);
    glVertex2f(tileSize + x, -tileSize + y);
    glVertex2f(x, -tileSize + y);

    glVertex2f(tileSize + x, y);
    glVertex2f(2*tileSize + x, y);
    glVertex2f(2*tileSize + x, -tileSize + y);
    glVertex2f(tileSize + x, -tileSize + y);

    glVertex2f(x, -tileSize + y);
    glVertex2f(tileSize + x, -tileSize + y);
    glVertex2f(tileSize + x, -2*tileSize + y);
    glVertex2f(x, -2*tileSize + y);

    glVertex2f(tileSize + x, -tileSize + y);
    glVertex2f(2*tileSize + x, -tileSize + y);
    glVertex2f(2*tileSize + x, -2*tileSize + y);
    glVertex2f(tileSize + x, -2*tileSize + y);

    glVertex2f(x, -2*tileSize + y);
    glVertex2f(tileSize + x, -2*tileSize + y);
    glVertex2f(tileSize + x, -3*tileSize + y);
    glVertex2f(x, -3*tileSize + y);
    //clear cordinates
    cordinates.clear();
    //add the cordinates for each tile
    setCordinates(x, y, tileSize + x, y, tileSize + x, -tileSize + y, x, -tileSize + y);
    setCordinates(tileSize + x, y, 2*tileSize + x, y, 2*tileSize + x, -tileSize + y, tileSize + x, -tileSize + y);
    setCordinates(x, -tileSize + y, tileSize + x, -tileSize + y, tileSize + x, -2*tileSize + y, x, -2*tileSize + y);
    setCordinates(tileSize + x, -tileSize + y, 2*tileSize + x, -tileSize + y, 2*tileSize + x, -2*tileSize + y, tileSize + x, -2*tileSize + y);
    setCordinates(x, -2*tileSize + y,tileSize + x, -2*tileSize + y, tileSize + x, -3*tileSize + y, x, -3*tileSize + y);

    glEnd();

    //LINES

    glLineWidth(0.03);

    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);

    glVertex2f(x, y);
    glVertex2f(x, -3*tileSize + y);

    glVertex2f(tileSize + x, y);
    glVertex2f(tileSize + x, -3*tileSize + y);

    glVertex2f(2*tileSize + x, y);
    glVertex2f(2*tileSize + x, -2*tileSize + y);

    glVertex2f(x, y);
    glVertex2f(2*tileSize + x, y);

    glVertex2f(x, -tileSize + y);
    glVertex2f(2*tileSize + x, -tileSize + y);

    glVertex2f(x, -2*tileSize + y);
    glVertex2f(2*tileSize + x, -2*tileSize + y);

    glVertex2f(x, -3*tileSize + y);
    glVertex2f(tileSize + x, -3*tileSize + y);

    glEnd();

    glPopMatrix();

    isClicked = 17;

}

void Piece:: create_X(float x, float y, int orientation){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x,y,0);
    glRotatef(orientation, 0, 0, 1);
    glTranslatef(-x,-y,0);

    glBegin(GL_QUADS);
    glColor3f(color[0], color[1], color[2]);

    glVertex2f(x, y);
    glVertex2f(tileSize + x, y);
    glVertex2f(tileSize + x, -tileSize + y);
    glVertex2f(x, -tileSize + y);

    glVertex2f(tileSize + x, y);
    glVertex2f(2*tileSize + x, y);
    glVertex2f(2*tileSize + x, -tileSize + y);
    glVertex2f(tileSize + x, -tileSize + y);

    glVertex2f(2*tileSize + x, y);
    glVertex2f(3*tileSize + x, y);
    glVertex2f(3*tileSize + x, -tileSize + y);
    glVertex2f(2*tileSize + x, -tileSize + y);

    glVertex2f(tileSize + x, tileSize + y);
    glVertex2f(2*tileSize + x, tileSize + y);
    glVertex2f(2*tileSize + x, y);
    glVertex2f(tileSize + x, y);

    glVertex2f(tileSize + x, -tileSize + y);
    glVertex2f(2*tileSize + x, -tileSize + y);
    glVertex2f(2*tileSize + x, -2*tileSize + y);
    glVertex2f(tileSize + x, -2*tileSize + y);

    //clear cordinates
    cordinates.clear();
    //add the cordinates for each tile
    setCordinates(x, y, tileSize + x, y, tileSize + x, -tileSize + y, x, -tileSize + y);
    setCordinates(tileSize + x, y, 2*tileSize + x, y, 2*tileSize + x, -tileSize + y, tileSize + x, -tileSize + y);
    setCordinates(2*tileSize + x, y, 3*tileSize + x, y, 3*tileSize + x, -tileSize + y, 2*tileSize + x, -tileSize + y);
    setCordinates(tileSize + x, tileSize + y, 2*tileSize + x, tileSize + y, 2*tileSize + x, y, tileSize + x, y);
    setCordinates(tileSize + x, -tileSize + y, 2*tileSize + x, -tileSize + y, 2*tileSize + x, -2*tileSize + y, tileSize + x, -2*tileSize + y);

    glEnd();

    //LINES

    glLineWidth(0.03);

    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);

    glVertex2f(x, y);
    glVertex2f(x, -tileSize + y);

    glVertex2f(3*tileSize + x, y);
    glVertex2f(3*tileSize + x, -tileSize + y);

    glVertex2f(tileSize + x, tileSize + y);
    glVertex2f(tileSize + x, -2*tileSize + y);

    glVertex2f(2*tileSize + x, tileSize + y);
    glVertex2f(2*tileSize + x, -2*tileSize + y);

    glVertex2f(3*tileSize + x, y);
    glVertex2f(3*tileSize + x, -tileSize + y);

    glVertex2f(tileSize + x, tileSize + y);
    glVertex2f(2*tileSize + x, tileSize + y);

    glVertex2f(x, y);
    glVertex2f(3*tileSize + x, y);

    glVertex2f(x, -tileSize + y);
    glVertex2f(3*tileSize + x, -tileSize + y);

    glVertex2f(tileSize + x, -2*tileSize + y);
    glVertex2f(2*tileSize + x, -2*tileSize + y);

    glEnd();

    glPopMatrix();

    isClicked = 18;

}

void Piece:: create_U(float x, float y, int orientation){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x,y,0);
    glRotatef(orientation, 0, 0, 1);
    glTranslatef(-x,-y,0);

    glBegin(GL_QUADS);
    glColor3f(color[0], color[1], color[2]);

    glVertex2f(x, y);
    glVertex2f(tileSize + x, y);
    glVertex2f(tileSize + x, -tileSize + y);
    glVertex2f(x, -tileSize + y);

    glVertex2f(tileSize + x, y);
    glVertex2f(2*tileSize + x, y);
    glVertex2f(2*tileSize + x, -tileSize + y);
    glVertex2f(tileSize + x, -tileSize + y);

    glVertex2f(2*tileSize + x, y);
    glVertex2f(3*tileSize + x, y);
    glVertex2f(3*tileSize + x, -tileSize + y);
    glVertex2f(2*tileSize + x, -tileSize + y);

    glVertex2f(x, tileSize + y);
    glVertex2f(tileSize + x, tileSize + y);
    glVertex2f(tileSize + x, y);
    glVertex2f(x, y);

    glVertex2f(2*tileSize + x, tileSize + y);
    glVertex2f(3*tileSize + x, tileSize + y);
    glVertex2f(3*tileSize + x, y);
    glVertex2f(2*tileSize + x, y);
    //clear cordinates
    cordinates.clear();
    //add the cordinates for each tile
    setCordinates(x, y, tileSize + x, y, tileSize + x, -tileSize + y, x, -tileSize + y);
    setCordinates(tileSize + x, y, 2*tileSize + x, y, 2*tileSize + x, -tileSize + y, tileSize + x, -tileSize + y);
    setCordinates(2*tileSize + x, y, 3*tileSize + x, y, 3*tileSize + x, -tileSize + y, 2*tileSize + x, -tileSize + y);
    setCordinates(x, tileSize + y, tileSize + x, tileSize + y, tileSize + x, y, x, y);
    setCordinates(2*tileSize + x, tileSize + y, 3*tileSize + x, tileSize + y, 3*tileSize + x, y, 2*tileSize + x, y);

    glEnd();

    //LINES

    glLineWidth(0.03);

    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);

    glVertex2f(x, tileSize + y);
    glVertex2f(x, -tileSize + y);

    glVertex2f(tileSize + x, tileSize + y);
    glVertex2f(tileSize + x, -tileSize + y);

    glVertex2f(2*tileSize + x, tileSize + y);
    glVertex2f(2*tileSize + x, -tileSize + y);

    glVertex2f(3*tileSize + x, tileSize + y);
    glVertex2f(3*tileSize + x, -tileSize + y);

    glVertex2f(x, tileSize + y);
    glVertex2f(tileSize + x, tileSize + y);

    glVertex2f(2*tileSize + x, tileSize + y);
    glVertex2f(3*tileSize + x, tileSize + y);

    glVertex2f(x, y);
    glVertex2f(3*tileSize + x, y);

    glVertex2f(x, -tileSize + y);
    glVertex2f(3*tileSize + x, -tileSize + y);

    glEnd();

    glPopMatrix();

    isClicked = 19;
}

void Piece:: create_F(float x, float y, int orientation){

    glBegin(GL_QUADS);
    glColor3f(color[0], color[1], color[2]);

    glVertex2f(x, y);
    glVertex2f(tileSize + x, y);
    glVertex2f(tileSize + x, -tileSize + y);
    glVertex2f(x, -tileSize + y);

    glVertex2f(tileSize + x, y);
    glVertex2f(2*tileSize + x, y);
    glVertex2f(2*tileSize + x, -tileSize + y);
    glVertex2f(tileSize + x, -tileSize + y);

    glVertex2f(2*tileSize + x, y);
    glVertex2f(3*tileSize + x, y);
    glVertex2f(3*tileSize + x, -tileSize + y);
    glVertex2f(2*tileSize + x, -tileSize + y);

    glVertex2f(x, -tileSize + y);
    glVertex2f(tileSize + x, -tileSize + y);
    glVertex2f(tileSize + x, -2*tileSize + y);
    glVertex2f(x, -2*tileSize + y);

    glVertex2f(tileSize + x, tileSize + y);
    glVertex2f(2*tileSize + x, tileSize + y);
    glVertex2f(2*tileSize + x, y);
    glVertex2f(tileSize + x, y);
    //clear cordinates
    cordinates.clear();
    //add the cordinates for each tile
    setCordinates(x, y, tileSize + x, y, tileSize + x, -tileSize + y, x, -tileSize + y);
    setCordinates(tileSize + x, y, 2*tileSize + x, y, 2*tileSize + x, -tileSize + y, tileSize + x, -tileSize + y);
    setCordinates(2*tileSize + x, y, 3*tileSize + x, y, 3*tileSize + x, -tileSize + y, 2*tileSize + x, -tileSize + y);
    setCordinates(x, -tileSize + y, tileSize + x, -tileSize + y, tileSize + x, -2*tileSize + y, x, -2*tileSize + y);
    setCordinates(tileSize + x, tileSize + y, 2*tileSize + x, tileSize + y, 2*tileSize + x, y, tileSize + x, y);

    glEnd();

    //LINES (includes border and grid lines)

    glLineWidth(0.03);

    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);

    glVertex2f(x, y);
    glVertex2f(3*tileSize + x, y);

    glVertex2f(tileSize + x, tileSize + y);
    glVertex2f(2*tileSize + x, tileSize + y);

    glVertex2f(x, -2*tileSize + y);
    glVertex2f(tileSize + x, -2*tileSize + y);

    glVertex2f(3*tileSize + x, y);
    glVertex2f(3*tileSize + x, -tileSize + y);

    glVertex2f(3*tileSize + x, -tileSize + y);
    glVertex2f(x, -tileSize + y);

    glVertex2f(x, y);
    glVertex2f(x, -2*tileSize + y);

    glVertex2f(tileSize + x, tileSize + y);
    glVertex2f(tileSize + x, -2*tileSize + y);

    glVertex2f(2*tileSize + x, tileSize + y);
    glVertex2f(2*tileSize + x, -tileSize + y);

    glEnd();

    isClicked = 20;

}
