/****************************************************************
* File      :   Circle.cpp
* Version   :   1.0
* Date      :   Winter 2021
* Author    :   Yang Kaili (keyang33@outlook.com)
* Subject   :   Modeling a Circle
*****************************************************************/
#include <windows.h>
#include <math.h>
#include <GL/freeglut.h>

const double PI = 3.14159;

/*Maximum vertices allowed*/
const int MAX_VERTICES =500;

void myinit(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}

void display(void)
{
	typedef GLfloat point2[2];

	point2 vertices[MAX_VERTICES];  /*Array of vertices*/
	//int numVertices(MAX_VERTICES);/* Number of vertices in spiral*/
	int i, k;

	/*Initialize spiral parameters*/
	double xcenter = 0.0, ycenter = 0.0;
	double Radius = 200.0;
	double alphaDeg = 10.0;//10, 23, 33, 43, 73, 103, 153, 203, 250, 251, 252, 254...
	double initAlpha = 10.0;

	/*Set up array of vertices*/
	double number = (double)MAX_VERTICES;

	for (i = 0; i < MAX_VERTICES; i++) {
		int R = 0;
		R = Radius * i / 200;
		vertices[i][0] = xcenter + R * cos(i * 2*PI / 100);
		vertices[i][1] = ycenter + R * sin(i * 2*PI / 100);
		//vertices[i][0] = xcenter + R * cos(alphaDeg * i * PI / 180.0);
		//vertices[i][1] = ycenter + R * sin(alphaDeg * i * PI / 180.0);
	}

	glClear(GL_COLOR_BUFFER_BIT);


	/*Draw vertices*/
	glBegin(GL_LINE_STRIP);
	for (k = 0; k < MAX_VERTICES; k++) {
		glVertex2fv(vertices[k]);
	}
	glEnd();


	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Spiral");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();

	return 0;
}
