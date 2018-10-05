/*
Figure 1
*/
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace cv;
using namespace std;


#define SIZE 700
#define PI 3.14159265

int main()
{
    Mat canvas(SIZE, SIZE, CV_8UC3, Scalar(255, 255, 255));

    int i, radius =( SIZE / 2) / 2;
    float theta = 0, x, y;

    for (i = 0; i < 12; i++)
    {
        x = radius * cos(theta);
        y = radius * sin(theta);
        circle(canvas, Point(SIZE / 2 + x, SIZE / 2 - y), radius, Scalar(0, 0, 0));
        theta += (PI / 6);
    }

    namedWindow("Draw", WINDOW_AUTOSIZE);
    imshow("Draw", canvas);

    waitKey(0);

    return 0;
}
