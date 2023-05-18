#include "stdio.h"

#define SIZE 10

void     show_board(int board[SIZE][SIZE])
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (i < SIZE)
    {
        j = 0;
        while (j < SIZE){
            printf("%d ", board[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

// void    queens_positions(int board[SIZE][SIZE], column, num_queens)
// {
//     if ((num_queens == SIZE) && (column == SIZE))
//         return void;
    

// }

int     ft_ten_queens_puzzle(void)
{
    int     board[SIZE][SIZE]; 
    int     i; // loop control
    int     j; // loop control
    int     s;
    int     control_columns[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    i = 0;
    while (i < SIZE)
    {
        j = 0;
        while (j < SIZE)
        {
            board[i][j] = 0;
            j++;
        }
        i++;
    }
    // show_board(board);

    s = 4;
    i = 0;
    while (i < SIZE)
    {
        if (s > 8)
        {
            s = 0;
        }
        while (control_columns[s] != 0)
        {
            // printf("%d, ", s);
            s += 2;
            // if (s > 8)
            // {
            //     s = 0;
            // }
            while (j >= 0)
            {
                if (board[j][j] == 0)
            }
        }
        printf("\n");
        board[i][s] = 1;
        control_columns[s] = 1;
        printf("%d, %d\n", i, s);
        s += 2;
        i++;
    }

    for (int t = 0; t < 10; t++)
    {
        printf("[%d] %d, ", t, control_columns[t]);
    }
    printf("\n");
    // i = 0;  
    // j = 0;  
    // int c = 0;    
    // while (i < SIZE) {
    //     if (c == (SIZE / 2))
    //         c = 1;
   
    //     j = c * 2; 
    //     printf("%d, %d\n", i, j);
    //     board[i][j] = 1;
    //     i++;
    //     c++;
    // }

    show_board(board);

    return (0);
}

int     main(void)
{
    ft_ten_queens_puzzle();

    return (0);
}