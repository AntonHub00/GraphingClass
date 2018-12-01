#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

float angle = 0.0;
float lx = 0.0f,lz = -1.0f;
float x = 0.0f,z = 5.0f;

void drawSnowMan()
{
    glColor3f(0.2f, 0.2f, 1.0f);
    glTranslatef(0.0f, 1.0f, -5.0f);
    glutWireTeapot(0.9);
}


void renderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(x, 1.0f, z, x+lx, 1.0f, z+lz, 0.0f, 1.0f, 0.0f);

	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_QUADS);
    glVertex3f(-100.0f, 0.0f, -100.0f);
    glVertex3f(-100.0f, 0.0f,  100.0f);
    glVertex3f( 100.0f, 0.0f,  100.0f);
    glVertex3f( 100.0f, 0.0f, -100.0f);
	glEnd();

    for(int i = -2; i < 2; i++)
    {
        for(int j = -1; j < 1; j++)
        {
            glPushMatrix();
            glTranslatef(i * 4.0, 0, j * 4.0);
            drawSnowMan();
            glPopMatrix();
        }
    }

	glutSwapBuffers();
}

void changeSize(int w, int h)
{

    if (h == 0)
        h = 1;

    float ratio =  w * 1.0 / h;

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    glViewport(0, 0, w, h);

    gluPerspective(45, ratio, 1, 100);

    glMatrixMode(GL_MODELVIEW);
}


void processSpecialKeys(int key, int xx, int yy) //MOVER CON EL TECLADO EL ESCENARIO
{
    float fraction = 0.5f;

    switch (key)
    {
        case GLUT_KEY_LEFT :
            angle -= 0.05f;
            lx = sin(angle);
            lz = -cos(angle);
            break;
        case GLUT_KEY_RIGHT :
            angle += 0.05f;
            lx = sin(angle);
            lz = -cos(angle);
            break;
        case GLUT_KEY_UP :
            x += lx * fraction;
            z += lz * fraction;
            break;
        case GLUT_KEY_DOWN :
            x -= lx * fraction;
            z -= lz * fraction;
            break;
    }
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(700, 700);
    glutCreateWindow("Luz GLUTH");

    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);
    glutSpecialFunc(processSpecialKeys);

    glEnable(GL_DEPTH_TEST);

    glutMainLoop();

    return 0;
}
