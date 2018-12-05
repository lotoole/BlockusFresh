#include "graphics.h"
#include "Piece.h"
#include "Board.h"
#include "Player.h"

#include <vector>

using namespace std;


vector<int> isClicked(20,-1);
vector<int> angles(20,0);
int add = 1;

vector<Coordinate> boardVector;

vector<Coordinate> tiles;

GLdouble width, height;

int wd;
int mouse_x, mouse_y;
//create a vector of pieces to keep track of
vector<Piece> pieces;
//enums for tracking the current state of the game
//------------------------------------------------**
//Created by Liam OToole on 11/27/18
//------------------------------------------------**
enum screen_state {menu, game_play, game_over};
// set the screen state
screen_state screen;
//create board
Board board;
//create pieces
Piece pieceO(1,1,0);
//pieceO.setName("PieceO");
Piece piece1(1,1,0);
Piece piece2(1,1,0);
Piece piecel3(1,1,0);
Piece piecel4(1,1,0);
Piece piecel5(1,1,0);
Piece pieceY(1,1,0);
Piece pieceN(1,1,0);
Piece pieceZ4(1,1,0);
Piece pieceZ5(1,1,0);
Piece pieceL4(1,1,0);
Piece pieceL5(1,1,0);
Piece pieceV3(1,1,0);
Piece pieceV5(1,1,0);
Piece pieceW(1,1,0);
Piece pieceT4(1,1,0);
Piece pieceT5(1,1,0);
Piece pieceP(1,1,0);
Piece pieceX(1,1,0);
Piece pieceU(1,1,0);
Piece pieceF(1,1,0);
//bool to see if a click was within the bounds of the board
bool inboard = false;
bool collision = false;

//------------------------------------------------**
//Modified by Liam OToole on 11/27/18
//------------------------------------------------**
void init() {
    //setting the screens width and height
    width = 1024;
    height = 980;
    //set screen to menu when we start
    screen = menu;
}
//------------------------------------------------**
//Created by Liam OToole on 12/1/18
// create methods to update pieces vector
//------------------------------------------------**
void addPiece(Piece piece) {
    pieces.push_back(piece);

}
//------------------------------------------------**
//Created by Liam OToole on 12/2/18
// find max value in vector
//------------------------------------------------**
double findMax(double one, double two, double three, double four) {
    double maxValue = max(one, max(two, max(three, four)));

    return maxValue;
}
//------------------------------------------------**
//Created by Liam OToole on 12/2/18
// find min value in vector
//------------------------------------------------**
double findMin(double one, double two, double three, double four) {
    double minValue = min(one, min(two, min(three,four)));

    return minValue;
}
//------------------------------------------------**
// Created by Liam OToole on 11/7/18
// Display start game menu
// Modified by Monique Demers
// Modified by Liam OToole
//------------------------------------------------**
void display_menu() {
    string message = "Welcome to blokus!";
    glColor3f(1, 1, 1);
    glRasterPos2i(300, 450);
    for (int i = 0; i < message.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
    }
    //replay message
    string message2 = "Click anywhere to start";
    glColor3f(1, 1, 1);
    glRasterPos2i(300, 550);
    for (int i = 0; i < message2.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message2[i]);
    }
}

