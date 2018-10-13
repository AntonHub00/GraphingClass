/*
A little game based on a machinarium puzzle
*/
#include "opencv2/core/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;

#define SIZE 530

#define LEFT_KEY 97
#define RIGHT_KEY 100
#define UP_KEY 119
#define DOWN_KEY 115
#define INTRO 10

void draw_grid(Mat ptr_canvas);
int set_position();

int main()
{
    Mat canvas(SIZE, SIZE, CV_8UC3, Scalar(255, 255, 255));
    int position;

    position = set_position();

    draw_grid(canvas);

    namedWindow("Draw", WINDOW_AUTOSIZE);
    imshow("Draw", canvas);

    waitKey(0);

    return 0;
}

void draw_grid(Mat ptr_canvas)
{
    Point vertices[4];
    int i, j;
    int x = 5, y = 5;

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            vertices[0] = Point(x, y);
            vertices[1] = Point(x + 100, y);
            vertices[2] = Point(x + 100, y + 100);
            vertices[3] = Point(x, y + 100);
            if(i == 0 &&  j >= 2 || i == 4 && j < 2)
                fillConvexPoly(ptr_canvas, vertices, 4, Scalar(0, 0, 0));
            else
                fillConvexPoly(ptr_canvas, vertices, 4, Scalar(200, 200, 200));
                //fillConvexPoly(ptr_canvas, vertices, 4, Scalar(255, 101, 106));
            x += 105;
        }
        x = 5;
        y += 105;
    }
}

int set_position()
{
    //void draw_cell(Mat ptr_canvas);
    char answer = INTRO, aux;

    do
    {
        cout << "Move with a, s, d, w (Enter to confirm or double enter to set):";
        aux = getchar();
        getchar();

        if(aux == INTRO)
            break;

        answer = aux;
    }while(true);

    cout << int(answer);
}

//void draw_cell(Mat ptr_canvas)
//{
//}
