// CG_SeahorsesChess.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define For(i,a,b) for(int i=a; i<b; i++)

static float house[][2] = { { 0, 0 }, { 0, 200 }, { 100, 200 }, { 150, 250 }, { 100, 300 }, { 0, 300 }, { 0, 450 }, { 400, 450 }, { 550, 350 }, { 550, 100 }, { 400, 0 } };

void myInit(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-200, 1000.0, -200.0, 600.0);

}

float scaleX = 1, scaleY = 1, tranX = 0, tranY = 0, angle = 0;

void drawHouse() {
	glClear(GL_COLOR_BUFFER_BIT);
	glScaled(scaleX, scaleY, 1);
	glTranslated(tranX, tranY, 0);
	glRotated(angle, 0, 0, 1);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < 13; i++) {
		glVertex2f(house[i][1], house[i][0]);
	}
	glEnd();
	glFlush();
}

void myKeyboardFunc(unsigned char key, int x, int y) {
	switch (key) {
		// wasd: scale
	case 'w':
		scaleY += 0.01; break;

	case 's':
		scaleY -= 0.01; break;

	case 'd':
		scaleX += 0.01; break;

	case 'a':
		scaleX -= 0.1; break;

		// tfgh: move
	case 't':
		tranY += 0.1; break;

	case 'g':
		tranY -= 0.1; break;

	case 'h':
		tranX += 0.1; break;

	case 'f':
		tranX -= 0.1; break;

		// qe: rotate
	case 'q':
		angle += 0.1; break;

	case 'e':
		angle -= 0.1; break;

	}
	drawHouse();

}

void myDisplay(void) {
	drawHouse();
}

int _tmain(int argc, CHAR **argv)
{
	// Initialize GLUT.
	glutInit(&argc, argv);
	// Set the mode to draw in.
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// Set the window size in screen pixels.
	glutInitWindowSize(1280, 720);
	// Set the window position in screen pixels.
	//glutInitWindowPosition(100, 150);
	// Create the window.
	glutCreateWindow("wasd: scale - tfgh: move - qe: rotate");
	// Set the callback funcion to call when we need to draw something.
	glutDisplayFunc(myDisplay);
	// Initialize some things.
	glutKeyboardFunc(&myKeyboardFunc);
	myInit();
	// Now that we have set everything up, loop responding to events.
	glutMainLoop();
	return 0;
}

