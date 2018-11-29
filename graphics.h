#ifndef graphics_h
#define graphics_h

#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <vector>
#include <stack>
#include <iomanip>
#include <iostream>
#include <cstdio>
#include <ctime>
#include <stdio.h>
#include <random>
#include <cmath>
#include <ostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <iomanip>
#include <sstream>

// Program initialization NOT OpenGL/GLUT dependent,
// as we haven't created a GLUT window yet
void init();

// Initialize OpenGL Graphics
void InitGL();

void display_menu();

void display_game();

void display_game_over();

// Callback functions for GLUT

// Draw the window - this is where all the GL actions are
void display();

// Trap and process alphanumeric keyboard events
void kbd(unsigned char key, int x, int y);

// Trap and process special keyboard events
void kbdS(int key, int x, int y);

// Handle "mouse cursor moved" events 
void cursor(int x, int y);

// Calls itself after a specified time
void timer(int dummy);

// Handle mouse button pressed and released events
void mouse(int button, int state, int x, int y);


#endif /* graphics_h */