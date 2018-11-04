/*
This is the same as the convolution kernel but in this case
by using a separable kernel
*/

#include "opencv2/core/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>


#define SIZE 400
using namespace cv;
using namespace std;

void convolution_op(Mat ptr_canvas, Mat ptr_aux_canvas, Mat ptr_canvas_final, int resize, int translate);

int main(int argc, char** argv)
{
    int resize = 1;
    int translate = 0;
    int new_size = (SIZE + translate) * resize;

    Mat canvas(new_size, new_size, CV_8UC1, Scalar(0));
    Mat aux_canvas(new_size, new_size, CV_8UC1, Scalar(0));
    Mat canvas_final(new_size, new_size, CV_8UC1, Scalar(0));

    canvas = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);

    convolution_op(canvas, aux_canvas, canvas_final, resize, translate);

    namedWindow("img", WINDOW_AUTOSIZE);
    imshow("img", canvas_final);

    waitKey(0);

    return 0;
}

void convolution_op(Mat ptr_canvas, Mat ptr_aux_canvas, Mat ptr_canvas_final, int resize, int translate)
{
    int sum_convolution(Mat p_ptr_canvas, int i, int j, int size, bool horizontal);
    int new_size = (SIZE + translate) * resize;
    int result = 0;
    int i, j, aux;
    bool state = true;

    for (aux = 0; aux < 2; aux++)
    {
        for (i = 0; i < new_size; i++)
        {
            for (j = 0; j < new_size; j++)
            {
                if (aux == 0)
                {
                    result = sum_convolution(ptr_canvas, i, j, new_size, state);
                    ptr_aux_canvas.at<uchar>(i, j) = result;
                }
                else
                {
                    result = sum_convolution(ptr_aux_canvas, i, j, new_size, state);
                    ptr_canvas_final.at<uchar>(i, j) = result;
                }
            }
        }
        state = false;
    }
}

int sum_convolution(Mat p_ptr_canvas, int i, int j, int size, bool horizontal)
{
    int split_kernel[][3] = {{1, 0, 1}, {1, 2, 1}};
    //int split_kernel[][3 ] = {{1, 1, 1}, {1, 1, 1}};
    int sum = 0;

    if (horizontal)
    {
        if (j - 1 >= 0)
        {
            sum += p_ptr_canvas.at<uchar>(i, j - 1) * split_kernel[0][0];
        }
        if (j + 1 < size)
        {
            sum += p_ptr_canvas.at<uchar>(i, j + 1) * split_kernel[0][2];
        }

        sum += p_ptr_canvas.at<uchar>(i, j) * split_kernel[0][1];
    }else
    {
        if (i - 1 >= 0)
        {
            sum += p_ptr_canvas.at<uchar>(i - 1, j) * split_kernel[1][0];
        }
        if (i + 1 < size)
        {
            sum += p_ptr_canvas.at<uchar>(i + 1, j) * split_kernel[1][2];
        }

        sum += p_ptr_canvas.at<uchar>(i, j) * split_kernel[1][1];
    }

    if (sum > 255)
        sum = 255;
    else if (sum < 0)
        sum = 0;

    return sum;
}
