/*
Figure 2
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

//Polygons=======================================================
//    vector <Point> contour;
//
//    contour.push_back(Point(3, 0));
//    contour.push_back(Point(100, 0));
//    contour.push_back(Point(100, 150));
//    contour.push_back(Point(3, 150));
//    contour.push_back(Point(3, 0));
//
//    const Point *pts = (const Point*) Mat(contour).data;
//    int npts = Mat(contour).rows;
//
//    //polylines(canvas, &pts, &npts, 1, true, Scalar(255, 0, 0));
//    fillPoly(canvas, &pts, &npts, 1, Scalar(255, 0, 0));
//End Polygons===================================================

    int i, radius = SIZE / 2;
    float theta, x, y, m;

    theta = 90;
    m = (radius / 2) - 100;
    for (i = 0; i < 5; i++)
    {
        x = m * cos(0.01745333333 * theta);
        y = m * sin(0.01745333333 * theta);
        circle(canvas, Point(radius + x, radius - y), radius / 2, Scalar(0, 0, 0));
        theta += 72;
    }

    theta = 90;
    m = (radius) - 100;
    //m = radius;
    for (i = 0; i < 5; i++)
    {
        x = m * cos(0.01745333333 * theta);
        y = m * sin(0.01745333333 * theta);
        line(canvas, Point(radius + x,radius - y), Point(radius + m * cos(0.01745333333 * (theta + 72)),radius - m * sin(0.01745333333 * (theta + 72))), Scalar(0, 0, 0));
        theta += 72;
    }

    theta = 90;
    m = (radius) - 120;
    //m = radius;
    for (i = 0; i < 5; i++)
    {
        x = m * cos(0.01745333333 * theta);
        y = m * sin(0.01745333333 * theta);
        line(canvas, Point(radius + x,radius - y), Point(radius + m * cos(0.01745333333 * (theta + 72)),radius - m * sin(0.01745333333 * (theta + 72))), Scalar(0, 0, 0));
        theta += 72;
    }

    theta = 90 + 36;
    m = (radius) - 165;
    //m = radius;
    for (i = 0; i < 5; i++)
    {
        x = m * cos(0.01745333333 * theta);
        y = m * sin(0.01745333333 * theta);
        line(canvas, Point(radius + x,radius - y), Point(radius + m * cos(0.01745333333 * (theta + 72)),radius - m * sin(0.01745333333 * (theta + 72))), Scalar(0, 0, 0));
        theta += 72;
    }

    theta = 90 + 36;
    m = (radius) - 251;
    //m = radius;
    for (i = 0; i < 5; i++)
    {
        x = m * cos(0.01745333333 * theta);
        y = m * sin(0.01745333333 * theta);
        line(canvas, Point(radius + x,radius - y), Point(radius + m * cos(0.01745333333 * (theta + 72)),radius - m * sin(0.01745333333 * (theta + 72))), Scalar(0, 0, 0));
        theta += 72;
    }

    theta = 90;
    m = (radius) - 271;
    //m = radius;
    for (i = 0; i < 5; i++)
    {
        x = m * cos(0.01745333333 * theta);
        y = m * sin(0.01745333333 * theta);
        line(canvas, Point(radius + x,radius - y), Point(radius + m * cos(0.01745333333 * (theta + 72)),radius - m * sin(0.01745333333 * (theta + 72))), Scalar(0, 0, 0));
        theta += 72;
    }

    //Middle line
    theta = 90;
    m = (radius) - 120;
    //m = radius;
    for (i = 0; i < 5; i++)
    {
        x = m * cos(0.01745333333 * theta);
        y = m * sin(0.01745333333 * theta);
        line(canvas, Point(radius, radius) , Point(radius + m * cos(0.01745333333 * (theta + 72)),radius - m * sin(0.01745333333 * (theta + 72))), Scalar(0, 0, 0));
        theta += 72;
    }

//    theta = 90;
//    m = radius - 20;
//    for (i = 0; i < 5; i++)
//    {
//        x = m * cos(0.01745333333 * theta);
//        y = m * sin(0.01745333333 * theta);
//        line(canvas, Point(radius + x,radius - y), Point(radius + m * cos(0.01745333333 * (theta + 72)),radius - m * sin(0.01745333333 * (theta + 72))), Scalar(0, 0, 0));
//        theta += 72;
//    }
//
//    theta = 90 + 36;
//    m = radius - 85;
//    for (i = 0; i < 5; i++)
//    {
//        x = m * cos(0.01745333333 * theta);
//        y = m * sin(0.01745333333 * theta);
//        line(canvas, Point(radius + x,radius - y), Point(radius + m * cos(0.01745333333 * (theta + 72)),radius - m * sin(0.01745333333 * (theta + 72))), Scalar(0, 0, 0));
//        theta += 72;
//    }
//
//    theta = 90;
//    m = 50;
//    for (i = 0; i < 5; i++)
//    {
//        x = m * cos(0.01745333333 * theta);
//        y = m * sin(0.01745333333 * theta);
//        line(canvas, Point(radius + x,radius - y), Point(radius + m * cos(0.01745333333 * (theta + 72)),radius - m * sin(0.01745333333 * (theta + 72))), Scalar(0, 0, 0));
//        theta += 72;
//    }
//
//    theta = 90 + 36;
//    //m = 62;
//    m = (radius / 2) - 100;
//    for (i = 0; i < 5; i++)
//    {
//        x = m * cos(0.01745333333 * theta);
//        y = m * sin(0.01745333333 * theta);
//        line(canvas, Point(radius + x,radius - y), Point(radius + m * cos(0.01745333333 * (theta + 72)),radius - m * sin(0.01745333333 * (theta + 72))), Scalar(0, 0, 0));
//        theta += 72;
//    }


    namedWindow("Draw", WINDOW_AUTOSIZE);
    imshow("Draw", canvas);

    waitKey(0);

    return 0;
}