//------------------------------------------------**
//Created by Liam OToole on 11/7/18
// Moved gameplay code to new screen
//------------------------------------------------**
void display_game() {
    pieces.clear();
    glClear(GL_COLOR_BUFFER_BIT);
    //draw the users first set of pieces, first row

    addPiece(pieceO);
    addPiece(piece1);
    addPiece(piece2);
    addPiece(piecel3);
    addPiece(piecel4);
    int i;
    double x1, x2, x3, x4, y1, y2, y3, y4;
    if (!tiles.empty()) {
        for (i = 0; i < tiles.size(); i++) {
            x1 = tiles[i].x1;
            x2 = tiles[i].x2;
            x3 = tiles[i].x3;
            x4 = tiles[i].x4;
            y1 = tiles[i].y1;
            y2 = tiles[i].y2;
            y3 = tiles[i].y3;
            y4 = tiles[i].y4;
            glBegin(GL_QUADS);
            glColor3f(1, 1, 0);

            glVertex2f(x1, y1);
            glVertex2f(x2, y2);
            glVertex2f(x3, y3);
            glVertex2f(x4, y4);
            glEnd();

        }
    }

    if(isClicked[0] == 0) {
        pieceO.create_O(mouse_x, mouse_y, angles[0]);
    } else if(isClicked[0] == 777) {}
    else {
        pieceO.create_O(50, 200, angles[0]);
    }

    if(isClicked[1] == 1) {
        piece1.create_1(mouse_x, mouse_y, angles[1]);
    } else if(isClicked[1] == 777) {}
    else {
        piece1.create_1(25, 250, angles[1]);
    }

    if(isClicked[2] == 2) {
        piece2.create_2(mouse_x, mouse_y, angles[2]);
    } else if(isClicked[2] == 777) {}
    else {
        piece2.create_2(25, 300, angles[2]);
    }

    if(isClicked[3] == 3) {
        piecel3.create_l3(mouse_x, mouse_y, angles[3]);
    } else if(isClicked[3] == 777) {}
    else {
        piecel3.create_l3(25, 350, angles[3]);
    }

    if(isClicked[4] == 4) {
        piecel4.create_l4(mouse_x, mouse_y, angles[4]);
    } else if(isClicked[4] == 777) {}
    else {
        piecel4.create_l4(25, 400, angles[4]);
    }

    addPiece(piecel5);
    if(isClicked[5] == 5) {
        piecel5.create_l5(mouse_x, mouse_y, angles[5]);
    } else if(isClicked[5] == 777) {}
    else {
        piecel5.create_l5(25, 450, angles[5]);
    }


    if(isClicked[6] == 6) {
        pieceY.create_Y(mouse_x, mouse_y, angles[6]);
    } else if(isClicked[6] == 777) {}
    else {
        pieceY.create_Y(25, 500, angles[6]);
    }
    addPiece(pieceY);

    if(isClicked[7] == 7) {
        pieceN.create_N(mouse_x, mouse_y, angles[7]);
    } else if(isClicked[7] == 777) {}
    else {
        pieceN.create_N(25, 525, angles[7]);
    }
    addPiece(pieceN);

    if(isClicked[8] == 8) {
        pieceZ4.create_Z4(mouse_x, mouse_y, angles[8]);
    } else if(isClicked[8] == 777) {}
    else {
        pieceZ4.create_Z4(25, 650, angles[8]);
    }
    addPiece(pieceZ4);

    if(isClicked[9] == 9) {
        pieceZ5.create_Z5(mouse_x, mouse_y, angles[9]);
    } else if(isClicked[9] == 777) {}
    else {
        pieceZ5.create_Z5(25, 725, angles[9]);
    }
    addPiece(pieceZ5);

    if(isClicked[10] == 10) {
        pieceL4.create_L4(mouse_x, mouse_y, angles[10]);
    } else if(isClicked[10] == 777) {}
    else {
        pieceL4.create_L4(25, 800, angles[10]);
    }
    addPiece(pieceL4);

    if(isClicked[11] == 11) {
        pieceL5.create_L5(mouse_x, mouse_y, angles[11]);
    } else if(isClicked[11] == 777) {}
    else {
        pieceL5.create_L5(25, 850, angles[11]);
    }
    addPiece(pieceL5);

    //second row of pieces
    if(isClicked[12] == 12) {
        pieceV3.create_V3(mouse_x, mouse_y, angles[12]);
    } else if(isClicked[12] == 777) {}
    else {
        pieceV3.create_V3(125, 250, angles[12]);
    }
    addPiece(pieceV3);

    if(isClicked[13] == 13) {
        pieceV5.create_V5(mouse_x, mouse_y, angles[13]);
    } else if(isClicked[13] == 777) {}
    else {
        pieceV5.create_V5(125, 325, angles[13]);
    }
    addPiece(pieceV5);

    if(isClicked[14] == 14) {
        pieceW.create_W(mouse_x, mouse_y, angles[14]);
    } else if(isClicked[14] == 777) {}
    else {
        pieceW.create_W(125, 400, angles[14]);
    }
    addPiece(pieceW);

    if(isClicked[15] == 15) {
        pieceT4.create_T4(mouse_x, mouse_y, angles[15]);
    } else if(isClicked[15] == 777) {}
    else {
        pieceT4.create_T4(150, 425, angles[15]);
    }
    addPiece(pieceT4);

    if(isClicked[16] == 16) {
        pieceT5.create_T5(mouse_x, mouse_y, angles[16]);
    } else if(isClicked[16] == 777) {}
    else {
        pieceT5.create_T5(125, 500, angles[16]);
    }
    addPiece(pieceT5);

    if(isClicked[17] == 17) {
        pieceP.create_P(mouse_x, mouse_y, angles[17]);
    } else if(isClicked[17] == 777) {}
    else {
        pieceP.create_P(125, 650, angles[17]);
    }
    addPiece(pieceP);

    if(isClicked[18] == 18) {
        pieceX.create_X(mouse_x, mouse_y, angles[18]);
    } else if(isClicked[18] == 777) {}
    else {
        pieceX.create_X(125, 700, angles[18]);
    }
    addPiece(pieceX);

    if(isClicked[19] == 19) {
        pieceU.create_U(mouse_x, mouse_y, angles[19]);
    } else if(isClicked[19] == 777) {}
    else {
        pieceU.create_U(125, 800, angles[19]);
    }
    addPiece(pieceU);

    if(isClicked[20] == 20) {
        pieceF.create_F(mouse_x, mouse_y, angles[20]);
    } else if(isClicked[20] == 777) {}
    else {
        pieceF.create_F(125, 900, angles[20]);
    }
    addPiece(pieceF);


    //draw the board
    Board board;
    boardVector = board.drawBoard();
    //now draw score
    board.drawScore();
    //now draw end game button
    board.drawEndGameButton();
}

