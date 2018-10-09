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

    int i, j, v_j = 4;
    int new_h, new_v;
    for(i = 4; i > 0; i--)
    {
        for(j = v_j; j > 0; j--)
        {
            line(canvas, Point(h + init_x, v + init_y), Point(h + init_x + face * cos(0 * 0.01745333333), v + init_y - face * sin(0 * 0.01745333333)), Scalar(0, 0, 0));
            imshow("Draw", canvas);
            waitKey(100);

            h += face;
        }

        h -= face;

        for(j = v_j; j > 0; j--)
        {
            line(canvas, Point(h + init_x + face * cos(0 * 0.01745333333), v + init_y - face * sin(0 * 0.01745333333)), Point(h + init_x + face * cos(60 * 0.01745333333), v + init_y - face * sin(60 * 0.01745333333)), Scalar(0, 0, 0));
            imshow("Draw", canvas);
            waitKey(100);

            if(j != 1){
                line(canvas, Point(h + init_x + face * cos(60 * 0.01745333333), v + init_y - face * sin(60 * 0.01745333333)), Point(h + init_x, v + init_y),Scalar(0, 0, 0));
                imshow("Draw", canvas);
                waitKey(100);
                h -= face;
            }
        }

        h = 0;
        new_h += face / 2;
        h += new_h;
        v -= sqrt(pow(face, 2) - pow(face / 2, 2));
        v_j--;
    }

    int f;
    h -= face / 2;
    v += sqrt(pow(face, 2) - pow(face / 2, 2));
    for(f = 4; f > 0; f--)
    {
        line(canvas, Point(h + init_x + face * cos(60 * 0.01745333333), v + init_y - face * sin(60 * 0.01745333333)), Point(h + init_x, v + init_y),Scalar(0, 0, 0));
        imshow("Draw", canvas);
        waitKey(100);
        h -= face / 2;
        v += sqrt(pow(face, 2) - pow(face / 2, 2));
    }

    imshow("Draw", canvas);
    waitKey(0);

    return 0;
}
