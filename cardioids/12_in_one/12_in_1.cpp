/*
This files creates 12 drawings using cardioids and each one is animated.
*/
#include "opencv2/core/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <math.h>
#include <iostream>

using namespace cv;
using namespace std;


#define SIZE 700

int main()
{
    Mat canvas(SIZE, SIZE, CV_8UC3, Scalar(250, 250, 250));

    int i, j;
    float theta, x, y, m, r, R, radius = SIZE / 2;
    bool flag;
    m =radius;

    while (true)
    {
        R = 200;
        r = 25;
        flag = true;

        while(flag)
        {
            for (i = R; i > 0; i--)
            {

                for (j = 0; j < 360; j++)
                {
                    theta = j * 0.01745333333;
                    x = m + (R + r) * cos(theta) - r * cos(((R + r) / r) * theta);
                    y = m - (R + r) * sin(theta) + r * sin(((R + r) / r) * theta);
                    circle(canvas, Point(x, y), 1, Scalar(0, 0, 0), -1);
                    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE)
                        flag = false;
                }
                imshow("Draw", canvas);
                waitKey(5);
                R--;
                r -= 0.125;
            }
            cout << R << endl;
            cout << r << endl;
            waitKey(1000);
            canvas = (SIZE, SIZE, CV_8UC3, Scalar(250, 250, 250));
            R = 200;
            //r = 25;
        }
    }

    namedWindow("Draw", WINDOW_AUTOSIZE);
    imshow("Draw", canvas);
    waitKey(0);

    return 0;
}

