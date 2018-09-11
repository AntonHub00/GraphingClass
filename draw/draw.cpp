/*
Testing "techniques" for printing the image
*/

#include "opencv2/core/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>

#define SIZE 800

using namespace cv;
using namespace std;

void set_background(int ptr_image[][SIZE], int color);

void print_image(int[][SIZE]);

void paint(int ptr_image[][SIZE], int x1, int y1, int x2, int y2, int color);

void complete_half(int ptr_image[][SIZE]);

int main()
{
    int image[SIZE][SIZE];

    set_background(image, 255);

    //Left side
    paint(image, 14, 4, 28, 6, 0);

    //Up-left side
    paint(image, 10, 6, 16, 8, 0);
    paint(image, 8, 8, 12, 10, 0);
    paint(image, 6, 10, 10, 12, 0);
    paint(image, 6, 12, 8, 16, 0);

    //top
    paint(image, 4, 14, 6, 20, 0);

    //Down-left side
    paint(image, 26, 6, 30, 8, 0);
    paint(image, 26, 8, 34, 10, 0);
    paint(image, 32, 10, 36, 12, 0);

    //Down
    paint(image, 34, 12, 36, 20, 0);

    //Face
    paint(image, 24, 10, 28, 12, 0);
    paint(image, 24, 12, 26, 20, 0);
    paint(image, 26, 16, 30, 18, 0);

    //Inside mushroom (5 up)
    paint(image, 10, 10, 14, 12, 128);
    paint(image, 12, 12, 22, 14, 128);
    paint(image, 12, 14, 16, 16, 128);
    paint(image, 10, 16, 14, 18, 128);
    paint(image, 6, 18, 14, 20, 128);

    //Inside mushroom (2 down)
    paint(image, 22, 6, 24, 16, 128);
    paint(image, 24, 6, 26, 10, 128);

    //Completing the half "automatically"
    complete_half(image);

    //Print the complete image
    // print_image(image);

    int i, j;
    Mat m(SIZE, SIZE, CV_8UC1, Scalar(255));
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            m.at<uchar>(i, j) = image[i][j];
        }
    }

    namedWindow("img", WINDOW_AUTOSIZE);

    imshow("img", m);

    waitKey(0);

    return 0;
}

void set_background(int ptr_image[][SIZE], int color)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            ptr_image[i][j] = color;
        }
    }
}

void print_image(int ptr_image[][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d ", ptr_image[i][j]);
        }
        printf("\n");
    }
}

void paint(int ptr_image[][SIZE], int x1, int y1, int x2, int y2, int color)
{
    int resize = SIZE / 40;

    for (int i = x1 * resize; i < x2 * resize; i++)
    {
        for (int j = y1 * resize; j < y2 * resize; j++)
        {
            ptr_image[i][j] = color;
        }
    }
}

void complete_half(int ptr_image[][SIZE])
{
    int aux = SIZE - 1;

    for (int i = 0; i < SIZE; i++)
    {
        aux = SIZE - 1;

        for (int j = 0; j < SIZE / 2; j++)
        {
            ptr_image[i][aux] = ptr_image[i][j];
            aux--;
        }
    }
}