#include <GL/glut.h>
#include <cmath>
#include <stdio.h>

#define CONST 450
using namespace std;

void RenderSineWave(){
    glClearColor(0.0, 0.0, 0.0, 1.0);  // clear background with black
    glClear(GL_COLOR_BUFFER_BIT);   

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    double w = glutGet( GLUT_WINDOW_WIDTH );
    double h = glutGet( GLUT_WINDOW_HEIGHT );
    double ar = w / h;
    int d = -5;
    const float PI=3.14159;
    float radius = 0.3f;
    glOrtho( -360 * ar, 390 * ar, -120, 120, -1, 1 );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glColor3f(1.0f, 0.3f, 0.0f); //laranja
    glPushMatrix();
    glTranslatef(-50.0,40.0,0.0);
    glBegin(GL_TRIANGLE_FAN);
		//All triangles fan out starting with this point
		glVertex2f (0,0);
		for (int i = 0; i <=361; i++)
		{				
				glColor3f(1.0f, 0.3f, 0.0f);
				glVertex2f(radius * cos(i*PI/180), radius *sin(i*PI/180));
		}
	glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-50.0,-40.0,0.0);
    glBegin(GL_QUADS);
    
    glVertex2f(0,10);
    glVertex2f(0,0);
    glVertex2f(10,0);
    glVertex2f(10,10);
    glEnd();
    glPopMatrix();

    glPointSize(10);
    
    glTranslatef(0.0,60,0.0);
    glBegin(GL_POINTS);
    for(int i=0;i<CONST;i=i+2)
    {
        float x = (float)i; 
        float y = 10.0 * sin(i *(4.1/190.0));
        glVertex2f(x,y);
    }
    glEnd();
    glPushMatrix();
    for(int j = 0; j < 8; j++){  
		glTranslatef(0.0,d,0.0);
		d = d - 0.5;
		glBegin(GL_POINTS);
		for(int i=0;i<CONST;i=i+2){
			float x = (float)i; 
			float y = 10.0 * sin(i *(4.1/190.0));
			glVertex2f(x,y);
		}
		glEnd();
	}
    glPopMatrix();
     glPointSize(10);
    
    
    glTranslatef(0.0,-40,0.0);
    glBegin(GL_POINTS);
    for(int i=0;i<CONST;i=i+2)
    {
        float x = (float)i; 
        float y = 10.0 * sin(i *(4.1/190.0));
        glVertex2f(x,y);
    }
    glEnd();
    
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);  
    glTranslatef(0.0,-45,0.0);
    glBegin(GL_POINTS);
    for(int i=0;i<CONST;i=i+2)
    {
        float x = (float)i; 
        float y = 10.0 * sin(i *(4.1/190.0));
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    
    for(int j = 0; j < 8; j++){  
		glTranslatef(0.0,d,0.0);
		d = d - 0.5;
		glBegin(GL_POINTS);
		for(int i=0;i<CONST;i=i+2){
			float x = (float)i; 
			float y = 10.0 * sin(i *(4.1/190.0));
			glVertex2f(x,y);
		}
		glEnd();
	}
    glPopMatrix();
    
    glColor3f(0.137255f, 0.556863f, 0.137255f);  //verde
    glPointSize(10);
    glTranslatef(0.0,-50,0.0);
    glBegin(GL_POINTS);
    for(int i=0;i<CONST;i=i+2)
    {
        float x = (float)i; 
        float y = 10.0 * sin(i *(4.1/190.0));
        glVertex2f(x,y);
    }
    glEnd();
    
    glPointSize(10);
    glPushMatrix();
    glTranslatef(0.0,-45,0.0);
    glBegin(GL_POINTS);
    for(int i=0;i<CONST;i=i+2)
    {
        float x = (float)i; 
        float y = 10.0 * sin(i *(4.1/190.0));
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();
    glPushMatrix();
    for(int j = 0; j < 8; j++){  
		glTranslatef(0.0,d,0.0);
		d = d - 0.5;
		glBegin(GL_POINTS);
		for(int i=0;i<CONST;i=i+2){
			float x = (float)i; 
			float y = 10.0 * sin(i *(4.1/190.0));
			glVertex2f(x,y);
		}
		glEnd();
	}
    glPopMatrix();
    /*glColor3f(1.0f, 0.3f, 0.0f);
    glTranslatef(-107.0, -5, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(100,140);
    glVertex2f(100, 100);
    glVertex2f(110,100);
    glVertex2f(110,140);
    glEnd();
    
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(0.0, -42, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(100,140);
    glVertex2f(100, 95);
    glVertex2f(110,95);
    glVertex2f(110,140);
    glEnd();
    
    glColor3f(0.137255f, 0.556863f, 0.137255f);
    glTranslatef(0.0, -50, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(100,140);
    glVertex2f(100, 95);
    glVertex2f(110,95);
    glVertex2f(110,140);
    glEnd();
    
    //glColor3f(0.137255f, 0.556863f, 0.137255f);
    glTranslatef(453.0, 0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(100,140);
    glVertex2f(100, 95);
    glVertex2f(110,95);
    glVertex2f(110,140);
    glEnd();
   
   glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(0.0, 47.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(100,140);
    glVertex2f(100, 96);
    glVertex2f(110,96);
    glVertex2f(110,140);
    glEnd();
   // glBegin(GL_POINTS);
    
	glColor3f(1.0f, 0.3f, 0.0f);
	glTranslatef(0.0, 48.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(100,135);
    glVertex2f(100,97);
    glVertex2f(110,97);
    glVertex2f(110,135);
    glEnd();*/
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y){
	if(key==27) exit(0);

	//tecla esc
}

int main(int argc, char** argv){
    
    printf("Bandeira do Níger\n");
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );
    glutInitWindowSize( 640, 480 );
    glutCreateWindow("Niger flag");
    glutDisplayFunc( RenderSineWave );
    glutKeyboardFunc(keyboard);
    glutMainLoop();
   }
