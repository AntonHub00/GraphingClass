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

    int h = 0, v = 0;

    int i;
    for(i = 4; i > 0; i--)
    {
        line(canvas, Point(h + SIZE / 2, v + SIZE / 2), Point(h + SIZE / 2 + 50 * cos(0 * 0.01745333333), v + SIZE / 2 - 50 * sin(0 * 0.01745333333)), Scalar(0, 0, 0));
        imshow("Draw", canvas);
        waitKey(100);

        line(canvas, Point(h + SIZE / 2 + 50 * cos(0 * 0.01745333333), v + SIZE / 2 - 50 * sin(0 * 0.01745333333)), Point(h + SIZE / 2 + 50 * cos(60 * 0.01745333333), v + SIZE / 2 - 50 * sin(60 * 0.01745333333)), Scalar(0, 0, 0));
        imshow("Draw", canvas);
        waitKey(100);

        line(canvas, Point(h + SIZE / 2 + 50 * cos(60 * 0.01745333333), v + SIZE / 2 - 50 * sin(60 * 0.01745333333)), Point(h + SIZE / 2, v + SIZE / 2),Scalar(0, 0, 0));
        imshow("Draw", canvas);
        waitKey(100);

        h += 50;
    }

    imshow("Draw", canvas);
    waitKey(0);

    return 0;
}
