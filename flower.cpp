/****************************************************************
* File      :   Cube.cpp
* Version   :   1.0
* Date      :   Winter, 2021
* Author    :   Yang Kaili (keyang33@outlook.com)
* Subject   :   Color Cube with vertex array
*****************************************************************/
#include <windows.h>
#include <math.h>
#include <GL/freeglut.h>

void InitGL(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}

/* Define the original square */
void drawSquare(void)
{
	glBegin(GL_LINE_LOOP);
	glVertex2f(50.0 / sqrt(2.0f), 50.0 / sqrt(2.0f));
	glVertex2f(-50.0 / sqrt(2.0f), 50.0 / sqrt(2.0f));
	glVertex2f(-50.0 / sqrt(2.0f), -50.0 / sqrt(2.0f));
	glVertex2f(50.0 / sqrt(2.0f), -50.0 / sqrt(2.0f));
	glEnd();
}

/* Transform the square into diamond */
void drawDiamond(void)
{
	glPushMatrix();
	glRotatef(45, 0.0, 0.0, 1.0);
	drawSquare();
	glPopMatrix();
}

void display(void)
{
	double rotate_angle = 30.0;
	int n = 0;

	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();

	for (n = 0; n <= 12; ++n)
	{
		/* Outer margin of petal */
		glPushMatrix();
		glRotatef(rotate_angle * n, 0.0, 0.0, 1.0);
		glScalef(4.0f, 1.0f, 1.0f);
		glTranslatef(50.0f, 0.0f, 0.0f);
		drawDiamond();
		glPopMatrix();

		/* Inner margin of petal */
		glPushMatrix();
		glRotatef(rotate_angle * n, 0.0, 0.0, 1.0);
		glScalef(3.0f, 0.5f, 1.0f);
		glTranslatef(50.0f, 0.0f, 0.0f);
		drawDiamond();
		glPopMatrix();

		/* The diamonds between each two petals */
		glPushMatrix();
		glRotatef(rotate_angle * n + 15, 0.0, 0.0, 1.0);
		glScalef(1 / sqrt(2.0f), 1 / sqrt(2.0f), 1.0f);
		glTranslatef(400.0 * sqrt(2.0f), 0.0f, 0.0f);
		drawDiamond();
		glPopMatrix();

		/* The squares between each two petals */
		glPushMatrix();
		glRotatef(rotate_angle * n + 15, 0.0, 0.0, 1.0);
		glScalef(1.0f, 1.0f, 1.0f);
		glTranslatef(400.0f, 0.0f, 0.0f);
		glRotatef(45, 0.0, 0.0, 1.0);
		drawDiamond();
		glPopMatrix();
	}

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("CS402-562 Window");
	InitGL();
	glutDisplayFunc(display);
	glutMainLoop();
	return 1;
}
