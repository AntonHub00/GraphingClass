#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

float angle = 0.0;
float lx = 0.0f, lz = -1.0f, ly = 1.0f;
float x = 0.0f, z = 5.0f, y = 1.0f;

void draw()
{

    glPushMatrix();
    glColor3f(0.0f, 1.0f, 0.0f);
    glTranslatef(-3.0f, 1.0f, -2.0f);
    glScalef(0.5f, 0.5f, 0.5f);
	glutSolidTetrahedron();
	glPopMatrix();

    glPushMatrix();
    glColor3f(0.0f, 1.0f, 0.0f);
    glTranslatef(-1.5, 1.0f, -2.0f);
    glScalef(0.5f, 0.5f, 0.5f);
	glutWireTetrahedron();
	glPopMatrix();

    glPushMatrix();
    glColor3f(0.0f, 0.0f, 1.0f);
    glTranslatef(0.0f, 1.0f, -2.0f);
    glScalef(0.5f, 0.5f, 0.5f);
	glutSolidIcosahedron();
	glPopMatrix();

    glPushMatrix();
    glColor3f(0.0f, 0.0f, 1.0f);
    glTranslatef(1.5, 1.0f, -2.0f);
    glScalef(0.5f, 0.5f, 0.5f);
	glutWireIcosahedron();
	glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(-3.0f, 1.0f, 0.0f);
	glutSolidCube(1.0);
	glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(-1.5f, 1.0f, 0.0f);
	glutWireCube(1.0);
	glPopMatrix();

    glPushMatrix();
    glColor3f(0.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 1.0f, 0.0f);
	glutSolidSphere(0.6, 50.0, 50.0);
	glPopMatrix();

    glPushMatrix();
    glColor3f(0.0f, 1.0f, 0.0f);
    glTranslatef(1.5f, 1.0f, 0.0f);
	glutWireSphere(0.6, 50.0, 50.0);
	glPopMatrix();

    glPushMatrix();
    glColor3f(0.0f, 0.0f, 1.0f);
    glTranslatef(3.0f, 1.0f, 0.0f);
    glScalef(0.5f, 0.5f, 0.5f);
	glutSolidDodecahedron();
	glPopMatrix();

    glPushMatrix();
    glColor3f(0.0f, 0.0f, 1.0f);
    glTranslatef(4.5f, 1.0f, 0.0f);
    glScalef(0.5f, 0.5f, 0.5f);
	glutWireDodecahedron();
	glPopMatrix();

    glPushMatrix();
    glColor3f(0.0f, 0.0f, 1.0f);
    glTranslatef(-3.0f, 1.0f, 2.0f);
    glRotated(90, 0, 1, 0);
	glutSolidCone(0.6, 0.6, 50.0, 50.0);
	glPopMatrix();

    glPushMatrix();
    glColor3f(0.0f, 0.0f, 1.0f);
    glTranslatef(-1.5f ,1.0f, 2.0f);
    glRotated(90, 0, 1, 0);
	glutWireCone(0.6, 0.6, 50.0, 50.0);
	glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f ,1.0f, 2.0f);
    glRotated(90, 0, 1, 0);
	glutSolidTorus(0.2f, 0.5f, 10, 20);
	glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(1.5f, 1.0f, 2.0f);
    glRotated(90, 0, 1, 0);
	glutWireTorus(0.2f, 0.5f, 10, 20);
	glPopMatrix();

    glPushMatrix();
    glColor3f(0.0f, 1.0f, 0.0f);
    glTranslatef(3.0f, 1.0f, 2.0f);
    glScalef(0.5f, 0.5f, 0.5f);
	glutSolidOctahedron();
	glPopMatrix();

    glPushMatrix();
    glColor3f(0.0f, 1.0f, 0.0f);
    glTranslatef(4.5f, 1.0f, 2.0f);
    glScalef(0.5f, 0.5f, 0.5f);
	glutWireOctahedron();
	glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(-1.5f, 1.0f , 4.0f);
    glScalef(0.5f, 0.5f, 0.5f);
	glutSolidTeapot(1.0f);
	glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(0.0f, 1.0f , 4.0f);
    glScalef(0.5f, 0.5f, 0.5f);
	glutWireTeapot(1.0f);
	glPopMatrix();
}

void renderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(x, y, z, x+lx, ly,  z+lz, 0.0f, 1.0f,  0.0f);

	glColor3f(0.5, 0.5, 0.5);

	glBegin(GL_QUADS);
	glVertex3f(-100.0f, 0.0f, -100.0f);
	glVertex3f(-100.0f, 0.0f,  100.0f);
	glVertex3f( 100.0f, 0.0f,  100.0f);
	glVertex3f( 100.0f, 0.0f, -100.0f);
	glEnd();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    draw();
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


void processSpecialKeys(unsigned char key, int r, int s) //MOVER CON EL TECLADO EL ESCENARIO
{
	float fraction = 0.5f;

	switch (key)
    {
		case 'a' :
			angle -= 0.05f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case 'd' :
			angle += 0.05f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case 'w' :
			x += lx * fraction;
			z += lz * fraction;
			break;
		case 's' :
			x -= lx * fraction;
			z -= lz * fraction;
			break;
		case 'm' :
            y = (y == 10.0) ? 1.0 : 10.0;
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
	//glutSpecialFunc(processSpecialKeys);
    glutKeyboardFunc(processSpecialKeys);

	glEnable(GL_DEPTH_TEST);

	glutMainLoop();

	return 1;
}
