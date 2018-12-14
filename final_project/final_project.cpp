#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <iostream>

//Refresh global variables
float fraction = 0.5f;
bool moved = false;
float angle = 0.0;

//Me (camera)
float lx = 0.0f, lz = -1.0f, ly = 1.0f;
float x = 0.0f, z = 0.0f, y = 1.0f;

float collision_radius = 0.8;

//LEFT WALL//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Cube1 collision data
float collision_x_1 = -1.0, collision_y_1 = 1.0, collision_z_1 = -1.0;
float distance_1 = 0.0;
//Cube2 collision data
float collision_x_2 = -1.0, collision_y_2 = 1.0, collision_z_2 = -2.0;
float distance_2 = 0.0;
//Cube3 collision data
float collision_x_3 = -1.0, collision_y_3 = 1.0, collision_z_3 = -3.0;
float distance_3 = 0.0;
//Cube4 collision data
float collision_x_4 = -1.0, collision_y_4 = 1.0, collision_z_4 = -4.0;
float distance_4 = 0.0;
//Cube5 collision data
float collision_x_5 = -1.0, collision_y_5 = 1.0, collision_z_5 = -5.0;
float distance_5 = 0.0;
//Cube6 collision data
float collision_x_6 = -1.0, collision_y_6 = 1.0, collision_z_6 = -6.0;
float distance_6 = 0.0;
//Cube7 collision data
float collision_x_7 = -1.0, collision_y_7 = 1.0, collision_z_7 = -7.0;
float distance_7 = 0.0;
//Cube8 collision data
float collision_x_8 = -1.0, collision_y_8 = 1.0, collision_z_8 = -8.0;
float distance_8 = 0.0;
//Cube9 collision data
float collision_x_9 = -1.0, collision_y_9 = 1.0, collision_z_9 = -9.0;
float distance_9 = 0.0;
//Cube10 collision data
float collision_x_10 = -1.0, collision_y_10 = 1.0, collision_z_10 = -10.0;
float distance_10 = 0.0;

//RIGHT WALL///////////////////////////////////////////////////////////////////////////////////////////////
//Cube1 collision data
float collision_x_1_r = 8.0, collision_y_1_r = 1.0, collision_z_1_r = -1.0;
float distance_1_r = 0.0;
//Cube2 collision data
float collision_x_2_r = 8.0, collision_y_2_r = 1.0, collision_z_2_r = -2.0;
float distance_2_r = 0.0;
//Cube3 collision data
float collision_x_3_r = 8.0, collision_y_3_r = 1.0, collision_z_3_r = -3.0;
float distance_3_r = 0.0;
//Cube4 collision data
float collision_x_4_r = 8.0, collision_y_4_r = 1.0, collision_z_4_r = -4.0;
float distance_4_r = 0.0;
//Cube5 collision data
float collision_x_5_r = 8.0, collision_y_5_r = 1.0, collision_z_5_r = -5.0;
float distance_5_r = 0.0;
//Cube6 collision data
float collision_x_6_r = 8.0, collision_y_6_r = 1.0, collision_z_6_r = -6.0;
float distance_6_r = 0.0;
//Cube7 collision data
float collision_x_7_r = 8.0, collision_y_7_r = 1.0, collision_z_7_r = -7.0;
float distance_7_r = 0.0;
//Cube8 collision data
float collision_x_8_r = 8.0, collision_y_8_r = 1.0, collision_z_8_r = -8.0;
float distance_8_r = 0.0;
//Cube9 collision data
float collision_x_9_r = 8.0, collision_y_9_r = 1.0, collision_z_9_r = -9.0;
float distance_9_r = 0.0;
//Cube10 collision data
float collision_x_10_r = 8.0, collision_y_10_r = 1.0, collision_z_10_r = -10.0;
float distance_10_r = 0.0;

//UP WALL///////////////////////////////////////////////////////////////////////////////////////////////
//Cube1 collision data
float collision_x_1_u = -1.0, collision_y_1_u = 1.0, collision_z_1_u = -11.0;
float distance_1_u = 0.0;
//Cube2 collision data
float collision_x_2_u = 0.0, collision_y_2_u = 1.0, collision_z_2_u = -11.0;
float distance_2_u = 0.0;
//Cube3 collision data
float collision_x_3_u = 1.0, collision_y_3_u = 1.0, collision_z_3_u = -11.0;
float distance_3_u = 0.0;
//Cube4 collision data
float collision_x_4_u = 2.0, collision_y_4_u = 1.0, collision_z_4_u = -11.0;
float distance_4_u = 0.0;
//Cube5 collision data
float collision_x_5_u = 3.0, collision_y_5_u = 1.0, collision_z_5_u = -11.0;
float distance_5_u = 0.0;
//Cube6 collision data
float collision_x_6_u = 4.0, collision_y_6_u = 1.0, collision_z_6_u = -11.0;
float distance_6_u = 0.0;
//Cube7 collision data
float collision_x_7_u = 5.0, collision_y_7_u = 1.0, collision_z_7_u = -11.0;
float distance_7_u = 0.0;
//Cube8 collision data
float collision_x_8_u = 6.0, collision_y_8_u = 1.0, collision_z_8_u = -11.0;
float distance_8_u = 0.0;
//Cube9 collision data
float collision_x_9_u = 7.0, collision_y_9_u = 1.0, collision_z_9_u = -11.0;
float distance_9_u = 0.0;
//Cube10 collision data
float collision_x_10_u = 8.0, collision_y_10_u = 1.0, collision_z_10_u = -11.0;
float distance_10_u = 0.0;

