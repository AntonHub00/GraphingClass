#include <GL/glut.h>
#include <iostream>
#include <math.h>

double angle = 0.0;
double pos_x_1 = 0.0, pos_y_1 = 0.0;
double pos_x_2 = 0.5, pos_y_2 = 0.5;
double distance = 0.0;
double radius = 0.05;
double sum_radius = 2 * radius;
bool moved[] = {false, false, false ,false};

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

    //Radius = 0.5

    //Solid black sphere #########
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(pos_x_1, pos_y_1, 0.0);
    glutSolidSphere(radius, 15, 15);
    glPopMatrix(); ////////////////////////////////////////////////////////

    //Solid green sphere #########
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(0.0, 0.8, 0.0);
    glTranslatef(pos_x_2, pos_y_2, 0.0);
    glutSolidSphere(radius, 15, 15);
    glPopMatrix(); ////////////////////////////////////////////////////////

    ////Triangle #########
    //glPushMatrix(); ////////////////////////////////////////////////////////
    //glColor3f(0.0, 0.8, 0.0);

    //glTranslatef(0.2, 0.2, 0.0);
    //glRotatef(angle, 0.0, 0.0, 1.0);
    //glTranslatef(-0.2, -0.2, 0);

    ////glRotatef(angle, 0.0, 0.0, 1.0);
    ////glScalef(0.5, 0.5, 0.5);
    //glBegin(GL_TRIANGLES);
    //glVertex3f(0.0, 0.0, 0.0);
    //glVertex3f(0.2, 0.0, 0.0);
    //glVertex3f(0.1, 0.17320508075688773, 0.0);
    //glEnd();
    //glPopMatrix(); ////////////////////////////////////////////////////////

    //Square #########
    //glPushMatrix(); ////////////////////////////////////////////////////////
    //glColor3f(0.0, 0.8, 0.0);

    //glTranslatef(0.2/2, 0./22, 0.0);
    //glRotatef(angle, 0.0, 0.0, 1.0);
    //glTranslatef(-0.2/2, -0.2/2, 0.0);

    //glBegin(GL_QUADS);
    //glVertex3f(0.0, 0.0, 0.0);
    //glVertex3f(0.2, 0.0, 0.0);
    //glVertex3f(0.2, 0.2, 0.0);
    //glVertex3f(0.0, 0.2, 0.0);
    //glEnd();
    //glPopMatrix(); ////////////////////////////////////////////////////////

    glutSwapBuffers();
}

void refresh()
{
    //Calculates the distance between the black sphere and the bottom left corner
	distance = sqrt((pos_x_2 - pos_x_1) * (pos_x_2 - pos_x_1) + (pos_y_2 - pos_y_1) * (pos_y_2 - pos_y_1));
    std::cout << "x = " << pos_x_1 << "||y = " << pos_y_1 << "||distance = " << distance << std::endl;
    std::cout << sum_radius << std::endl;

    //The wired sphere rotates when the black sphere approaches the bottom left corner
	if(distance <= sum_radius)
    {
        std::cout << "collison!" << std::endl;

        if (moved[0])
            pos_y_1 -= 0.01;
        else if (moved[1])
            pos_y_1 += 0.01;
        else if (moved[2])
            pos_x_1 += 0.01;
        else if (moved[3])
            pos_x_1 -= 0.01;
    }

	glutPostRedisplay();
}

//Arguments defined in this function are mandatory for the handling of the key events
void keys_setup(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 'w':
            pos_y_1 += 0.01;
            moved[0] = true;
            moved[1] = false;
            moved[2] = false;
            moved[3] = false;
            break;
        case 's':
            pos_y_1 -= 0.01;
            moved[0] = false;
            moved[1] = true;
            moved[2] = false;
            moved[3] = false;
            break;
        case 'a':
            pos_x_1 -= 0.01;
            moved[0] = false;
            moved[1] = false;
            moved[2] = true;
            moved[3] = false;
            break;
        case 'd':
            pos_x_1 += 0.01;
            moved[0] = false;
            moved[1] = false;
            moved[2] = false;
            moved[3] = true;
            break;
    }
}

int main(int argc, char **args)
{
    glutInit(&argc, args);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(400, 000);
    glutInitWindowSize(700, 700);
    glutCreateWindow("Master template");
    init();
    glutDisplayFunc(draw);
    glutIdleFunc(refresh);
    glutKeyboardFunc(keys_setup);
    glutMainLoop();

    return 0;
}
