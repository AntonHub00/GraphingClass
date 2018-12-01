#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

float angle = 0.0;
float lx = 0.0f, lz = -1.0f;
float x = 0.0f, z = 5.0f;

void body()
{
    glPushMatrix();
    glColor3f(0.90f, 1.0f, 0.0f);
    glTranslatef(0.0f ,1.0f, 0.0f);
    glScalef(1.5f ,0.5f, 1.0f);
	glutSolidCube(2.0);
	glPopMatrix();
}

void wheel()
{
    glPushMatrix();
    glColor3f(0.09, 0.83f, 0.34f);
    glTranslatef(0.0f ,1.0f, 0.0f);
    glScalef(0.7f ,0.7f, 0.7f);
	glutSolidTorus(0.4f, 0.7f, 10, 20);
	glPopMatrix();
}

void renderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(	x, 1.0f, z, x+lx, 1.0f,  z+lz, 0.0f, 1.0f,  0.0f);

	glColor3f(0.5, 0.5, 0.5);

	glBegin(GL_QUADS);
	glVertex3f(-100.0f, 0.0f, -100.0f);
	glVertex3f(-100.0f, 0.0f,  100.0f);
	glVertex3f( 100.0f, 0.0f,  100.0f);
	glVertex3f( 100.0f, 0.0f, -100.0f);
	glEnd();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    body();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.5, 0, 1.2);
    wheel();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5, 0, 1.2);
    wheel();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.5, 0, -1.2);
    wheel();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5, 0, -1.2);
    wheel();
    glPopMatrix();

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

	gluPerspective(45,ratio,1,100);

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
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("Luz GLUTH");

	//glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	glutSpecialFunc(processSpecialKeys);

	glEnable(GL_DEPTH_TEST);

	glutMainLoop();

	return 1;
}