//------------------------------------------------**
//Created by Liam OToole on 11/7/18
// Display start game menu
// Modified by Monique Demers
//------------------------------------------------**
void display_game_over () {
    glClear(GL_COLOR_BUFFER_BIT);
    string message = "The game is Over!";
    glColor3f(1, 1, 1);
    glRasterPos2i(400, 550);
    for (int i = 0; i < message.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
    }
    board.gameOverScore();
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Black and opaque
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);
    
    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
//    glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1);
    glOrtho(0.0f, width, height, 0.0f, -1.0f, 1.0f);
       // Clear the color buffer with current clearing color
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    //------------------------------------------------**
    //Created by Liam OToole on 11/7/18
    // Switch that changes depending on game state the user wants
    //------------------------------------------------**
    switch(screen) {
        case menu:
            display_menu();
            break;
        case game_play:
            display_game();
            break;
        case game_over:
            display_game_over();
            break;
    }

    glFlush();

}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y) {
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }
    //------------------------------------------------**
    //Created by Liam OToole on 11/7/18
    // Change screen state on certain button clicks
    //------------------------------------------------**
    //end the game if they hit e
    if(key == 'e' && screen == game_play) {
        screen = game_over;
    }
    //end the game if they hit e
    if(key == 'e' && screen == game_play) {
        screen = game_over;
    }
    if(key == 'r' && screen == game_play) {
        for (int i = 0; i < isClicked.size(); ++i){
            if (isClicked[i] == i){
                int theta = (angles[i] + 90) % 360;
                angles[i] = theta;
            }
        }
    }
    glutPostRedisplay();
    
    return;
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:
            
            break;
        case GLUT_KEY_LEFT:
            
            break;
        case GLUT_KEY_RIGHT:
            
            break;
        case GLUT_KEY_UP:
            
            break;
    }
    
    glutPostRedisplay();
    
    return;
}

void cursor(int x, int y) {
    //Ensure variables are tracking the current mouse position
    //------------------------------------------------**
    //Created by Liam OToole on 11/7/18
    //------------------------------------------------**

    mouse_x = x;
    int add;
    add = 980 - glutGet(GLUT_WINDOW_HEIGHT);
    mouse_y = y + add;

    glutPostRedisplay();
}

//------------------------------------------------**
//Created by Nick on 12/1/18
// compare two struct's of coords
//------------------------------------------------**

