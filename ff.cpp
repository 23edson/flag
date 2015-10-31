//
// File Name:     drawCircle.cpp
// Programmer:    Dr. Hankins
// Class:         CSCI 4250
// Due Date:      9/4/07
// Instructor:    Dr. Hankins
//
// The purpose of this program is to introduce the student
// to OpenGL and GLUT.  The program opens a window and on 
// a black background, it draws a multicolored circle.
//
// This program has no input.
//
// This program draws a multicolored circle on a black background.
//
// The program has no limitations.  It fulfills its purpose.

// including the C standard library is tricky -- Visual Studio
// sometimes generates an error saying that you are trying to
// redefine the exit() function.  Thus you may have to reposition
// your include files.
#include <cstdlib>
#include <GL/glut.h>
#include <cmath>
using namespace std;

//
// Function Name:   mydisplay()
//
// This function serves as the display callback.  When
// the window is displayed for the first time or is
// redisplayed again, this function is called.
//
// It fills the frame buffer with the background color,
// then it draws a multi-colored circle.

void mydisplay()
{
	const float PI=3.14159;

	//fill the frame buffer with the background color
	glClear(GL_COLOR_BUFFER_BIT); 

	//fill a circle using a different color for each point
	//You get totally different drawings using the drawing
	//modes GL_POLYGON and GL_TRIANGLE_FAN
	//glBegin(GL_POLYGON); 

	//fill a circle using a triangle fan
	//glTranslatef(1.0,0.0,0.0);
	
	
	
	// Desenha um quadrado preenchido com a cor corrente
	
	
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glVertex2f(-0.95, 1.0);
	glVertex2f(-0.95, -0.2);
	// Especifica que a cor corrente � azul
	
	glVertex2f(1.0, -0.2);
	glVertex2f(1.0, 1.0);
	glEnd();
	
	
	glColor3f(1.0f, 0.3f, 0.0f); //laranja
	glBegin(GL_QUADS);
				glVertex2f(-0.95, 1.0);
				glVertex2f(-0.95, 0.6);
	// Especifica que a cor corrente � azul
	//glColor3f(0.0f, 0.0f, 1.0f);
				glVertex2f(1.0, 0.6);
				glVertex2f(1.0, 1.0);
				glEnd();
	
	
	glColor3f(0.137255f, 0.556863f, 0.137255f); //verde
	glBegin(GL_QUADS);
					glVertex2f(-0.95, -0.11);
					glVertex2f(-0.95, -0.5);
	// Especifica que a cor corrente � azul
	//glColor3f(0.0f, 0.0f, 1.0f);
					glVertex2f(1.0, -0.5);
					glVertex2f(1.0, -0.11);
					glEnd();
					
	glColor3f(0.6f,0.6f,0.6f);//mastro
	glBegin(GL_QUADS);
					glVertex2f(-1.0, 1.1);
					glVertex2f(-1.0, -1.7);
	// Especifica que a cor corrente � azul
	//glColor3f(0.0f, 0.0f, 1.0f);
					glVertex2f(-0.95, -1.7);
					glVertex2f(-0.95, 1.1);
					glEnd();
	glTranslatef(0.0,0.25,0.0);
	glColor3f(1.0f, 0.3f, 0.0f);
	float radius = 0.3f;
	glBegin(GL_TRIANGLE_FAN);
		//All triangles fan out starting with this point
		glVertex2f (0.0,0.0);
		for (int i = 0; i <=361; i++)
		{				
				glColor3f(1.0f, 0.3f, 0.0f);
				glVertex2f(radius * cos(i*PI/180), radius *sin(i*PI/180));
		}
	glEnd();
	
	//flush the buffer so the circle displays
	//immediately
	//glTranslatef(0.0,0.0,-1.0);
	
	glFlush(); 
}

//
// Function Name:  init()
//
// This function initializes several of
// OpenGL's state variables.  Namely it
// sets the background color, the fill
// color, and sets up the "real" world
// coordinate system.

void init()
{
	//set the background color to black
	glClearColor (0.0, 0.0, 0.0, 0.0);

	//set the draw/fill color to white
	glColor3f(1.0f, 0.3f, 0.0f);

	//set the "real" world coordinates
	//to a window from -2.5 to 2.5 in x and
	//-2.5 to 2.5 in y
	glMatrixMode (GL_PROJECTION);    
	glLoadIdentity ();    
	gluOrtho2D(-2.5,2.5,-2.5,2.5);  
}
int main(int argc, char** argv)
{
	//set up a session with the window system
	glutInit(&argc, argv);

	//use a single frame buffer with red, green,
	//and blue color
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA); 

	//set the window size to 500 by 500
	glutInitWindowSize(500,500);

	//the upper left corner will appear
	//at (0,0) on the screen
	glutInitWindowPosition(0,0);

	//When the window appears it has "simple"
	//on the title bar
	glutCreateWindow("circle"); 

	//register the display callback to be the
	//function mydisplay
	glutDisplayFunc(mydisplay);  

	//initialize OpenGL
	init();  

	//start the infinite event loop
	glutMainLoop();
}