//DOWN WALL///////////////////////////////////////////////////////////////////////////////////////////////
//Cube1 collision data
float collision_x_1_d = -1.0, collision_y_1_d = 1.0, collision_z_1_d = 0.0;
float distance_1_d = 0.0;
//Cube2 collision data
float collision_x_2_d = 0.0, collision_y_2_d = 1.0, collision_z_2_d = 0.0;
float distance_2_d = 0.0;
//Cube3 collision data
float collision_x_3_d = 1.0, collision_y_3_d = 1.0, collision_z_3_d = 0.0;
float distance_3_d = 0.0;
//Cube4 collision data
float collision_x_4_d = 2.0, collision_y_4_d = 1.0, collision_z_4_d = 0.0;
float distance_4_d = 0.0;
//Cube5 collision data
float collision_x_5_d = 3.0, collision_y_5_d = 1.0, collision_z_5_d = 0.0;
float distance_5_d = 0.0;
//Cube6 collision data
float collision_x_6_d = 4.0, collision_y_6_d = 1.0, collision_z_6_d = 0.0;
float distance_6_d = 0.0;
//Cube7 collision data
float collision_x_7_d = 5.0, collision_y_7_d = 1.0, collision_z_7_d = 0.0;
float distance_7_d = 0.0;
//Cube8 collision data
float collision_x_8_d = 6.0, collision_y_8_d = 1.0, collision_z_8_d = 0.0;
float distance_8_d = 0.0;
//Cube9 collision data
float collision_x_9_d = 7.0, collision_y_9_d = 1.0, collision_z_9_d = 0.0;
float distance_9_d = 0.0;
//Cube10 collision data
float collision_x_10_d = 8.0, collision_y_10_d = 1.0, collision_z_10_d= 0.0;
float distance_10_d = 0.0;

