//------------------------------------------------**
//Created by Will on 11/13/18
//------------------------------------------------**

#ifndef BLOCKUS_PIECE_H
#define BLOCKUS_PIECE_H

#include <vector>
using namespace std;
struct PieceCoordinate
{
    double x, y;

    PieceCoordinate(double x, double y) : x(x), y(y) {}
};

class Piece {

public:
    Piece();
    Piece(float r, float g, float b);
    ~Piece();

    void setColor(float r, float g, float b);


    //Piece creation methods
    void create_O(float x, float y);
    void create_1(float x, float y);
    void create_2(float x, float y);
    void create_l3(float x, float y);
    void create_l4(float x, float y);
    void create_l5(float x, float y);
    void create_Y(float x, float y);
    void create_N(float x, float y);
    void create_Z4(float x, float y);
    void create_Z5(float x, float y);
    void create_L4(float x, float y);
    void create_L5(float x, float y);
    void create_V3(float x, float y);
    void create_V5(float x, float y);
    void create_W(float x, float y);
    void create_T4(float x, float y);
    void create_T5(float x, float y);
    void create_P(float x, float y);
    void create_X(float x, float y);
    void create_U(float x, float y);
    void create_F(float x, float y);
    void setCordinates(double x, double y);
    vector<PieceCoordinate> getCordinates();
    int getNumberOfTiles();

private:
    float tileSize = 20;
    std::vector<float> color;
    std::vector<PieceCoordinate> cordinates;
    int numberOfTiles;

};

#endif //BLOCKUS_PIECE_H

