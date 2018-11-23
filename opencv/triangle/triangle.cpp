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

    int face, n, x1, y1,x, y, new_x, new_y, counter, counter_line;
    n = 4;
    face = 100;
    float h = sqrt(pow(face, 2) - pow(face / 2, 2)), m;
    counter = n * face;
    counter_line = n;
    new_x = (SIZE - counter) / 2;
    new_y =  SIZE - ((SIZE - n * h) / 2);

    int i, j, k;
    for(i = 0; i < n; i++)
    {
        x1 = new_x;
        y1 = new_y;

        for(j = 0; j < counter; j++)
        {
            x1++;
            circle(canvas, Point(x1, y1), 1, Scalar(0, 0, 0), 2);
            imshow("Draw", canvas);
            waitKey(1);
        }

        for(k = counter_line; k > 0; k--)
        {
            m = h  / (face / 2);
            x = x1;
            y = y1;
            for(j = 0; j < face / 2; j++)
            {
                x1--;
                y1 = m * (x1 - x) + y;
                circle(canvas, Point(x1, y1), 1, Scalar(0, 0, 0), 2);
                imshow("Draw", canvas);
                waitKey(1);
            }

            if(k != 1)
            {
                x = x1;
                y = y1;
                m = -h  / (face / 2);
                for(j = 0; j < face / 2; j++)
                {
                    x1--;
                    y1 = m * (x1 - x) + y;
                    circle(canvas, Point(x1, y1), 1, Scalar(0, 0, 0), 2);
                    imshow("Draw", canvas);
                    waitKey(1);
                }
            }
        }

        if(i == n - 1)
        {
            m = -h  / (face / 2);

            for(k = n; k > 0; k--)
            {
                x = x1;
                y = y1;

                for(j = 0; j < face / 2; j++)
                {
                    x1--;
                    y1 = m * (x1 - x) + y;
                    circle(canvas, Point(x1, y1), 1, Scalar(0, 0, 0), 2);
                    imshow("Draw", canvas);
                    waitKey(1);
                }
                x = x1;
                y = y1;
            }
        }

        new_x += face / 2 ;
        new_y -= h;
        counter -= face;
        counter_line--;
    }

    imshow("Draw", canvas);
    waitKey(0);

    return 0;
}
