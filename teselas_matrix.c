/*
Filling a 8x8 matrix with "teselas" 
*/
#include <stdio.h>

#define SIZE 8

void print_matrix(int ptr_image[][SIZE]);

void fill_teselas(int ptr_matrix[][SIZE], int num, int row, int flag, int final_flag);

int main()
{
    int matrix[SIZE][SIZE] = {0};

    print_matrix(matrix);
    printf("\n");

    fill_teselas(matrix, 1, 0, 1, 1);

    print_matrix(matrix);
    printf("\n");

    return 0;
}

void print_matrix(int ptr_image[][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%*d ", 4, ptr_image[i][j]);
        }
        printf("\n");
    }
}

void fill_teselas(int ptr_matrix[][SIZE], int num, int row, int flag, int final_flag)
{
    if (final_flag)
    {
        if (flag)
        {
            int flagy = 1;
            while (row < (SIZE - 2))
            {
                for (int column = 0; column < SIZE; column += 2)
                {
                    ptr_matrix[row][column] = num;
                    ptr_matrix[row][column + 1] = num;
                    num++;
                }
                row += (flagy) ? 2 : 1;
                flagy = (flagy) ? 0 : 1;
            }
            return fill_teselas(ptr_matrix, num, 1, 0, 1);
        }
        else
        {
            int flagy = 1;

            while (row < (SIZE - 2))
            {
                for (int column = 0; column < SIZE; column++)
                {
                    if (flagy)
                        ptr_matrix[row][column] = ptr_matrix[row + 1][column];
                    else
                        ptr_matrix[row][column] = ptr_matrix[row - 1][column];

                    flagy = (flagy) ? 0 : 1;
                }
                row += 3;
            }

            return fill_teselas(ptr_matrix, num, row - 1, 0, 0);
        }
    }
    else
    {

        int counter = 2, column_flag = 1;

        while (counter > 0)
        {
            for (int column = 0; column < SIZE; column++)
            {
                if (!(column == SIZE - 1))
                {
                    if (column_flag)
                    {
                        ptr_matrix[row][column] = num;
                        ptr_matrix[row][column + 1] = num;
                        column++;
                        num++;
                    }
                    else
                    {
                        if (!column)
                            num = ptr_matrix[row - 1][column];

                        ptr_matrix[row][column] = num;
                        num++;
                    }
                }

                column_flag = (column_flag) ? 0 : 1;
            }
            row++;
            counter--;
        }
    }
}