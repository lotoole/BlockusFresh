//------------------------------------------------**
//Created by Will on 11/13/18
//------------------------------------------------**

#ifndef BLOCKUS_PIECE_H
#define BLOCKUS_PIECE_H

#include <vector>
using namespace std;
struct PieceCoordinate
{
    double x1, y1, x2, y2, x3, y3, x4, y4;

    PieceCoordinate(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3), x4(x4), y4(y4) {}
};

class Piece {

public:
    Piece();
    Piece(float r, float g, float b);
    ~Piece();

    void setColor(float r, float g, float b);


    //Piece creation methods
    void create_O(float x, float y, int orientation);
    void create_1(float x, float y, int orientation);
    void create_2(float x, float y, int orientation);
    void create_l3(float x, float y, int orientation);
    void create_l4(float x, float y, int orientation);
    void create_l5(float x, float y, int orientation);
    void create_Y(float x, float y, int orientation);
    void create_N(float x, float y, int orientation);
    void create_Z4(float x, float y, int orientation);
    void create_Z5(float x, float y, int orientation);
    void create_L4(float x, float y, int orientation);
    void create_L5(float x, float y, int orientation);
    void create_V3(float x, float y, int orientation);
    void create_V5(float x, float y, int orientation);
    void create_W(float x, float y, int orientation);
    void create_T4(float x, float y, int orientation);
    void create_T5(float x, float y, int orientation);
    void create_P(float x, float y, int orientation);
    void create_X(float x, float y, int orientation);
    void create_U(float x, float y, int orientation);
    void create_F(float x, float y, int orientation);
    void setCordinates(double x1, double y1, double x2, double y2, double x3, double y3,double x4,double y4);
    vector<PieceCoordinate> getCordinates();
    void setIsClicked(int test);
    int getIsClicked();
private:
    float tileSize = 20;
    std::vector<float> color;
    std::vector<PieceCoordinate> cordinates;
    int isClicked;

};

#endif //BLOCKUS_PIECE_H

