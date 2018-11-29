#include <GL/glut.h>
#include <iostream>
#include <math.h>

double angle = 0.0;
double pos_x = 0.0, pos_y = 0.0;
double distance = 0.0;

void init()
{
    glClearColor(1, 1, 1, 1);
    glPointSize(10);
    glLineWidth(1);
    glColor3f(1.0, 0,0);
    glOrtho(700, 0, 700, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    //Little guy#########
    glPushMatrix(); ////////////////////////////////////////////////////////
    glTranslatef(pos_x, pos_y, 0.0);
    glBegin(GL_POINTS);
    glColor3f(0.2, 0.6, 0.5);
    glVertex2f(0.07, -0.015);
    glVertex2f(0.01, -0.015);
    glColor3f(0.2, 0.6, 0.5);
    glVertex2f(-0.01, 0.09);
    glVertex2f(0.09, 0.09);
    glColor3f(0.3, 0.2, 0.2);
    glVertex2f(-0.01, 0.11);
    glVertex2f(0.09, 0.11);
    glColor3f(0.3, 0.2,0.2);
    glVertex2f(0.0, 0.11);
    glVertex2f(0.08, 0.11);
    glEnd();

    glScaled(2, 2, 0);

    glBegin(GL_QUADS);
    glColor3f(0.3, 0.2, 0.2);
    glVertex2f(0.0, 0.00);
    glVertex2f(0.04, 0.0);
    glVertex2f(0.04, 0.04);
    glVertex2f(0.0, 0.04);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2, 0.6, 0.5);
    glVertex2f(0.0, 0.04);
    glVertex2f(0.04, 0.04);
    glVertex2f(0.04, 0.08);
    glVertex2f(0.0, 0.08);
    glEnd();
    glPopMatrix(); ////////////////////////////////////////////////////////

    //Left stick########
    glPushMatrix(); ////////////////////////////////////////////////////////
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-1.0, 0.3);
    glVertex2f(-0.95, 0.3);
    glVertex2f(-0.95, -0.3);
    glVertex2f(-1.0, -0.3);
    glEnd();
    glPopMatrix(); ////////////////////////////////////////////////////////

    //Right stick########
    glPushMatrix(); ////////////////////////////////////////////////////////
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(1.0, 0.3);
    glVertex2f(0.95, 0.3);
    glVertex2f(0.95, -0.3);
    glVertex2f(1.0, -0.3);
    glEnd();
    glPopMatrix(); ////////////////////////////////////////////////////////

    //Wired sphere#########
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(0.5, 0.5, 0.5);
    glTranslatef(0.0, 0.0, 0.0);
    glRotated(angle, 1, 1, 1);
    glScalef(1.0, 1.0, 1.0);
    glutWireSphere(1.0, 15, 15);
    glPopMatrix(); ////////////////////////////////////////////////////////

    glutSwapBuffers();
}

void refresh()
{
	distance = sqrt((-0.75 - pos_x) * (-0.75 - pos_x) + (-0.75 - pos_y) * (-0.75 - pos_y));
    std::cout << "x = " << pos_x << "||y = " << pos_y << "||distance = " << distance << std::endl;

	if(distance >= 0.0000 && distance <= 0.1000)
        angle += 0.9;

	glutPostRedisplay();
}

void keys_setup(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 'w':
            pos_y += 0.02;
            break;
        case 's':
            pos_y -= 0.02;
            break;
        case 'a':
            pos_x -= 0.02;
            break;
        case 'd':
            pos_x += 0.02;
            break;
    }
}

int main(int argc, char **args) {
    glutInit(&argc, args);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(400, 000);
    glutInitWindowSize(700, 700);
    glutCreateWindow("Ping Pong");
    init();
    glutDisplayFunc(draw);
    glutIdleFunc(refresh);
    glutKeyboardFunc(keys_setup);
    glutMainLoop();

    return 0;
}

