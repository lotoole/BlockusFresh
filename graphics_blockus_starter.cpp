#include "graphics.h"
#include "Piece.h"
#include "Board.h"
#include "Player.h"

#include <vector>

using namespace std;

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
    glClear(GL_COLOR_BUFFER_BIT);
    //draw the users first set of pieces, first row
    Piece pieceO(1,1,0);
    pieceO.create_O(50, 200);
    addPiece(pieceO);
    Piece piece1(1,1,0);
    piece1.create_1(25, 250);
    addPiece(piece1);
    Piece piece2(1,1,0);
    piece2.create_2(25, 300);
    addPiece(piece2);
    Piece piecel3(1,1,0);
    piecel3.create_l3(25, 350);
    addPiece(piecel3);
    Piece piecel4(1,1,0);
    piecel4.create_l4(25, 400);
    addPiece(piecel4);
    Piece piecel5(1,1,0);
    piecel5.create_l5(25, 450);
    addPiece(piecel5);
    Piece pieceY(1,1,0);
    pieceY.create_Y(25, 500);
    addPiece(pieceY);
    Piece pieceN(1,1,0);
    pieceN.create_N(25, 525);
    addPiece(pieceN);
    Piece pieceZ4(1,1,0);
    pieceZ4.create_Z4(25, 650);
    addPiece(pieceZ4);
    Piece pieceZ5(1,1,0);
    pieceZ5.create_Z5(25, 725);
    addPiece(pieceZ5);
    Piece pieceL4(1,1,0);
    pieceL4.create_L4(25, 800);
    addPiece(pieceL4);
    Piece pieceL5(1,1,0);
    pieceL5.create_L5(25, 850);
    addPiece(pieceL5);

    //second row of pieces
    Piece pieceV3(1,1,0);
    pieceV3.create_V3(125, 250);
    addPiece(pieceV3);
    Piece pieceV5(1,1,0);
    pieceV5.create_V5(125, 325);
    addPiece(pieceV5);
    Piece pieceW(1,1,0);
    pieceW.create_W(125, 400);
    addPiece(pieceW);
    Piece pieceT4(1,1,0);
    pieceT4.create_T4(150, 425);
    addPiece(pieceT4);
    Piece pieceT5(1,1,0);
    pieceT5.create_T5(125, 500);
    addPiece(pieceT5);
    Piece pieceP(1,1,0);
    pieceP.create_P(125, 650);
    addPiece(pieceP);
    Piece pieceX(1,1,0);
    pieceX.create_X(125, 700);
    addPiece(pieceX);
    Piece pieceU(1,1,0);
    pieceU.create_U(125, 800);
    addPiece(pieceU);
    Piece pieceF(1,1,0);
    pieceF.create_F(125, 900);
    addPiece(pieceF);

//    cout << "Mouse position: " << mouse_x << ", " << mouse_y << endl;
//    cout << endl;
//    cout << "start of cordinates in beg: " << endl;
//    pieceO.getCordinates();
//    cout << "end of cordinates: " << endl;

    //draw the board
    Board board;
    vector<Coordinate> boardVector = board.drawBoard();
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

//    cout << x << endl;
//    cout << y << endl;
    mouse_x = x;
    mouse_y = y;

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
    //Created by Liam OToole on 12/1/18
    // all checks for when the user clicks in the menu
    //------------------------------------------------**
    //if the user clicks a location
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN  && state != GLUT_UP && screen == game_play) {
        //if the user clicks over the button, change the screen state
        if (mouse_x >= 700 && mouse_x <= 850 && mouse_y >= 850 - 125 && mouse_y <= 900 - 125) {
            screen = game_over;
        }
    }
    //if the user clicks on a shape, make it dragable
    cout << pieces[0].getNumberOfTiles() << endl;
    for(int i=0; i < pieces.size(); ++i) {
        vector<PieceCoordinate> temporary = pieces[i].getCordinates();
        for(int i =1; i < temporary.size(); ++i) {
            double x = temporary[i].x;
            double y = temporary[i].y;
            double x2 = temporary[i -1].x;
            double y2 = temporary[i -1].y;
            if(mouse_x >= x && mouse_x <= x && mouse_y >= y - 125 && mouse_y <= y - 125) {
                cout << "clicked on a piece" << endl;
            }
        }
//        cout << pieces[i].getNumberOfTiles() << endl;
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
