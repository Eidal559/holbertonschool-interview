#include <stdio.h>
#include "sandpiles.h"

/**
 * sandpiles_sum - Computes the sum of two sandpiles and stabilizes the result
 * @grid1: First 3x3 grid (output grid)
 * @grid2: Second 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;

    // Add grid2 to grid1 element-wise
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            grid1[i][j] += grid2[i][j];

    // Continue toppling until stable
    while (!is_stable(grid1))
    {
        printf("=\n");
        print_grid(grid1);
        topple(grid1);
    }
}

/**
 * is_stable - Check if the grid is stable
 * @grid: 3x3 grid
 *
 * Return: 1 if stable, 0 if unstable
 */
int is_stable(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (grid[i][j] > 3)
                return (0);
        }
    }
    return (1);
}

/**
 * topple - Topple unstable sandpile cells
 * @grid: 3x3 grid
 */
void topple(int grid[3][3])
{
    int temp[3][3] = {{0}};

    // Topple each cell with more than 3 grains
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i][j] > 3)
            {
                temp[i][j] -= 4;  // Reduce by 4 for the current cell

                // Distribute to neighboring cells
                if (i > 0)
                    temp[i - 1][j] += 1;  // Top neighbor
                if (i < 2)
                    temp[i + 1][j] += 1;  // Bottom neighbor
                if (j > 0)
                    temp[i][j - 1] += 1;  // Left neighbor
                if (j < 2)
                    temp[i][j + 1] += 1;  // Right neighbor
            }
        }
    }

    // Update grid1 with the toppling result
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            grid[i][j] += temp[i][j];
}

/**
 * print_grid - Print a 3x3 grid
 * @grid: 3x3 grid
 */
void print_grid(int grid[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j != 0)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}