bool compareCoordinate(Coordinate board, Coordinate piece){
    if(board.x1 == piece.x1 && board.x2 == piece.x2 && board.x3 == piece.x3 && board.x4 == piece.x4){
        return false;
    }
    return true;

}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {

    // Set game screen to game play if the user clicks on the screen
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP &&screen == menu && screen!= game_over) {
        screen = game_play;
    }

    //------------------------------------------------**
    //Created by Nick on 12/1/18
    // Checks for clicks within the bounds of the board
    //------------------------------------------------**
    int i;
    int j;
    int k;
    double x1, x2, x3, x4, y1, y2, y3, y4;

    inboard = false;

    if (boardVector.size() != 0) {
        for(i=0; i < pieces.size(); ++i) {
            vector<PieceCoordinate> temporary = pieces[i].getCordinates();
            double x1, x2, x3, x4, y1, y2, y3, y4;
            for (j = 0; j < temporary.size(); ++j) {

                x1 = temporary[j].x1;
                x2 = temporary[j].x2;
                x3 = temporary[j].x3;
                x4 = temporary[j].x4;
                y1 = temporary[j].y1;
                y2 = temporary[j].y2;
                y3 = temporary[j].y3;
                y4 = temporary[j].y4;

                double centerX = (x1 + x2 + x4) / 3;
                double centerY = (y1 + y2 + y4) / 3;

                for (k = 0; k <= boardVector.size(); k++) {

                    x1 = boardVector[k].x1;
                    x2 = boardVector[k].x2;
                    x3 = boardVector[k].x3;
                    x4 = boardVector[k].x4;
                    y1 = boardVector[k].y1;
                    y2 = boardVector[k].y2;
                    y3 = boardVector[k].y3;
                    y4 = boardVector[k].y4;

                    double BoardXMax = findMax(x1, x2, x3, x4);
                    double BoardYMax = findMax(y1, y2, y3, y4);
                    double BoardXMin = findMin(x1, x2, x3, x4);
                    double BoardYMin = findMin(y1, y2, y3, y4);


                    if (y1 >= mouse_y && y3 <= mouse_y && mouse_x >= x2 && mouse_x <= x1) {
                        inboard = true;
                    }

                    if (BoardYMax >= centerY && BoardYMin <= centerY && centerX >= BoardXMin && centerX <= BoardXMax) {
                            tiles.push_back(Coordinate(x1, y1, x2, y2, x3, y3, x4, y4));
                    }
                }

            }

        }
        glFlush();
    }
    //------------------------------------------------**
    //Created by Liam OToole on 12/1/18
    // all checks for when the user clicks in the menu
    //------------------------------------------------**
    //if the user clicks a location
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN  && state != GLUT_UP && screen == game_play) {
        //if the user clicks over the button, change the screen state
        if (mouse_x >= 700 && mouse_x <= 850 && mouse_y >= 850 && mouse_y <= 900) {
            screen = game_over;
        }

        //if the user clicks on a shape, make it dragable
        if(pieces.size() != 0) {
            for(int i=0; i < pieces.size(); ++i) {
                vector<PieceCoordinate> temporary = pieces[i].getCordinates();
                double x1, x2, x3, x4, y1, y2, y3, y4;
                for(int j =0; j < temporary.size(); ++j) {

                    x1 = temporary[j].x1;
                    x2 = temporary[j].x2;
                    x3 = temporary[j].x3;
                    x4 = temporary[j].x4;
                    y1 = temporary[j].y1;
                    y2 = temporary[j].y2;
                    y3 = temporary[j].y3;
                    y4 = temporary[j].y4;

                    double xMax = findMax(x1, x2, x3, x4);
                    double yMax = findMax(y1, y2, y3, y4);
                    double xMin = findMin(x1, x2, x3, x4);
                    double yMin = findMin(y1, y2, y3, y4);

                    if(mouse_x >= xMin && mouse_x <= xMax && mouse_y >= yMin && mouse_y <= yMax) {

                        //check if clicking within bounds of the board,
                        if(inboard) {
                            if(collision) {
                                //if can not be added, unbound from mouse location and print at original location
                                isClicked[pieces[i].getIsClicked()] = -1;

                            } else {
                                //if can be added, remove from display, color in board tiles
                                isClicked[pieces[i].getIsClicked()] = 777;

                            }

                        } else {

                            //if click not within board, simply make the clicked piece dragable
                            isClicked[pieces[i].getIsClicked()] = pieces[i].getIsClicked();

                        }
                    }
                }
            }
        }
    }

    glutPostRedisplay();
}

void timer(int extra) {
    
    glutPostRedisplay();
    glutTimerFunc(30, timer, 0);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    //Player testing
    Player human;
    cout << "Player Test - Human" << endl;
    cout << "Human (True/False): " << boolalpha << human.getHuman() << endl;
    cout << "Player Name: " << human.getName() << endl;
    cout << "Player Score: " << human.getScore() << endl;

    //Computer testing
    Computer computer;
    cout << "\nPlayer Test - Computer" << endl;
    cout << "Human (True/False): " << boolalpha << computer.getHuman() << endl;
    cout << "Player Name: " << computer.getName() << endl;
    cout << "Player Score: " << computer.getScore() << endl;

    //Player Setters and addToScore Testing
    cout << "\nPlayer Test - Setters" << endl;
    human.setName("Monique");
    human.setScore(100);
    cout << "Human Name: " << human.getName() << endl;
    cout << "Player Score: " << human.getScore() << endl;
    human.addToScore(5);
    cout << "Player Score: " << human.getScore() << endl;

    init();

    glutInit(&argc, argv);          // Initialize GLUT
    
    glutInitDisplayMode(GLUT_RGBA);
    
    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(100, 200); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Blokus" /* title */ );
    
    // Register callback handler for window re-paint event
    glutDisplayFunc(display);
    
    // Our own OpenGL initialization
    initGL();
    
    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);
    
    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);
    
    // handles mouse movement
    glutPassiveMotionFunc(cursor);
    
    // handles mouse click
    glutMouseFunc(mouse);
    
    // handles timer
    glutTimerFunc(0, timer, 0);
    
    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}
