/*
Drawing with a matrix
*/
#include <stdio.h>

#define SIZE 400

void print_matrix(int[][SIZE]);

int main()
{
    int matrix[SIZE][SIZE] = {0};

    print_matrix(matrix);
}

void print_matrix(int ptr_matrix[][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d ", ptr_matrix[i][j]);
        }
        printf("\n");
    }
}