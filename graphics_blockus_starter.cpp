#include "graphics.h"
#include "Piece.h"
#include "Board.h"
#include "Player.h"
#include <string>

GLdouble width, height;
int wd;
float tileSize = 0.03;

void init() {
    width = 1024;
    height = 980;
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

    /*
     * Draw tile
     */





    Piece piece(1,1,0);
    piece.create_l5(12,-40);

    Piece piece1(1,1,0);
    piece1.create_l5(5,-30);


    Piece piece2(1,1,0);
    piece2.create_l5(5,-35);

    Piece piece3(1,1,0);
    piece3.create_l5(12,-45);




    Board board;
    board.drawBoard();




    glFlush();

}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y)
{
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
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
    
    
    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {
    
    
    
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
