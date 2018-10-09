/*
Drawign a triangule with translations
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
    Mat canvas(SIZE, SIZE, CV_8UC3, Scalar(255, 255, 255));

    int h = 0, v = 0, face = 100;
    int init_x = SIZE / 2 - 2 * face, init_y = SIZE / 2 + face;

    int i;
    for(i = 4; i > 0; i--)
    {
        line(canvas, Point(h + init_x, v + init_y), Point(h + init_x + face * cos(0 * 0.01745333333), v + init_y - face * sin(0 * 0.01745333333)), Scalar(0, 0, 0));
        imshow("Draw", canvas);
        waitKey(100);

        line(canvas, Point(h + init_x + face * cos(0 * 0.01745333333), v + init_y - face * sin(0 * 0.01745333333)), Point(h + init_x + face * cos(60 * 0.01745333333), v + init_y - face * sin(60 * 0.01745333333)), Scalar(0, 0, 0));
        imshow("Draw", canvas);
        waitKey(100);

        line(canvas, Point(h + init_x + face * cos(60 * 0.01745333333), v + init_y - face * sin(60 * 0.01745333333)), Point(h + init_x, v + init_y),Scalar(0, 0, 0));
        imshow("Draw", canvas);
        waitKey(100);

        h += face;
    }

    imshow("Draw", canvas);
    waitKey(0);

    return 0;
}
