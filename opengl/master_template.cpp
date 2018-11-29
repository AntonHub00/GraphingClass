#include <GL/glut.h>
#include <iostream>
#include <math.h>

double angle = 0.0;
double pos_x = 0.0, pos_y = 0.0;
double distance = 0.0;

void init()
{
    //The line below defines the "background" color
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

    //Solid black sphere #########
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(pos_x, pos_y, 0.0);
    glScalef(0.1, 0.1, 0.1);
    glutSolidSphere(0.5, 15, 15);
    glPopMatrix(); ////////////////////////////////////////////////////////

    //Wired sphere #########
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(0.5, 0.5, 0.5);
    glTranslatef(0.0, 0.0, 0.0);
    glRotated(angle, 1, 1, 1);
    glScalef(1.0, 1.0, 1.0);
    glutWireSphere(0.5, 15, 15);
    glPopMatrix(); ////////////////////////////////////////////////////////

    glutSwapBuffers();
}

void refresh()
{
    //Calculates the distance between the black sphere and the bottom left corner
	distance = sqrt((-1.0 - pos_x) * (-1.0 - pos_x) + (-1.0 - pos_y) * (-1.0 - pos_y));
    std::cout << "x = " << pos_x << "||y = " << pos_y << "||distance = " << distance << std::endl;

    //The wired sphere rotates when the black sphere approaches the bottom left corner
	if(distance >= 0.0000 && distance <= 0.2000)
        angle += 0.9;

	glutPostRedisplay();
}

//Arguments defined in this function are mandatory for the handling of the key events
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


