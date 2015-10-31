// Quadrado.c - Isabel H. Manssour
// Um programa OpenGL simples que desenha um 
// quadrado em  uma janela GLUT.
// Este c�digo est� baseado no GLRect.c, exemplo 
// dispon�vel no livro "OpenGL SuperBible", 
// 2nd Edition, de Richard S. e Wright Jr.
//gcc somefile.c -lGLU -lGL -lglut
//#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

//#define PI 3.1415926535897932
// Fun��o callback chamada para fazer o desenho
void Desenha(void)
{
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();

	// Limpa a jnela de visualiza��o com a cor de fundo especificada
	glClear(GL_COLOR_BUFFER_BIT);

	// Especifica que a cor corrente � vermelha
	//         R     G     B
	/*glColor3f(1.0f, 1.0f, 1.0f);

	// Desenha um quadrado preenchido com a cor corrente
	glBegin(GL_QUADS);
	glVertex2i(100, 150);
	glVertex2i(100, 100);
	// Especifica que a cor corrente � azul
	
	glVertex2i(200, 100);
	glVertex2i(200, 150);
	glEnd();
	glColor3f(1.0f, 0.3f, 0.0f); //laranja
	
	glPushMatrix();
		glTranslatef(0.0,-15.1,0);
			glBegin(GL_QUADS);
				glVertex2i(100, 170);
				glVertex2i(100, 150);
	// Especifica que a cor corrente � azul
	//glColor3f(0.0f, 0.0f, 1.0f);
				glVertex2i(200, 150);
				glVertex2i(200, 170);
				glEnd();
	glPopMatrix();
	
	glColor3f(0.137255f, 0.556863f, 0.137255f); //verde
		glPushMatrix();
			glTranslatef(0.0,-15.1,0);
				glBegin(GL_QUADS);
					glVertex2i(100, 120);
					glVertex2i(100, 100);
	// Especifica que a cor corrente � azul
	//glColor3f(0.0f, 0.0f, 1.0f);
					glVertex2i(200, 100);
					glVertex2i(200, 120);
					glEnd();
		glPopMatrix();
	//glPushMatrix();
	//glTranslatef(30,25, 0.0); // position head
	//glutSolidSphere(17.0, 50, 20); // head sphere
	// Executa os comandos OpenGL
	//glEnd();*/
	//glTranslatef(5.0,0.0, 0.0);
	
	const float PI=3.14159;
	float radius = 0.2f;
	glBegin(GL_TRIANGLE_FAN);
		//All triangles fan out starting with this point
		glVertex2f (0.0,0.0);
		for (int i = 0; i <=361; i++)
		{				
				glColor3f(1.0f, 0.3f, 0.0f);
				glVertex2f(radius * cos(i*PI/180), radius *sin(i*PI/180));
		}
	glEnd();
	
	glFlush();
}

// Inicializa par�metros de rendering
void Inicializa(void)
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

// Fun��o callback chamada quando o tamanho da janela � alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Evita a divisao por zero
	if (h == 0) h = 1;

	// Especifica as dimens�es da Viewport
	glViewport(0, 0, w, h);

	// Inicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Estabelece a janela de sele��o (left, right, bottom, top)
	if (w <= h)
		gluOrtho2D(0.0f, 250.0f, 0.0f, 250.0f*h / w);
	else
		gluOrtho2D(0.0f, 250.0f*w / h, 0.0f, 250.0f);
}

void keyboard(unsigned char key, int x, int y){
	if(key==27) exit(0);

	//tecla esc
}

// Programa Principal 
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500,500);

	//the upper left corner will appear
	//at (0,0) on the screen
	glutInitWindowPosition(0,0);
	glutCreateWindow("Bandeira");
	glutDisplayFunc(Desenha);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(AlteraTamanhoJanela);
	Inicializa();
	//glEnable(GL_DEPTH_TEST);
    //glDepthFunc(GL_LESS);
	glutMainLoop();
}
