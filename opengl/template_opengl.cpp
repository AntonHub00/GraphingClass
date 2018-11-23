#include <GL/glut.h>

float x = 0, y = 0;

void init()
{
    glClearColor(1, 1, 1, 1);
    glPointSize(7);
    glLineWidth(3);
    glColor3f(1.f, 0, 0);
    glOrtho(800, 0, 600, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void draw()
{
    //glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glScaled(0, 0, 0);
    glTranslatef(x,y,0);
    glRotated(0, 0, 0, 1);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.10, 0.0);
    glVertex2f(0.10, 0.10);
    glVertex2f(0.0, 0.10);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glColor3f(1, 1, 1);
    glScaled(0, 0, 0);
    glTranslatef(x, y, 0);
    glRotated(0, 0, 0, 1);
    glVertex2f(0.0, 0.10);
    glVertex2f(0.10, 0.10);
    glVertex2f(0.05, 0.20);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glColor3f(1, 1, 1);
    glScaled(0, 0, 0);
    glTranslatef(x, y, 0);
    glRotated(0, 0, 0, 1);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.10, 0.0);
    glVertex2f(0.05, -0.10);
    glEnd();
    glPopMatrix();

    //glPushMatrix();
    //glutSolidTeapot(0.2);
    //glColor3f(1, 1, 1);
    //glScaled(0, 0, 0);
    //glTranslatef(x, y, 0);
    //glRotated(0, 0, 0, 1);
    //glPopMatrix();

    glutSwapBuffers();
}

void refresh()
{
    x += 0.1;
    y += 0.1;
    glutPostRedisplay();
}

int main(int argc, char **args)
{
    glutInit(&argc, args);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("canvas");
    init();
    glutDisplayFunc(draw);
    glutIdleFunc(refresh);
    glutMainLoop();
    return 0;
}

