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
    float radius = 14.9f;
    glOrtho( -360 * ar, 400* ar, -160, 160, -1, 1 );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glColor3f(1.0f, 0.3f, 0.0f); //laranja
    
    
    /*glPushMatrix();
    glTranslatef(-50.0,-40.0,0.0);
    glBegin(GL_QUADS);
    
    glVertex2f(0,10);
    glVertex2f(0,0);
    glVertex2f(10,0);
    glVertex2f(10,10);
    glEnd();
    glPopMatrix();
    */
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
    
    
    /*float g = 180.0;
    glColor3f(1.0f, 0.3f, 0.0f);
   for( int i = 0 ; i < 150; i++){
		glPushMatrix();
		glTranslatef(g,17,0.0);
		g = g + 0.5;
		//glTranslatef(0,0.0,0.0);
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
	}
	
	 glPushMatrix();
	 glTranslatef(30.0,19,0.0);
		//g = g + 0.5;
		//glTranslatef(0,0.0,0.0);
	glBegin(GL_TRIANGLE_FAN);
		//All triangles fan out starting with this point
	glVertex2f (0,0);
	for (int i = 0; i <=361; i++){				
				glColor3f(1.0f, 0.3f, 0.0f);
				glVertex2f(radius * cos(20.5*i*PI/180), radius *sin(20.5 *i*PI/180));
	}
	glEnd();
	glPopMatrix();
	
	 glPointSize(10);
    glPushMatrix();
    glTranslatef(174,29.0,0.0);
    glBegin(GL_POINTS);
    for(int i=0;i<80;i=i+2)
    {
        float x = (float)i; 
        float y = 4.9 * sin(i *(8.6/210.0));
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();
    
    */
    glPushMatrix();
    //glTranslatef(200,20,0);
    //glRotated(20,10,0.55,-0.5);
    //glutSolidSphere(3.9,40,40);
    //glutSolidTorus(2.3,3.0,12,16);
    glColor3f(0.6f,0.6f,0.6f);//mastro
    glTranslatef(0,-5.5,0);
    glBegin(GL_QUADS);
    glVertex2f(-20,100);
    glVertex2f(-20,-100);
    glVertex2f(-6.5,-100);
    glVertex2f(-6.5,100);
    glEnd();
    
    glTranslatef(0, 5.5, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-13,110);
    glVertex2f(-20,100);
    glVertex2f(-6,100);
    glEnd();
    
    glTranslatef(-12.5,94, 0);
    glBegin(GL_TRIANGLE_FAN);
		//All triangles fan out starting with this point
	glVertex2f (0,0);
	for (int i = 0; i <=361; i++){				
				glColor3f(0.6f, 0.6f, 0.6f);
				glVertex2f(6.1* cos(20.5*i*PI/180), 6.1*sin(20.5 *i*PI/180));
	}
	glEnd();
    
    
    glTranslatef(-4,-58,0);
    glBegin(GL_QUADS);
    glVertex2f(-60,-140);
    glVertex2f(-40,-150);
    glVertex2f(40,-150);
    glVertex2f(60,-140);
    glEnd();
    
    glPopMatrix();
    
    
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