void draw()
{
    //Cube1
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(1.0f, 1.0f, 0.0f);
    glTranslatef(collision_x_1, collision_y_1, collision_z_1);
	glutSolidCube(1.0);
	glPopMatrix(); ////////////////////////////////////////////////////////

    //Cube2
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(0.0f, 1.0f, 0.0f);
    glTranslatef(collision_x_2, collision_y_2, collision_z_2);
	glutSolidCube(1.0);
	glPopMatrix(); ////////////////////////////////////////////////////////

    //Cube3
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(0.0f, 0.0f, 1.0f);
    glTranslatef(collision_x_3, collision_y_3, collision_z_3);
	glutSolidCube(1.0);
	glPopMatrix(); ////////////////////////////////////////////////////////

    //Cube4
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(collision_x_4, collision_y_4, collision_z_4);
	glutSolidCube(1.0);
	glPopMatrix(); ////////////////////////////////////////////////////////

    //Cube5
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(1.0f, 1.0f, 0.0f);
    glTranslatef(collision_x_5, collision_y_5, collision_z_5);
	glutSolidCube(1.0);
	glPopMatrix(); ////////////////////////////////////////////////////////

    //Cube6
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(0.0f, 1.0f, 0.0f);
    glTranslatef(collision_x_6, collision_y_6, collision_z_6);
	glutSolidCube(1.0);
	glPopMatrix(); ////////////////////////////////////////////////////////

    //Cube7
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(0.0f, 0.0f, 1.0f);
    glTranslatef(collision_x_7, collision_y_7, collision_z_7);
	glutSolidCube(1.0);
	glPopMatrix(); ////////////////////////////////////////////////////////

    //Cube8
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(collision_x_8, collision_y_8, collision_z_8);
	glutSolidCube(1.0);
	glPopMatrix(); ////////////////////////////////////////////////////////

    //Cube9
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(0.0f, 0.0f, 1.0f);
    glTranslatef(collision_x_9, collision_y_9, collision_z_9);
	glutSolidCube(1.0);
	glPopMatrix(); ////////////////////////////////////////////////////////

    //Cube10
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(collision_x_10, collision_y_10, collision_z_10);
	glutSolidCube(1.0);
	glPopMatrix(); ////////////////////////////////////////////////////////


    //RIGHT WALL ////////////////////////////////////////////////////////////////////////////////////////////////////
    //Cube1_r
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(1.0f, 1.0f, 0.0f);
    glTranslatef(collision_x_1_r, collision_y_1_r, collision_z_1_r);
	glutSolidCube(1.0);
	glPopMatrix(); ////////////////////////////////////////////////////////

    //Cube2
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(0.0f, 1.0f, 0.0f);
    glTranslatef(collision_x_2_r, collision_y_2_r, collision_z_2_r);
	glutSolidCube(1.0);
	glPopMatrix(); ////////////////////////////////////////////////////////

    //Cube3_r
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(0.0f, 0.0f, 1.0f);
    glTranslatef(collision_x_3_r, collision_y_3_r, collision_z_3_r);
	glutSolidCube(1.0);
	glPopMatrix(); ////////////////////////////////////////////////////////

    //Cube4_r
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(collision_x_4_r, collision_y_4_r, collision_z_4_r);
	glutSolidCube(1.0);
	glPopMatrix(); ////////////////////////////////////////////////////////

    //Cube5_r
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(1.0f, 1.0f, 0.0f);
    glTranslatef(collision_x_5_r, collision_y_5_r, collision_z_5_r);
	glutSolidCube(1.0);
	glPopMatrix(); ////////////////////////////////////////////////////////

    //Cube6_r
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(0.0f, 1.0f, 0.0f);
    glTranslatef(collision_x_6_r, collision_y_6_r, collision_z_6_r);
	glutSolidCube(1.0);
	glPopMatrix(); ////////////////////////////////////////////////////////

    //Cube7_r
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(0.0f, 0.0f, 1.0f);
    glTranslatef(collision_x_7_r, collision_y_7_r, collision_z_7_r);
	glutSolidCube(1.0);
	glPopMatrix(); ////////////////////////////////////////////////////////

    //Cube8_r
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(collision_x_8_r, collision_y_8_r, collision_z_8_r);
	glutSolidCube(1.0);
	glPopMatrix(); ////////////////////////////////////////////////////////

    //Cube9_r
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(0.0f, 0.0f, 1.0f);
    glTranslatef(collision_x_9_r, collision_y_9_r, collision_z_9_r);
	glutSolidCube(1.0);
	glPopMatrix(); ////////////////////////////////////////////////////////

    //Cube10_r
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(collision_x_10_r, collision_y_10_r, collision_z_10_r);
	glutSolidCube(1.0);
	glPopMatrix(); ////////////////////////////////////////////////////////

    //UP WALL ////////////////////////////////////////////////////////////////////////////////////////////////////
    //Cube1_u
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(1.0f, 1.0f, 0.0f);
    glTranslatef(collision_x_1_u, collision_y_1_u, collision_z_1_u);
	glutSolidCube(1.0);
	glPopMatrix(); ////////////////////////////////////////////////////////

    //Cube2
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(0.0f, 1.0f, 0.0f);
    glTranslatef(collision_x_2_u, collision_y_2_u, collision_z_2_u);
	glutSolidCube(1.0);
	glPopMatrix(); ////////////////////////////////////////////////////////

    //Cube3_u
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(0.0f, 0.0f, 1.0f);
    glTranslatef(collision_x_3_u, collision_y_3_u, collision_z_3_u);
	glutSolidCube(1.0);
	glPopMatrix(); ////////////////////////////////////////////////////////

    //Cube4_u
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(collision_x_4_u, collision_y_4_u, collision_z_4_u);
	glutSolidCube(1.0);
	glPopMatrix(); ////////////////////////////////////////////////////////

    //Cube5_u
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(1.0f, 1.0f, 0.0f);
    glTranslatef(collision_x_5_u, collision_y_5_u, collision_z_5_u);
	glutSolidCube(1.0);
	glPopMatrix(); ////////////////////////////////////////////////////////

    //Cube6_u
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(0.0f, 1.0f, 0.0f);
    glTranslatef(collision_x_6_u, collision_y_6_u, collision_z_6_u);
	glutSolidCube(1.0);
	glPopMatrix(); ////////////////////////////////////////////////////////

    //Cube7_u
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(0.0f, 0.0f, 1.0f);
    glTranslatef(collision_x_7_u, collision_y_7_u, collision_z_7_u);
	glutSolidCube(1.0);
	glPopMatrix(); ////////////////////////////////////////////////////////

    //Cube8_u
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(collision_x_8_u, collision_y_8_u, collision_z_8_u);
	glutSolidCube(1.0);
	glPopMatrix(); ////////////////////////////////////////////////////////

    //Cube9_u
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(0.0f, 0.0f, 1.0f);
    glTranslatef(collision_x_9_u, collision_y_9_u, collision_z_9_u);
	glutSolidCube(1.0);
	glPopMatrix(); ////////////////////////////////////////////////////////

    //Cube10_u
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(collision_x_10_u, collision_y_10_u, collision_z_10_u);
	glutSolidCube(1.0);
	glPopMatrix(); ////////////////////////////////////////////////////////

    //DOWN WALL ////////////////////////////////////////////////////////////////////////////////////////////////////
    //Cube1_d
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(1.0f, 1.0f, 0.0f);
    glTranslatef(collision_x_1_d, collision_y_1_d, collision_z_1_d);
	glutSolidCube(1.0);
	glPopMatrix(); ////////////////////////////////////////////////////////

    //Cube2
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(0.0f, 1.0f, 0.0f);
    glTranslatef(collision_x_2_d, collision_y_2_d, collision_z_2_d);
	glutSolidCube(1.0);
	glPopMatrix(); ////////////////////////////////////////////////////////

    //Cube3_d
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(0.0f, 0.0f, 1.0f);
    glTranslatef(collision_x_3_d, collision_y_3_d, collision_z_3_d);
	glutSolidCube(1.0);
	glPopMatrix(); ////////////////////////////////////////////////////////

    //Cube4_d
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(collision_x_4_d, collision_y_4_d, collision_z_4_d);
	glutSolidCube(1.0);
	glPopMatrix(); ////////////////////////////////////////////////////////

    //Cube5_d
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(1.0f, 1.0f, 0.0f);
    glTranslatef(collision_x_5_d, collision_y_5_d, collision_z_5_d);
	glutSolidCube(1.0);
	glPopMatrix(); ////////////////////////////////////////////////////////

    //Cube6_d
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(0.0f, 1.0f, 0.0f);
    glTranslatef(collision_x_6_d, collision_y_6_d, collision_z_6_d);
	glutSolidCube(1.0);
	glPopMatrix(); ////////////////////////////////////////////////////////

    //Cube7_d
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(0.0f, 0.0f, 1.0f);
    glTranslatef(collision_x_7_d, collision_y_7_d, collision_z_7_d);
	glutSolidCube(1.0);
	glPopMatrix(); ////////////////////////////////////////////////////////

    //Cube8_d
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(collision_x_8_d, collision_y_8_d, collision_z_8_d);
	glutSolidCube(1.0);
	glPopMatrix(); ////////////////////////////////////////////////////////

    //Cube9_d
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(0.0f, 0.0f, 1.0f);
    glTranslatef(collision_x_9_d, collision_y_9_d, collision_z_9_d);
	glutSolidCube(1.0);
	glPopMatrix(); ////////////////////////////////////////////////////////

    //Cube10_d
    glPushMatrix(); ////////////////////////////////////////////////////////
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(collision_x_10_d, collision_y_10_d, collision_z_10_d);
	glutSolidCube(1.0);
	glPopMatrix(); ////////////////////////////////////////////////////////
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

    //LEFT WALL ////////////////////////////////////////////////////////////////////////////////////////////////////
    //Cube1
	distance_1 = sqrt((collision_x_1 - x) * (collision_x_1 - x) + (collision_y_1 - y) * (collision_y_1 - y) + (collision_z_1 - z) * (collision_z_1 - z));
    std::cout << distance_1 << std::endl;

    //Cube2
	distance_2 = sqrt((collision_x_2 - x) * (collision_x_2 - x) + (collision_y_2 - y) * (collision_y_2 - y) + (collision_z_2 - z) * (collision_z_2 - z));
    std::cout << distance_2 << std::endl;

    //Cube3
	distance_3 = sqrt((collision_x_3 - x) * (collision_x_3 - x) + (collision_y_3 - y) * (collision_y_3 - y) + (collision_z_3 - z) * (collision_z_3 - z));
    std::cout << distance_3 << std::endl;

    //Cube4
	distance_4 = sqrt((collision_x_4 - x) * (collision_x_4 - x) + (collision_y_4 - y) * (collision_y_4 - y) + (collision_z_4 - z) * (collision_z_4 - z));
    std::cout << distance_4 << std::endl;

    //Cube5
	distance_5 = sqrt((collision_x_5 - x) * (collision_x_5 - x) + (collision_y_5 - y) * (collision_y_5 - y) + (collision_z_5 - z) * (collision_z_5 - z));
    std::cout << distance_5 << std::endl;

    //Cube6
	distance_6 = sqrt((collision_x_6 - x) * (collision_x_6 - x) + (collision_y_6 - y) * (collision_y_6 - y) + (collision_z_6 - z) * (collision_z_6 - z));
    std::cout << distance_6 << std::endl;

    //Cube7
	distance_7 = sqrt((collision_x_7 - x) * (collision_x_7 - x) + (collision_y_7 - y) * (collision_y_7 - y) + (collision_z_7 - z) * (collision_z_7 - z));
    std::cout << distance_7 << std::endl;

    //Cube8
	distance_8 = sqrt((collision_x_8 - x) * (collision_x_8 - x) + (collision_y_8 - y) * (collision_y_8 - y) + (collision_z_8 - z) * (collision_z_8 - z));
    std::cout << distance_8 << std::endl;

    //Cube9
	distance_9 = sqrt((collision_x_9 - x) * (collision_x_9 - x) + (collision_y_9 - y) * (collision_y_9 - y) + (collision_z_9 - z) * (collision_z_9 - z));
    std::cout << distance_9 << std::endl;

    //Cube10
	distance_10 = sqrt((collision_x_10 - x) * (collision_x_10 - x) + (collision_y_10 - y) * (collision_y_10 - y) + (collision_z_10 - z) * (collision_z_10 - z));
    std::cout << distance_10 << std::endl;

    //RIGHT WALL ////////////////////////////////////////////////////////////////////////////////////////////////////
    //Cube1_r
	distance_1_r = sqrt((collision_x_1_r - x) * (collision_x_1_r - x) + (collision_y_1_r - y) * (collision_y_1_r - y) + (collision_z_1_r - z) * (collision_z_1_r - z));
    std::cout << distance_1_r << std::endl;

    //Cube2_r
	distance_2_r = sqrt((collision_x_2_r - x) * (collision_x_2_r - x) + (collision_y_2_r - y) * (collision_y_2_r - y) + (collision_z_2_r - z) * (collision_z_2_r - z));
    std::cout << distance_2_r << std::endl;

    //Cube3_r
	distance_3_r = sqrt((collision_x_3_r - x) * (collision_x_3_r - x) + (collision_y_3_r - y) * (collision_y_3_r - y) + (collision_z_3_r - z) * (collision_z_3_r - z));
    std::cout << distance_3_r << std::endl;

    //Cube4_r
	distance_4_r = sqrt((collision_x_4_r - x) * (collision_x_4_r - x) + (collision_y_4_r - y) * (collision_y_4_r - y) + (collision_z_4_r - z) * (collision_z_4_r - z));
    std::cout << distance_4_r << std::endl;

    //Cube5_r
	distance_5_r = sqrt((collision_x_5_r - x) * (collision_x_5_r - x) + (collision_y_5_r - y) * (collision_y_5_r - y) + (collision_z_5_r - z) * (collision_z_5_r - z));
    std::cout << distance_5_r << std::endl;

    //Cube6_r
	distance_6_r = sqrt((collision_x_6_r - x) * (collision_x_6_r - x) + (collision_y_6_r - y) * (collision_y_6_r - y) + (collision_z_6_r - z) * (collision_z_6_r - z));
    std::cout << distance_6_r << std::endl;

    //Cube7_r
	distance_7_r = sqrt((collision_x_7_r - x) * (collision_x_7_r - x) + (collision_y_7_r - y) * (collision_y_7_r - y) + (collision_z_7_r - z) * (collision_z_7_r - z));
    std::cout << distance_7_r << std::endl;

    //Cube8_r
	distance_8_r = sqrt((collision_x_8_r - x) * (collision_x_8_r - x) + (collision_y_8_r - y) * (collision_y_8_r - y) + (collision_z_8_r - z) * (collision_z_8_r - z));
    std::cout << distance_8_r << std::endl;

    //Cube9_r
	distance_9_r = sqrt((collision_x_9_r - x) * (collision_x_9_r - x) + (collision_y_9_r - y) * (collision_y_9_r - y) + (collision_z_9_r - z) * (collision_z_9_r - z));
    std::cout << distance_9_r << std::endl;

    //Cube10_r
	distance_10_r = sqrt((collision_x_10_r - x) * (collision_x_10_r - x) + (collision_y_10_r - y) * (collision_y_10_r - y) + (collision_z_10_r - z) * (collision_z_10_r - z));
    std::cout << distance_10_r << std::endl;

    //UP WALL ////////////////////////////////////////////////////////////////////////////////////////////////////
    //Cube1_u
	distance_1_u = sqrt((collision_x_1_u - x) * (collision_x_1_u - x) + (collision_y_1_u - y) * (collision_y_1_u - y) + (collision_z_1_u - z) * (collision_z_1_u - z));
    std::cout << distance_1_u << std::endl;

    //Cube2_u
	distance_2_u = sqrt((collision_x_2_u - x) * (collision_x_2_u - x) + (collision_y_2_u - y) * (collision_y_2_u - y) + (collision_z_2_u - z) * (collision_z_2_u - z));
    std::cout << distance_2_u << std::endl;

    //Cube3_u
	distance_3_u = sqrt((collision_x_3_u - x) * (collision_x_3_u - x) + (collision_y_3_u - y) * (collision_y_3_u - y) + (collision_z_3_u - z) * (collision_z_3_u - z));
    std::cout << distance_3_u << std::endl;

    //Cube4_u
	distance_4_u = sqrt((collision_x_4_u - x) * (collision_x_4_u - x) + (collision_y_4_u - y) * (collision_y_4_u - y) + (collision_z_4_u - z) * (collision_z_4_u - z));
    std::cout << distance_4_u << std::endl;

    //Cube5_u
	distance_5_u = sqrt((collision_x_5_u - x) * (collision_x_5_u - x) + (collision_y_5_u - y) * (collision_y_5_u - y) + (collision_z_5_u - z) * (collision_z_5_u - z));
    std::cout << distance_5_u << std::endl;

    //Cube6_u
	distance_6_u = sqrt((collision_x_6_u - x) * (collision_x_6_u - x) + (collision_y_6_u - y) * (collision_y_6_u - y) + (collision_z_6_u - z) * (collision_z_6_u - z));
    std::cout << distance_6_u << std::endl;

    //Cube7_u
	distance_7_u = sqrt((collision_x_7_u - x) * (collision_x_7_u - x) + (collision_y_7_u - y) * (collision_y_7_u - y) + (collision_z_7_u - z) * (collision_z_7_u - z));
    std::cout << distance_7_u << std::endl;

    //Cube8_u
	distance_8_u = sqrt((collision_x_8_u - x) * (collision_x_8_u - x) + (collision_y_8_u - y) * (collision_y_8_u - y) + (collision_z_8_u - z) * (collision_z_8_u - z));
    std::cout << distance_8_u << std::endl;

    //Cube9_u
	distance_9_u = sqrt((collision_x_9_u - x) * (collision_x_9_u - x) + (collision_y_9_u - y) * (collision_y_9_u - y) + (collision_z_9_u - z) * (collision_z_9_u - z));
    std::cout << distance_9_u << std::endl;

    //Cube10_u
	distance_10_u = sqrt((collision_x_10_u - x) * (collision_x_10_u - x) + (collision_y_10_u - y) * (collision_y_10_u - y) + (collision_z_10_u - z) * (collision_z_10_u - z));
    std::cout << distance_10_u << std::endl;

    //DOWN WALL ////////////////////////////////////////////////////////////////////////////////////////////////////
    //Cube1_d
	distance_1_d = sqrt((collision_x_1_d - x) * (collision_x_1_d - x) + (collision_y_1_d - y) * (collision_y_1_d - y) + (collision_z_1_d - z) * (collision_z_1_d - z));
    std::cout << distance_1_d << std::endl;

    //Cube2_d
	distance_2_d = sqrt((collision_x_2_d - x) * (collision_x_2_d - x) + (collision_y_2_d - y) * (collision_y_2_d - y) + (collision_z_2_d - z) * (collision_z_2_d - z));
    std::cout << distance_2_d << std::endl;

    //Cube3_d
	distance_3_d = sqrt((collision_x_3_d - x) * (collision_x_3_d - x) + (collision_y_3_d - y) * (collision_y_3_d - y) + (collision_z_3_d - z) * (collision_z_3_d - z));
    std::cout << distance_3_d << std::endl;

    //Cube4_d
	distance_4_d = sqrt((collision_x_4_d - x) * (collision_x_4_d - x) + (collision_y_4_d - y) * (collision_y_4_d - y) + (collision_z_4_d - z) * (collision_z_4_d - z));
    std::cout << distance_4_d << std::endl;

    //Cube5_d
	distance_5_d = sqrt((collision_x_5_d - x) * (collision_x_5_d - x) + (collision_y_5_d - y) * (collision_y_5_d - y) + (collision_z_5_d - z) * (collision_z_5_d - z));
    std::cout << distance_5_d << std::endl;

    //Cube6_d
	distance_6_d = sqrt((collision_x_6_d - x) * (collision_x_6_d - x) + (collision_y_6_d - y) * (collision_y_6_d - y) + (collision_z_6_d - z) * (collision_z_6_d - z));
    std::cout << distance_6_d << std::endl;

    //Cube7_d
	distance_7_d = sqrt((collision_x_7_d - x) * (collision_x_7_d - x) + (collision_y_7_d - y) * (collision_y_7_d - y) + (collision_z_7_d - z) * (collision_z_7_d - z));
    std::cout << distance_7_d << std::endl;

    //Cube8_d
	distance_8_d = sqrt((collision_x_8_d - x) * (collision_x_8_d - x) + (collision_y_8_d - y) * (collision_y_8_d - y) + (collision_z_8_d - z) * (collision_z_8_d - z));
    std::cout << distance_8_d << std::endl;

    //Cube9_d
	distance_9_d = sqrt((collision_x_9_d - x) * (collision_x_9_d - x) + (collision_y_9_d - y) * (collision_y_9_d - y) + (collision_z_9_d - z) * (collision_z_9_d - z));
    std::cout << distance_9_d << std::endl;

    //Cube10_d
	distance_10_d = sqrt((collision_x_10_d - x) * (collision_x_10_d - x) + (collision_y_10_d - y) * (collision_y_10_d - y) + (collision_z_10_d - z) * (collision_z_10_d - z));
    std::cout << distance_10_d << std::endl;

    //LEFT WALL ////////////////////////////////////////////////////////////////////////////////////////////////////
	if(distance_1 < collision_radius)//Cube1
    {
        std::cout << "Collision!!!!!!!!!" << std::endl;

        if (moved)
        {
			x -= lx * fraction;
			z -= lz * fraction;
        }
        else
        {
			x += lx * fraction;
			z += lz * fraction;
        }
    }
    else if(distance_2 < collision_radius)//Cube2
    {
        std::cout << "Collision!!!!!!!!!" << std::endl;

        if (moved)
        {
			x -= lx * fraction;
			z -= lz * fraction;
        }
        else
        {
			x += lx * fraction;
			z += lz * fraction;
        }
    }
    else if(distance_3 < collision_radius)//Cube3
    {
        std::cout << "Collision!!!!!!!!!" << std::endl;

        if (moved)
        {
			x -= lx * fraction;
			z -= lz * fraction;
        }
        else
        {
			x += lx * fraction;
			z += lz * fraction;
        }
    }
    else if(distance_4 < collision_radius)//Cube4
    {
        std::cout << "Collision!!!!!!!!!" << std::endl;

        if (moved)
        {
			x -= lx * fraction;
			z -= lz * fraction;
        }
        else
        {
			x += lx * fraction;
			z += lz * fraction;
        }
    }
    else if(distance_5 < collision_radius)//Cube5
    {
        std::cout << "Collision!!!!!!!!!" << std::endl;

        if (moved)
        {
			x -= lx * fraction;
			z -= lz * fraction;
        }
        else
        {
			x += lx * fraction;
			z += lz * fraction;
        }
    }
    else if(distance_6 < collision_radius)//Cube6
    {
        std::cout << "Collision!!!!!!!!!" << std::endl;

        if (moved)
        {
			x -= lx * fraction;
			z -= lz * fraction;
        }
        else
        {
			x += lx * fraction;
			z += lz * fraction;
        }
    }
    else if(distance_7 < collision_radius)//Cube7
    {
        std::cout << "Collision!!!!!!!!!" << std::endl;

        if (moved)
        {
			x -= lx * fraction;
			z -= lz * fraction;
        }
        else
        {
			x += lx * fraction;
			z += lz * fraction;
        }
    }

    else if(distance_8 < collision_radius)//Cube8
    {
        std::cout << "Collision!!!!!!!!!" << std::endl;

        if (moved)
        {
			x -= lx * fraction;
			z -= lz * fraction;
        }
        else
        {
			x += lx * fraction;
			z += lz * fraction;
        }
    }
    else if(distance_9 < collision_radius)//Cube9
    {
        std::cout << "Collision!!!!!!!!!" << std::endl;

        if (moved)
        {
			x -= lx * fraction;
			z -= lz * fraction;
        }
        else
        {
			x += lx * fraction;
			z += lz * fraction;
        }
    }
    else if(distance_10 < collision_radius)//Cube10
    {
        std::cout << "Collision!!!!!!!!!" << std::endl;

        if (moved)
        {
			x -= lx * fraction;
			z -= lz * fraction;
        }
        else
        {
			x += lx * fraction;
			z += lz * fraction;
        }
    }

    //RIGHT WALL ////////////////////////////////////////////////////////////////////////////////////////////////////
	if(distance_1_r < collision_radius)//Cube1_r
    {
        std::cout << "Collision!!!!!!!!!" << std::endl;

        if (moved)
        {
			x -= lx * fraction;
			z -= lz * fraction;
        }
        else
        {
			x += lx * fraction;
			z += lz * fraction;
        }
    }
    else if(distance_2_r < collision_radius)//Cube2_r
    {
        std::cout << "Collision!!!!!!!!!" << std::endl;

        if (moved)
        {
			x -= lx * fraction;
			z -= lz * fraction;
        }
        else
        {
			x += lx * fraction;
			z += lz * fraction;
        }
    }
    else if(distance_3_r < collision_radius)//Cube3_r
    {
        std::cout << "Collision!!!!!!!!!" << std::endl;

        if (moved)
        {
			x -= lx * fraction;
			z -= lz * fraction;
        }
        else
        {
			x += lx * fraction;
			z += lz * fraction;
        }
    }
    else if(distance_4_r < collision_radius)//Cube4_r
    {
        std::cout << "Collision!!!!!!!!!" << std::endl;

        if (moved)
        {
			x -= lx * fraction;
			z -= lz * fraction;
        }
        else
        {
			x += lx * fraction;
			z += lz * fraction;
        }
    }
    else if(distance_5_r < collision_radius)//Cube5_r
    {
        std::cout << "Collision!!!!!!!!!" << std::endl;

        if (moved)
        {
			x -= lx * fraction;
			z -= lz * fraction;
        }
        else
        {
			x += lx * fraction;
			z += lz * fraction;
        }
    }
    else if(distance_6_r < collision_radius)//Cube6_r
    {
        std::cout << "Collision!!!!!!!!!" << std::endl;

        if (moved)
        {
			x -= lx * fraction;
			z -= lz * fraction;
        }
        else
        {
			x += lx * fraction;
			z += lz * fraction;
        }
    }
    else if(distance_7_r < collision_radius)//Cube7_r
    {
        std::cout << "Collision!!!!!!!!!" << std::endl;

        if (moved)
        {
			x -= lx * fraction;
			z -= lz * fraction;
        }
        else
        {
			x += lx * fraction;
			z += lz * fraction;
        }
    }

    else if(distance_8_r < collision_radius)//Cube8_r
    {
        std::cout << "Collision!!!!!!!!!" << std::endl;

        if (moved)
        {
			x -= lx * fraction;
			z -= lz * fraction;
        }
        else
        {
			x += lx * fraction;
			z += lz * fraction;
        }
    }
    else if(distance_9_r < collision_radius)//Cube9_r
    {
        std::cout << "Collision!!!!!!!!!" << std::endl;

        if (moved)
        {
			x -= lx * fraction;
			z -= lz * fraction;
        }
        else
        {
			x += lx * fraction;
			z += lz * fraction;
        }
    }
    else if(distance_10_r < collision_radius)//Cube10_r
    {
        std::cout << "Collision!!!!!!!!!" << std::endl;

        if (moved)
        {
			x -= lx * fraction;
			z -= lz * fraction;
        }
        else
        {
			x += lx * fraction;
			z += lz * fraction;
        }
    }

    //UP WALL ////////////////////////////////////////////////////////////////////////////////////////////////////
	if(distance_1_u < collision_radius)//Cube1_u
    {
        std::cout << "Collision!!!!!!!!!" << std::endl;

        if (moved)
        {
			x -= lx * fraction;
			z -= lz * fraction;
        }
        else
        {
			x += lx * fraction;
			z += lz * fraction;
        }
    }
    else if(distance_2_u < collision_radius)//Cube2_u
    {
        std::cout << "Collision!!!!!!!!!" << std::endl;

        if (moved)
        {
			x -= lx * fraction;
			z -= lz * fraction;
        }
        else
        {
			x += lx * fraction;
			z += lz * fraction;
        }
    }
    else if(distance_3_u < collision_radius)//Cube3_u
    {
        std::cout << "Collision!!!!!!!!!" << std::endl;

        if (moved)
        {
			x -= lx * fraction;
			z -= lz * fraction;
        }
        else
        {
			x += lx * fraction;
			z += lz * fraction;
        }
    }
    else if(distance_4_u < collision_radius)//Cube4_u
    {
        std::cout << "Collision!!!!!!!!!" << std::endl;

        if (moved)
        {
			x -= lx * fraction;
			z -= lz * fraction;
        }
        else
        {
			x += lx * fraction;
			z += lz * fraction;
        }
    }
    else if(distance_5_u < collision_radius)//Cube5_u
    {
        std::cout << "Collision!!!!!!!!!" << std::endl;

        if (moved)
        {
			x -= lx * fraction;
			z -= lz * fraction;
        }
        else
        {
			x += lx * fraction;
			z += lz * fraction;
        }
    }
    else if(distance_6_u < collision_radius)//Cube6_u
    {
        std::cout << "Collision!!!!!!!!!" << std::endl;

        if (moved)
        {
			x -= lx * fraction;
			z -= lz * fraction;
        }
        else
        {
			x += lx * fraction;
			z += lz * fraction;
        }
    }
    else if(distance_7_u < collision_radius)//Cube7_u
    {
        std::cout << "Collision!!!!!!!!!" << std::endl;

        if (moved)
        {
			x -= lx * fraction;
			z -= lz * fraction;
        }
        else
        {
			x += lx * fraction;
			z += lz * fraction;
        }
    }

    else if(distance_8_u < collision_radius)//Cube8_u
    {
        std::cout << "Collision!!!!!!!!!" << std::endl;

        if (moved)
        {
			x -= lx * fraction;
			z -= lz * fraction;
        }
        else
        {
			x += lx * fraction;
			z += lz * fraction;
        }
    }
    else if(distance_9_u < collision_radius)//Cube9_u
    {
        std::cout << "Collision!!!!!!!!!" << std::endl;

        if (moved)
        {
			x -= lx * fraction;
			z -= lz * fraction;
        }
        else
        {
			x += lx * fraction;
			z += lz * fraction;
        }
    }
    else if(distance_10_u < collision_radius)//Cube10_u
    {
        std::cout << "Collision!!!!!!!!!" << std::endl;

        if (moved)
        {
			x -= lx * fraction;
			z -= lz * fraction;
        }
        else
        {
			x += lx * fraction;
			z += lz * fraction;
        }
    }

    //DOWN WALL ////////////////////////////////////////////////////////////////////////////////////////////////////
	if(distance_1_d < collision_radius)//Cube1_d
    {
        std::cout << "Collision!!!!!!!!!" << std::endl;

        if (moved)
        {
			x -= lx * fraction;
			z -= lz * fraction;
        }
        else
        {
			x += lx * fraction;
			z += lz * fraction;
        }
    }
    else if(distance_2_d < collision_radius)//Cube2_d
    {
        std::cout << "Collision!!!!!!!!!" << std::endl;

        if (moved)
        {
			x -= lx * fraction;
			z -= lz * fraction;
        }
        else
        {
			x += lx * fraction;
			z += lz * fraction;
        }
    }
    else if(distance_3_d < collision_radius)//Cube3_d
    {
        std::cout << "Collision!!!!!!!!!" << std::endl;

        if (moved)
        {
			x -= lx * fraction;
			z -= lz * fraction;
        }
        else
        {
			x += lx * fraction;
			z += lz * fraction;
        }
    }
    else if(distance_4_d < collision_radius)//Cube4_d
    {
        std::cout << "Collision!!!!!!!!!" << std::endl;

        if (moved)
        {
			x -= lx * fraction;
			z -= lz * fraction;
        }
        else
        {
			x += lx * fraction;
			z += lz * fraction;
        }
    }
    else if(distance_5_d < collision_radius)//Cube5_d
    {
        std::cout << "Collision!!!!!!!!!" << std::endl;

        if (moved)
        {
			x -= lx * fraction;
			z -= lz * fraction;
        }
        else
        {
			x += lx * fraction;
			z += lz * fraction;
        }
    }
    else if(distance_6_d < collision_radius)//Cube6_d
    {
        std::cout << "Collision!!!!!!!!!" << std::endl;

        if (moved)
        {
			x -= lx * fraction;
			z -= lz * fraction;
        }
        else
        {
			x += lx * fraction;
			z += lz * fraction;
        }
    }
    else if(distance_7_d < collision_radius)//Cube7_d
    {
        std::cout << "Collision!!!!!!!!!" << std::endl;

        if (moved)
        {
			x -= lx * fraction;
			z -= lz * fraction;
        }
        else
        {
			x += lx * fraction;
			z += lz * fraction;
        }
    }

    else if(distance_8_d < collision_radius)//Cube8_d
    {
        std::cout << "Collision!!!!!!!!!" << std::endl;

        if (moved)
        {
			x -= lx * fraction;
			z -= lz * fraction;
        }
        else
        {
			x += lx * fraction;
			z += lz * fraction;
        }
    }
    else if(distance_9_d < collision_radius)//Cube9_d
    {
        std::cout << "Collision!!!!!!!!!" << std::endl;

        if (moved)
        {
			x -= lx * fraction;
			z -= lz * fraction;
        }
        else
        {
			x += lx * fraction;
			z += lz * fraction;
        }
    }
    else if(distance_10_d < collision_radius)//Cube10_d
    {
        std::cout << "Collision!!!!!!!!!" << std::endl;

        if (moved)
        {
			x -= lx * fraction;
			z -= lz * fraction;
        }
        else
        {
			x += lx * fraction;
			z += lz * fraction;
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

	gluPerspective(45,ratio,1,100);

	glMatrixMode(GL_MODELVIEW);
}

void processSpecialKeys(unsigned char key, int r, int s) //MOVER CON EL TECLADO EL ESCENARIO
{
	switch (key)
    {
		case 'w' :
			x += lx * fraction;
			z += lz * fraction;
            moved = true;
			break;
		case 's' :
			x -= lx * fraction;
			z -= lz * fraction;
            moved = false;
			break;
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
		case 'm' :
            y = (y == 40.0) ? 1.0 : 40.0;
	}
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("aMEZEing");

	//glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	//glutSpecialFunc(processSpecialKeys);
    glutKeyboardFunc(processSpecialKeys);

	glEnable(GL_DEPTH_TEST);

	glutMainLoop();

	return 1;
}
