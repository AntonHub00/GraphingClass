/*
This build a magic square with odd number size
*/
#include <stdio.h>

#define SIZE 7

void print_matrix(int ptr_matrix[][SIZE]);

void fill_square(int ptr_matrix[][SIZE]);

int main()
{
    int matrix[SIZE][SIZE] = {0};

    print_matrix(matrix);

    printf("\n");

    fill_square(matrix);

    print_matrix(matrix);

    printf("\n");

    return 0;
}

void fill_square(int ptr_matrix[][SIZE])
{
    int i = 0, j = SIZE / 2;
    ptr_matrix[i][j] = 1;

    int num = 2;
    int counter = 1;
    while (counter < SIZE * SIZE) //(SIZE * SIZE) - 1)
    {

        if (i - 1 >= 0)
        {
            if (j + 1 == SIZE)
            {
                i--;
                j = 0;
                ptr_matrix[i][j] = num;
                num++;
            }
            else
            {
                if (ptr_matrix[i - 1][j + 1] == 0)
                {
                    i--;
                    j++;
                    ptr_matrix[i][j] = num;
                    num++;
                }
                else
                {
                    i++;
                    ptr_matrix[i][j] = num;
                    num++;
                }
            }
        }
        else
        {
            if (j + 1 == SIZE)
            {
                i++;
                ptr_matrix[i][j] = num;
                num++;
            }
            else
            {
                i = SIZE - 1;
                j++;
                while (ptr_matrix[i][j] != 0)
                {
                    i--;
                }
                ptr_matrix[i][j] = num;
                num++;
            }
        }
        counter++;
    }
}

void print_matrix(int ptr_matrix[][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%5d ", ptr_matrix[i][j]);
        }
        printf("\n");
    }
}