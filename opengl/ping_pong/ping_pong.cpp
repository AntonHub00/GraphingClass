#include <GL/glut.h>
#include <iostream>
#include <math.h>

double angle = 0.0;
double ball_x = 0.0, ball_y = 0.0;
double left_stick_x = 0.0, left_stick_y = 0.0;
double right_stick_x = 0.0, right_stick_y = 0.0;
double distance_l = 0.0, distance_r = 0.0;
bool flag = true;

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

    //Wired sphere/teapot#########
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(0.5, 0.5, 0.5);
    glTranslatef(0.0, 0.0, 0.0);
    glRotated(angle, 1, 1, 1);
    glutWireTeapot(0.25);
    //glutWireSphere(0.25, 15, 15);
    glPopMatrix(); ////////////////////////////////////////////////////////

    //Solid sphere#########
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(1.0, 0.0, 0.0);
    glTranslatef(ball_x, ball_y, 0.0);
    glutSolidSphere(0.05, 15, 15);
    glPopMatrix(); ////////////////////////////////////////////////////////

    //Left stick########
    glPushMatrix(); ////////////////////////////////////////////////////////
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(left_stick_x, left_stick_y, 0.0);
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
    //glTranslatef(right_stick_x, right_stick_y, 0.0);
    glVertex2f(1.0, 0.3);
    glVertex2f(0.95, 0.3);
    glVertex2f(0.95, -0.3);
    glVertex2f(1.0, -0.3);
    glEnd();
    glPopMatrix(); ////////////////////////////////////////////////////////

    glutSwapBuffers();
}

void refresh()
{
    angle += 0.9;
	distance_l = sqrt(pow(-1.0 - ball_x, 2) + pow(-1.0 - (-1.0), 2));
	distance_r = sqrt(pow(1.0 - 1.0, 2) + pow(1.0 - (ball_x), 2));
    std::cout << "x = " << ball_x << "||y = " << ball_y << "||distance_l = " << distance_l << std::endl;
    std::cout << "x = " << ball_x << "||y = " << ball_y << "||distance_r = " << distance_r << std::endl;

	if(distance_l <= 0.01000)
        flag = false;
	if(distance_r <= 0.01000)
        flag = true;

    if (flag == true)
        ball_x -= 0.01;
    else
        ball_x += 0.01;

	glutPostRedisplay();
}

void keys_setup(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 'w':
            //pos_y += 0.02;
            break;
        case 's':
            //pos_y -= 0.02;
            break;
        case 'a':
            //pos_x -= 0.02;
            break;
        case 'd':
            //pos_x += 0.02;
            break;
    }
}

int main(int argc, char **args)
{
    glutInit(&argc, args);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(400, 0);
    glutInitWindowSize(700, 700);
    glutCreateWindow("Ping Pong");
    init();
    glutDisplayFunc(draw);
    glutIdleFunc(refresh);
    glutKeyboardFunc(keys_setup);
    glutMainLoop();

    return 0;
}
