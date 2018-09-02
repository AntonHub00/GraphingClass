/*
Testing "techniques" for printing the image
*/
#include <stdio.h>

#define SIZE 40

void set_background(int ptr_image[][SIZE], int color);

void print_image(int[][SIZE]);

void paint(int ptr_image[][SIZE], int x1, int y1, int x2, int y2, int color);

void complete_half(int ptr_image[][SIZE]);

int main()
{
    int image[SIZE][SIZE];

    set_background(image, 0);

    //Left side
    paint(image, 16, 4, 30, 6, 1);

    //Up-left side
    paint(image, 12, 6, 18, 8, 1);
    paint(image, 10, 8, 14, 10, 1);
    paint(image, 8, 10, 12, 12, 1);
    paint(image, 8, 12, 10, 16, 1);

    //top
    paint(image, 6, 14, 8, 20, 1);

    //Down-left side
    paint(image, 28, 6, 32, 8, 1);
    paint(image, 28, 8, 36, 10, 1);
    paint(image, 34, 10, 38, 12, 1);

    //Down
    paint(image, 36, 12, 38, 20, 1);

    //Face
    paint(image, 26, 10, 30, 12, 1);
    paint(image, 26, 12, 28, 20, 1);
    paint(image, 28, 16, 32, 18, 1);

    //Inside mushroom
    // paint(image, 14, 6, 20, 12, 5);

    //Completing the half "automatically"
    complete_half(image);

    //Print the complete image
    print_image(image);

    return 0;
}

void set_background(int ptr_image[][SIZE], int color)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            ptr_image[i][j] = color;
        }
    }
}

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
}

void paint(int ptr_image[][SIZE], int x1, int y1, int x2, int y2, int color)
{
    for (int i = x1; i < x2; i++)
    {
        for (int j = y1; j < y2; j++)
        {
            ptr_image[i][j] = color;
        }
    }
}

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
}