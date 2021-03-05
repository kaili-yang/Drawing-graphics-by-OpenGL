/****************************************************************
* File      :   polygons.cpp
* Version   :   1.0
* Date      :   Winter, 2021
* Author    :   Yang Kaili (keyang33@outlook.com)
* Subject   :   Set attributes
 *****************************************************************/
# include <windows.h> 
# include <GL/freeglut.h>

void InitGL(){

	glClearColor(1.0, 1.0, 1.0, 1.0);
   	//glShadeModel(GL_FLAT);
  	//glShadeModel(GL_SMOOTH);
    
    glEnable (GL_CULL_FACE);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1.0, 0.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
   	glLoadIdentity();

}

GLubyte fly[] = {
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x03, 0x80, 0x01, 0xC0, 0x06, 0xC0, 0x03, 0x60,
   0x04, 0x60, 0x06, 0x20, 0x04, 0x30, 0x0C, 0x20,
   0x04, 0x18, 0x18, 0x20, 0x04, 0x0C, 0x30, 0x20,
   0x04, 0x06, 0x60, 0x20, 0x44, 0x03, 0xC0, 0x22,
   0x44, 0x01, 0x80, 0x22, 0x44, 0x01, 0x80, 0x22,
   0x44, 0x01, 0x80, 0x22, 0x44, 0x01, 0x80, 0x22,
   0x44, 0x01, 0x80, 0x22, 0x44, 0x01, 0x80, 0x22,
   0x66, 0x01, 0x80, 0x66, 0x33, 0x01, 0x80, 0xCC,
   0x19, 0x81, 0x81, 0x98, 0x0C, 0xC1, 0x83, 0x30,
   0x07, 0xe1, 0x87, 0xe0, 0x03, 0x3f, 0xfc, 0xc0,
   0x03, 0x31, 0x8c, 0xc0, 0x03, 0x33, 0xcc, 0xc0,
   0x06, 0x64, 0x26, 0x60, 0x0c, 0xcc, 0x33, 0x30,
   0x18, 0xcc, 0x33, 0x18, 0x10, 0xc4, 0x23, 0x08,
   0x10, 0x63, 0xC6, 0x08, 0x10, 0x30, 0x0c, 0x08,
   0x10, 0x18, 0x18, 0x08, 0x10, 0x00, 0x00, 0x08
};

void DrawScene(){

	glClear(GL_COLOR_BUFFER_BIT);
   	//glColor3f(1.0, 1.0, 1.0);
   
    //glPolygonMode(GL_FRONT, GL_FILL); 
    glPolygonMode(GL_FRONT, GL_FILL);
    glFrontFace(GL_CCW);
    glCullFace(GL_FRONT);


    glBegin(GL_QUADS);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(0.25, 0.25, 0.0);
        glColor3f(0.0, 0.0, 1.0);
        glVertex3f(0.25, 0.75, 0.0);
        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(0.75, 0.75, 0.0);
        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(0.75, 0.25, 0.0);

    glEnd();

    
  
   	glLineWidth(3.0);
   	//
   	glColor3f(0.0, 1.0, 1.0);
   
  	
 

    
    glPolygonMode(GL_BACK,GL_FILL);
    glEnable(GL_POLYGON_STIPPLE);
  	glPolygonStipple(fly);
   
   	glBegin(GL_QUADS);
   		glVertex3f (0.25, 0.25, 0.0);
   		glVertex3f (0.75, 0.25, 0.0);
   		glVertex3f (0.75, 0.75, 0.0);
   		glVertex3f (0.25, 0.75, 0.0);
   	glEnd();
    
   
   	glFlush();
}



int main(int argc, char **argv){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  	glutInitWindowSize(700, 700);
  	glutInitWindowPosition(0,0);
	glutCreateWindow("Polygons");
  	InitGL();
  	glutDisplayFunc(&DrawScene);
  	glutMainLoop();
  	return 1;
}

