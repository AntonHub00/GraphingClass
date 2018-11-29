#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

double angulo=0.f;
double mov=0.0, mova=0.3;
double pos_x=0.0, pos_y=0.0;
double distancia=0.0;

void iniciar()
{
    glClearColor(1,1,1,1);
    glPointSize(10);
    glLineWidth(3);
    glColor3f(1.f,0,0);
    glOrtho(800, 0, 600,0,-1,1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void dibujar()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix(); ////////////////////////////////////////////////////////
    glTranslatef(pos_x,pos_y,0);
    glBegin(GL_POINTS);
    glColor3f(0.2,0.6,0.5);
    glVertex2f(0.07,-0.015);
    glVertex2f(0.01,-0.015);
    glColor3f(0.2,0.6,0.5);
    glVertex2f(-0.01,0.09);
    glVertex2f(0.09,0.09);
    glColor3f(0.3,0.2,0.2);
    glVertex2f(-0.01,0.11);
    glVertex2f(0.09,0.11);
    glColor3f(0.3,0.2,0.2);
    glVertex2f(0.0,0.11);
    glVertex2f(0.08,0.11);
    glEnd();

    glScaled(2,2,0);

    glBegin(GL_QUADS);
    glColor3f(0.3,0.2,0.2);
    glVertex2f(0.0,0.00);
    glVertex2f(0.04,0.0);
    glVertex2f(0.04,0.04);
    glVertex2f(0.0,0.04);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2,0.6,0.5);
    glVertex2f(0.0,0.04);
    glVertex2f(0.04,0.04);
    glVertex2f(0.04,0.08);
    glVertex2f(0.0,0.08);
    glEnd();
    glPopMatrix(); ////////////////////////////////////////////////////////

    glPushMatrix(); ////////////////////////////////////////////////////////
    glTranslatef(-0.75,-0.75,0.0);
    glRotated(angulo, 1, 1, 1);
    glScalef(1.0, 1.0, 1.0);
    glRotatef(45, 0, 1, 1);
    glColor3f(0.9, 0.5, 1.0);
    glutWireSphere(0.2, 15, 15);
    glPopMatrix(); ////////////////////////////////////////////////////////

    glutSwapBuffers();
}

void refresco()
{
	if(mov>=0.5)
    {
        mov=0.5;
        mova+=0.01;
	}else
        mov+=0.001;


	distancia=sqrt((-0.75 - pos_x)*(-0.75 - pos_x) + (-0.75 - pos_y) * (-0.75 - pos_y));
	printf("pos_x=%f pos_y=%f  distancia=%f \n", pos_x, pos_y, distancia);

	if(distancia >= 0.000 && distancia <= 0.100)
        angulo += 0.5;

	glutPostRedisplay();
}

void teclado(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 'w':
            pos_y+=0.01;
            break;
        case 's':
            pos_y-=0.01;
            break;
        case 'a':
            pos_x-=0.01;
            break;
        case 'd':
            pos_x+=0.01;
            break;
    }
}

int main(int argc, char **args) {
    glutInit(&argc, args);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Demo Dibujo");
    iniciar();
    glutDisplayFunc(dibujar);
    glutIdleFunc(refresco);
    glutKeyboardFunc(teclado);
    glutMainLoop();

    return 0;
}


