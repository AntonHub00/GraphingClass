/*
This creates a drawing using cardioids.
*/
#include "opencv2/core/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <math.h>
//#include <iostream>

using namespace cv;
using namespace std;


#define SIZE 700

int main()
{
    Mat canvas(SIZE, SIZE, CV_8UC3, Scalar(255, 255, 255));

    int i, radius = SIZE / 2;
    float theta, x, y, m;

    theta = 0;
    m = 3 * radius / 4;
    for (i = 0; i < 360; i++)
    {
        x = m * cos(0.01745333333 * theta);
        y = m * sin(0.01745333333 * theta);
        //circle(canvas, Point(radius + x, radius - y), radius / 2, Scalar(0, 0, 0));
        //circle(canvas, Point(radius + x, radius - y), radius / 2, Scalar(0, 0, 0));
        //line(canvas, Point(m, m), Point(m + x, m - y), Scalar(0, 0, 0));
        //line(canvas, Point(m, m), Point(m + 100 * (1 - cos(i * 0.01745333333)), m - 100 * (1 - cos(i * 0.01745333333))), Scalar(0, 0, 0));
        //line(canvas, Point(m, m), Point(m + 100 * cos(i * 0.01745333333) * (1 - cos(i * 0.01745333333)), m - 100 * sin(i * 0.01745333333) * (1 - cos(i * 0.01745333333))), Scalar(0, 0, 0));
        circle(canvas, Point(m + 50 * cos(i * 0.01745333333) * (1 - cos(i * 0.01745333333)), m - 50 * sin(i * 0.01745333333) * (1 - cos(i * 0.01745333333))), 1, Scalar(0, 0, 0), -1);
        //theta += 90;
        imshow("Draw", canvas);
        waitKey(10);
    }

    namedWindow("Draw", WINDOW_AUTOSIZE);
    imshow("Draw", canvas);
    waitKey(0);

    return 0;
}

