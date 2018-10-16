/*
This file creates a drawing using primitives (circles, lines, polygons, etc.).
*/
#include "opencv2/core/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <stdio.h>
#include <iostream>

using namespace cv;
using namespace std;

#define VER 700
#define HOR 1200

int main()
{
    Mat canvas(VER, HOR, CV_8UC3, Scalar(255, 242, 205));

    //Sun
    circle(canvas, Point(HOR - 200, 100), 50, Scalar(0, 0, 0));

    //Fisrt mountain
    line(canvas, Point(0, VER - 1), Point(150, VER - 250), Scalar(0, 0, 0));
    line(canvas, Point(150, VER - 250), Point(300, VER - 1), Scalar(0, 0, 0));

    //Second mountain
    line(canvas, Point(180, VER - 1), Point(350, VER - 375), Scalar(0, 0, 0));
    line(canvas, Point(350, VER - 375), Point(520, VER - 1), Scalar(0, 0, 0));

    //Third mountain
    line(canvas, Point(400, VER - 1), Point(650, VER - 500), Scalar(0, 0, 0));
    line(canvas, Point(650, VER - 500), Point(900, VER - 1), Scalar(0, 0, 0));

    //Fourth mountain
    line(canvas, Point(880, VER - 1), Point(1040, VER - 170), Scalar(0, 0, 0));
    line(canvas, Point(1040, VER - 170), Point(HOR - 1, VER - 1), Scalar(0, 0, 0));

    namedWindow("Draw", WINDOW_AUTOSIZE);
    imshow("Draw", canvas);

    waitKey(0);
    waitKey(0);
    waitKey(0);

    return 0;
}
