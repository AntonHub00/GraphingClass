/*
Moving the two knights at the bottom in the place of the 
knights at the top and vice versa
*/
#include "stdio.h"

#define SIZE 3

void print_matrix(char ptr_matrix[][SIZE]);
void swap(char ptr_matrix[][SIZE]);

int main()
{
    char matrix[SIZE][SIZE] = {{'O', '-', 'o'}, {'-', '-', '-'}, {'X', '-', 'x'}};

    print_matrix(matrix);
    printf("\n");

    swap(matrix);

    return 0;
}

void swap(char ptr_matrix[][SIZE])
{
    for (int i = 0; i < 2; i++)
    {
        char aux = ptr_matrix[0][1];
        ptr_matrix[0][1] = ptr_matrix[SIZE - 1][SIZE - 1];
        ptr_matrix[SIZE - 1][SIZE - 1] = aux;
        print_matrix(ptr_matrix);
        printf("\n");

        aux = ptr_matrix[SIZE - 1][1];
        ptr_matrix[SIZE - 1][1] = ptr_matrix[0][0];
        ptr_matrix[0][0] = aux;
        print_matrix(ptr_matrix);
        printf("\n");

        aux = ptr_matrix[1][SIZE - 1];
        ptr_matrix[1][SIZE - 1] = ptr_matrix[SIZE - 1][0];
        ptr_matrix[SIZE - 1][0] = aux;
        print_matrix(ptr_matrix);
        printf("\n");

        aux = ptr_matrix[1][0];
        ptr_matrix[1][0] = ptr_matrix[0][SIZE - 1];
        ptr_matrix[0][SIZE - 1] = aux;
        print_matrix(ptr_matrix);
        printf("\n");

        aux = ptr_matrix[0][0];
        ptr_matrix[0][0] = ptr_matrix[1][SIZE - 1];
        ptr_matrix[1][SIZE - 1] = aux;
        print_matrix(ptr_matrix);
        printf("\n");

        aux = ptr_matrix[SIZE - 1][SIZE - 1];
        ptr_matrix[SIZE - 1][SIZE - 1] = ptr_matrix[1][0];
        ptr_matrix[1][0] = aux;
        print_matrix(ptr_matrix);
        printf("\n");

        aux = ptr_matrix[SIZE - 1][0];
        ptr_matrix[SIZE - 1][0] = ptr_matrix[0][1];
        ptr_matrix[0][1] = aux;
        print_matrix(ptr_matrix);
        printf("\n");

        aux = ptr_matrix[SIZE - 1][1];
        ptr_matrix[SIZE - 1][1] = ptr_matrix[0][SIZE - 1];
        ptr_matrix[0][SIZE - 1] = aux;
        print_matrix(ptr_matrix);
        printf("\n");
    }
}

void print_matrix(char ptr_matrix[][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%c ", ptr_matrix[i][j]);
        }
        printf("\n");
    }
}