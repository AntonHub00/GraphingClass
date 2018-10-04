/*
This code prints a circle figure just with lines and 24 vertices
*/
#include "opencv2/core/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
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

    int i, j, radius = SIZE / 2;
    float theta_alpha = 0, x1, y1;

    for (i = 0; i < 24; i++)
    {
        x1 = radius * cos(theta_alpha);
        y1 = radius * sin(theta_alpha);
        float theta = 0, x2, y2;

        for (j = 0; j < 24; j++)
        {
            x2 = radius * cos(theta);
            y2 = radius * sin(theta);
            line(canvas, Point(radius + x1, radius - y1), Point(radius + x2, radius - y2), Scalar(0, 0, 0));
            theta += (PI / 12);
        }
        theta_alpha += (PI / 12);
    }

    namedWindow("Draw", WINDOW_AUTOSIZE);
    imshow("Draw", canvas);

    waitKey(0);

    return 0;
}
