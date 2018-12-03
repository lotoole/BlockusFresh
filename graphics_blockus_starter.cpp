#include "graphics.h"
#include "Piece.h"
#include "Board.h"
#include "Player.h"

#include <vector>

using namespace std;

vector<Coordinate> boardVector;

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
bool inboard = true;

bool pieceOClicked = false;
bool piece1Clicked = false;
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
    if(piece1Clicked) {
        pieceO.create_O(mouse_x, mouse_y);
    } else {
        pieceO.create_O(50, 200);
    }

    if(pieceOClicked) {
        piece1.create_1(mouse_x, mouse_y);
    } else {
        piece1.create_1(25, 250);
    }
    addPiece(piece1);

    if(piece2.getIsClicked()) {
        piece2.create_2(mouse_x, mouse_y);
    } else {
        piece2.create_2(25, 300);
    }
    addPiece(piece2);

    if(piecel3.getIsClicked()) {
        piecel3.create_l3(mouse_x, mouse_y);
    } else {
        piecel3.create_l3(25, 350);
    }
    addPiece(piecel3);

    if(piecel4.getIsClicked()) {
        piecel4.create_l4(mouse_x, mouse_y);
    } else {
        piecel4.create_l4(25, 400);
    }
    addPiece(piecel4);

    if(piecel5.getIsClicked()) {
        piecel5.create_l5(mouse_x, mouse_y);
    } else {
        piecel5.create_l5(25, 450);
    }
    addPiece(piecel5);

    if(pieceY.getIsClicked()) {
        pieceY.create_Y(mouse_x, mouse_y);
    } else {
        pieceY.create_Y(25, 500);
    }
    addPiece(pieceY);

    if(pieceN.getIsClicked()) {
        pieceN.create_N(mouse_x, mouse_y);
    } else {
        pieceN.create_N(25, 525);
    }
    addPiece(pieceN);

    if(pieceZ4.getIsClicked()) {
        pieceZ4.create_Z4(mouse_x, mouse_y);
    } else {
        pieceZ4.create_Z4(25, 650);
    }
    addPiece(pieceZ4);

    if(pieceZ5.getIsClicked()) {
        pieceZ5.create_Z5(mouse_x, mouse_y);
    } else {
        pieceZ5.create_Z5(25, 725);
    }
    addPiece(pieceZ5);

    if(pieceL4.getIsClicked()) {
        pieceL4.create_Z5(mouse_x, mouse_y);
    } else {
        pieceL4.create_L4(25, 800);
    }
    addPiece(pieceL4);

    if(pieceL5.getIsClicked()) {
        pieceL5.create_L5(mouse_x, mouse_y);
    } else {
        pieceL5.create_L5(25, 850);
    }
    addPiece(pieceL5);

    //second row of pieces
    if(pieceV3.getIsClicked()) {
        pieceV3.create_V3(mouse_x, mouse_y);
    } else {
        pieceV3.create_V3(125, 250);
    }
    addPiece(pieceV3);

    if(pieceV5.getIsClicked()) {
        pieceV5.create_V5(mouse_x, mouse_y);
    } else {
        pieceV5.create_V5(125, 325);
    }
    addPiece(pieceV5);

    if(pieceW.getIsClicked()) {
        pieceW.create_W(mouse_x, mouse_y);
    } else {
        pieceW.create_W(125, 400);
    }
    addPiece(pieceW);

    if(pieceT4.getIsClicked()) {
        pieceT4.create_T4(mouse_x, mouse_y);
    } else {
        pieceT4.create_T4(150, 425);
    }
    addPiece(pieceT4);

    if(pieceT5.getIsClicked()) {
        pieceT5.create_T5(mouse_x, mouse_y);
    } else {
        pieceT5.create_T5(125, 500);
    }
    addPiece(pieceT5);

    if(pieceP.getIsClicked()) {
        pieceP.create_P(mouse_x, mouse_y);
    } else {
        pieceP.create_P(125, 650);
    }
    addPiece(pieceP);

    if(pieceX.getIsClicked()) {
        pieceX.create_X(mouse_x, mouse_y);
    } else {
        pieceX.create_X(125, 700);
    }
    addPiece(pieceX);

    if(pieceU.getIsClicked()) {
        pieceU.create_U(mouse_x, mouse_y);
    } else {
        pieceU.create_U(125, 800);
    }
    addPiece(pieceU);

    if(pieceF.getIsClicked()) {
        pieceF.create_F(mouse_x, mouse_y);
    } else {
        pieceF.create_F(125, 900);
    }
    addPiece(pieceF);

    //draw the board
//    Board board;
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
    mouse_y = y + 125;

    glutPostRedisplay();
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
    double x1, x2, x3, x4, y1, y2, y3, y4;
    double minX,minY,maxX,maxY;
    minX=999;
    minY=999;
    maxX=0;
    maxY=0;

    if (boardVector.size() != 0) {
        for (i = 0; i <= boardVector.size(); i++){

            x1 = boardVector[i].x1;
            x2 = boardVector[i].x2;
            x3 = boardVector[i].x3;
            x4 = boardVector[i].x4;
            y1 = boardVector[i].y1;
            y2 = boardVector[i].y2;
            y3 = boardVector[i].y3;
            y4 = boardVector[i].y4;

            double xMax = findMax(x1, x2, x3, x4);
            double yMax = findMax(y1, y2, y3, y4);
            double xMin = findMin(x1, x2, x3, x4);
            double yMin = findMin(y1, y2, y3, y4);

            if(xMax > maxX){
                maxX = xMax;
            }
            if(yMax > maxY){
                maxY = yMax;
            }
            if(xMin < minX){
                minX = xMin;
            }
            if(yMin < minY){
                minY = yMin;
            }


            if (y1 >= mouse_y && y3 <= mouse_y && mouse_x >= x2 && mouse_x <= x1) {

                glBegin(GL_QUADS);
                glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                glColor3f(1.0, 1.0, 1.0);

                glVertex3f(x1, y1, 0.0);
                glVertex3f(x2, y2, 0.0);
                glVertex3f(x3, y3, 0.0);
                glVertex3f(x4, y4, 0.0);
                glEnd();

            }


        }
        glFlush();
    }

    if(mouse_x >= minX && mouse_x <= maxX && mouse_y >= minY && mouse_y <= maxY) {
        inboard = true;
    }
    else{
        inboard = false;
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
                            //if can be added, remove from display, color in board tiles

                            //if can not be added, unbound from mouse location and print at original location
                            pieceOClicked = false;
                        } else {
                         //if click not within board, simply make the clicked piece dragable
                            pieces[i].setIsClicked(true);
                            pieceOClicked = true;
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
