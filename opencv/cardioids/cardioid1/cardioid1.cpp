/*
This creates a drawing using cardioids.
*/
#include "opencv2/core/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <math.h>

using namespace cv;
using namespace std;


#define SIZE 700

int main()
{
    Mat canvas(SIZE, SIZE, CV_8UC3, Scalar(250, 250, 250));

    int i;
    float theta, x, y, m, k, r, R, radius;
    radius = SIZE / 2;
    m =radius;

    while(true)
    {
        for (i = 0; i < 360; i++)
        {
            theta = i * 0.01745333333;

            R = 200;
            r = 25;
            x = m + (R + r) * cos(theta) - r * cos(((R + r) / r) * theta);
            y = m - (R + r) * sin(theta) + r * sin(((R + r) / r) * theta);
            circle(canvas, Point(x, y), 2, Scalar(0, 0, 0), -1);

            R = 100;
            r = 25;
            x = m + (R + r) * cos(theta) - r * cos(((R + r) / r) * theta);
            y = m - (R + r) * sin(theta) + r * sin(((R + r) / r) * theta);
            circle(canvas, Point(x, y), 2, Scalar(0, 0, 0), -1);

            R = 50;
            r = 25;
            x = m + (R + r) * cos(theta) - r * cos(((R + r) / r) * theta);
            y = m - (R + r) * sin(theta) + r * sin(((R + r) / r) * theta);
            circle(canvas, Point(x, y), 2, Scalar(0, 0, 0), -1);

            imshow("Draw", canvas);
            waitKey(5);
        }
        waitKey(1000);
        canvas = (SIZE, SIZE, CV_8UC3, Scalar(250, 250, 250));
    }

    namedWindow("Draw", WINDOW_AUTOSIZE);
    imshow("Draw", canvas);
    waitKey(0);

    return 0;
}

