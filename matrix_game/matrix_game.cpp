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

void draw_grid(Mat image, int x_selected = -1, int y_selected = -1);
void set_position(int x_y[]);
bool value_bounded(int value);
int draw_selection(Mat ptr_temp, int x, int y);

int main()
{
    Mat canvas(SIZE, SIZE, CV_8UC3, Scalar(255, 255, 255));
    int init_point[2];

    draw_grid(canvas);
    imshow("Draw", canvas);
    waitKey(100);

    set_position(init_point);

    //namedWindow("Draw", WINDOW_AUTOSIZE);
    waitKey(0);

    return 0;
}

void draw_grid(Mat image, int x_selected, int y_selected)
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

            //Draw black squares by default
            if(x_selected == -1 && y_selected == -1)
            {
                if(i == 0 &&  j >= 2 || i == 4 && j < 2)
                    fillConvexPoly(image, vertices, 4, Scalar(0, 0, 0));
                else
                    fillConvexPoly(image, vertices, 4, Scalar(200, 200, 200));
            }else
            {
                if(i == y_selected &&  j == x_selected)
                    fillConvexPoly(image, vertices, 4, Scalar(255, 101, 106));
            }
            x += 105;
        }
        x = 5;
        y += 105;
    }
}

void set_position(int x_y[])
{
    //void draw_cell(Mat ptr_canvas);
    Mat temp(SIZE, SIZE, CV_8UC3, Scalar(255, 255, 255));
    draw_grid(temp);
    draw_grid(temp, 0, 0);
    imshow("Draw", temp);
    waitKey(100);

    char answer = INTRO, aux;
    int x = 0, y = 0;

    do
    {
        draw_grid(temp);
        cout << "Move with a, s, d, w (Enter to confirm or double enter to set):";
        aux = getchar();
        getchar();

        if(aux == INTRO)
            break;

        answer = aux;

        switch(answer)
        {
            case LEFT_KEY: x--;
                           x += draw_selection(temp, x, y);
                           break;
            case RIGHT_KEY: x++;
                           x -= draw_selection(temp, x, y);
                           break;
            case UP_KEY: y--;
                           y += draw_selection(temp, x, y);
                           break;
            case DOWN_KEY: y++;
                           y -= draw_selection(temp, x, y);
                           break;
        }

    }while(true);

    //cout << int(answer);

    x_y[0] = x;
    x_y[1] = y;
}

bool value_bounded(int value)
{
    if(value >= 0 && value < 5)
        return true;
    else

        return false;

}

bool value_in_rock(int x, int y)
{
    if(x >= 2 && y == 0)
        return true;
    else if (x < 2 && y == 4)
        return true;
    else
        return false;
}

int draw_selection(Mat ptr_temp, int x, int y)
{
    if (value_bounded(x) && value_bounded(y) && !(value_in_rock(x, y)))
    {
        draw_grid(ptr_temp, x, y);
        imshow("Draw", ptr_temp);
        waitKey(100);
        return 0;
    }else
        return 1;
}

//void draw_cell(Mat ptr_canvas, int point[])
//{
//}
