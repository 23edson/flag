/**
*   Universidade Federal da Fronteira Sul
*
*   TRABALHO II
*   Disciplina: Computação gráfica
*   Professor: José Carlos Bins Filho
*
*
* 	Alunos : Edson Lemes da Silva & Lucas Cezar Parnoff
*   Compilação pelo Makefile
*   g++ main.cpp -o  main -lGL -lGLU -lglut
*
*   Este programa representa a renderização da bandeira da Holanda, de modo
*   haja a simulação da mesma tremulando no mastro. Este processo é feito
* 	através do processo de "animação" dela.
*
*
**/
#include <GL/glut.h>
#include <cmath>
#include <stdio.h>

#define CONST 450

using namespace std;

//constantes para movimento
double t = 0.0;
double time = 0.0;
double timeAtual = 0.0;
double fator = 1.0;
int frames = 0;

/**
 * @function resize
 *
 * @param int width - define a largura;
 * @param int height - define a altura.
 *
 * A função define a rotina para o redimensionar a tela.
 *
 **/
static void resize(int width, int height){
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

/**
 * @function RenderFlag
 *
 * Função principal. Esta define a rotina de criação da bandeira. Além de definir
 * a simulação de movimento da bandeira. Para o cálculo da ondulação dela, foi
 * usado a função seno; para a movimentação foi usado a função cosseno.
 *
 * Para a renderização da bandeira, as principais funções utilizadas foram:
 * 	 glTranslatef - Para colocar cada elemento em seu devido lugar;
 * 	 glVertex2f - Criação dos vértices correspondentes à bandeira;
 *   glPushMatrix & glPopMatrix - Para "edição" local;
 *   glColor3f - Alterar as cores de cada área;
 *   glPointSize - Tamanho de cada ponto ondulado;
 *
 **/

void RenderFlag(){
    timeAtual = glutGet(GLUT_ELAPSED_TIME)/1000.0;
    time=timeAtual-t;
    frames++;
    if(time>1.00){ t += 1.0 ;printf("%d Frames/s\n",frames);frames=0;}
    timeAtual*=fator;
    glClearColor(0.0, 0.0, 0.0, 1.0);  // Cor de fundo preto
    glClear(GL_COLOR_BUFFER_BIT);
    time*=4;
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    double w = glutGet( GLUT_WINDOW_WIDTH );
    double h = glutGet( GLUT_WINDOW_HEIGHT );
    double ar = w / h;
    int d = -5;
    const float PI=3.14159;
    float radius = 14.9f;
    glOrtho( -360 * ar, 400* ar, -160, 160, -1, 1 ); //visão

    glMatrixMode( GL_MODELVIEW ); //modelo de visao
    glLoadIdentity();
    glColor3f(1.0f, 0.0f, 0.0f); //Vermelho

    glPointSize(10); //Tamanhos dos pontos na faixa.

    glTranslatef(0.0,60,0.0);//este bloco desenha uma faixa ondulada Vermelha
    glBegin(GL_POINTS);
    for(int i=0;i<CONST;i=i+2)
    {
        float x = (float)i;
        float y = 10.0 *cos(timeAtual)* sin(i *(4.1/190.0));
        glVertex2f(x+sin(timeAtual)*sin(timeAtual),y);
    }
    glEnd();
    glPushMatrix();

    for(int j = 0; j < 8; j++){//completa a área desenhando mais 8 faixas Vermelha
		glTranslatef(0.0,d,0.0);
		d = d - 0.5;
		glBegin(GL_POINTS);
		for(int i=0;i<CONST;i=i+2){
			float x = (float)i;
			float y = 10.0 *cos(timeAtual)* sin(i *(4.1/190.0));
			glVertex2f(x+sin(timeAtual)*sin(timeAtual),y);
		}
		glEnd();
	}
    glPopMatrix();
    
	glPointSize(10);


    glTranslatef(0.0,-40,0.0);//Última faixa Vermelha; "fronteira" com a próxima área
    glBegin(GL_POINTS);
    for(int i=0;i<CONST;i=i+2)
    {
        float x = (float)i;
        float y = 10.0 *cos(timeAtual)* sin(i *(4.3/190.0));
        glVertex2f(x+sin(timeAtual)*sin(timeAtual),y);
    }
    glEnd();

    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f); //cor branca
    glTranslatef(0.0,-45,0.0); //este bloco desenha uma faixa branca ondulada
    glBegin(GL_POINTS);
    for(int i=0;i<CONST;i=i+2)
    {
        float x = (float)i;
        float y = 10.0 *cos(timeAtual)* sin(i *(4.1/190.0));
        glVertex2f(x+sin(timeAtual)*sin(timeAtual),y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
   

    for(int j = 0; j < 8; j++){ //desenha as oito faixas brancas intermediárias
		glTranslatef(0.0,d,0.0);
		d = d - 0.5;
		glBegin(GL_POINTS);
		for(int i=0;i<CONST;i=i+2){
			float x = (float)i;
			float y = 10.0 *cos(timeAtual)* sin(i *(4.1/190.0));
			glVertex2f(x+sin(timeAtual)*sin(timeAtual),y);
		}
		glEnd();
	}
    glPopMatrix();

    glColor3f(0.0f, 0.0f, 1.0f);  //define cor Azul
    glPointSize(10);
    glTranslatef(0.0,-50,0.0); //desenha primeira faixa azul
    glBegin(GL_POINTS);
    for(int i=0;i<CONST;i=i+2)
    {
        float x = (float)i;
        float y = 10.0 *cos(timeAtual)* sin(i *(4.1/190.0));
        glVertex2f(x+sin(timeAtual)*sin(timeAtual),y);
    }
    glEnd();

    glPointSize(10);
    glPushMatrix();
    glTranslatef(0.0,-45,0.0);//desenha a última faixa azul
    glBegin(GL_POINTS);
    for(int i=0;i<CONST;i=i+2)
    {
        float x = (float)i;
        float y = 10.0 *cos(timeAtual)* sin(i *(4.1/190.0));
        glVertex2f(x+sin(timeAtual)*sin(timeAtual),y);
    }
    glEnd();
    glPopMatrix();
    glPushMatrix();
    for(int j = 0; j < 8; j++){
		glTranslatef(0.0,d,0.0); //ðesenha as oito faixas intermediárias
		d = d - 0.5;
		glBegin(GL_POINTS);
		for(int i=0;i<CONST;i=i+2){
			float x = (float)i;
			float y = 10.0 *cos(timeAtual) * sin(i *(4.1/190.0));
			glVertex2f(x+sin(timeAtual)*sin(timeAtual),y);
		}
		glEnd();
	}
    glPopMatrix();


    glPushMatrix();
    
    glColor3f(0.6f,0.6f,0.6f);//cor cinza
    glTranslatef(0,-5.5,0); //desenha a rotina para o mastro
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
		//rotina para desenhar um círculo
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


/**
 * @function keyboard
 *
 * Função define o uso do teclado. Especificamente as teclas 'ESC', '+' & '-'
 * para encerrar a aplicação, aumentar velocidade de ondulação e diminuir respectivamente.
 *
 **/
void keyboard(unsigned char key, int x, int y){
	if(key==27) exit(0); //tecla esc
    if(key == '+') fator+=0.1;
    if(key == '-') fator-=0.1;
	
}

/**
 * @function idle
 *
 * Marca a janela para ser redesenhada para efeitos de animação
 **/
static void idle(void){
    glutPostRedisplay();
}

int main(int argc, char** argv){

    printf("Bandeira da Holanda\n");
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA );
    glutInitWindowSize( 640, 480 );
    glutCreateWindow("Netherlands flag");
    glutReshapeFunc(resize);
    glutDisplayFunc( RenderFlag);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(idle);
    glutMainLoop();
}
