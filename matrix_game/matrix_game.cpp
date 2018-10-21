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
bool value_bounded(int value);
bool value_in_rock(int x, int y);
int draw_selection(Mat ptr_temp, int x, int y);
void set_position(int x_y[]);
void draw_till_border(Mat ptr_canvas, int x, int y);
bool is_filled();

struct square
{
    Point initial_point;
    Point final_point;
    Scalar color;
    bool ocupated;
};

struct square squares[5][5];

int main()
{
    //cout << "true" << endl;
    Mat canvas(SIZE, SIZE, CV_8UC3, Scalar(255, 255, 255));
    int init_point[2];

    //rectangle(canvas, Point(0, 0), Point(100, 100), Scalar(0, 0, 255), CV_FILLED);
    //circle(canvas, Point(100, 100), 50, Scalar(0, 0, 255), CV_FILLED);
    draw_grid(canvas);
    imshow("Game", canvas);
    waitKey(100);

    set_position(init_point);

    cout << "----------Now the selection will be painted till the border or the black tiles----------" << endl;

    draw_till_border(canvas, init_point[0], init_point[1]);

    //cout << init_point[0] <<endl;
    //cout << init_point[1] <<endl;

    waitKey(0);

    return 0;
}


void draw_grid(Mat image, int x_selected, int y_selected)
{
    int i, j;
    int x = 5, y = 5;

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {

            //Draw black squares by default
            if(x_selected == -1 && y_selected == -1)
            {
                squares[i][j].initial_point = Point(x, y);
                squares[i][j].final_point = Point(x + 100, y + 100);
                squares[i][j].ocupated = false;

                if(i == 0 &&  j >= 2 || i == 4 && j < 2)
                {
                    squares[i][j].color = Scalar(0, 0, 0);
                    rectangle(image, squares[i][j].initial_point, squares[i][j].final_point, squares[i][j].color, CV_FILLED);
                }
                else
                {
                    squares[i][j].color = Scalar(200, 200, 200);
                    rectangle(image, squares[i][j].initial_point, squares[i][j].final_point, squares[i][j].color, CV_FILLED);
                }
            }
            else
            {
                if(i == y_selected && j == x_selected)
                {
                    squares[i][j].color = Scalar(255, 101, 106);
                    rectangle(image, squares[i][j].initial_point, squares[i][j].final_point, squares[i][j].color, CV_FILLED);
                }
            }
            x += 105;
        }
        x = 5;
        y += 105;
    }
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
    if(x >= 2 && y == 0 || x < 2 && y == 4)
        return true;
    else
        return false;
}

//One at the time
int draw_selection(Mat ptr_temp, int x, int y)
{
    if (value_bounded(x) && value_bounded(y) && !(value_in_rock(x, y)))
    {
        draw_grid(ptr_temp, x, y);
        imshow("Game", ptr_temp);
        waitKey(100);
        return 0;
    }else
        return 1;
}

void set_position(int x_y[])
{
    Mat temp(SIZE, SIZE, CV_8UC3, Scalar(255, 255, 255));
    draw_grid(temp);
    draw_grid(temp, 0, 0);
    imshow("Game", temp);
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

    x_y[0] = x;
    x_y[1] = y;
}

////Till border
void draw_till_border(Mat ptr_canvas, int x, int y)
{
    bool was_in;
    imshow("Game", ptr_canvas);
    waitKey(100);

    char answer = INTRO, aux;
    draw_selection(ptr_canvas, x, y);
    squares[x][y].ocupated = true;

    do
    {
        cout << "Move with a, s, d, w (Enter to confirm or double enter to set):";
        aux = getchar();
        getchar();

        if(aux == INTRO)
            break;

        answer = aux;

        switch(answer)
        {
            case LEFT_KEY:
                           x--;
                           while (value_bounded(x) && value_bounded(y) && !value_in_rock(x, y) && !squares[x][y].ocupated)
                           {
                               draw_selection(ptr_canvas, x, y);
                               squares[x][y].ocupated = true;
                               x--;
                           }
                           x++;
                           break;
            case RIGHT_KEY:
                           x++;
                           while (value_bounded(x) && value_bounded(y) && !value_in_rock(x, y) && !squares[x][y].ocupated)
                           {
                               draw_selection(ptr_canvas, x, y);
                               squares[x][y].ocupated = true;
                               x++;
                           }
                           x--;
                           break;
            case UP_KEY:
                           y--;
                           while (value_bounded(x) && value_bounded(y) && !value_in_rock(x, y) && !squares[x][y].ocupated)
                           {
                               draw_selection(ptr_canvas, x, y);
                               squares[x][y].ocupated = true;
                               y--;
                           }
                           y++;
                           break;
            case DOWN_KEY:
                           y++;
                           while (value_bounded(x) && value_bounded(y) && !value_in_rock(x, y) && !squares[x][y].ocupated)
                           {
                               draw_selection(ptr_canvas, x, y);
                               squares[x][y].ocupated = true;
                               y++;
                           }
                           y--;
                           break;
        }

    }while(true);
}
