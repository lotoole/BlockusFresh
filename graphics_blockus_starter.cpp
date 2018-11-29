#include "graphics.h"
#include "Piece.h"
#include "Board.h"
#include "Player.h"

GLdouble width, height;
int wd;
int mouse_x, mouse_y;
//enums for tracking the current state of the game
//------------------------------------------------**
//Created by Liam OToole on 11/27/18
//------------------------------------------------**
enum screen_state {menu, game_play, game_over};
// set the screen state
screen_state screen;
//------------------------------------------------**
//Modified by Liam OToole on 11/27/18
//------------------------------------------------**
void init() {
    //setting the screens width and height
    width = 1024;
    height = 980;
    //set screen to menu when we start
    screen = game_play;
}

//------------------------------------------------**
//Created by Liam OToole on 11/7/18
// Display start game menu
//------------------------------------------------**
void display_menu() {
    string message = "The game is Over!";
    glColor3f(1, 1, 0);
    glRasterPos2i(100, 250);
    for (int i = 0; i < message.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
    }
    //replay message
    string message2 = "Press 'r' to restart!";
    glColor3f(1, 1, 0);
    glRasterPos2i(100, 550);
    for (int i = 0; i < message2.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message2[i]);
    }
}

//------------------------------------------------**
//Created by Liam OToole on 11/7/18
// Moved gameplay code to new screen
//------------------------------------------------**
void display_game() {
    Piece piece(1,1,0);
    piece.create_1(0.0,0.0);
    //After drawing pieces, draw the board
    Board board;
    board.drawBoard();
}

//------------------------------------------------**
//Created by Liam OToole on 11/7/18
// Display start game menu
//------------------------------------------------**
void display_game_over () {
    string message = "The game is Over!";
    glColor3f(1, 1, 1);
    glRasterPos2i(-10, 25);
    for (int i = 0; i < message.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
    }
    //replay message
    string message2 = "Press 'r' to restart!";
    glColor3f(1, 1, 0);
    glRasterPos2i(100, 550);
    for (int i = 0; i < message2.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message2[i]);
    }
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
    glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1);

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
    //restart game
    if(key == 'r' && screen == game_over) {
        screen = menu;
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
    mouse_y = y;
    
    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {

    // Set game screen to game play if the user clicks on the screen
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP &&screen == menu) {
        screen = game_play;
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
    wd = glutCreateWindow("Blockus" /* title */ );
    
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
