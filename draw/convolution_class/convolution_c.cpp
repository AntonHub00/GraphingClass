/*
Convolution matrix to fill "blank" spaces
*/

#include "opencv2/core/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>


#define SIZE 400
using namespace cv;
using namespace std;

//Beginning of Functions
void set_background(int ptr_image[][SIZE], int color);

void print_image(int[][SIZE]);

void paint(int ptr_image[][SIZE], int x1, int y1, int x2, int y2, int color);

void complete_half(int ptr_image[][SIZE]);

void draw_in_canvas(Mat ptr_canvas, int ptr_image[][SIZE], int resize, int translate);

void convolution_op(Mat ptr_canvas, Mat ptr_canvas_final, int resize, int translate);
//End of functions

//Beginning of main
int main(int argc, char** argv)
{
    int image[SIZE][SIZE];

    set_background(image, 255);

    //Left side
    paint(image, 14, 4, 28, 6, 0);

    //Up-left side
    paint(image, 10, 6, 16, 8, 0);
    paint(image, 8, 8, 12, 10, 0);
    paint(image, 6, 10, 10, 12, 0);
    paint(image, 6, 12, 8, 16, 0);

    //top
    paint(image, 4, 14, 6, 20, 0);

    //Down-left side
    paint(image, 26, 6, 30, 8, 0);
    paint(image, 26, 8, 34, 10, 0);
    paint(image, 32, 10, 36, 12, 0);

    //Down
    paint(image, 34, 12, 36, 20, 0);

    //Face
    paint(image, 24, 10, 28, 12, 0);
    paint(image, 24, 12, 26, 20, 0);
    paint(image, 26, 16, 30, 18, 0);

    //Inside mushroom (5 up)
    paint(image, 10, 10, 14, 12, 200);
    paint(image, 12, 12, 22, 14, 200);
    paint(image, 12, 14, 16, 16, 200);
    paint(image, 10, 16, 14, 18, 200);
    paint(image, 6, 18, 14, 20, 200);

    //Inside mushroom (2 down)
    paint(image, 22, 6, 24, 16, 200);
    paint(image, 24, 6, 26, 10, 200);

    //Completing the half "automatically"
    complete_half(image);

    int resize = 1;
    int translate = 0;
    int new_size = (SIZE + translate) * resize;

    //Mat canvas = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
    //Mat canvas_f(SIZE * resize, SIZE * resize, CV_8UC1, Scalar(0));
    Mat canvas(new_size, new_size, CV_8UC1, Scalar(0));
    Mat canvas_final(new_size, new_size, CV_8UC1, Scalar(0));

    //draw_in_canvas(canvas, image, resize, translate);
    canvas = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);

    convolution_op(canvas, canvas_final, resize, translate);

    namedWindow("img", WINDOW_AUTOSIZE);
    imshow("img", canvas_final);

    waitKey(0);
    waitKey(0);
    waitKey(0);

    return 0;
} //End of main

//Beginning of set_background
void set_background(int ptr_image[][SIZE], int color)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            ptr_image[i][j] = color;
        }
    }
} //End of set_background

//Beginning of print_image
void print_image(int ptr_image[][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d ", ptr_image[i][j]);
        }
        printf("\n");
    }
} //End of print_image

//Beginning of paint
void paint(int ptr_image[][SIZE], int x1, int y1, int x2, int y2, int color)
{
    int resize = SIZE / 40;

    for (int i = x1 * resize; i < x2 * resize; i++)
    {
        for (int j = y1 * resize; j < y2 * resize; j++)
        {
            ptr_image[i][j] = color;
        }
    }
} //End of paint

//Beginning of complete_half
void complete_half(int ptr_image[][SIZE])
{
    int aux = SIZE - 1;

    for (int i = 0; i < SIZE; i++)
    {
        aux = SIZE - 1;

        for (int j = 0; j < SIZE / 2; j++)
        {
            ptr_image[i][aux] = ptr_image[i][j];
            aux--;
        }
    }
} //End of complete_half

//Beginning of draw_in_canvas
void draw_in_canvas(Mat ptr_canvas, int ptr_image[][SIZE], int resize, int translate)
{
    int i, j;

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j  < SIZE; j++)
        {
            ptr_canvas.at<uchar>((i  + translate) * resize, (j + translate) * resize) = ptr_image[i][j];
        }
    }
}//End of draw_in_canvas

void convolution_op(Mat ptr_canvas, Mat ptr_canvas_final, int resize, int translate)
{
    int sum_convolution(Mat p_ptr_canvas, int i, int j, int size);
    int new_size = (SIZE + translate) * resize;
    int result = 0;
    int i, j;

    for (i = 0; i < new_size; i++)
    {
        for (j = 0; j < new_size; j++)
        {
            result = sum_convolution(ptr_canvas, i, j, new_size);
            ptr_canvas_final.at<uchar>(i, j) = result;
        }
    }
} //End of paint

int sum_convolution(Mat p_ptr_canvas, int i, int j, int size)
{
    //int con_matrix[][3]= {{1, 0, 1}, {2, 0, 2}, {1, 0, 1}};
    //int con_matrix[][3]= {{0, -1, 0}, {-1, -5, -1}, {0, -1, 0}};
    //int con_matrix[][3]= {{-1, -1, 0}, {-1, -8, -1}, {-1, -1, -1}};
    //int con_matrix[][3]= {{0, 1, 0}, {0, -4, 0}, {0, 1, 0}};
    //int con_matrix[][3]= {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    //int con_matrix[][3]= {{5, 5, 5}, {5, 7, 5}, {5, 5, 5}};
    int con_matrix[][3]= {{0, 0, 0}, {-1, 1, 0}, {0, 0, 0}};
    int sum = 0;

    if (i - 1 >= 0 & j - 1 >= 0)
    {
        sum += p_ptr_canvas.at<uchar>(i - 1, j - 1) * con_matrix[0][0];
    }
    if (i - 1 >= 0)
    {
        sum += p_ptr_canvas.at<uchar>(i - 1, j) * con_matrix[0][1];
    }
    if (i - 1 >= 0 & j + 1 < size)
    {
        sum += p_ptr_canvas.at<uchar>(i -1, j + 1) * con_matrix[0][2];
    }
    if (j + 1 < size)
    {
        sum += p_ptr_canvas.at<uchar>(i, j + 1) * con_matrix[1][2];
    }
    if (i + 1 < size & j + 1 < size)
    {
        sum += p_ptr_canvas.at<uchar>(i + 1, j + 1) * con_matrix[2][2];
    }
    if (i + 1 < size)
    {
        sum += p_ptr_canvas.at<uchar>(i + 1, j) * con_matrix[2][1];
    }
    if (i + 1 < size & j - 1 >= 0)
    {
        sum += p_ptr_canvas.at<uchar>(i + 1, j - 1) * con_matrix[2][0];
    }
    if (j - 1 >= 0)
    {
        sum += p_ptr_canvas.at<uchar>(i, j - 1) * con_matrix[1][0];
    }

    sum += p_ptr_canvas.at<uchar>(i, j) * con_matrix[1][1];
    sum += sum / 9;

    if (sum > 255)
    {
        sum = 255;
    }else if (sum < 0)
    {
        sum = 0;
    }

    return sum;
}
