/*
Fibonacci display in spiral
*/
#include <stdio.h>

#define SIZE 3

void fibonacci(int ptr_matrix[][SIZE]);
void print_matrix(int ptr_matrix[][SIZE]);

int main()
{
    int matrix[SIZE][SIZE] = {0};

    fibonacci(matrix);

    print_matrix(matrix);

    return 0;
}

void fibonacci(int ptr_matrix[][SIZE])
{
    void insert_spiral(int ptr_matrix[][SIZE], int number);
    int a = 1, b = 1, aux = 0;

    for (int i = 0; i < SIZE * SIZE; i++)
    {
        insert_spiral(ptr_matrix, a);
        aux = b;
        b += a;
        a = aux;
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

void insert_spiral(int ptr_matrix[][SIZE], int number)
{
    /*Up Rigth Down Left
    u = up
    r = rigth
    d = down
    l = left
    */
    static char direction_flag = 'u';
    static int counter = 1;
    static int row = SIZE / 2, column = SIZE % 2 == 0 ? (SIZE / 2) - 1 : (SIZE / 2);
    static int check_final = 0, check_counter = 0;

    if (ptr_matrix[SIZE / 2][SIZE % 2 == 0 ? (SIZE / 2) - 1 : (SIZE / 2)] == 0)
        ptr_matrix[SIZE / 2][SIZE % 2 == 0 ? (SIZE / 2) - 1 : (SIZE / 2)] = number;
    else
    {
        if (direction_flag == 'u')
        {
            row--;
            ptr_matrix[row][column] = number;
            check_counter++;

            if (check_counter == counter)
            {
                direction_flag = 'r';
                check_final++;
                check_counter = 0;
            }
        }
        else if (direction_flag == 'r')
        {
            column++;
            ptr_matrix[row][column] = number;
            check_counter++;

            if (check_counter == counter)
            {
                direction_flag = 'd';
                check_final++;
                check_counter = 0;
            }
        }
        else if (direction_flag == 'd')
        {
            row++;
            ptr_matrix[row][column] = number;
            check_counter++;

            if (check_counter == counter)
            {
                direction_flag = 'l';
                check_final++;
                check_counter = 0;
            }
        }
        else if (direction_flag == 'l')
        {
            column--;
            ptr_matrix[row][column] = number;
            check_counter++;

            if (check_counter == counter)
            {
                direction_flag = 'u';
                check_final++;
                check_counter = 0;
            }
        }

        if (check_final == 2)
        {
            check_final = 0;
            counter++;
        }
    }
}