/****************************************************************
* File      :   Cube.cpp
* Version   :   1.0
* Date      :   Winter, 2021
* Author    :   Yang Kaili (keyang33@outlook.com)
* Subject   :   Color Cube with vertex array
*****************************************************************/
#include <windows.h>
#include <GL/freeglut.h>

GLfloat vertices[][3] = {{-1.0,-1.0,-1.0},{1.0,-1.0,-1.0}, {1.0,1.0,-1.0}, {-1.0,1.0,-1.0}, {-1.0,-1.0,1.0},
{1.0,-1.0,1.0},{1.0,1.0,1.0}, {-1.0,1.0,1.0}};

GLfloat colors[][3] = {{0.0,0.0,0.0},{1.0,0.0,0.0}, {1.0,1.0,0.0}, {0.0,1.0,0.0},
{0.0,0.0,1.0},{1.0,0.0,1.0}, {1.0,1.0,1.0}, {0.0,1.0,1.0}};

GLubyte cubeIndices[24]={0,3,2,1,2,3,7,6,0,4,7,3,1,2,6,5,4,5,6,7,0,1,5,4};

void colorcube(void)
{
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colors);
    //for (int i=0; i<6; i++)
    //	  glDrawElements(GL_POLYGON,4,GL_UNSIGNED_BYTE,&cubeIndices[4*i]);
    glDrawElements(GL_QUADS,24,GL_UNSIGNED_BYTE,cubeIndices);

}


void display(void)
{
/* display callback, clear frame buffer and z buffer,
   rotate cube and draw, swap buffers */

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(45, 0.0, 1.0, 0.0);
	glRotatef(45, 0.0, 0.0, 1.0);

    colorcube();

    glFlush();
	
}



void init(  )
{
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glShadeModel(GL_FLAT);
    //glShadeModel(GL_SMOOTH);

    //Initialize viewing values
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();  // Reset The Projection Matrix
    glOrtho(-4.0, 4.0, -4.0, 4.0, -4.0, 4.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);

/* need both double buffering and z buffer */
    
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Colorcube");
    init();
    glutDisplayFunc(display);
	glEnable(GL_DEPTH_TEST); /* Enable hidden--surface--removal */
    glutMainLoop();
    return 1;
}
